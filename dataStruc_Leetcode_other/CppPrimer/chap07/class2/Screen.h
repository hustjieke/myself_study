// 1. string的size_type来源于allocator< charT >或者make_unsigned< difference_type >，两者均是无符号整形（不仅是unsigned int，而是包括
// unsigned long、unsigned long long等整个整形类别），其最大值及最小值可通过std::numeric_limits<  std::string::size_type >::max(  )和
// std::numeric_limits< std::string::size_type >::min( )获得。
// 2. 定义在类内部的成员函数是自动内联的,内联函数应该定义在头文件中,因为内联函数编译时需要直接插入到函数代码中,所以只能是static的，每个
// 编译模块(cpp源文件)中必须包含其定义代码(不是声明)，所以"内联函数有可能在程序中不止定义一次"就是指在每个调用Inline函数的源文件中都要有
// inline的定义,需要时include就可以了
// 3. 在用下标访问元素时，vector使用vector::size_type作为下标类型，而数组下标的正确类型则是size_t。vector使用的
// 下标实际也是size_t，源码是typedef size_t size_type
// 4. 类还可以把其他的类定义成友元,也可以把其他类的成员函数定义成友元。此外,友元函数能定义在类内部,这样的函数是隐式内联的
class Screen
{
	public:
		typedef std::string::size_type pos;

		Screen() {}; // C++11标准支持 = default,隐式内联函数,让系统生成合成的构造函数
		//cursor 由于存在雷内初始值,否则像其他成员一样显示地初始化cursor
		Screen(pos ht, pos wd, char c): height(ht), width(wd), contents(ht * wd) { }

		Screen &set(char);
		Screen &set(pos, pos, char);

		char get() const
		{ return contents(cursor); } // 隐式内联,获得光标处的内容
		inline char get(pos ht, pos wd) const; // 显示声明
		Screen &move(pos r, pos c);

		void some_member() const; // 用于演示const函数里面的可变数据成员也可以被修改

		Screen &display(std::ostream &os) 
		{ do_display(os); return *this; }
		
		const Screen &display(std::ostream &os) const
		{ do_display(os); return *this; } // 重载,根据对象是否常量调用响应的函数来显示Screen内容
		

		friend class Window_mgr; // 友元类
		
	private:
		pos	cursor		= 0;
		pos height		= 0,	width	= 0;
		std::string		contents;
		mutable size_t access_ctr; // 即使在一个const对象也能改变,可变的成员变量

		// 之所以对这个操作单独定义一个函数,有很多原因,详情见P248下面建议部分
		void do_display(std::ostream &os) const { os << contents; }// 显示屏幕内容
};

inline
Screen &Screen::move(pos r, pos c)
{
	pos row	= r * width; // 计算行的位置,列是column
	cursor	= row + c; // 在行内将光标移动到指定的列
	return *this; // 以左值的形式返回
}

inline
Screen &Screen::set(char c)
{
	contents[cursor] = c;
	return *this;
}

inline
Screen &Screen::set(pos r, pos col, char ch)
{
	contents[r * width + col] = ch; // 设置给定位置的新值
	return *this; // 把this对象作为左值返回
} // 比如调用：myScreen.move(4, 0).set('#');
// 相当于myScreen.move(4, 0);  myScreen.set('#');

char Screen::get(pos ht, pos wd) const  // 在类的内部声明成inline
{
	pos row = ht * width; // 计算行的位置
	return contents[row + wd]; // 返回给定列的字符
}

void Screen::some_member() const
{
	++access_ctr; // 保存一个数值,用于记录成员函数被调用的次数
	 //该成员需要完成的其他操作....
}


// 调用示例
// Screen myScreen(5, 3);
// const Screen blank(5, 3);
// myScreen.set('#').display(cout);//调用非常累版本
// blank.display(cout);//调用常量版本
