#include <iostream>

//using namespace std;

/*
    1.某个类只能有一个实例
    2.它必须自己创建这个实例
    3.它必须向整个系统提供这个实例
*/
class Singleton
{
public:
    static Singleton * GetSingleton()
    {
        if (sm_instance == nullptr)
        {
            sm_instance = new Singleton();
        }
        return sm_instance;
    }
private:
    Singleton() = default;
    static Singleton * sm_instance;
};

//init sm_instance as nullptr
Singleton * Singleton::sm_instance = nullptr;

int main()
{
    auto a = Singleton::GetSingleton();
    auto b = Singleton::GetSingleton();

    if (a == b) {
        std::cout <<"same" << std::endl;
    }
}