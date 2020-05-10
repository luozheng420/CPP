#include <iostream>
#include <functional>

//普通函数
void comFunc()
{
    std::cout << __FUNCTION__ << std::endl;
}

//仿函数
class MyFunctor
{
public:
    void operator()(int val) {
        std::cout << __FUNCTION__ << " " << val << std::endl;
    }
};

//类成员函数
class MyClass
{
public:
    static void staticPrint() {
        std::cout << __FUNCTION__ << std::endl;
    }
    void Print(){
        std::cout << __FUNCTION__ << std::endl;
    }
    void PrintWith(int val) {
        std::cout << __FUNCTION__ << " " << val << std::endl;
    }
};

int main()
{
    //指向普通函数
    std::function<void()> funCom = comFunc;
    funCom();
    //指向lambda函数
    std::function<void()> funLambda = [](){std::cout << __FUNCTION__ << std::endl;};
    funLambda();
    //指向仿函数
    std::function<void(int)> funFunctor = MyFunctor();
    funFunctor(11);
    //指向static成员函数
    std::function<void()> funStatic = MyClass::staticPrint;
    funStatic();
    //指向非static成员函数
    std::function<void(MyClass&)> funClass = &MyClass::Print;
    MyClass myobject;
    funClass(myobject);
    //指向带参数的非static成员函数
    std::function<void(int)> funClassExt = std::bind(&MyClass::PrintWith, myobject, std::placeholders::_1);
    funClassExt(1);
    return 0;
}