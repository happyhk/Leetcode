
#include<iostream>
using namespace std;

//抽象工厂模式
class Product_P{
public:
	virtual int operation(int a, int b) = 0;
};

class Product_Padd : public Product_P{
public:
	int operation(int a, int b){
		return abs(a) + abs(b);
	}
};

class Product_Pmul : public Product_P{
public:
	int operation(int a, int b){
		return abs(a) * abs(b);
		
	}
};

class Product_F{
public:
	virtual int operation(int a, int b) = 0;
};

class Product_Fadd : public Product_F{
public:
	int operation(int a, int b){
		return (-a) + (-b);
	}
};
class Product_Fmul : public Product_F{
public:
	int operation(int a, int b){
		return -(a*b);
	}
};

class Factory{
public:
	virtual Product_P* Create_P() = 0;
	virtual Product_F* Create_F() = 0;
};


class Factory_Add : public Factory{
public:
	  Product_Padd* Create_P(){
		return new Product_Padd;
	}
	Product_Fadd*  Create_F(){
		return new Product_Fadd;
	}
};

class Factory_Mul : public Factory{
public:
	Product_Pmul* Create_P(){
		return new Product_Pmul;
	}
	Product_Fmul* Create_F(){
		return new Product_Fmul;
	}
};

int main()
{
	Factory_Add *factory_add = new Factory_Add();
	Factory_Mul *factory_mul = new Factory_Mul();
	int p_add_result = factory_add->Create_P()->operation(1, 2);
	int p_mul_result = factory_mul->Create_P()->operation(1, 2);
	int f_add_result = factory_add->Create_F()->operation(1, 2);
	int f_mul_result = factory_mul->Create_F()->operation(1, 2);
	cout << "op_p_add：" << p_add_result << endl;
	cout << "op_p_multiply：" << p_mul_result << endl;
	cout << "op_f_add：" << f_add_result << endl;
	cout << "op_f_multiply：" << f_mul_result << endl;
	getchar();
	return 0;
}
