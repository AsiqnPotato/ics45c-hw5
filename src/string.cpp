#include <iostream>

#include "string.hpp"
#include "list.hpp"

String::String(const char *s);
String::String(const String &s);
// String::String(String &&s);
void String:swap(String &s);
String &String::operator=(const String &s);
// String &String::operator=(String &&s);

bool String::in_bounds(int index) const {
	return (index >= 0 && index <= list::length(head));
}
char String::operator[](int index) const {
	return list::nth(head, index)->data;
}
int String::size() const {
	return list::length(head);
}
String String::reverse() const {
	return list::reverse(head);
}
int String::indexOf(char c) const {
	return list::find_char(head, c);
}
int String::indexOf(const String &s) const;

bool String::operator==(const String &s) const {
	return list::compare(head, s.head) == 0;
}
std::strong_ordering String::operator<=>(const String &s) const {
	return list::compare(head, s.head) <=> 0;
}
String String::operator+(const String &s) const;
String &String::operator+=(const String &s);

void String::print(std::ostream&out) const {
	list::print(out, head);
}
void String::read(std::istream &in);

// ~String::String();

std::ostream &opreator<<(std::ostream &out, const String &s);
std::istream &operator>>(std::istream&in, String &s);
