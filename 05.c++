# include <iostream>
# include <stack>
using namespace std;

typedef struct LinklistNode{
	int value;
	LinklistNode* next;
}LinklistNode;

void AddToTail(LinklistNode* & head, int a) {
	
	LinklistNode* new_Node = new LinklistNode;
	new_Node->value = a;
	new_Node->next = NULL;

	LinklistNode* temp = head;
	if (temp == NULL) {
		head = new_Node;
		return;
	}
	while(temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = new_Node;
	return;
}

void AddToHead(LinklistNode* & head, int a) {

	LinklistNode* new_Node = new LinklistNode;
	new_Node->value = a;
	new_Node->next = NULL;

	LinklistNode* temp = head;
	head = new_Node;
	if (temp != NULL) {
		head->next = temp;
	}
	return;
}

void print(LinklistNode* head) {
	if (head == NULL) {
		cout << "Blank!" << endl;
		return;
	}
	while (head != NULL) {
		cout << head->value << " ";
		head = head->next;
	}
	cout << endl;
	return;
}

void PrintReverse(LinklistNode* head) {
	if (head == NULL) {
		cout << "Blank!" << endl;
		return;
	}
	stack<int> s;
	while (head != NULL) {
		s.push(head->value);
		head = head->next;
	}
	while(!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;
}

int main() {
	LinklistNode* head = NULL;
	int a;
	for (int i = 0; i < 10; i++) {
		cin >> a;
		AddToHead(head, a);
		
	}
	print(head);
	PrintReverse(head);
	
}