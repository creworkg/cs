#include <iostream>
#include <memory>

class Operation
{
public:
    virtual ~Operation() = default;
    virtual double getResult(double optA, double optB) const= 0;
};

class Operation_add : public Operation
{
    virtual double getResult(double optA, double optB) const override
    {
        return optA + optB;
    }
};

class Operation_sub : public Operation
{
    virtual double getResult(double optA, double optB) const override
    {
        return optA - optB;
    }
};

class Operation_multi : public Operation
{
    virtual double getResult(double optA, double optB) const override
    {
        return optA * optB;
    }
};

class Operation_div : public Operation
{
    virtual double getResult(double optA, double optB) const override
    {
        return optA / optB;
    }
};

std::unique_ptr<Operation> getOperation(char opt_symbol)
{
    // std::unique_ptr<Operation> OperationBase;

    // switch (opt_symbol)
    // {
    //     case '+':
    //     {
    //         OperationBase = std::make_unique<Operation_add> ();
    //         break;
    //     }
    //     case '-':
    //     {
    //         OperationBase = std::make_unique<Operation_sub> ();
    //         break;
    //     }
    //     case '*':
    //     {
    //         OperationBase = std::make_unique<Operation_multi> ();
    //         break;
    //     }
    //     case '/':
    //     {
    //         OperationBase = std::make_unique<Operation_div> ();
    //         break;
    //     }
    //     default:
    //     {
    //         break;
    //     }
    // }
    // return OperationBase;


    switch (opt_symbol)
    {
        case '+':
        {
            return std::make_unique<Operation_add> ();
        }
        case '-':
        {
            return std::make_unique<Operation_sub> ();
        }
        case '*':
        {
            return std::make_unique<Operation_multi> ();
        }
        case '/':
        {
            return std::make_unique<Operation_div> ();
        }
        default:
        {
            return nullptr;
        }
    }
}


int main()
{
    double oA, oB;
    char oSymbol;

    while (true){
        std::cout << "input num A:";
        std::cin >> oA;
        std::cout << "input num B:";
        std::cin >> oB;
        std::cout <<"input operation symbol:";
        std::cin >> oSymbol;

        auto op = getOperation(oSymbol);
        if (op)
        {
            /* code */
            std::cout<< op->getResult(oA, oB);
        }
        
    }
    
}