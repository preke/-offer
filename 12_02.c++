# include <iostream>
# include <cstdlib>
# define MAXN 10
using namespace std;


//有点时钟周期的感觉
//我按照自己的感觉来的，用到了一个静态的数组
//还是有bug
//明天再试试，想不出来，就用书上的方法
char array[MAXN];
void printArray() {
	int index = 0;
	while(array[MAXN - 1 - index] != '0' ) {
		index ++;
	}
	for (int i = MAXN - index; i < MAXN; i ++) {
		cout << array[i];
	}
	//cout << endl;
}

void Print1ToMaxOfDigits(int n) {
	if (n <= 0) {
		printArray();
	}
	for (int i = 0; i < n; i ++) {
		for (char ch = '1'; ch <= '9'; ch ++) {
			array[MAXN - 1 - i] = ch;
			Print1ToMaxOfDigits(n - 1);
		}
	}
 	
}

int main(){
	memset(array, '0', MAXN);
	int i;
	while(cin >> i) {
		Print1ToMaxOfDigits(i);
		memset(array, '0', MAXN);
	}
}