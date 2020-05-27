#include <iostream>
#include <string>
using namespace std;

//构造函数执行顺序
//一、先执行静态成员的构造函数，如果静态成员只是在类定义中声明了，而没有实现，是不用构造的。必须初始化后才执行其构造函数。

//二、任何虚拟基类的构造函数按照它们被继承的顺序构造（不是初始化列表中的顺序）

//三、任何非虚拟基类的构造函数按照它们被继承的顺序构造（不是初始化列表中的顺序）

//四、任何成员对象的构造函数按照它们声明的顺序构造

//五、类自己的构造函数

 
//抽象类A
class A
{
public:
	A() {cout<<__FUNCTION__<<endl;}
	//纯虚函数fun
	virtual void fun1() = 0;
};
 
//抽象类B
class B
{
public:
	B(){cout<<__FUNCTION__<<endl;}
	//纯虚函数fun
	virtual void fun2() = 0;
};
 
//普通类C
class C
{
public:
	C(){cout<<__FUNCTION__<<endl;}
};
 
//普通类D
class D
{
public:
	D(){cout<<__FUNCTION__<<endl;}
};
 
//普通类C
class E
{
public:
	E(){cout<<__FUNCTION__<<endl;}
};
 
//普通类D
class F
{
public:
	F(){cout<<__FUNCTION__<<endl;}
};
 
//普通类D
class G
{
public:
	G(){cout<<__FUNCTION__<<endl;}
};
 
//普通类D
class H
{
public:
	H(){cout<<__FUNCTION__<<endl;}
};
//普通类D
class M
{
public:
	M(){cout<<__FUNCTION__<<endl;}
};
 
class Test: public E,public F,public A,public B,virtual public C,virtual public D
{
public:
	Test():B(),A(),D(),C(),F(),E(){cout<<__FUNCTION__<<endl;}
	void fun1(){}
	void fun2(){}
private:
	G g;
	static H h;
	static M m;
};
 
H Test::h;
 
int main(int argc, char* argv[])
{
	Test test;
	return EXIT_SUCCESS;
}