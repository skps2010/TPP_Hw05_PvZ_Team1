#ifndef String__
#define String__
#include <iostream>

class String
{
public:
    // 1. default constructor
    String();

    // 2. copy constructor
    String(const String &in);

    // 3. constructor with one parameter with type const char *
    String(const char in[]);

    // 4. destructor
    ~String();

    // 5. size()
    size_t size() const;

    // 6. c_str()
    const char *c_str() const;

    // 7. operator []
    char &operator[](int in);
    const char &operator[](int in) const;

    // 8. operator +=
    String &operator+=(const String &rhs);
    String &operator+=(const char &rhs);

    // 9. clear()
    void clear();

    // 10. operator =
    String &operator=(String rhs);

    // 11. swap()
    void swap(String &rhs);

private:
    char *str_ = nullptr;
    size_t size_ = 0, capacity_ = 0;
};

// A. relational operators (<, >, <=, >=, ==, !=)
bool operator<(const String &lhs, const String &rhs);
bool operator>(const String &lhs, const String &rhs);
bool operator<=(const String &lhs, const String &rhs);
bool operator>=(const String &lhs, const String &rhs);
bool operator==(const String &lhs, const String &rhs);
bool operator!=(const String &lhs, const String &rhs);

// B. operator <<, >>
std::ostream &operator<<(std::ostream &os, const String &out);
std::istream &operator>>(std::istream &is, String &in);

// C. operators+
const String operator+(const String &lhs, const String &rhs);

#endif

//cool