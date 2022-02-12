// Copyright 2022 Shevelyova Darya photodoshfy@gmail.com

#ifndef INCLUDE_STACK_TASK_1_HPP_
#define INCLUDE_STACK_TASK_1_HPP_

#include <iostream>
#include <type_traits>
#include <utility>

template <typename T>
struct Node1 {
  T value; // значение
  Node1<T>* prev; // указатель на следующий элемент стека
};

template <typename T>
class Stack_1 {
 protected:
  Node1<T>* head_node = nullptr; //
 public:
  Stack_1() = default;
  Stack_1(const Stack_1 &stack) = delete; // некопируемый стек
  Stack_1(Stack_1&& stack) noexcept = default; //
  ~Stack_1();
  auto operator=(const Stack_1&) -> Stack_1& = delete; // некопируемый стек
  auto operator=(Stack_1&& stack) noexcept ->class Stack_1& = default;

  void push(T&& value); //
  void push(const T& value); //
  void pop(); //
  const T& head() const; //

  size_t stack_size() const;

};

template <typename T>
Stack_1<T>::~Stack_1() {
  while (head_node != nullptr) {
    Node1<T>* current_node = head_node;
    head_node = head_node->prev;
    delete current_node;
  }
}

template <typename T>
void Stack_1<T>::push(T&& value) {
  auto* new_node = new Node1<T>{std::forward<T>(value), head_node};
  head_node = new_node;
}

template <typename T>
void Stack_1<T>::push(const T& value) {
  auto* new_node = new Node1<T>{value, head_node};
  head_node = new_node;
}

template <typename T>
void Stack_1<T>::pop() {
  if (head_node == nullptr) {
    throw std::exception();
  }
  Node1<T>* current_node = head_node;
  head_node = head_node->prev;
  delete current_node;
}

template <typename T>
const T& Stack_1<T>::head() const {
  if (head_node == nullptr) {
    throw std::exception();
  }
  return head_node->value;
}

template <typename T>
size_t Stack_1<T>::stack_size() const {
  size_t stack_size = 0;
  Node1<T>* current_node = head_node;
  while (current_node != nullptr) {
    stack_size++;
    current_node = current_node->prev;
  }
  return stack_size;
}

#endif // INCLUDE_STACK_TASK_1_HPP_
