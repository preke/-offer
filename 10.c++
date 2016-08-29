# include <iostream>
using namespace std;

//	右移n
// int NumOf1(int n) {
// 	int cnt = 0;
// 	while(n) {
// 		if (n & 1)	cnt++;
// 		n = n >> 1;
// 	}
// 	return cnt;
// }

//左移flag
// int NumOf1(int n) {
// 	int cnt = 0;
// 	int flag = 1;
// 	for (int i = 0; i < 32; i ++) {
// 		if (flag & n) 	cnt++;
// 		flag = flag << 1;
// 	}
//	return cnt;
// }

// n 和 n-1做与运算
int NumOf1(int n) {
	int cnt = 0;
	while(n) {
		cnt++;
		n = n & n-1;
	}
	return cnt;
}

int main() {

}