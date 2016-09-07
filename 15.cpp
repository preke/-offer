# include <iostream>
using namespace std;

template<typename T>
struct LinkList {
	T value;
	LinkList* next;
};

template<typename T>
LinkList<T>* FindkthToTail(LinkList<T>* head, int k) {
	if (head == NULL || k <= 0) {
		cout << "Invalid" << endl;
		return NULL;
	}
	LinkList<T>* front = head;
	LinkList<T>* back = head;
	k--;
	while (k--) {
		if (front == NULL) {
			cout << "Invalid" << endl;
			return;
		}
		front = front->next;
	}
	while (front != NULL) {
		front = front->next;
		back = back->next;
	}
	return back;
}

int main() {

	return 0;
}