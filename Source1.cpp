#include "Header.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>


using namespace std;
const int COLUMN_WIDTH = 60;


MyString::MyString() : str(""), frequency(0) {}
MyString::MyString(string s) : str(s), frequency(1) {}
bool MyString:: operator==(const MyString& rhs) const
{
    return (str == rhs.str);
}
bool MyString:: operator>(const MyString& s) const
{
    if (frequency == s.frequency)
    {
        return str < s.str;
    }
    else
    {
        return frequency > s.frequency;
    }
}
bool MyString:: operator<(const MyString& s) const
{
    if (frequency == s.frequency)
    {
        return str < s.str;
    }
    else
    {
        return frequency < s.frequency;
    }
}
MyString MyString:: operator++(int)
{
    frequency++;
    return *this;
}
string MyString::getStr() const
{
    return str;
}


ofstream& operator<<(ofstream& o, const MyString& obj)
{
    o << left << setw(COLUMN_WIDTH) << obj.str << obj.frequency << endl;
    return o;
}
