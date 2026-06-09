#include "../header/List.h"
#include <gtest/gtest.h>

TEST(ListTests, CreateEmptyList)
{
	const List list;

	EXPECT_TRUE(list.IsEmpty());
	EXPECT_EQ(list.GetSize(), 0);
	EXPECT_EQ(list.ToString(), "{}");
}

TEST(ListTests, CreateListWithValues)
{
	const List list = { 1, 2, 3 };

	EXPECT_FALSE(list.IsEmpty());
	EXPECT_EQ(list.GetSize(), 3);
	EXPECT_EQ(list.ToString(), "{1, 2, 3}");
}

TEST(ListTests, PushFront)
{
	List list = { 2, 3 };

	list.PushFront(1);

	EXPECT_EQ(list.ToString(), "{1, 2, 3}");
}

TEST(ListTests, PushBack)
{
	List list = { 1, 2 };

	list.PushBack(3);

	EXPECT_EQ(list.ToString(), "{1, 2, 3}");
}

TEST(ListTests, Insert)
{
	List list = { 1, 3 };

	list.Insert(1, 2);

	EXPECT_EQ(list.ToString(), "{1, 2, 3}");
}

TEST(ListTests, Remove)
{
	List list = { 1, 2, 3 };

	EXPECT_TRUE(list.Remove(2));
	EXPECT_EQ(list.ToString(), "{1, 3}");
}

TEST(ListTests, Contains)
{
	const List list = { 1, 2, 3 };

	EXPECT_TRUE(list.Contains(2));
	EXPECT_FALSE(list.Contains(10));
}

TEST(ListTests, Change)
{
	List list = { 1, 2, 3 };

	EXPECT_TRUE(list.Change(2, 20));
	EXPECT_EQ(list.ToString(), "{1, 20, 3}");
}

TEST(ListTests, GetValue)
{
	const List list = { 5, 10, 15 };

	EXPECT_EQ(list.GetValue(0), 5);
	EXPECT_EQ(list.GetValue(1), 10);
	EXPECT_EQ(list.GetValue(2), 15);
}

TEST(ListTests, PopFront)
{
	List list = { 1, 2, 3 };

	int value = list.PopFront();

	EXPECT_EQ(value, 1);
	EXPECT_EQ(list.ToString(), "{2, 3}");
}

TEST(ListTests, Operators)
{
	List list = { 1, 2 };
	int value = 0;

	list << 3;
	list >> value;

	EXPECT_EQ(value, 1);
	EXPECT_EQ(list.ToString(), "{2, 3}");
}

TEST(ListTests, CopyList)
{
	List list = { 1, 2, 3 };
	List copy = list;

	copy.Change(2, 20);

	EXPECT_EQ(list.ToString(), "{1, 2, 3}");
	EXPECT_EQ(copy.ToString(), "{1, 20, 3}");
}

TEST(ListTests, Clear)
{
	List list = { 1, 2, 3 };

	list.Clear();

	EXPECT_TRUE(list.IsEmpty());
	EXPECT_EQ(list.ToString(), "{}");
}
