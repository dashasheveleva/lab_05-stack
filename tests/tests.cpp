// Copyright 2022 Shevelyova Darya photodoshfy@gmail.com

#include <stdexcept>
#include <string>
#include <gtest/gtest.h>
#include "Stack_task_1.hpp"
#include "Stack_task_2.hpp"

TEST(Stack_1, PushTest) {
  Stack_1<int> stack;
  EXPECT_EQ(stack.stack_size(), 0);
  stack.push(19);
  EXPECT_EQ(stack.stack_size(), 1);
  EXPECT_EQ(stack.head(), 19);
  stack.push(20);
  EXPECT_EQ(stack.stack_size(), 2);
  EXPECT_EQ(stack.head(), 20);
}

TEST(Stack_1, PopTest) {
  Stack_1<int> stack;
  EXPECT_EQ(stack.stack_size(), 0);
  EXPECT_ANY_THROW(stack.head());
  stack.push(19);
  stack.push(20);
  stack.pop();
  EXPECT_EQ(stack.stack_size(), 1);
  EXPECT_EQ(stack.head(), 19);
  stack.pop();
  EXPECT_EQ(stack.stack_size(), 0);
  EXPECT_ANY_THROW(stack.head());
}

TEST(Stack_1, HeadTest) {
  Stack_1<int> stack;
  EXPECT_EQ(stack.stack_size(), 0);
  EXPECT_ANY_THROW(stack.head());
  stack.push(19);
  EXPECT_EQ(stack.stack_size(), 1);
  EXPECT_EQ(stack.head(), 19);
  stack.push(20);
  EXPECT_EQ(stack.stack_size(), 2);
  EXPECT_EQ(stack.head(), 20);
  stack.pop();
  EXPECT_EQ(stack.stack_size(), 1);
  EXPECT_EQ(stack.head(), 19);
  stack.pop();
  EXPECT_EQ(stack.stack_size(), 0);
  EXPECT_ANY_THROW(stack.head());
}

TEST(Stack_1, MoveTest) {
  EXPECT_TRUE(std::is_move_constructible<Stack_1<int>>::value);
  EXPECT_TRUE(std::is_move_constructible<Stack_1<std::string>>::value);
  EXPECT_TRUE(std::is_move_assignable<Stack_1<int>>::value);
  EXPECT_TRUE(std::is_move_assignable<Stack_1<std::string>>::value);
}

TEST(Stack_1, CopyTest) {
  EXPECT_FALSE(std::is_copy_constructible<Stack_1<int>>::value);
  EXPECT_FALSE(std::is_copy_constructible<Stack_1<std::string>>::value);
  EXPECT_FALSE(std::is_copy_assignable<Stack_1<int>>::value);
  EXPECT_FALSE(std::is_copy_assignable<Stack_1<std::string>>::value);
}

class StackData {
 public:
  int num;
  std::string data;
  StackData() = default;
  StackData(int n, std::string d) : num(n), data(d) {}
  StackData(const StackData& value) = delete;
  StackData(StackData&& value) noexcept = default;
  auto operator=(const StackData& value) -> StackData& = delete;
  auto operator=(StackData&& value) noexcept -> StackData& = default;
};

TEST(Stack_2, CorrectClassTest) {
  EXPECT_TRUE(std::is_move_constructible<StackData>::value);
  EXPECT_TRUE(std::is_move_assignable<StackData>::value);
  EXPECT_FALSE(std::is_copy_constructible<StackData>::value);
  EXPECT_FALSE(std::is_copy_assignable<StackData>::value);
}

TEST(Stack_2, PushTest) {
  Stack_2<StackData> stack;
  EXPECT_EQ(stack.stack_size(), 0);
  EXPECT_ANY_THROW(stack.head());
  StackData elem(1, "dasha");
  stack.push(std::move(elem));
  EXPECT_EQ(stack.head().num, 1);
  EXPECT_EQ(stack.head().data, "dasha");
  EXPECT_EQ(stack.stack_size(), 1);
}

TEST(Stack_2, PushEmplanceTest) {
  Stack_2<StackData> stack;
  EXPECT_EQ(stack.stack_size(), 0);
  EXPECT_ANY_THROW(stack.head());
  stack.push_emplace(12345, "Dasha");
  EXPECT_EQ(stack.head().num, 12345);
  EXPECT_EQ(stack.head().data, "Dasha");
  EXPECT_EQ(stack.stack_size(), 1);
  stack.push_emplace(54321, "ashaD");
  EXPECT_EQ(stack.head().num, 54321);
  EXPECT_EQ(stack.head().data, "ashaD");
  EXPECT_EQ(stack.stack_size(), 2);
}

TEST(Stack_2, PopTest) {
  Stack_2<StackData> stack;
  EXPECT_EQ(stack.stack_size(), 0);
  EXPECT_ANY_THROW(stack.head());
  StackData elem(1, "dasha");
  stack.push(std::move(elem));
  EXPECT_EQ(stack.stack_size(), 1);
  EXPECT_EQ(stack.head().num, 1);
  EXPECT_EQ(stack.head().data, "dasha");
  stack.pop();
  EXPECT_EQ(stack.stack_size(), 0);
  EXPECT_ANY_THROW(stack.head());
}

TEST(Stack_2, HeadTest) {
  Stack_2<StackData> stack;
  EXPECT_EQ(stack.stack_size(), 0);
  EXPECT_ANY_THROW(stack.head());
  StackData elem(1, "dasha");
  stack.push(std::move(elem));
  EXPECT_EQ(stack.head().num, 1);
  EXPECT_EQ(stack.head().data, "dasha");
  stack.pop();
  EXPECT_ANY_THROW(stack.head());
}

TEST(Stack_2, MoveTest) {
  EXPECT_TRUE(std::is_move_constructible<Stack_2<int>>::value);
  EXPECT_TRUE(std::is_move_constructible<Stack_2<std::string>>::value);
  EXPECT_TRUE(std::is_move_assignable<Stack_2<int>>::value);
  EXPECT_TRUE(std::is_move_assignable<Stack_2<std::string>>::value);
}

TEST(Stack_2, CopyTest) {
  EXPECT_FALSE(std::is_copy_constructible<Stack_2<int>>::value);
  EXPECT_FALSE(std::is_copy_constructible<Stack_2<std::string>>::value);
  EXPECT_FALSE(std::is_copy_assignable<Stack_2<int>>::value);
  EXPECT_FALSE(std::is_copy_assignable<Stack_2<std::string>>::value);
}