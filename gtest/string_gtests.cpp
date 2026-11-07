#include <gtest/gtest.h>

#include <algorithm>
#include <sstream>

#include "string.hpp"

using namespace std;

TEST(StringClass, Constructors) {
    String s("hello");
    EXPECT_EQ(s.size(), 5);

    String t(s);
    EXPECT_EQ(t.size(), 5);
    EXPECT_EQ(s.size(), 5);
}

TEST(StringClass, Print) {
    String s("foo");
    stringstream out;
    s.print(out);
    EXPECT_STREQ(out.str().c_str(), "foo");

    stringstream out2;
    String().print(out2);
    EXPECT_STREQ(out2.str().c_str(), "");

    stringstream out3;
    out3 << s << s << String("bar");
    EXPECT_STREQ(out3.str().c_str(), "foofoobar");
}

TEST(StringClass, Comparisons) {
    EXPECT_LT(String("aaaa"), String("aaab"));
    EXPECT_LE(String("aaaa"), String("aaab"));
    EXPECT_EQ(String("foo"), String("foo"));
    EXPECT_NE(String("foo"), String("fooo"));
}

TEST(StringClass, Assignment) {
    String s("test"), t("foo");

    s = t;
    EXPECT_EQ(s.size(), t.size());
    EXPECT_EQ(s, t);

    s = s;
    EXPECT_EQ(s.size(), t.size());
    EXPECT_EQ(s, t);

    s = String();
    EXPECT_EQ(s, String());
    EXPECT_EQ(s.size(), 0);
}

TEST(StringClass, Indexing) {
	String s("carols");
	EXPECT_TRUE(s.in_bounds(0));
	EXPECT_TRUE(s.in_bounds(5));
	EXPECT_FALSE(s.in_bounds(-1));
	EXPECT_FALSE(s.in_bounds(6));

	EXPECT_EQ(s[0], 'c');
	EXPECT_EQ(s[5], 's');

	EXPECT_EQ(s.indexOf('c'), 0);
	EXPECT_EQ(s.indexOf('r'), 2);
	EXPECT_EQ(s.indexOf('f'), -1);

	String empty;
	EXPECT_FALSE(empty.in_bounds(0));
}

TEST(StringClass, Reverse) {
	String s("hello");
	String rev = s.reverse();

	stringstream out_orig, out_rev;
	s.print(out_orig);
	rev.print(out_rev);

	EXPECT_STREQ(out_orig.str().c_str(), "hello");
	EXPECT_STREQ(out_rev.str().c_str(), "olleh");

	EXPECT_EQ(String().reverse(), String());
	EXPECT_EQ(String("a").reverse(), String("a"));
}

TEST(StringClass, Concat) {
	String s1("Hello");
	String s2(" World");
	String s3 = s1 + s2;

	EXPECT_EQ(s3, String("Hello World"));
	EXPECT_EQ(s1, String("Hello"));

	s1 += s2;
	EXPECT_EQ(s1, String("Hello World"));
	String empty;
	EXPECT_EQ(s1 + empty, s1);
	EXPECT_EQ(empty + s1, s1);
}

TEST(StringClass, StreamInput) {
	String s;
	stringstream in("apple banana");
    
	in >> s;
	EXPECT_EQ(s, String("apple"));
    
	in >> s;
	EXPECT_EQ(s, String("banana"));
}

TEST(StringClass, MoveConstruct) {
	String s1("hello");
	String s2(std::move(s1));
	
	EXPECT_EQ(s2.size(), 5);

	stringstream out;
	s2.print(out);
	EXPECT_STREQ(out.str().c_str(), "hello");
	EXPECT_EQ(s1.size(), 0);
}

TEST(StringClass, MoveAssign) {
	String s1("hello");
	String s2("world");

	s2 = std::move(s1);

	EXPECT_EQ(s2.size(), 5);
	stringstream out;
	s2.print(out);
	EXPECT_STREQ(out.str().c_str(), "hello");
	EXPECT_EQ(s1.size(), 0);

	s2 = std::move(s2);
	EXPECT_EQ(s2.size(), 5);
}
