const char * const authorname = "John Doe";

class GamePlayer{
private:
    static const int turns = 5;
    int scores[turns];
};

#include <cstddef>

const GamePlayer p1, p2;

#define CALL_WITH_MAX(a, b) f((a) > (b) ? (a) : (b))
int a = 5, b = 0;
int CALL_WITH_MAX(++a, b); // a is incremented twice
int CALL_WITH_MAX(++a, b+10); // a is incremented once

class CTextBlock{
public:
    std::size_t length() const;
private:
    char *pText;
    static std::size_t textLength;
    mutable bool lengthIsValid;
};
#include <cstring>

std::size_t CTextBlock::length() const{
    if(!lengthIsValid){
        //const成员函数中，不允许修改类的任何非静态成员变量
        textLength = std::strlen(pText);
        lengthIsValid = true;
    }
    return textLength;
}

class TextBlock{
private:
    std::size_t length;
    char *pText;
    mutable std::size_t textLength;
    mutable bool lengthIsValid;
public:
    const char& operator[](std::size_t position) const{
        return pText[position];
    }
    char& operator[](std::size_t position){
        /*
        1. static_cast<const TextBlock&>(*this)将*this转换为const TextBlock&类型
        2. [position]调用const版本的operator[]，返回const char&类型
        3. const_cast<char&>将const char&转换为char&
        */
        return const_cast<char&>(
            static_cast<const TextBlock&>(*this)[position]
        );
    }
};