#include <iostream>
using namespace std;
#pragma warning (disable:4996)
#include <string.h>
class Teacher{
private:
	char name[20];
	int pay;
public:
	Teacher(const char *np="아무개", int p=0){
		strcpy(name, np);
		pay=p;
	}
	virtual void teach() = 0; // { cout << "가르친다..." << endl; }
	void view(){
		cout << "이름 : " << name << ", 수업료 : " << pay << endl;
	}
	virtual ~Teacher(){ cout << "~Teacher 수행중..." << endl; }

};

class kTeacher : public Teacher{
public:
	kTeacher(const char *np="아무개", int p=0) : Teacher(np, p) {}
	void teach() { cout << "국어를 가르친다..." << endl; }
	~kTeacher(){ cout << "~kTeacher 수행중..." << endl; }
};

class eTeacher : public Teacher{
public:
	eTeacher(const char *np="아무개", int p=0) : Teacher(np, p) {}
	void teach() { cout << "영어를 가르친다..." << endl; }
	~eTeacher(){ cout << "~eTeacher 수행중..." << endl; }
};

class mTeacher : public Teacher{
public:
	mTeacher(const char *np="아무개", int p=0) : Teacher(np, p) {}
	void teach() { cout << "수학을 가르친다..." << endl; }
	~mTeacher(){ cout << "~mTeacher 수행중..." << endl; }
};

int main()
{
	Teacher *cheoli[2];
	cheoli[0]=new kTeacher("홍길동", 70);
	cheoli[1]=new mTeacher("이순신", 80);

	Teacher *metel[3];
	metel[0]=new kTeacher("신사임당", 200);
	metel[1]=new eTeacher("임꺽정", 50);
	metel[2]=new mTeacher("강감찬", 90);

	int i;
	cout << "철이의 선생님..." << endl;
	for(i=0; i<2; i++){
		cheoli[i]->view();
		cheoli[i]->teach();
	}
	//cout << "메텔의 선생님..." << endl;
	//for(i=0; i<3; i++){
	//	metel[i]->view();
	//	metel[i]->teach();
	//}
	for(i=0; i<2; i++){
		delete cheoli[i];
	}
	return 0;
}

//#include <iostream>
//using namespace std;
//class BaseClass{
//public:BaseClass(){ cout << "[Base] 생성자\n\n"; }
//	   virtual ~BaseClass(){ cout << "[Base]소멸자\n\n"; }
//};
//class DerivedClass : public BaseClass
//{
//public:DerivedClass(){ cout << "[Derived] 생성자\n\n"; }
//	   ~DerivedClass(){ cout << "[Derived]소멸자\n\n"; }
//};
//
//int main()
//{
//	BaseClass *base = new DerivedClass;
//	delete base;
//
//	DerivedClass ob;
//
//	return 0;
//}