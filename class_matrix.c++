# include <iostream>
# define MAXSIZE 2
using namespace std;

class Matrix {
	private:
		int row;
		int column;
		int array[MAXSIZE][MAXSIZE];
	public:	
		Matrix(int r, int c) {
			row = r;
			column = c;
			
			for (int i = 0; i < row; i ++) {
				for (int j = 0; j < column; j ++) {
					cin >> array[i][j];
				}
			}

		}

		Matrix(int r, int c, int a) {
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

		int get(int i, int j){
			if (i < 0 || j < 0 || i >= row || j >= column) {
				cout << "Wrong input!" << endl;
				return -1;
			}
			return array[i][j];
		}

};


int main() {
	
	// Matrix m1 = Matrix(2, 2);
	// Matrix ans = m1^2;
	// ans.print();

}