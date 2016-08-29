# include <iostream>
# include <cstdlib>
# define MAXSIZE 2
using namespace std;

class Matrix {
	private:
		int row;
		int column;
		unsigned long long int array[MAXSIZE][MAXSIZE];
	public:	
		Matrix(int r, int c) {
			if (r > MAXSIZE || c > MAXSIZE) {
				cout << "Wrong" << endl;
				r = 0;
				c = 0;
			}
			row = r;
			column = c;
			for (int i = 0; i < row; i ++) {
				for (int j = 0; j < column; j ++) {
					cin >> array[i][j];
				}
			}

		}

		Matrix(int r, int c, int a) {
			if (r > MAXSIZE || c > MAXSIZE) {
				cout << "Wrong" << endl;
				r = 0;
				c = 0;
			}
			row = r;
			column = c;
			
			for (int i = 0; i < row; i ++) {
				for (int j = 0; j < column; j ++) {
					array[i][j] = a;
				}
			}

		}

		Matrix(const Matrix& m) {
			row = m.row;
			column = m.column;
			
			for (int i = 0; i < row; i ++) {
				for (int j = 0; j < column; j ++) {
					array[i][j] = m.array[i][j];
				}
			}

		}

		Matrix & operator = (const Matrix & m) {
			
			if (&m == this)		return *this;

			row = m.row;
			column = m.column;
			
			for (int i = 0; i < row; i ++) {
				for (int j = 0; j < column; j ++) {
					array[i][j] = m.array[i][j];
				}
			}

			return *this;
		}

		Matrix operator * (const Matrix & m) const {
			if (column != m.row ) {
				cout << "Wrong!" << endl;
				return Matrix(1, 1, -1);
			}
			Matrix ans(row, m.column, 0);
			for (int i = 0; i < ans.row; i ++) {
				for (int j = 0; j < ans.column; j ++) {
					int temp = 0;
					for (int k = 0; k < ans.row; k ++) {
						temp += this->array[i][k] * m.array[k][j];	
					}
					ans.array[i][j] = temp;

				}
			}
			return ans;
		}

		Matrix operator ^ (int n) const {
			if (n <= 0) {
				cout << "Wrong!" << endl;
				return Matrix(1, 1, -1);
			}
			Matrix ans = *this;
			for (int i = 1; i < n; i ++) {
				ans = ans * (*this);
			}
			return ans;
		}

		void print() {
			cout << "row: " << row << endl;
			cout << "column: " << column << endl;
			for (int i = 0; i < row; i ++) {
				for (int j = 0; j < column; j ++) {
					cout << array[i][j] << " "; 
				}
				cout << endl;
			}
		}

		unsigned long long int get(int i, int j){
			if (i < 0 || j < 0 || i >= row || j >= column) {
				cout << "Wrong input!" << endl;
				return -1;
			}
			return array[i][j];
		}

};

Matrix FastPower(const Matrix & m, int n) {
	if (n == 1) {
		return m;
	}
	if (n % 2 == 0) {
		return FastPower(m, n/2) * FastPower(m, n/2);
	} else {
		return FastPower(m, (n - 1)/2) * FastPower(m, (n - 1)/2) * m;
	}
}

Matrix m = Matrix(2, 2); //在此我们输入 1,1,1,0 初始化这个矩阵
unsigned long long int Fibonacci(int n) {
	if (n <= 0) return 0;
	if (n == 1) return 1;	
	Matrix m1 = m;
	m1 = FastPower(m1, n-1);
	return m1.get(0, 0); //为f(n)
}

//怎么突破int呢？

int main() {
	for(int i = 0; i < 48; i ++)
		cout << i << ": " << Fibonacci(i) << endl;

}