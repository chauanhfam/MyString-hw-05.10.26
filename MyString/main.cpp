#include <iostream>
#include "MyString.h"
using namespace std;

int main()
{
    cout << "Total objects: " << MyString::GetCount() << endl;

    MyString str1("Hello");
    MyString str2("World");

    str1.MyStrCat(str2);
    cout << "Concatenation: "; 
    str1.Output();
    cout << endl;

    cout << "Length: " << str1.MyStrLen() << endl;
    cout << "Search 'W' index: " << str1.MyChr('W') << endl;

    cout << "Contains 'llo'?: " << (str1.MyStrStr("llo") ? "Yes" : "No") << endl;

    str1.MyDelChr('l');
    cout << "After deleting 'l': ";
    str1.Output(); 
    cout << endl;

    cout << "Comparison str1 and str2: " << str1.MyStrCmp(str2) << endl;

    cout << "\n Operators testing" << endl;
    MyString base("Test");

    MyString res1 = base + '!';
    cout << "obj + '!': ";
    res1.Output(); 
    cout << endl;

    MyString res2 = '@' + base;
    cout << "'@' + obj: "; 
    res2.Output(); 
    cout << endl;

    MyString res3 = base + 5;
    cout << "obj + 5 (added spaces): '"; 
    res3.Output();
    cout << "'" << endl;

    MyString res4 = 3 + base;
    cout << "3 + obj (added spaces): '"; 
    res4.Output(); 
    cout << "'" << endl;

    ++base;
    cout << "++obj (prefix): "; 
    base.Output(); 
    cout << endl;

    base++;
    cout << "obj++ (postfix): "; 
    base.Output(); 
    cout << endl;

    cout << "\nTotal objects at the end: " << MyString::GetCount() << endl;

    return 0;
}