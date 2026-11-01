#include <iostream>

#include "list.hpp"

Node* list::from_string(const char* s);
void list::free(Node* head);
void list::print(std::ostream& out, Node* head);
Node* list::copy(Node* head);

int list::compare(Nodes* lhs, Node* rhs, int n);
int list::compare(Node* lhs, Node* rhs, int n);
int list::length(Node* head);
Node* list::reverse(Node* head);

Node* list::append(Node* lhs, Node* rhs);
int list::index(Node* head, Node* node);
Node* list::find_char(Node* head, char c);
Node* list::find_list(Node* haystack, Node* needle);

Node* nth(Node* head, int n);
Node* last(Node* head);
