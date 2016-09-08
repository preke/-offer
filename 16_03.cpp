# include <iostream>
using namespace std;

struct LinkList {
	int value;
	LinkList* next;
};

LinkList* reverse(LinkList* head) {
	if (!head || !head->next) return head;
	
	LinkList* new_head = reverse(head->next);
	head->next->next = head;
	head->next = NULL;
	return new_head;
}

int main() {

	return 0;
}

/* reference:
 * http://blog.csdn.net/yunzhongguwu005/article/details/10350339
 */
