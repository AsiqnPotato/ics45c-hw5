#include <iostream>

#include "string.hpp"

String::String(const char *s);
String::String(const String &s);
// String::String(String &&s);
void String:swap(String &s);
String &String::operator=(const String &s);
// String &String::operator=(String &&s);

bool String::in_bounds(int index) const;
char String::operator[](int index) const;
int String::size() const;
String String::reverse() const;
int String::indexOf(char c) const;
int String::indexOf(const String &s) const;
int String::indexOf(const String &s) const;

bool String::operator==(const String &s) const;
std::strong_ordering String::operator<=>(const String &s) const;
String String::operator+(const String &s) const;
String &String::operator+=(const String &s);

void String::print(std::ostream&out) const;
void String::read(std::istream &in);

// ~String::String();

std::ostream &opreator<<(std::ostream &out, const String &s);
std::istream &operator>>(std::istream&in, String &s);
