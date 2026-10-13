#include <iostream>
#include "MyString.h"
using namespace std;
int main()
{
    cout << "Total objects: " << MyString::GetCount() << endl;

    MyString str1("Hello");
    MyString str2("World");

    /*str1.MyStrCat(str2);
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

    cout << "\nTotal objects at the end: " << MyString::GetCount() << endl;*/

    
    cout << "Testing operator():" << endl;
    MyString str3;
    str3();
    cout << "You entered: ";
    str3.Output();
    cout << endl << endl;

    cout << "Testing operator[]:" << endl;
    cout << "First char of str1: " << str1[0] << endl;
    str1[0] = 'h';
    cout << "After modification: ";
    str1.Output();
    cout << endl;

    cout << "Operators testing:" << endl;
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

    cout << "Total objects before I/O tests: " << MyString::GetCount() << endl;

    MyString test1;
    cout << endl;
    cout << "Enter a string for test1: ";
    cin >> test1;

    cout << "You entered: " << test1 << endl;

    MyString test2;
    MyString test3;
    test3 = test2 = test1;

    cout << "test2 after assignment: " << test2 << endl;
    cout << "test3 after assignment: " << test3 << endl;

    test1 = test1;
    cout << "test1 after self-assignment: " << test1 << endl;

    MyString obj{ 'H', 'e', 'l', 'l', 'o' };
    cout << "String obj: " << obj << endl << endl;

    // Конструктор перенесення
    MyString movedObj = MyString{ 'T', 'e', 's', 't' };
    cout << "String movedObj: " << movedObj << endl << endl;

    // Оператор присвоювання з перенесенням
    MyString targetStr("Old data");
    cout << "Before: " << targetStr << endl;
    targetStr = MyString("New data");
    cout << "After: " << targetStr << endl;
    return 0;
}