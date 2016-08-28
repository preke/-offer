# include <iostream>
# include <stack>
using namespace std;

template<typename T> class CQueue {
	public:
		CQueue(){}
		~CQueue(){}
		void appendTail(const T & node);
		T deleteHead();
		void print();
	private:
		stack<T> stack1;
		stack<T> stack2;
};

template<typename T>
void CQueue<T>::appendTail(const T & node) {
	stack1.push(node);
}

//自己拙劣的实现
// template<typename T>
// T CQueue<T>::deleteHead() {
// 	if (stack1.empty()) {
// 		cout << "Blank!" << endl;
// 		return -1;
// 	}

// 	while( !stack1.empty() ) {
// 		stack2.push( stack1.top() );
// 		stack1.pop();
// 	}

// 	T temp = stack2.top();
// 	stack2.pop();

// 	while( !stack2.empty() ) {
// 		stack1.push( stack2.top() );
// 		stack2.pop();
// 	}

// 	return temp;
// }

//书上的实现
template<typename T>
T CQueue<T>::deleteHead() {
	if (stack2.empty()) {
		while( !stack1.empty() ) {
	 		stack2.push( stack1.top() );
	 		stack1.pop();
	 	}
	}

	if (stack2.empty()) {
		cout << "Blank" << endl;
		return -1;
	}

	T temp = stack2.top();
	stack2.pop();
	return temp;
}


template<typename T>
void CQueue<T>::print() {
	while( !stack1.empty() ) {
		stack2.push( stack1.top() );
		stack1.pop();
	}

	while( !stack2.empty() ) {
		cout << stack2.top() << endl;
		stack1.push( stack2.top() );
		stack2.pop();
	}
	cout << endl;
}

int main() {
	CQueue<int> test;
	for (int i = 0; i < 1; i ++)
		test.appendTail(i);

	test.print();
	for (int i = 0; i < 10; i ++) {
		int a; cin >> a;
		cout << test.deleteHead() << endl;
		cout << "Now:\n";
		test.print();
	}
}

