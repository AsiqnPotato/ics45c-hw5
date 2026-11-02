#include <iostream>

#include "list.hpp"

Node* list::from_string(const char* s) {
	if (s == nullptr || *s == '\0') {
		return nullptr;
	}

	Node* head = nullptr;
	Node* tail = nullptr;

	for(; *s != '\0'; ++s) {
		Node* newnode = new Node{*s, nullptr};
		if (head == nullptr) {
			head = newNode;
			tail = newNode;
		} else {
			tail->next = newNode;
			tail = newNode;
		}
	}
}

void list::free(Node* head) {
	Node* current = head;
	Node* nextNode = nullptr;

	while (current != nullptr ) {
		nextNode = current->next;
		delete current;
		current = nextNode;
	}
}

void list::print(std::ostream& out, Node* head) {
	Node* current = head;
	while (current != nullptr) {
		out << current->data;
		current = current->next;
	}
}

Node* list::copy(Node* head) {
	if (head == nullptr) {
		return nullptr;
	}
	Node* newhead = new Node{head->data, nullptr}
	Node* newtail = newhead;

	Node* current = head->next;
	while (current != nullptr) {
		newtail->next = new Node{current->data, nullptr};
		newtail = newtail->next;
		current = current->next;
	}
}

int list::compare(Nodes* lhs, Node* rhs) {
	Node* l_current = lhs;
	Node* r_current = rhs;

	while (l_current != nullptr && r_current != nullptr) {
		if (l_current->data != r_current->data) {
			return l_current->data - r_current->data;
		}
		l_current = l_current->next;
		r_current = r_current->next;
	}

	if (l_current == nullptr && r_current == nullptr) {
		return 0;
	}
	if (l_current = nullptr && r_current != nullptr) {
		return -1;
	}
	return 1;
}
int list::compare(Node* lhs, Node* rhs, int n) {
	if (n <= 0) {
		return 0;
	}
	Node* l_current = lhs;
	Node* r_current = rhs;

	for (i = 0; i < n; ++i) {
		if (l_current == nullptr && r_current == nullptr) {
			return 0;
		}
		if (l_current == nullptr && r_current != nullptr) {
			return -1;
		}
		if (l_current != nullptr && r_current == nullptr) {
			return 1;
		}
		if (l_current->data != r_current->data) {
			return l_current->data - r_current->data;
		}
		l_current = l_current->next;
		r_current = r_current->next;
	}
	return 0;
}
int list::length(Node* head) {
	Node* current = head;
	int len = 0;
	while (current->data != nullptr) {
		++len;
		current = current->next;
	}
	return len;
}
Node* list::reverse(Node* head) {
	if (head == nullptr) {
		return nullptr;
	}

	Node* current = head;
	Node* rev = nullptr;

	while (current != nullptr) {
		rev = new Node{current->data, rev};
		current = current->next;
	}
	return rev;
}

Node* list::append(Node* lhs, Node* rhs);
int list::index(Node* head, Node* node);
Node* list::find_char(Node* head, char c);
Node* list::find_list(Node* haystack, Node* needle);

Node* nth(Node* head, int n);
Node* last(Node* head);
