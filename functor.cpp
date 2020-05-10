#include <iostream>

//关键在于重载()运算符
class MyFunctor
{
public:
    void operator()(){
        std::cout << "call function(void)" << std::endl;
    }
    void operator()(int x, int y){
        std::cout << "call function(int,int) with " << x << " " << y << std::endl;
    }
};

int main()
{
    MyFunctor func;
    std::cout << "hello " << std::endl;
    func();
    func(1, 2);
    return 0;
}