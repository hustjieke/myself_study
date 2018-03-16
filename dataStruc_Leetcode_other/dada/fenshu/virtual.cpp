// 展示类里面string类型默认占用4个字节（里面其实就是指针），虚函数占用4个字节，在内存中单独有个虚函数表来维护
// 用虚函数来实现多态是有代价的，不止4个字节。有虚函数的类编译器在处理的时候会申请一块内存空间里面放上所有的虚函数的地址
// 叫虚函数表,而且每个对象里面都会保存一个那个表的地址，每个对象里面都会有一个指向虚函数表的指针就，因此都会增加4个字节，
// 不管有多少个虚函数，都只需要4个字节，因为虚函数表只有一个

#include <iostream>

using namespace std;

class Animal{
	public:
		virtual void eat(){
			cout << "动物吃食物" << endl;
		}//保存在虚函数表中，4字节,为什么实际占用8个字节？编译器自动获得,我们不用关心怎么获取

		virtual void sleep(){
			cout << "动物休息" << endl;
		}//保存在虚函数表中，4字节,类只保存一个虚函数表指针，因此多了4个字节,为什么运行占用8个字节？

		virtual void shout(){
			cout << "动物叫" << endl;
		}
		
	private:
		string name; //在内存占用默认4个字节
};


class Cat : public Animal{
	public:
		// 父类写了virtual，子类写不写都可以,但是父类必须写，这里实际测试是这样的
		virtual void eat(){
			cout << "猫吃猫粮" << endl;
		}

		void sleep(){
			cout << "猫在睡觉zzZ" << endl;
		}

		virtual void shout(){
			cout << "猫喵喵叫" << endl;
		}
};


class Dog : public Animal{
	public:
		void eat(){
			cout << "狗吃骨头" << endl;
		}

		void sleep(){
			cout << "狗在睡觉" << endl;
		}

		virtual void shout() {
			cout << "狗在汪汪叫" << endl;
		}
};


class Jiafeimao : public Animal{
	public:
		void eat(){
			cout << "加菲猫吃沙拉" << endl;
		}
		void sleep(){
			cout << "加菲猫躺着睡觉" << endl;
		}
		virtual void shout(){
			cout << "加菲猫不会叫" << endl;
		}
};

class Player{
	private:
		string name;
		
	public:
		Player(string n):name(n){}

		void play(Animal *p){
			p->eat();
			p->sleep();
			p->shout();
		}//传指针

		void play(Animal &p){
			p.eat();
			p.sleep();
			p.shout();
		}//传引用
};

int main()
{
	int num = 100;
	int *point = &num;

	string name_t;

	cout << "*p: " << sizeof(point) << endl;
	cout << "string 默认大小: " << sizeof(name_t) << endl;
	cout << "类大小: " << sizeof(Animal) << endl;

	Cat c;
	Dog d;
	Jiafeimao j;

	Player p1("高");
	Player p2("赵");
	Player p3("陈");

	p1.play(&c);//改成引用也一样的结果
	p2.play(&d);
	p3.play(&j);

	cout << "引用形式" << endl;
	 
	p1.play(c);//改成引用也一样的结果
	p2.play(d);
	p3.play(j);

	return 0;
}
