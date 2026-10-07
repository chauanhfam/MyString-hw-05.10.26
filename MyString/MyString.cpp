#define _CRT_SECURE_NO_WARNINGS
#include "MyString.h"
using namespace std;

int MyString::count = 0; 

MyString::MyString() : length(80)
{
    str = new char[length + 1];
    str[0] = '\0';
    count++;
}

MyString::MyString(int size)
{
    length = size;
    str = new char[length + 1];
    str[0] = '\0';
    count++;
}

MyString::MyString(const char* userStr)
{
    length = strlen(userStr);
    str = new char[length + 1];
    strcpy(str, userStr);
    count++;
}

MyString::MyString(const MyString& obj)
{
    length = obj.length;
    str = new char[length + 1];
    strcpy(str, obj.str);
    count++;
}

MyString::~MyString()
{
    delete[] str;
    count--;
}

void MyString::Input()
{
    char temp[1024];
    cout << "Enter string: ";
    cin.getline(temp, 1024);

    delete[] str;
    length = strlen(temp);
    str = new char[length + 1];
    strcpy(str, temp);
}

void MyString::Output() const
{
    if (str != nullptr)
    {
        cout << str;
    }
}

bool MyString::MyStrStr(const char* searchStr) const
{
    return strstr(str, searchStr) != nullptr; 
}

int MyString::MyChr(char c) const
{
    for (int i = 0; i < length; i++)
    {
        if (str[i] == c) 
        {
            return i;
        }
    }
    return -1; 
}

int MyString::MyStrLen() const
{
    return length;
}

void MyString::MyStrCat(const MyString& b)
{
    int newLength = length + b.length;
    char* temp = new char[newLength + 1];

    strcpy(temp, str);
    strcat(temp, b.str);

    delete[] str;
    str = temp;
    length = newLength;
}

void MyString::MyDelChr(char c)
{
    int newLength = 0;
    for (int i = 0; i < length; i++)
    {
        if (str[i] != c) 
        {
            newLength++;
        }
    }

    char* temp = new char[newLength + 1];
    int j = 0;
    for (int i = 0; i < length; i++)
    {
        if (str[i] != c) 
        {
            temp[j++] = str[i];
        }
    }
    temp[j] = '\0';

    delete[] str;
    str = temp;
    length = newLength;
}

int MyString::MyStrCmp(const MyString& b) const
{
    int res = strcmp(str, b.str);
    if (res < 0) 
    {
        return -1;
    }
    if (res > 0) 
    {
        return 1;
    }
    return 0; 
}

int MyString::GetCount()
{
    return count;
}

const char* MyString::GetStr() const
{
    return str;
}

int MyString::GetLength() const
{
    return length;
}

MyString& MyString::operator=(const MyString& obj)
{
    if (this == &obj)
    {
        return *this;
    }
    delete[] str;
    length = obj.length;
    str = new char[length + 1];
    strcpy(str, obj.str);
    return *this;
}

// obj + 'A'
MyString MyString::operator+(char c) const
{
    char* tempStr = new char[length + 2];
    strcpy(tempStr, str);
    tempStr[length] = c;
    tempStr[length + 1] = '\0';

    MyString tempObj(tempStr);
    delete[] tempStr;
    return tempObj;
}

// obj + 10
MyString MyString::operator+(int n) const
{
    int newLen = length + n;
    char* tempStr = new char[newLen + 1];
    strcpy(tempStr, str);
    for (int i = length; i < newLen; i++)
    {
        tempStr[i] = ' ';
    }
    tempStr[newLen] = '\0';

    MyString tempObj(tempStr);
    delete[] tempStr;
    return tempObj;
}

// Префіксний інкремент
MyString& MyString::operator++()
{
    char* temp = new char[length + 2];
    temp[0] = '*';
    strcpy(temp + 1, str);

    delete[] str;
    str = temp;
    length++;
    return *this;
}

// Постфіксний інкремент
MyString MyString::operator++(int)
{
    MyString oldState(*this);

    char* temp = new char[length + 2];
    strcpy(temp, str);
    temp[length] = '*';
    temp[length + 1] = '\0';

    delete[] str;
    str = temp;
    length++;

    return oldState;
}

char& MyString::operator[](int index)
{
    if (index >= 0 && index < length)
    {
        return str[index];
    }
    return str[length];
}

//operator()
void MyString::operator()()
{
    this->Input();
}

// 'A' + obj
MyString operator+(char c, const MyString& obj)
{
    int newLen = obj.GetLength() + 1;
    char* tempStr = new char[newLen + 1];
    tempStr[0] = c;
    strcpy(tempStr + 1, obj.GetStr());

    MyString res(tempStr);
    delete[] tempStr;
    return res;
}
// 10 + obj
MyString operator+(int n, const MyString& obj)
{
    int newLen = obj.GetLength() + n;
    char* tempStr = new char[newLen + 1];
    strcpy(tempStr, obj.GetStr());
    for (int i = obj.GetLength(); i < newLen; i++)
    {
        tempStr[i] = ' ';
    }
    tempStr[newLen] = '\0';

    MyString res(tempStr);
    delete[] tempStr;
    return res;
}
