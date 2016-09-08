# include <iostream>
using namespace std;

struct ListNode {
	int value;
	ListNode* next;
};

ListNode* Merge(ListNode* head1, ListNode* head2) {
	ListNode* ans = NULL;
	ListNode** ans_address = &ans;
	
	while (head1 && head2) {
		ans = new ListNode;
		ans->next = NULL;	
		if (head1->value > head2->value) {
			ans->value = head2->value;
			head2 = head2->next;
		} else {
			ans->value = head1->value;
			head1 = head1->next;
		}
		ans = ans->next;
	}

	if (head1 == NULL) {
		ans = head2;
	} else {
		ans = head1;
	}

	return *ans_address;
}

int main() {

	return 0;
}


