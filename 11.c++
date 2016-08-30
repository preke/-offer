# include <iostream>
using namespace std;

# define MINVALUE 0.0000001

int error = 0;

bool equel(double n1, double n2) {
	if ((n1 - n2) > -MINVALUE && (n1 - n2) < MINVALUE) {
		return true;
	}
	return false;
}

//普通解法
// double PowerWithPositiveExp(double base, int exponent) {
// 	double ans = 1.0;
// 	for (int i = 0; i < exponent; i++) {
// 		ans = ans * base;
// 	}
// 	return ans;
// }

//快速幂
double PowerWithPositiveExp(double base, int exponent) {
	if (exponent == 0)	return 1.0;
	if (exponent % 2 == 0) return PowerWithPositiveExp(base, exponent / 2) * PowerWithPositiveExp(base, exponent / 2);
	else return PowerWithPositiveExp(base, (exponent - 1) / 2) * PowerWithPositiveExp(base, (exponent - 1) / 2) * base;
}

double Power(double base, int exponent) {
	if (equel(base, 0.0) && exponent <= 0) {
		error = 1;
		cout << " error here " << endl;
		return (double)-1;
	}
	
	bool negitive = 0;
	if (exponent < 0) {
		exponent = -exponent;
		negitive = 1;
	} 
	double ans = PowerWithPositiveExp(base, exponent);
	if (negitive == 1) {
		ans = 1.0 / ans;
	}
	return ans;
}

int main() {
	double a;int b;
	cin >> a >> b;
	cout << Power(a, b) << endl;
	return 0;
}