//不创建新节点
# include <iostream>
using namespace std;

struct ListNode {
	int value;
	ListNode* next;
};

ListNode* Merge(ListNode* head1, ListNode* head2) {
	ListNode* ans = new ListNode;
	ListNode** ans_address = &ans;
	while(head1 && head2) {
		if (head1->value > head2->value) {
			ans->next = head2;
			head2 = head2->next;
		} else {
			ans->next = head1;
			head1 = head1->next;
		}
		ans = ans->next;
	}
	if (head1) {
		ans->next = head1;
	} else {
		ans->next = head2;
	}
	return (*ans_address)->next;
}

int main() {

	return 0;
}


