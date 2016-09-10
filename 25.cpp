# include <iostream>
# include <vector>
using namespace std;

struct BinaryTreeNode{
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


vector<int> v;
int current = 0;
void FindPath(BinaryTreeNode* root, int sum) {
	if (sum <= 0) return;
	if (root) {
		v.push_back(root->value);
		current += root->value;

		if (!root->left && !root->right) {  //到叶子结点
			if (current == sum) {
				for (int i = 0; i < v.size(); i ++) {
						cout << v[i] << " ";
				}
				cout << endl;
			}
			current -= root->value;
			v.pop_back();
			return;
		}

		//剪枝
		if (current >= sum) {
			current -= root->value;
			v.pop_back();
			return;
		}

		if (root->left) 
			FindPath(root->left, sum);
		if (root->right)
			FindPath(root->right, sum);

		current -= root->value;
		v.pop_back(); //访问过该节点，就pop掉
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
	FindPath(root, 22);
	return 0;
}