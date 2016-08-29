# include <iostream>
using namespace std;

//递归
// long long Fibonacci(int n) {
// 	if (n <= 0) return 0;
// 	if (n == 1) return 1;
// 	return Fibonacci(n - 1) + Fibonacci(n - 2);
// }

//递推
long long Fibonacci(int n) {
	if (n <= 0) return 0;
 	if (n == 1) return 1;
	long long n2 = 0;
	long long n1 = 1;
	long long n0;
	for (int i = 2; i <= n; i ++) {
		n0 = n2 + n1;
		n2 = n1;
		n1 = n0;
	} 	
	return n0;
}


int main() {

}