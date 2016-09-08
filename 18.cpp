# include <iostream>
using namespace std;

struct BinaryTreeNode {
	int value;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
};
/*
	其实个人觉得更直接的思路是找出两棵树的前序遍历，
	然后字符串匹配，但是那样的话也许复杂度不如这种算法好。
*/


bool DoesTree1HaveTree2(BinaryTreeNode* root1, BinaryTreeNode* root2) {
	if (root2 == NULL)
		return true;
	if (root1 == NULL)
		return false;
	if (root1->value != root2->value)
		return false;

	return DoesTree1HaveTree2(root1->left, root2->left) &&
	  DoesTree1HaveTree2(root1->right, root2->right);
}

bool HasSubTree(BinaryTreeNode* root1, BinaryTreeNode* root2) {
	bool result = false;
	if (root1 != NULL && root2 != NULL) {
		if (root1->value == root2->value) {
			result = DoesTree1HaveTree2(root1, root2);
			if (!result)
				result = HasSubTree(root1->left, root2);
			if (!result)
				result = HasSubTree(root1->right, root2);
		}
	}
	return result;
}

int main() {

	return 0;
}