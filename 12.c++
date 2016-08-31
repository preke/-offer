# include <iostream>
using namespace std;

void add(char* array, int n) {
	int index = n;
	while(1) {
		if (array[index - 1] == '9') {
			array[index - 1] = '0';
			index --;
		} else {
			array[index - 1] = array[index - 1] + 1;
			break;
		}
	}
}

void print(char* array, int n) {
	int index = 0;
	for (int i = 0; i < n; i ++) {
		if (array[i] != '0') {
			index = i;
			break;
		}
	}

	for (int i = index; i < n; i ++) {
		cout << array[i];
	}
	cout << endl;
}

void Print1ToMaxOfDigits(int n) {
	if (n <= 0) {
		return;
	}
	char array[n];
	for (int i = 0; i < n; i ++) {
		array[i] = '0';
	}	
	int cnt = 0;
	while(1) {
		cnt = 0;
		for (int i = 0; i < n; i ++) {
			if (array[i] == '9') {
				cnt++;
			}	
		}
		if (cnt == n) {
			break;
		}

		add(array, n);
		print(array, n);
	}
}

int main(){
	int i;
	while(cin >> i)
		Print1ToMaxOfDigits(i);

}