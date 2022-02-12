// Copyright 2022 Shevelyova Darya photodoshfy@gmail.com

#include <stdexcept>
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
  EXPECT_ANY_THROW(stack.pop());
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