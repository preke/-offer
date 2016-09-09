# include <iostream>
# include <queue>
using namespace std;

struct BinaryTreeNode{
	int value;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
};


void BFS(BinaryTreeNode* root) {
	if (root == NULL)	return;
	queue<BinaryTreeNode*> q;
	q.push(root);
	while(!q.empty()) {
		cout << q.front()->value << " ";
		if (root->left)
			q.push(root->left);
		if (root->right)
			q.push(root->right);
		q.pop();
	}
}

int main() {
	return 0;
}