#pragma once
#define MAX_STACK_SIZE 11
#include <iostream>

// 오류 처리 함수
inline void error(const char* message) { // inline - > 해당함수를 소스코드 안에 쓰인걸로 치환 시킴
	std::cout << message << std::endl;
	exit(1); // 함수가 비정상적으로 종료 됐음을 의미함.
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
