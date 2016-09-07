# include <iostream>
using namespace std;

void Reorder(int* a, int n) {
	if (n <= 0 || a == NULL) {
		cout << "Invalid!" << endl;
		return;
	}
	int j = -1;
	for (int i = 0; i < n; i ++) {
		if ( (a[i] & 1) == 1) { //奇数
			//pass
		} else { //偶数
			j ++;
			swap(a[i], a[j]);
		}
	}
}

int main() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
	}
	Reorder(a, n);
	for (int i = 0; i < n; i ++) {
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}
