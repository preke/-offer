# include <iostream>

using namespace std;

typedef struct LinkList {
	int value;
	LinkList* next;
}LinkList;

void Delete(LinkList* &head, LinkList* to_be_deleted) {
	if ( !(head && to_be_deleted) )	return;

	if (head == to_be_deleted) { //头结点
		LinkList* p = head;
		head = head->next;
		delete p;
		return;
	} else if (to_be_deleted->next == NULL) { //尾结点
		LinkList* temp = head;
		while (temp->next->next) {
			temp = temp->next;
		}
		delete temp->next;
		return;
	} else { //非尾节点
		LinkList* Next = to_be_deleted->next;
		to_be_deleted->value = Next->value;
		to_be_deleted->next = Next->next;
		delete Next;
	}

}

int main() {

	return 0;
}