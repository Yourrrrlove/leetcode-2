#!/usr/bin/env python
# _*_ coding: utf-8 _*_
 
import os
import re
import time
import warnings
import requests
 
warnings.filterwarnings("ignore")
 
session = requests.session()  # 对全局进行会话实例化
 
default_headers = {
    'authority': 'www.zhihu.com',
    'pragma': 'no-cache',
    'cache-control': 'no-cache',
    'sec-ch-ua': '"Chromium";v="21", " Not;A Brand";v="99"',
    'sec-ch-ua-mobile': '?0',
    'sec-ch-ua-platform': '"Windows"',
    'upgrade-insecure-requests': '1',
    'user-agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/95.0.4638.69 Safari/537.36',
    'accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9',
    'sec-fetch-site': 'same-origin',
    'sec-fetch-mode': 'navigate',
    'sec-fetch-user': '?1',
    'sec-fetch-dest': 'document',
    'referer': 'https://www.zhihu.com/',
    'accept-language': 'zh-CN,zh;q=0.9',
}
 
 
 
def get_resp(method, url, headers=default_headers, timeout=5, **kwargs):
    for i in range(5):  # 最多重试5次
        try:
            response = session.request(method=method, url=url, headers=headers, timeout=timeout, **kwargs)
            if response.status_code == 200:
                return response.text
            else:
                if i == 4:
                    print('【致命错误】接口状态码' + str(response.status_code) + '异常：' + url)
                else:
                    time.sleep(1)
        except:
            if i == 4:
                print('【致命错误】接口连接异常：' + url)
            else:
                time.sleep(1)
    return None
 
def downloadFile(fileUrl, folderName, fileSaveName):
    folderName = rename(folderName)
    fileSaveName = rename(fileSaveName)
    if not os.path.exists(folderName):
        os.mkdir(folderName)
    for i in range(5):  # 最多重试5次
        try:
            resp1 = session.get(url=fileUrl,headers=default_headers)
            with open(folderName + "/" + fileSaveName, 'wb') as f:
                f.write(resp1.content)
                print(fileSaveName)
            return
        except:
            if i == 4:
                print('【致命错误】文件下载异常：' + fileUrl)
            else:
                time.sleep(1)
 
 
def fixname(fileName):
    pattern = r'[\\/:*?"<>|\r\n]+'  # 过滤Windows文件名中的非法字符
    fileName = re.sub(pattern, "_", fileName)
    return fileName
 
def rename(fileName):
    fileName = re.sub(r'[\\]+', "＼", fileName)
    fileName = re.sub(r'[/]+', "／", fileName)
    fileName = re.sub(r'[:]+', "：", fileName)
    fileName = re.sub(r'[*]+', "＊", fileName)
    fileName = re.sub(r'[?]+', "？", fileName)
    fileName = re.sub(r'["]+', "＂", fileName)
    fileName = re.sub(r'[<]+', "＜", fileName)
    fileName = re.sub(r'[>]+', "＞", fileName)
    fileName = re.sub(r'[|]+', "｜", fileName)
    fileName = re.sub(r'[\r\n]+', "_", fileName)
    return fileName
 
 
def main():
    while 1 == 1:
        urlkey = str(input("请输入知乎链接："))
        if urlkey != '':
            resp = get_resp('post', urlkey)
            list = re.findall(r'data-original-token="(.*?)"', resp)
            for i in list:
                url = f'https://pic2.zhimg.com/{i}.png'
                downloadFile(url, '图片', f'{i}.png')
 
 
if __name__ == '__main__':
    main()