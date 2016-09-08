# include <iostream>
using namespace std;

struct BinaryTreeNode {
	int value;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
};

void MirrorRecurisively(BinaryTreeNode* root) {
	if (root == NULL || (root->left == NULL && root->right == NULL)) {
		return;
	}
	BinaryTreeNode* temp = root->left;
	root->left = root->right;
	root->right = temp;

	if (root->left) {
		MirrorRecurisively(root->left);
	}
	if (root->right) {
		MirrorRecurisively(root->right);
	}
}

int main() {

	return 0;
}