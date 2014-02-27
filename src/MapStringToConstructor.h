#include <string>
#include <memory>

using namespace std;

class Super{
public:

	virtual void f(){cout<<"s"<<endl;}
	virtual ~Super(){}
}

;


class Child1:public Super{
public:
	void f(){cout<<"ch1"<<endl;}
	virtual ~Child1(){}

};

class Child2: public Super{
public:
	void f(){cout<<"ch2"<<endl;}
	virtual ~Child2(){}
};


class Factory{
public:
	unique_ptr<Super> create(string className){
		if (className=="c1")
			return unique_ptr<Child1>(new Child1());
		if (className=="c2")
			return unique_ptr<Child2>(new Child2());
		//return NULL;
	}
};
