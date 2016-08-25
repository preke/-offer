# include <iostream>
using namespace std;

class Singleton {
	private:
		static Singleton* instance;
		Singleton() {
		}

	public:
		static Singleton* GetInstance() {
			if ( instance == NULL ) {
				instance = new Singleton();
			}
			return instance;
		}	
};

//静态变量在类外初始化
Singleton* Singleton::instance = new Singleton();

int main() {
	
	Singleton* test1 = Singleton::GetInstance();
	Singleton* test2 = Singleton::GetInstance();
	if (test1 == test2) {
		cout << "the only one instance" << endl;
	}
}

