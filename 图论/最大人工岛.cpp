#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
private:
	int area = 0;
	int dire[2][4] = { {-1,1,0,0},{0,0,-1,1} };  //1—4表示上下左右四个方向
	void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y, int flag) {
		if (visited[x][y] == true || grid[x][y] == 0) return; //dfs的作用是遍历地图，得出各个岛屿的面积，并做编号记录；所以dfs只遍历陆地，碰到海洋或者已经遍历过的陆地就返回
		visited[x][y] = true; //将当前陆地标记为已访问
		grid[x][y] = flag; //给陆地标号
		area++;  //每遍历一块陆地，岛屿面积就加一，因为每块陆地的面积为1
		for (int i = 0; i < 4; i++) {
			int next_x = x + dire[0][i], next_y = y + dire[1][i];
			if (next_x < 0 || next_x >= grid.size() || next_y < 0 || next_y >= grid[0].size()) continue; //如果下一个位置超出地图范围，就跳过
			if (grid[next_x][next_y] == 1) dfs(grid, visited, next_x, next_y, flag); //继续搜索陆地
		}
	}
public:
	int largestIsland(vector<vector<int>>& grid) {
		int n = grid.size();
		if (n == 0) return 0;
		int m = grid[0].size();
		int mark = 0;  //标记是否全是陆地
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == 0) {
					mark = 1; //如果有海洋，就将mark置1
					break;
				}
			}
		}
		if(mark == 0) return n * m;  //如果mark仍为0，说明grid全是陆地，直接返回grid的面积
		int flag = 2;  //用来给每一块遍历的陆地标号；因为0代表海洋，1代表陆地，所以从2开始标号
		unordered_map<int, int> area_map;  //用来记录每一个岛屿的面积：key为岛屿的标号flag，value为岛屿的面积
		vector<vector<bool>> visited(n, vector<bool>(m, false));
		//遍历地图，得出各个岛屿的面积，并做编号记录
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == 1 && visited[i][j] == false) { //之前的dfs可能把其它位置的陆地标记为已访问了，只有未访问过的陆地才是新发现的岛屿
					area = 0;  //每次找到新岛屿，都要从0开始计算岛屿面积
					dfs(grid, visited, i, j, flag);
					area_map[flag] = area;  //记录岛屿面积
					flag++;  //下一个岛屿应该用不同的编号
				}
			}
		}
		int result = 0; //记录最大的岛屿面积
		unordered_set<int> visitedIsland_set; //用来记录当前岛屿的上下左右四个方向是否有其它岛屿，如果有，就将其它岛屿的编号加入到set中
		//遍历地图，找到每一个海洋，然后看看它上下左右四个方向是否连着其它岛屿，如果有，就将其它岛屿的面积加起来，再加上当前海洋的面积，就是当前海洋变成陆地后的最大岛屿面积
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				area = 1; //每次找到新海洋，都要从1开始计算岛屿面积，因为当前海洋变成陆地后，面积为1
				visitedIsland_set.clear();  //每次找到新海洋，都要清空set
				if (grid[i][j] == 0) {
					for (int k = 0; k < 4; k++) {
						int next_x = i + dire[0][k], next_y = j + dire[1][k];
						if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= m) continue;  //防止超出grid范围
						//unordered_set中元素不允许重复，所以计算元素出现次数时，要不就是0，要不就是1
						if (visitedIsland_set.count(grid[next_x][next_y]) == 1) continue; //如果grid[i][j]上下左右四个方向中有些方向被标记为同一个flag，说明是同一个岛屿，不能重复计算面积
						area += area_map[grid[next_x][next_y]];  //新岛屿的面积等于当前海洋的面积1 + 它连着的上下左右四个方向的不同岛屿的面积
						visitedIsland_set.insert(grid[next_x][next_y]); //将上下左右四个方向的岛屿编号加入到set中
					}
				}
				result = max(result, area);  //更新最大岛屿面积
			}
		}
		return result;
	}
};