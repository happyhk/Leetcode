#include <iostream>
using namespace std;

class Product {
public:
    virtual int operation(int a, int b)= 0;
};

class Product_Add : public Product {
public:
    int operation(int a, int b){
        return a+b;
    }
}; 

class Product_Mul : public Product {
public:
    int operation(int a, int b){
        return a*b;
    }
};

class Factory {
    Product* create() = 0;
};

class Factory_add : public Factory {
public:
    Product* create(){
        return new Product_Add;
        
    }
};

class Factory_mul : public Factory {
public:
    Product* create() {
        return new Product_Mul;
    }
};

int main()
{
    Factory_add *factory_add = new Factory_add;
    Factory_mul *factory_mul = new Factory_mul;
    int add = factory_add->create()->operation(1,2);
    int mul = factory_mul->create()->operation(1,2);
    cout<<"add: "<<add<<endl;
    cout<<"mul: "<<mul<<endl;
    return 0;
}


















