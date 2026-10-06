#define _CRT_SECURE_NO_WARNINGS
#include "MyString.h"
using namespace std;
int MyString::count = 0;

MyString::MyString() : length(30)
{
    str = new char[length + 1];
    str[0] = '\0';
    count++;
}

MyString::MyString(int size)
{
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
        if (str[i] != c) newLength++;
    }

    char* temp = new char[newLength + 1];
    int j = 0;
    for (int i = 0; i < length; i++)
    {
        if (str[i] != c) temp[j++] = str[i];
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

MyString MyString::operator+(char c)
{
    MyString temp(length + 1);
    strcpy(temp.str, str);
    temp.str[length] = c;
    temp.str[length + 1] = '\0';
    return temp;
}

MyString MyString::operator+(int n)
{
    MyString temp(length + n);
    strcpy(temp.str, str);
    for (int i = length; i < length + n; i++)
    {
        temp.str[i] = ' ';
    }
    temp.str[length + n] = '\0';
    return temp;
}

MyString operator+(char c, const MyString& obj)
{
    MyString temp(obj.length + 1);
    temp.str[0] = c;
    strcpy(temp.str + 1, obj.str);
    return temp;
}

MyString operator+(int n, const MyString& obj)
{
    MyString temp(obj.length + n);
    strcpy(temp.str, obj.str);
    for (int i = obj.length; i < obj.length + n; i++) 
    {
        temp.str[i] = ' ';
    }
    temp.str[obj.length + n] = '\0';
    return temp;
}

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