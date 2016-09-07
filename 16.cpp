# include <iostream>
using namespace std;

struct LinkList {
	int value;
	LinkList* next;
};

LinkList* reverse(LinkList* head) {
	LinkList* ans = NULL;
	LinkList* temp = head;
	while (temp != NULL) {
		//创建新节点
		LinkList* node = new LinkList;
		node->value = temp->value;
		//头插入
		node->next = ans;
		ans = node;
	}
	return ans;
}

int main() {

	return 0;
}

