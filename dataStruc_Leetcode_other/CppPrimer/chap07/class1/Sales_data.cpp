// 定义Sales_data类中的函数

#include <iostream>
#include "Sales_data.h"

using namespace std;

Sales_data& Sales_data::combine(const Sales_data &rhs)
{
	units_sold	+=	rhs.units_sold; // 把rhs的成员加到this对象的成员上
	revenue		+=	rhs.revenue;	
	return *this; 					// 返回调用该函数的对象
}

// 输入的交易信息包括ISBN、售出总数和售出价格
istream& read(istream &is, Sales_data &item)
{
	double price	= 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue	= price * item.units_sold;
	return is;
}

// 这里Sales_data前面要加const限制,因为只是读取信息输出,不能改变
ostream& print(ostream &os, const Sales_data &item)
{
	os << item.isbn() << " " << item.units_sold << " "
		<< item.revenue << " " << item.arg_price();
	return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data sum = lhs;// 把lhs的数据拷贝给sum
	sum.combine(rhs);	 // 把rhs的数据加到sum中
	return sum;
}
