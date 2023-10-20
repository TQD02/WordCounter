#pragma once
#ifndef MyString_H
#define MyString_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class MyString 
{
private:
    string str;
    int frequency;
public:
    MyString();
    MyString(string s);
    bool operator==(const MyString& rhs) const;
    bool operator>(const MyString& s) const;
    bool operator<(const MyString& s) const;
    MyString operator++(int);
    string getStr() const;
    friend ofstream& operator<<(ofstream& o, const MyString& obj);
};
ofstream& operator<<(ofstream& o, const MyString& obj);
