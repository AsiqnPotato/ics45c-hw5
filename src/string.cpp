#include <iostream>

#include "string.hpp"
#include "list.hpp"

String::String(const char *s) {
	head = list::from_string(s);
}
String::String(const String &s) {
	head = list::copy(s.head);
}
// String::String(String &&s);
void String:swap(String &s) {
	list::Node *temp = head;
	head = s.head;
	s.head = temp;
}
String &String::operator=(const String &s) {
	if (this == &s) {
		return *this;
	}
	list::free(head);
	head = list::copy(s.head);
	return *this;
}
// String &String::operator=(String &&s);

bool String::in_bounds(int index) const {
	return (index >= 0 && index <= list::length(head));
}
char String::operator[](int index) const {
	if head != nullptr{
		return list::nth(head, index)->data;
	}
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
int String::indexOf(const String &s) const {
	return list::find_list(head, s.head);
}

bool String::operator==(const String &s) const {
	return list::compare(head, s.head) == 0;
}
std::strong_ordering String::operator<=>(const String &s) const {
	return list::compare(head, s.head) <=> 0;
}
String String::operator+(const String &s) const {
	return String(list::append(head, s.head);
}
String &String::operator+=(const String &s) {
	if (head == nullptr) {
		return *this;
	}
	list::Node *tail = list::last(head);
	tail->next = list::copy(s.head);
}

void String::print(std::ostream&out) const {
	list::print(out, head);
}
void String::read(std::istream &in) {
	char buf[1024];
	if (in >> buf) {
		list::free(head);
		head = list::from_string(buf);
	}
}

// ~String::String();

std::ostream &operator<<(std::ostream &out, const String &s) {
	s.print(out);
	return out;
}
std::istream &operator>>(std::istream&in, String &s);
	s.read(in);
	return in;
}
