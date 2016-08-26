# include <iostream>
# define MIN -1
using namespace std;

void merge(int* a, int* b, int a_max_length, int a_len, int b_len) {
	if (a_len + b_len > a_max_length) {
		cout << "Out of memory!" << endl;
		return;
	}
	int* pa = a + a_len - 1;
	int* pb = b + b_len - 1;
	int end = MIN;
	int* p_all = a + a_len + b_len - 1;
	for (int i = 0; i < a_len + b_len; i ++) {
		
		if (*pa > *pb) {
			*p_all = *pa;
			if (pa != a) pa--;
			else pa = &end;
		} else {
			*p_all = *pb;
			if (pb != b) pb--;
			else pb = &end;
		}
		p_all--;
	}
}
int main() {
	int a[20] = {1, 4, 6, 8, 9, 22, 22, 23, 45, 46};
	int b[4] = {2, 5, 8, 9};
	merge(a, b, 20, 10, 4);
	for (int i = 0; i < 20; i ++) {
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}