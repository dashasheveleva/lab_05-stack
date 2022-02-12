// Copyright 2022 Shevelyova Darya photodoshfy@gmail.com

#ifndef INCLUDE_STACK_TASK_2_HPP_
#define INCLUDE_STACK_TASK_2_HPP_

#include <iostream>
#include <string>
#include <utility>

template <typename T>
struct Node2 {
  T value; // значение
  Node2<T>* prev; // указатель на следующий элемент стека
};

class Args;
template <typename T>
class Stack_2 {
 protected:
  Node2<T>* head_node = nullptr; //
 public:
  Stack_2() = default;
  Stack_2(const Stack_2 &stack) = delete; // некопируемый стек
  Stack_2(Stack_2&& stack) noexcept = default; //
  ~Stack_2();
  auto operator=(const Stack_2&) -> Stack_2& = delete; // некопируемый стек
  auto operator=(Stack_2&& stack) noexcept ->class Stack_2& = default;

  template <typename ... Args>
  void push_emplace(Args&&... value);
  void push(T&& value);
  const T& head() const;
  T pop();

  size_t stack_size() const;
};

template <typename T>
Stack_2<T>::~Stack_2() {
  while (head_node != nullptr) {
    Node2<T>* current_node = head_node;
    head_node = head_node->prev;
    delete current_node;
  }
}

template <typename T>
template <typename... Args>
void Stack_2<T>::push_emplace(Args&&... value) {
  if ((std::is_copy_constructible<T>::value) ||
      (std::is_copy_assignable<T>::value)) {
    throw std::exception();
  }
  Stack_2<T>::head_node =
      new Node2<T>{{std::forward<Args>(value)...}, Stack_2<T>::head_node};
}
template <typename T>
void Stack_2<T>::push(T&& value) {
  if ((std::is_copy_constructible<T>::value) ||
      (std::is_copy_assignable<T>::value)) {
    throw std::exception();
  }

  Stack_2<T>::head_node =
      new Node2<T>{std::forward<T>(value), Stack_2<T>::head_node};
}
template <typename T>
const T& Stack_2<T>::head() const {
  if (Stack_2<T>::head_node == nullptr) {
    throw std::exception();
  }
  return Stack_2<T>::head_node->value;
}
template <typename T>
T Stack_2<T>::pop() {
  if (Stack_2<T>::head_node == nullptr) {
    throw std::exception();
  }
  auto* current_node = Stack_2<T>::head_node;
  T value = std::move(Stack_2<T>::head_node->value);
  Stack_2<T>::head_node = Stack_2<T>::head_node->prev;
  delete current_node;
  return value;
}

template <typename T>
size_t Stack_2<T>::stack_size() const {
  size_t stack_size = 0;
  Node2<T>* current_node = head_node;
  while (current_node != nullptr) {
    stack_size++;
    current_node = current_node->prev;
  }
  return stack_size;
}


#endif // INCLUDE_STACK_TASK_2_HPP_
