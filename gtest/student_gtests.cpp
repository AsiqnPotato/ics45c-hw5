#include <gtest/gtest.h>

#include "list.hpp"

using namespace std;
using list::Node;

TEST(ListTests, FromStringBasic) {
    Node* const foo_list_head = list::from_string("foo");
    Node* foo_list = foo_list_head;

    EXPECT_EQ(foo_list->data, 'f');
    // ASSERT instead of EXPECT means: end the test here if this fails, do not try to continue
    // running. This is useful to prevent early crashes.
    ASSERT_NE(foo_list->next, nullptr);

    foo_list = foo_list->next;
    EXPECT_EQ(foo_list->data, 'o');
    ASSERT_NE(foo_list->next, nullptr);

    foo_list = foo_list->next;
    EXPECT_EQ(foo_list->data, 'o');
    ASSERT_EQ(foo_list->next, nullptr);

    list::free(foo_list_head);
}

TEST(ListTests, Length) {
    Node* const head = list::from_string("foo");
    EXPECT_EQ(list::length(head), 3);
    list::free(head);

	Node* one = list::from_string("e");
	EXPECT_EQ(list::length(one), 1);
	list::free(one);

	EXPECT_EQ(list::length(nullptr), 0);
	list::free(nullptr);
}

// Add remaining tests below. All tests should follow
// the format of `TEST(ListTests, <TestName>){}`.

TEST(ListTests, ReplaceMe) {
    Node* const head = list::from_string("test");
	ASSERT_NE(head, nullptr);
	EXPECT_EQ(head->data, 't');

	Node* last_node = list::last(head);
	EXPECT_EQ(last_node->data, 't');
	EXPECT_EQ(last_node->next, nullptr);

	list::free(head);
}

TEST(ListTests, Print) {
	list::print(std::cout, nullptr);

	Node* head = list::from_string("hello");

	std::cout << "Printing: ";
	list::print(std::cout, head);
	std::cout << std::endl;

	list::free(head);
}

TEST(ListTests, Copy) {
	EXPECT_EQ(list::copy(nullptr), nullptr);

	Node* original = list::from_string("test");
	Node* copy_head = list::copy(original);

	ASSERT_NE(copy_head, nullptr);
	EXPECT_NE(copy_head, original);
	EXPECT_NE(copy_head->next, original->next);

	Node* origcurr = original;
	Node* copycurr = copy_head;
	while (origcurr != nullptr && copycurr != nullptr) {
		EXPECT_EQ(origcurr->data, copycurr->data);
		origcurr = origcurr->next;
		copycurr = copycurr->next;
	}
	EXPECT_EQ(origcurr, nullptr);
	EXPECT_EQ(copycurr, nullptr);
	list::free(original);
	list::free(copy_head);
}
