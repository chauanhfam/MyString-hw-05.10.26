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

    static int GetCount();

    MyString operator+(char c);
    MyString operator+(int n); 

    MyString& operator++();
    MyString operator++(int); 

    MyString& operator=(const MyString& obj);



    friend MyString operator+(char c, const MyString& obj);
    friend MyString operator+(int n, const MyString& obj);
};

