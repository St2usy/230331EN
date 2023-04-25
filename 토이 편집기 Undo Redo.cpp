#include "Stack.h"

int main() {
	char a;
	ArrayStack<char> stack1;
	ArrayStack<char> stack2;
	while (1) {
		a = std::cin.get(); // ���๮�ڵ� �Է��� �޴´�. cin�� ���๮�ڸ� �����Ѵ�.
		if (a >= 'a' && a <= 'z'&&stack2.isEmpty()) {
			stack1.push(a);
		}
		else if (a == 'U') {
			stack2.push(stack1.pop());
		}
		else if (a == 'R') {
			stack1.push(stack2.pop());
		}
		else if (a >= 'a' && a <= 'z' && !stack2.isEmpty()) {
			while (!stack2.isEmpty()) {
				stack2.pop();
			}	
			stack1.push(a);
		}
		if (a=='\n')
			break;
	}
	stack1.display();
	stack2.display();
	return 0;
}
