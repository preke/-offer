# include <iostream>
# include <stack>

using namespace std;

bool IsPopOrder(int* a, int* b, int length) {
	if (a == NULL || b == NULL || length <= 0) return false;
	stack<int> temp;
	int i = 0, j = 0;
	while(i < length && j < length) {
		if (a[i] == b[j]) {
			i ++;
			j ++;
		} else if (a[i] != b[j]) {
			if (!temp.empty() && temp.top() == b[j]) {
				temp.pop();
				j ++;
			} else {
				temp.push(a[i]);			
				i ++;
			}
		}
	}

	while(!temp.empty() && j < length) {
		if (b[j] == temp.top()) {
			temp.pop();
			j++;
		} else {
			break;
		}
	}

	if (temp.empty())
		return true;
	else return false;

}

int main() {
	int n;
	cin >> n;
	if (n > 0) {
		int a[n], b[n];
		for (int i = 0; i < n; i ++)	cin >> a[i];
		for (int i = 0; i < n; i ++)	cin >> b[i];
		bool ans = IsPopOrder(a, b, n);
		if (ans)	cout << "Can" << endl;
		else cout << "Can`t" << endl;
	} else cout << "Can`t" << endl;
	
	return 0;
}

