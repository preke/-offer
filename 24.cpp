# include <iostream>
using namespace std;

bool isPostOrder(int* a, int length) {
	if (a == NULL || length <= 0) {
		return 0;
	}
	bool left_true  = 1;
	bool right_true = 1;

	int left_length, right_length;
	for (int i = 0; i < length - 1; i ++) {
		if (a[i] > a[length - 1]) {
			left_length = i;
			right_length = length - i- 1;
			break;
		}
	}
	for (int j = left_length; j < length - 1; j ++) {
		if (a[j] < a[length - 1]) {
			return false;
		}
	}
	left_true  = isPostOrder(a, left_length);
	right_true = isPostOrder(a + left_length, right_length);
	return (right_true && left_true);
}

int main() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
	}
	bool ans = isPostOrder(a, n);
	if (ans == 1) {
		cout << "IS" << endl;
	} else {
		cout << "NOT" << endl;
	}
	return 0;
}