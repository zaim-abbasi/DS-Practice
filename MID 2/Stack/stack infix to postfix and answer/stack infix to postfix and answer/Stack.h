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

	string infixToPostFix(string input) {
		string output = "";
		triverse(0, input.size(), input, output);
		/*for (int i = 0;i < input.size();i++) {
			if (input[i] >= 97 && input[i] <= 122) {
				output += input[i];
			}
			else if (input[i] == '/' || input[i] == '*') {
				push(input[i]);
			}
			else {
				if (isEmpty()) {
					push(input[i]);
				}
				else {
					bool check = true;
					while (check) {
						char temp = showTop();
						if (temp == '*' || temp == '/') {
							output += temp;
							pop();
						}
						else {
							push(input[i]);
							check = false;
						}
					}
				}
			}
		}*/

		popAll(output);
		/*while (!isEmpty())
		{
			output += showTop();
			pop();
		}*/
		return output;
	}

	void triverse(int i, int limit, string input, string& output) {
		if (i < limit) {
			if (input[i] >= 97 && input[i] <= 122) {
				output += input[i];
			}
			else if (input[i] == '/' || input[i] == '*') {
				push(input[i]);
			}
			else {
				if (isEmpty()) {
					push(input[i]);
				}
				else {
					bool check = true;
					precidence(check, i, input, output);
					/*while (check) {
						char temp = showTop();
						if (temp == '*' || temp == '/') {
							output += temp;
							pop();
						}
						else {
							push(input[i]);
							check = false;
						}
					}*/
				}
			}
			triverse(++i, limit, input, output);
		}
		return;
	}

	void precidence(bool check,int i, string input, string& output) {
		if (check) {
			char temp = showTop();
			if (temp == '*' || temp == '/') {
				output += temp;
				pop();
			}
			else {
				push(input[i]);
				check = false;
			}
			precidence(check, i, input, output);
		}
		return;
	}

	void popAll(string& output) {
		if (!isEmpty()) {
			output += showTop();
			pop();
			popAll(output);
		}
		return;
	}

	int postFixToAnswer(string input) {//12-   1-2
		char temp;
		for (int i = 0;i < input.size();i++) {
			temp = input[i];
			if (temp >= 49 && temp <= 57) {
				push(temp);
			}
			else {
				char opnd2 = showTop();
				pop();
				char opnd1 = showTop();
				pop();
				if (opnd2 > 9) {
					opnd2 -= 48;
				}
				if (opnd1 > 9) {
					opnd1 -= 48;
				}
				int val = 0;
				if (temp == '+') {
					val = int(opnd1) + int(opnd2);
				}else if (temp == '-') {
					val = int(opnd1) - int(opnd2);
				}
				else if(temp == '*') {
					val = int(opnd1) * int(opnd2);
				}
				else if(temp == '/') {
					val = int(opnd1) / int(opnd2);
				}
				push(char(val));
			}
		}
		temp = showTop();
		pop();
		return int(temp);
	}
};