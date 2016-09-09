# include <iostream>
# include <stack>
using namespace std;

struct Stack{
	stack<int> s;
	stack<int> min_stack;
	void push(int a);
	void pop();
	int min();
};

void Stack::push(int a) {
	s.push(a);
	if (min_stack.empty() || min_stack.top() > a) {
		min_stack.push(a);
	}
	else min_stack.push(min_stack.top());
}

void Stack::pop() {
	if (!s.empty()) {
		s.pop();
		min_stack.pop();
	}
	else {
		cout << "Already Empty!" << endl;
		return;
	}
}

int Stack::min() {
	if (min_stack.empty()) {
		cout << "No elements!" << endl;
		return -1;
	}
	return min_stack.top();
}

int main() {
	return 0;
}