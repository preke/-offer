# include <iostream>
using namespace std;

struct LinkList {
	int value;
	LinkList* next;
};

LinkList* reverse(LinkList* head) {
	if (!head || !head->next) {
		return head;
	}
	LinkList* curr = head;
	LinkList* temp = curr->next;
	LinkList* s = NULL; 
	while(temp) {
		s = temp->next;
		temp->next = curr;
		curr = temp;
		temp = s;
	}
	return curr;
}

int main() {

	return 0;
}

