# include <iostream>
using namespace std;

typedef struct BinaryTreeNode{
	int value;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
}BinaryTreeNode;



BinaryTreeNode* Rebuild(int* pre, int* in, int num) {
	if(pre == NULL || in == NULL || num <= 0)  return NULL;

	BinaryTreeNode* root = new BinaryTreeNode;
	root->value = *pre;
	root->left = root->right = NULL;

	int root_in_inorder = -1;
	for (int i = 0; i < num; i ++) {
		if (in[i] == *pre) {
			root_in_inorder = i;
			break;
		}
	}

	int num_left  = root_in_inorder + 1;
	int num_right = num - 1 - num_left;

	int* pre_left = pre + 1;
	int* in_left  = in;
	root->left = Rebuild(pre_left, in_left, num_left);

	int* pre_right = pre + num_left + 1;
	int* in_right  = in + num_left + 1;
	root->right = Rebuild(pre_right, in_right, num_right);

	return root;
}

int main() {

}