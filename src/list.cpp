#include <iostream>

#include "list.hpp"

namespace list {
Node* from_string(const char* s) {
	if (s == nullptr || *s == '\0') {
		return nullptr;
	}

	Node* head = nullptr;
	Node* tail = nullptr;

	for(; *s != '\0'; ++s) {
		Node* newNode = new Node{*s, nullptr};
		if (head == nullptr) {
			head = newNode;
			tail = newNode;
		} else {
			tail->next = newNode;
			tail = newNode;
		}
	}
	return head;
}

void free(Node* head) {
	Node* current = head;
	Node* nextNode = nullptr;

	while (current != nullptr ) {
		nextNode = current->next;
		delete current;
		current = nextNode;
	}
}

void print(std::ostream& out, Node* head) {
	Node* current = head;
	while (current != nullptr) {
		out << current->data;
		current = current->next;
	}
}

Node* copy(Node* head) {
	if (head == nullptr) {
		return nullptr;
	}
	Node* newhead = new Node{head->data, nullptr};
	Node* newtail = newhead;

	Node* current = head->next;
	while (current != nullptr) {
		newtail->next = new Node{current->data, nullptr};
		newtail = newtail->next;
		current = current->next;
	}
	return newhead;
}

int compare(Node* lhs, Node* rhs) {
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
	if (l_current == nullptr && r_current != nullptr) {
		return -1;
	}
	return 1;
}

int compare(Node* lhs, Node* rhs, int n) {
	if (n <= 0) {
		return 0;
	}

	Node* l_current = lhs;
	Node* r_current = rhs;
	for(int i = 0; i < n; ++i) {
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
			return (l_current->data - r_current->data);
		}
		l_current = l_current->next;
		r_current = r_current->next;
	}
	return 0;
}

int length(Node* head) {
	Node* current = head;
	int len = 0;
	while (current != nullptr) {
		++len;
		current = current->next;
	}
	return len;
}

Node* reverse(Node* head) {
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

Node* append(Node* lhs, Node* rhs) {
	if (lhs == nullptr && rhs == nullptr) {
		return nullptr;
	}

	Node* newhead = nullptr;
	Node* newtail = nullptr;
	
	Node* current = lhs;
	while (current != nullptr) {
		Node* new_node = new Node{current->data, nullptr};
		if (newhead == nullptr) {
			newhead = new_node;
			newtail = new_node;
		} else {
			newtail->next = new_node;
			newtail = new_node;
		}
		current = current->next;
	}

	current = rhs;
	while (current != nullptr) {
		Node* new_node = new Node{current->data, nullptr};
		if (newhead == nullptr) {
			newhead = new_node;
			newtail = new_node;
		} else {
			newtail->next = new_node;
			newtail = new_node;
		}
	}
	return newhead;
}

int index(Node* head, Node* node) {
	Node* current = head;
	int idx = 0;
	while (current != nullptr) {
		if (current == node) {
			return idx;
		}
		current = current->next;
		++idx;
	}
	return -1;
}

Node* find_char(Node* head, char c) {
	Node* current = head;
	while (current != nullptr) {
		if (current->data == c) {
			return current;
		}
		current = current->next;
	}
	return nullptr;
}

Node* find_list(Node* haystack, Node* needle) {
	if (needle == nullptr) {
		return haystack;
	}
	if (haystack == nullptr) {
		return nullptr;
	}

	Node* current = haystack;
	while (current != nullptr) {
		if (current->data == needle->data) {
			return current;
		}
	current = current->next;
	}
	return nullptr;
}

Node* nth(Node* head, int n) {
	Node* current = head;
	for (int i = 0; i < n; ++i) {
		current = current->next;
	}
	return current;
}

Node* last(Node* head) {
	if (head == nullptr) {
		return nullptr;
	}

	Node* current = head;
	while (current->next != nullptr) {
		current = current->next;
	}
	return current;
}

}
