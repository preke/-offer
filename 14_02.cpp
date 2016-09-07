//用函数指针
# include <iostream>
using namespace std;

bool isOdd(int n) {
	return (n & 1) == 1;
}

void Reorder(int* a, int n, bool (*fun)(int) ) {
	if (n <= 0 || a == NULL) {
		cout << "Invalid!" << endl;
		return;
	}
	int j = -1;
	for (int i = 0; i < n; i ++) {
		if ( fun(a[i]) ) { //奇数
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
	Reorder(a, n, isOdd);
	for (int i = 0; i < n; i ++) {
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}