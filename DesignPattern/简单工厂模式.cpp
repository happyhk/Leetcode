//简单工厂模式
#include <iostream>
using namespace std;

//产品的基类
class Product {
  public:
    //基类的纯虚函数
    virtual int operation (int a, int b) = 0;
};
//产品的子类Add

class Product_Add : public Product {
public:
    int operation(int a, int b) {
        return a+b;
    }
};

//产品的子类Mul
class Product_Mul : public Product {
public:
    int operation(int a, int b) {
        return a*b;
    }
};

class Factory {
public:
    Product* Create(int i) {
        switch (i) {
        case 1:
            return new Product_Add;
            break;
        case 2:
            return new Product_Mul;
            break;
        default:
            break;
        }
    }
};

int main()
{
    Factory *factory = new Factory();
    int add_result = factory->Create(1)->operation(1,2);
    int mul_result = factory->Create(2)->operation(1,2);
    cout<<"op_add"<<add_result<<end;
    cout<<"op_mul"<<mul_result<<endl;
    getchar();
    return 0;
}















