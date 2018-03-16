// struct默认公有,class默认私有
// string 连接 a = a + b执行效率没有 a += b高!!!

class Window_mgr
{
	public:
		// 窗口中每个屏幕的编号
		typedef std::vector<Screen>::size_type ScreenIndex;
		// 按照编号将指定的Screen重置为空白
		void clear(ScreenIndex);
		
	private:
		// default情况下,一个Window_mgr包含一个标准尺寸的空白Screen
	std::vector<Screen> screens {Screen(24, 80, ' ')};
};

void Window_mgr::clear(ScreenIndex i)
{
	// s是一个Screen的引用,指向我们想清空的那个屏幕
	Screen &s = screens[i];
	// 将按个选定的Screen重置为空白
	s.contents = string(s.height * s.width, '');
}
