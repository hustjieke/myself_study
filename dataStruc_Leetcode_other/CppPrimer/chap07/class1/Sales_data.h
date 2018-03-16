#ifndef SALES_DATA_H_
#define SALES_DATA_H_

#include <iostream>
#include <string>

using namespace std;

// 统一编程风格,若类的所有成员都是public时,使用struct,反之,若希望成员是private,则使用class
class Sales_data
{ 
	public:
		Sales_data(){} // C++11标准可以用 = default;表示要求编译器来生成默认构造函数,在类内部这个函数就是内联的
		Sales_data(const std::string &s): bookNo(s) { }//其他的没有没有传递参数的则使用默认初始化
		Sales_data(const std::string &s, unsigned n, double p)
			: bookNo(s), units_sold(n), revenue(p * n) { }//上面这些函数函数体都是空的,因为只执行数据成员赋值
		Sales_data(std::istream &);
		// 返回的其实是对象的成员,对象的地址传给隐式this指针,return this->bookNo或者obj.bookNo,伪代码：
		// Sales_data::isbn(&total)(只是用于说明函数的实际执行过程),当调用这个成员函数时,用请求该函数的对象的地址来初始化
		// 这也意味着this是一个常量指针(常量必须定义的时候初始化,一经定义不再改变的特性),类型:Sales_data *const this
		string isbn() const { return bookNo; }

		Sales_data& 	combine (const Sales_data&);  // 模仿操作符'+=',当然现在还没接触到重载
	private:
		double 			arg_price() const; // 伪代码:arg_price(const Sales_data *const this),这么用叫const member funciton
		// 解决了不能在一个常量对象上调用普通成员函数的问题,因为this常量指定特性不能绑定到一个常量对象上,这也const对象可以
		// 调用,非const对象也可以调用(本身非const对象就可以调用),注意常量函数就不能修改对象了

		// 数据成员
		string			bookNo;
		unsigned 		units_sold;
		double 			revenue;

		// 友元只是指定了访问权限,若要类的用户能调用某个函数,需要在类的外面再专门对函数进行一次友元声明
		friend Sales_data add(const Sales_data&, const Sales_data&);
		friend std::ostream& print(std::ostream&, const Sales_data&);
		friend std::istream& read(std::istream&, Sales_data&);
};


// Sales_data 的非成员接口函数
Sales_data add(const Sales_data&, const Sales_data&);
std::ostream& print(std::ostream&, const Sales_data&);
std::istream& read(std::istream&, Sales_data&);

#endif
