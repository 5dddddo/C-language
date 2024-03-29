#include<iostream>
using namespace std;

class Base{
private:
	int a;
public:
	Base(int n=10) { a=n;}  // 생성자
	void view() { cout << "Base(" << a << ')' << endl; } // 출력 멤버함수
};

class BaseA :  public Base {
public:
	BaseA() : Base(20) {cout << "BaseA생성자 수행중" << endl; } 
};

class BaseB : public Base {
public:
	BaseB() : Base(30) {cout << "BaseB생성자 수행중" << endl; }  
};

class Derived : public BaseA, public BaseB 
{
public : 
	Derived() : BaseA(), BaseB()
	{cout << "Derived 생성자 수행중" << endl;  }
	void view()
	{
		BaseA::view();
		BaseB::view();
	}
};  // 다중상속

int main()
{
	Derived d;

	d.view();
	return 0;
}
