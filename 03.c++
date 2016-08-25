# include <iostream>
# define MAXSIZE 100
using namespace std;


int array[MAXSIZE][MAXSIZE];

bool find(int n, int size) {
	if (size == 0) {
		return 0;
	}
	int row, col;	
	for (int i = size - 1; i >= 0; i --) {
		if (n == array[0][i]) {
			return 1;
		}
		if (n > array[0][i]) {
			col = i;
			break;
		}
	}
	for (int i = 0; i < size - 1; i ++) {
		if (n == array[i][col]) {
			return 1;
		}
	}
	return 0;
}

int main(){	
	//for test:
	int size;
	cin >> size;
	for (int i = 0; i < size; i ++) {
		for (int j = 0; j < size; j ++) {
			cin >> array[i][j];
		}
	}
	int n;
	cin >> n;
	if ( !find(n, size) ) {
		cout << "Not ";
	}
	cout << "Found!" << endl;
}

