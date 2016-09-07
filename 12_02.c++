# include <iostream>
# include <cstdlib>
# define MAXN 10
using namespace std;


//有点时钟周期的感觉
//我按照自己的感觉来的，用到了一个静态的数组
//还是有bug
//明天再试试，想不出来，就用书上的方法
char array[MAXN];
void printArray(int length) {
	int index = 0;
	for (int i = 0; i < length; i ++) {
		if (array[i] != '0') {
			index = i;
			break;
		}	
	}
	for (int i = index; i < length; i ++)
		cout << array[i];

	cout << endl;
}

void printRecurisively(int length, int index) {
	if (index == length - 1) {
		printArray(length);
		return;
	}
	for (char ch = '0'; ch <= '9'; ch ++) {
		array[index + 1] = ch;
		printRecurisively(length, index + 1);
	}
}

void Print1ToMaxOfDigits(int n) {
	if (n <= 0) return;
	for (char ch = '0'; ch <= '9'; ch ++) {
		array[0] = ch;
		printRecurisively(n, 0);
	}
}

int main(){
	int i;
	while(cin >> i) {
		memset(array, '0', MAXN);
		Print1ToMaxOfDigits(i);
		memset(array, '0', MAXN);
	}
}