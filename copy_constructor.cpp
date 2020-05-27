#include <iostream>
#include <cstring>

class Test
{
public:
    static int id;
    int sid;
public:
    Test(){id++;sid = id;std::cout << sid << __FUNCTION__ << std::endl;}
    ~Test(){std::cout << sid << __FUNCTION__ << std::endl;}
    Test(const Test& rhs){id++; sid = id; std::cout << sid << "copy "<<__FUNCTION__ << std::endl;}
    //Test& operator=(const Test& rhs){};
};

int Test::id = 0;

void useTest(Test test)//调用复制构造函数
{
    std::cout << __FUNCTION__ << std::endl;
}

Test returnTest()
{
    std::cout << __FUNCTION__ << std::endl;
    Test test;//调用构造函数,returnTest返回后将会析构该对象
    return test;//调用复制构造函数构造一个中间对象，如果returnTest的返回不是用来构造Test对象，那么returnTest返回后将会析构该中间对象
}

int main(void)
{
    Test test1;//调用构造函数
    Test test2 = test1;//调用复制构造函数
    useTest(test2);
    returnTest();
    Test test3 = returnTest();
    Test test4;
    test4 = returnTest();
    return 0;
}