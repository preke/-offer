//不创建新节点, 递归
# include <iostream>
using namespace std;

struct ListNode {
	int value;
	ListNode* next;
};

ListNode* Merge(ListNode* head1, ListNode* head2) {
	if (head1 == NULL) {
		return head2;
	} else if (head2 == NULL) {
		return head1;
	}

	ListNode* new_head = NULL; 
	if (head2->value > head1->value) {
		new_head = head1;
		new_head->next = Merge(head1->next, head2);
	} else {
		new_head = head2;
		new_head->next = Merge(head1, head2->next);
	}
	return new_head;
}

int main() {

	return 0;
}


