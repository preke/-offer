# include <iostream>
# include <stack>
using namespace std;

struct BinaryTreeNode {
	int value;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
};

int Pre[100], In[100], Post[100];

BinaryTreeNode* buildByPreAndIn(int* pre_order, int* in_order, int num) {
    if (pre_order == NULL || in_order == NULL || num <= 0)  return NULL;

    BinaryTreeNode* root = new BinaryTreeNode;
    root->value = *pre_order;
    root->left = root->right = NULL;

    int rootPositionInOrder = -1;
    for (int i = 0; i < num; i++) {
        if (in_order[i] == root->value) {
            rootPositionInOrder = i;
            break;
        }
    }

    int num_Left  = rootPositionInOrder;
    int num_Right = num - num_Left - 1;

    int* pre_order_left  = pre_order + 1;
    int* in_order_left   = in_order;
    root->left          = buildByPreAndIn(pre_order_left, in_order_left, num_Left);

    int* pre_order_right = pre_order + num_Left + 1;
    int* in_order_right  = in_order + num_Left + 1;
    root->right         = buildByPreAndIn(pre_order_right, in_order_right, num_Right);

    return root;
}

//将交换左右子树理解为遍历，那么就是一个简单的前序遍历

void Mirror(BinaryTreeNode* root) {
	if (root == NULL || (root->left == NULL && root->right == NULL)) {
		return;
	}
	stack<BinaryTreeNode*> s;
	while(root || !s.empty()) {
		while (root) {
			
			BinaryTreeNode* temp = root->left;
			root->left = root->right;
			root->right = temp;	
			
			s.push(root);
			root = root->left;
		}
		while(!s.empty()) {
			root = s.top();
			s.pop();
			root = root->right;
		}
	}
}

void PreOrderTraversal (BinaryTreeNode* root) {
	if (root == NULL) {
		return;
	} else {
		cout << root->value << ' ';
		PreOrderTraversal(root->left);
		PreOrderTraversal(root->right);
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i ++) {
		cin >> Pre[i];
	}
	for (int i = 0; i < n; i ++) {
		cin >> In[i];
	}
	BinaryTreeNode* root = NULL;
	root = buildByPreAndIn(Pre, In, n);
	PreOrderTraversal(root);
	cout << endl;
	Mirror(root);
	PreOrderTraversal(root);
	cout << endl;
	return 0;
}