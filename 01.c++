# include <iostream>
# include <cstring>
# include <exception>
using namespace std;
//面试题01
//添加赋值运算符函数
class CMyString {
	public:
		CMyString(char* pData = NULL);
		CMyString(const CMyString& str);
		~CMyString();
		void print();
		CMyString & operator = (const CMyString& str); 
	private:
	//public:
		char* m_pData;
}; 

CMyString& CMyString::operator = (const CMyString& str) {
	if (this == &str) {
		return *this;
	}
	try{
		
		delete [] this->m_pData;
		this->m_pData = new char [strlen(str.m_pData) + 1];
		strcpy(this->m_pData, str.m_pData);
	} catch(std::exception& e) {
		std::cout << "申请内存错误，赋值失败，返回原对象" << std::endl;
		std::cout << e.what() << std::endl;
		
	}
	return *this;
}

CMyString::CMyString(char* pData) {
	if (pData == NULL) {
		std::cout << "字符串为空，创建失败" << std::endl;
		m_pData = NULL;			//这里很关键！！
		return;
	}
	try {
		this->m_pData = new char [strlen(pData) + 1];
		strcpy(this->m_pData, pData);
	} catch(std::exception& e) {
		std::cout << "申请内存错误，创建失败" << std::endl;
		std::cout << e.what() << std::endl;
	}	
}

CMyString::CMyString(const CMyString& str) {
	try{
		this->m_pData = new char [strlen(str.m_pData) + 1];
		strcpy(this->m_pData, str.m_pData);
	} catch(std::exception& e) {
		std::cout << "申请内存错误，创建失败" << std::endl;
		std::cout << e.what() << std::endl;
	}
}

CMyString::~CMyString() {
	try{
		delete [] m_pData;
	} catch(std::exception& e) {
		cout << "释放内存失败" << endl;
		std::cout << e.what() << std::endl;
	}
	m_pData = NULL;
}

void CMyString::print() {
	if (m_pData == NULL) {
		std::cout << "Blank" << std::endl;
		return;
	}
	for (int i = 0; i < strlen(m_pData); i++) {
		std::cout << *(m_pData + i);
	}
	std::cout << std::endl;
}



int main() {
	//for test
	// char test[10] = "hello";
	// cout << strlen(test) << endl;
	// CMyString s1(test); 
	// CMyString s2 = s1;

	// char* test01 = NULL;
	// CMyString s3(test01);
	// s3.print();
	
	// s3 = s1;
	// s3.print();

}

