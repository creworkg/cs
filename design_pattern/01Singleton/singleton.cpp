#include <iostream>

//using namespace std;

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

Singleton * Singleton::sm_instance = nullptr;

int main()
{
    auto a = Singleton::GetSingleton();
    auto b = Singleton::GetSingleton();

    if (a == b) {
        std::cout <<"same" << std::endl;
    }
}