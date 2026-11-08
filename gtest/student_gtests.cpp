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

TEST(ListTests, Compare) {
	Node* one = list::from_string("abc");
	Node* two = list::from_string("abc");
	Node* three = list::from_string("abd");
	Node* four = list::from_string("ab");

	EXPECT_EQ(list::compare(one, two), 0);
	EXPECT_LT(list::compare(one, three), 0);
	EXPECT_GT(list::compare(one, four), 0);
	EXPECT_LT(list::compare(four, one), 0);
	EXPECT_GT(list::compare(three, one), 0);

	EXPECT_EQ(list::compare(nullptr, nullptr), 0);
	EXPECT_LT(list::compare(nullptr, one), 0);
	EXPECT_GT(list::compare(one, nullptr), 0);

	list::free(one);
	list::free(two);
	list::free(three);
	list::free(four);
}

TEST(ListTests, CompareEdgeCases) {
	Node* one = list::from_string("abc");
	Node* two = list::from_string("abcdef");

	EXPECT_LT(list::compare(one, two), 0);
	EXPECT_GT(list::compare(two, one), 0);
	EXPECT_EQ(list::compare(one, one, 5), 0);
	EXPECT_EQ(list::compare(one, two, 3), 0);

	list::free(one);
	list::free(two);
}

TEST(ListTests, CompareN) {
	Node* one = list::from_string("apple");
	Node* two = list::from_string("application");

	EXPECT_EQ(list::compare(one, two, 0), 0);
	EXPECT_EQ(list::compare(one, two, 3), 0);
	EXPECT_LT(list::compare(one, two, 5), 0);

	list::free(one);
	list::free(two);
}

TEST(ListTests, Reverse) {
	EXPECT_EQ(list::reverse(nullptr), nullptr);

	Node* one = list::from_string("a");
	Node* rev_one = list::reverse(one);

	ASSERT_NE(rev_one, nullptr);
	EXPECT_EQ(rev_one->data, 'a');
	EXPECT_EQ(rev_one->next, nullptr);
	list::free(one);
	list::free(rev_one);

	Node* multi = list::from_string("abc");
	Node* rev_multi = list::reverse(multi);

	ASSERT_NE(rev_multi, nullptr);
	EXPECT_EQ(rev_multi->data, 'c');
	ASSERT_NE(rev_multi->next, nullptr);
	EXPECT_EQ(rev_multi->next->data, 'b');
	list::free(multi);
	list::free(rev_multi);
}

TEST(ListTests, Append) {
	Node* one = list::from_string("hi ");
	Node* two = list::from_string("there");

	Node* combined = list::append(one, two);
	ASSERT_NE(combined, nullptr);

	Node* current = combined;
	Node* orig_curr = one;
	while (orig_curr != nullptr) {
		ASSERT_NE(current, nullptr);
		ASSERT_NE(current, orig_curr);
		EXPECT_EQ(current->data, orig_curr->data);
		current = current->next;
		orig_curr = orig_curr->next;
	}

	orig_curr = two;
	while (orig_curr != nullptr) {
		ASSERT_NE(current, nullptr);
		ASSERT_NE(current, orig_curr);
		EXPECT_EQ(current->data, orig_curr->data);
		current = current->next;
		orig_curr = orig_curr->next;
	}
	EXPECT_EQ(current, nullptr);
	
	list::free(one);
	list::free(two);
	list::free(combined);

	Node* test = list::from_string("test");
	Node* res1 = list::append(nullptr, test);
	ASSERT_NE(res1, nullptr);
	EXPECT_EQ(res1->data, 't');

	Node* res2 = list::append(test, nullptr);
	ASSERT_NE(res2, nullptr);
	EXPECT_EQ(res2->data, 't');

	Node* res3 = list::append(nullptr, nullptr);
	EXPECT_EQ(res3, nullptr);

	list::free(test);
	list::free(res1);
	list::free(res2);
}

TEST(ListTests, Index) {
	Node* head = list::from_string("abcde");
	Node* two = head->next;
	Node* three = head->next->next;
	Node* four = head->next->next->next;
	Node* five = head->next->next->next->next;

	EXPECT_EQ(list::index(head, head), 0);
	EXPECT_EQ(list::index(head, two), 1);
	EXPECT_EQ(list::index(head, three), 2);
	EXPECT_EQ(list::index(head, four), 3);
	EXPECT_EQ(list::index(head, five), 4);
	EXPECT_EQ(list::index(head, nullptr), -1);

	Node* single = list::from_string("x");
	EXPECT_EQ(list::index(single, single), 0);

	list::free(head);
	list::free(single);
}

