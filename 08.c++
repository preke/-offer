# include <iostream>
using namespace std;

int FindMin(int* a, int size) {
	if (a == NULL || size <= 0) {
		cout << "Wrong input" << endl;
		return -1;
	}
	int high = size - 1;
	int low = 0;
	int mid = (high + low) / 2;
	while(low < high - 1) {
		if (a[low] == a[high] && a[mid] == a[low]) { //先判断特殊情况
			int minIndex = low;
			for (int i = low; i < high; i ++) {
				if (a[i] < a[minIndex]) minIndex = i;
			}
			return a[minIndex];
		}
		
		if (a[mid] > a[low]) {
			low = mid;
		} else {
			high = mid;
		}
		mid = (low + high) / 2;
	}
	if (high == size - 1 && a[high] > a[low])
		return a[0];

	return a[high];
}

int main() {
	// for test
	// int array[5] = {1,1,1,1,1};
	// cout << FindMin(array, 5) << endl;	
}