# include <iostream>
using namespace std;

void print(int n) {
  int* matrix = new int [n*n];
  int cnt = 1;
  int row = 0, col = -1;
  int count_up = n-1;
  int count_down = 0;
  for (int i = 0; i < n*n; i ++){
    while(col < count_up) {
      	col ++;
    		matrix[row*n + col] = cnt;
      	cnt ++;
    }
    while(row < count_up) {
    		row ++;
      	matrix[row*n + col] = cnt;
      	cnt ++;
    }
    count_up--;
    while(col > count_down) {
    		col --;
      	matrix[row*n + col] = cnt;
      	cnt ++;
    }
    count_down++;
    while(row > count_down) {
    		row --;
      	matrix[row*n + col] = cnt;
      	cnt ++;
    }
  }
  for (int i = 0; i < n; i ++) {
    for (int j = 0; j < n; j ++) {
    	cout << matrix[i * n + j] << " ";
  	}
  	cout << endl;
  }
  cout <<endl;
  delete matrix;	
}

int main(){
  int n;
  cin >> n;
  if(n > 0) {
  	print(n);
  }
  return 0;
}