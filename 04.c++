# include <iostream>
# include <cstring>
using namespace std;

//这个字符串：
//1. 字符数组有长度限制，如果长度超过之后返回错误
//2. 动态再去申请内存空间，然后将str指向新的内存空间，这时要传引用,而且不可以原址操作
//只实现第一种吧
void Replace(char* str, int length) {
	int len = strlen(str);
	if (length == 0) 	return;
	int num_of_blank = 0;
	for (int i = 0; i < len; i ++) {
		if (str[i] == ' ') {
			num_of_blank ++;
		}
	}
	int new_length = len + 2 * num_of_blank;
	if (new_length > length) {
		cout << "Out of memory!" << endl;
		return;
	}
	char* p2 = str + new_length;
	char* p1 = str + len;
	for (int i = 0; i <= len; i ++ ) {
		if (*p1 == ' ') {
			*p2 = '0';
			p2--;
			*p2 = '2';
			p2--;
			*p2 = '%';
			p1--;
			p2--; 
		} else {
			*p2 = *p1;
			p1--;
			p2--;
		}
	}
}


int main() {
	//for test:
	char str[20] = "   ";
	char* p = NULL;
	Replace(str, 0);
	for (int i = 0; i < 20; i ++) {
		cout << str[i];
	}
	cout << endl;
	return 0;
}