TEST(ListTests, Find) {
	Node* head = list::from_string("banana");

	Node* found = list::find_char(head, 'n');
	ASSERT_NE(found, nullptr);
	EXPECT_EQ(found->data, 'n');
	EXPECT_EQ(list::index(head, found), 2);
	EXPECT_EQ(list::find_char(head, 'z'), nullptr);
	EXPECT_EQ(list::find_char(nullptr, 'a'), nullptr);

	list::free(head);

	Node* haystack = list::from_string("alakazam");
	Node* needle = list::from_string("alak");
	Node* empty = nullptr;

	Node* result = list::find_list(haystack, needle);
	ASSERT_NE(result, nullptr);
	EXPECT_EQ(list::index(haystack, result), 0);
	EXPECT_EQ(list::find_list(haystack, empty), haystack);
	EXPECT_EQ(list::find_list(nullptr, needle), nullptr);

	list::free(haystack);
	list::free(needle);

	Node* hay2 = list::from_string("kaxabra");
	Node* needle2 = list::from_string("abra");
	Node* result2 = list::find_list(hay2, needle2);
	ASSERT_NE(result2, nullptr);
	EXPECT_EQ(list::index(hay2, result2), 3);

	list::free(hay2);
	list::free(needle2);

	Node* hay3 = list::from_string("abacaba");
	Node* needle3 = list::from_string("aba");
	Node* result3 = list::find_list(hay3, needle3);
	ASSERT_NE(result3, nullptr);
	EXPECT_EQ(list::index(hay3, result3), 0);

	Node* needle_long = list::from_string("abacabae");
	EXPECT_EQ(list::find_list(hay3, needle_long), nullptr);

	list::free(hay3);
	list::free(needle3);
	list::free(needle_long);
}

TEST(ListTests, Nth) {
	Node* head = list::from_string("xyz");

	EXPECT_EQ(list::nth(head, 0)->data, 'x');
	EXPECT_EQ(list::nth(head, 1)->data, 'y');
	EXPECT_EQ(list::nth(head, 2)->data, 'z');
	EXPECT_EQ(list::nth(head, 3), nullptr);

	list::free(head);
}

TEST(ListTests, Last) {
	Node* one = list::from_string("a");
	EXPECT_EQ(list::last(one), one);

	Node* multi = list::from_string("hello");
	Node* last_node = list::last(multi);
	ASSERT_NE(last_node, nullptr);
	EXPECT_EQ(last_node->data, 'o');
	EXPECT_EQ(last_node->next, nullptr);

	Node* two = list::from_string("xy");
	Node* last_two = list::last(two);
	ASSERT_NE(last_two, nullptr);
	EXPECT_EQ(last_two->data, 'y');

	list::free(one);
	list::free(multi);
	list::free(two);
}

TEST(ListTests, IndexRepeating) {
	Node* head = list::from_string("aabaa");
	Node* first = head;
	Node* second = head->next;
	Node* third = head->next->next->next;
	Node* fourth = head->next->next->next->next;

	EXPECT_EQ(list::index(head, first), 0);
	EXPECT_EQ(list::index(head, second), 1);
	EXPECT_EQ(list::index(head, third), 3);
	EXPECT_EQ(list::index(head, fourth), 4);

	list::free(head);
}

TEST(ListTests, FindListOverlapping) {
	Node* haystack = list::from_string("aaaa");
	Node* needle = list::from_string("aa");

	Node* result = list::find_list(haystack, needle);
	ASSERT_NE(result, nullptr);
	EXPECT_EQ(list::index(haystack,result), 0);

	Node* long_needle = list::from_string("aaaaa");
	EXPECT_EQ(list::find_list(haystack, long_needle), nullptr);

	list::free(haystack);
	list::free(needle);
	list::free(long_needle);
}

TEST(ListTests, FindListSpecific) {
	Node* haystack = list::from_string("mississippi");
	Node* needle1 = list::from_string("iss");
	Node* needle2 = list::from_string("sip");

	Node* res1 = list::find_list(haystack, needle1);
	ASSERT_NE(res1, nullptr);
	EXPECT_EQ(list::index(haystack, res1), 1);

	Node* res2 = list::find_list(haystack, needle2);
	ASSERT_NE(res2, nullptr);
	EXPECT_EQ(list::index(haystack, res2), 6);

	list::free(haystack);
	list::free(needle1);
	list::free(needle2);
}
