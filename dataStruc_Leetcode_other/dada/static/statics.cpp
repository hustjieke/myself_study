// 用static成员统计对象的个数,静态成员函数只能访问静态成员
// 
#include <iostream>

using namespace std;

class Cat {
	public:
		Cat(int age):itsAge(age) { HowManyCats++; }
		virtual ~Cat() { HowManyCats--; }
		virtual int GetAge() { return itsAge; }
		virtual void setAge(int age) { itsAge = age; }
		static int HowManyCats;
        static void TelepathicFunction();

	private:
		int itsAge;
};

int Cat::HowManyCats = 0; // 初始化一般都是在类外面，跟全局变量一样
//void TelepathicFunction();
int main()
{
	const int MaxCats = 5; 
	int i;
	Cat *CatHouse[MaxCats]; // 对象指针数组

	for (i = 0; i < MaxCats; i++)
	{
		CatHouse[i] = new Cat(i); // 执行构造函数++并初始化
		CatHouse[i]->TelepathicFunction();
	}

	for (i = 0; i < MaxCats; i++)
	{
		delete CatHouse[i]; // 删除对象指针指向的对象
		CatHouse[i]->TelepathicFunction();
	}

	return 0;
}
void Cat::TelepathicFunction()
{
	cout << "There are: ";
	cout << Cat::HowManyCats << "cats alive!\n"; // 用静态成员最好用::成员而不是用对象.成员来调用成员
}
