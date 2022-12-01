#include<iostream>
using namespace std;

class A {
  int i;
public:
  A(int ii) : i(ii) { cout << "a.constructor called" << endl;}
  ~A() { cout << "a.destructor called" << endl;}
  void f() const {}
};

class B {
  int i;
public:
  B(int ii) : i(ii) { cout << "b.constructor called" << endl;}
  ~B() { cout << "b.Destructor called " << endl;}
  void f() const {}
};


class C : public B 
{
  A a;
public:
  C(int ii) : B(ii), a(ii) {cout << "c.constructor called" << endl;}
  ~C() {cout << "c.destructor called" << endl;}
  void f() const {  
    a.f();
    B::f();
  }
};



int main() {
	
  C c(47);
  
  
  return 0;
}
