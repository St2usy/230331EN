#pragma once
#define MAX_STACK_SIZE 11
#include <iostream>

// ���� ó�� �Լ�
inline void error(const char* message) { // inline - > �ش��Լ��� �ҽ��ڵ� �ȿ� ���ΰɷ� ġȯ ��Ŵ
	std::cout << message << std::endl;
	exit(1); // �Լ��� ������������ ���� ������ �ǹ���.
}

template <typename T>
class ArrayStack {
private:
	int top;
	T data[MAX_STACK_SIZE];
public:
	ArrayStack()
		: top(-1) {}
	~ArrayStack() {}
	bool isEmpty() {
		if (top == -1) return true;
		else return false;
	}
	bool isFuLL() {
		if (top == MAX_STACK_SIZE - 2) return true;
		else return false;
	}
	void push(T n) {
		if (isFuLL()) {
			for (int i = 1; i < MAX_STACK_SIZE - 1; i++) {
				data[i - 1] = data[i];
			}
			data[top] = n;
		}
		else {
			top += 1;
			data[top] = n;
		}
	}
	T pop() {
		if (isEmpty()) { error("ERROR"); }
		else {
			T popdata = data[top];
			top -= 1;
			return popdata;
		}
	}
	T peek() {
		if (isEmpty()) { error("Error :: Stack is Empty !!"); }
		else {
			return data[top];
		}
	}
	void display() {
		if (!isEmpty()) {
			for (int i = top; i >= 0; i--) {
				std::cout << data[i] << " ";
			}
		}
		else {
			std::cout << "EMPTY";
		}
		std::cout << std::endl;
	}
};
