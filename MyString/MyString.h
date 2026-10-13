#pragma once
#include <iostream>
class MyString
{
private:
    char* str;
    int length;
    static int count;

public:
    MyString();
    MyString(int size);
    MyString(const char* userStr);
    MyString(const MyString& obj);
    ~MyString();

    void Input();
    void Output() const;
    bool MyStrStr(const char* searchStr) const;
    int MyChr(char c) const;
    int MyStrLen() const;
    void MyStrCat(const MyString& b);
    void MyDelChr(char c);
    int MyStrCmp(const MyString& b) const;

    const char* GetStr() const;
    int GetLength() const;

    static int GetCount();

    //check all
    MyString& operator=(const MyString& obj); 
    //method[]
    char& operator[](int index);
    //method()
    void operator()();
    //function obj+ 'A'
    MyString operator+(char c) const; 
    //obj + 10
    MyString operator+(int n) const; 
    //++obj
    MyString& operator++(); 
    //obj++
    MyString operator++(int);


    MyString(std::initializer_list<char> list);
    MyString(MyString&& obj) noexcept;
    MyString& operator=(MyString&& obj) noexcept;
};

MyString operator+(char c, const MyString& obj);
MyString operator+(int n, const MyString& obj);

std::ostream& operator<<(std::ostream& os, const MyString& obj);
std::istream& operator>>(std::istream& is, MyString& obj);
