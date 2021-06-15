#include <iostream>
#include <sstream>
#include <string.h>
#include "String.h"
using namespace std;

// 1.
String::String() : capacity_(1), size_(0), str_(new char('\0')) {}

// 2.
String::String(char const in[]) : capacity_(1), size_(strlen(in))
{
    while (capacity_ <= size_)
    {
        capacity_ *= 2;
    }
    str_ = new char[capacity_];
    strcpy(str_, in);
}

// 3.
String::String(const String &in) : capacity_(in.capacity_), size_(in.size_), str_(new char[in.capacity_])
{
    strcpy(str_, in.str_);
}

// 4.
String::~String()
{
    delete[] str_;
}

// 5.
size_t String::size() const
{
    return size_;
}

// 6.
const char *String::c_str() const
{
    return str_;
}

// 7.
char &String::operator[](int in)
{
    return str_[in];
}

const char &String::operator[](int in) const
{
    return str_[in];
}

// 8.
String &String::operator+=(String const &rhs)
{
    int tmpsize = size_;
    size_ += rhs.size_;
    if (capacity_ <= size_)
    {
        while (capacity_ <= size_)
        {
            capacity_ *= 2;
        }
        char *tmp = str_;
        str_ = new char[capacity_];
        strcpy(str_, tmp);
        delete tmp;
    }
    strcat(str_, rhs.str_);
    return *this;
}
String &String::operator+=(char const &rhs)
{
    char tmpchar[] = {rhs, '\0'};
    String tmp(tmpchar);
    return *this += tmp;
}

// 9.
void String::clear()
{
    str_[0] = '\0';
    size_ = 0;
}

// 10.
String &String::operator=(String rhs)
{
    this->swap(rhs);
    return *this;
}

// 11.
void String::swap(String &rhs)
{
    std::swap(capacity_, rhs.capacity_);
    std::swap(size_, rhs.size_);
    std::swap(str_, rhs.str_);
}

//

// A. relational operators (<, >, <=, >=, ==, !=)
bool operator<(const String &lhs, const String &rhs)
{
    return strcmp(lhs.c_str(), rhs.c_str()) < 0;
}
bool operator>(const String &lhs, const String &rhs)
{
    return !(lhs < rhs) && !(lhs == rhs);
}
bool operator<=(const String &lhs, const String &rhs)
{
    return (lhs < rhs) || (rhs == lhs);
}
bool operator>=(const String &lhs, const String &rhs)
{
    return !(lhs < rhs);
}
bool operator==(const String &lhs, const String &rhs)
{
    return strcmp(lhs.c_str(), rhs.c_str()) == 0;
}
bool operator!=(const String &lhs, const String &rhs)
{
    return !(lhs == rhs);
}

// B. operator <<, >>
ostream &operator<<(ostream &os, const String &out)
{
    os << out.c_str();
    return os;
}
istream &operator>>(istream &is, String &in)
{
    char tmp;
    in.clear();
    while (is.get(tmp) && isgraph(tmp))
    {
        in += tmp;
    }
    return is;
}

// C. operators +
const String operator+(const String &lhs, const String &rhs)
{
    String tmp(lhs);
    tmp += rhs;
    return tmp;
}