#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Stack {
public:
	template <typename T>
	struct Node
	{
		T data;
		Node<T>* next;

		Node() {
			next = nullptr;
		}

		Node(T val) {
			next = nullptr;
			data = val;
		}
	};

	Node<T>* top;

	Stack() {
		top = nullptr;
	}

	bool isEmpty() {
		if (top) {
			return false;
		}
		return true;
	}

	void push(T val) {
		Node<T>* n = new Node<T>(val);
		if (!isEmpty()) {
			n->next = top;
			top = n;
		}
		else {
			top = n;
		}
	}

	void pop() {
		if (!isEmpty()) {
			top = top->next;
		}
	}

	T showTop() {
		if (!isEmpty()) {
			return top->data;
		}
	}

	void print() {
		if (!isEmpty()) {
			string output = showTop();
			cout << output << endl;
			pop();
			print();
			push(output);
		}
	}
};