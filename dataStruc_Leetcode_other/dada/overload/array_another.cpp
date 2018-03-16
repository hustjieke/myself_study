// 动态数组,这里跟视频演示的不一样，11集1小时1分地方，运行的时候明显出错，不会出现他那样的还能看修改后的情况
// 默认拷贝是浅拷贝，根据不同的情形设置不同的拷贝函数叫深拷贝

#include <iostream>

using namespace std;

class Array {
	private:
		char *p;
		int len;

	public:
		// 构造函数
		Array(int n) : len(n), p(new char[n]) {
		}

		Array(const Array& o):len(o.len) {
			p = new char[len];

			for (int i = 0; i < len; i++) {
				p[i] = o.p[i];
			}
		}

		// 返回大小
		int size() {
			return len;
		}

		// 跳跃填值
		void fill(char start, int skip) {
			for (int i = 0; i < len; i++) {
				p[i] = start + i * skip;
			}
		}

		void show() {
			for (int i = 0; i < len; i++) {
				cout << p[i];
			}
			cout << endl;
		}

		// 释放资源
		~Array() {
				delete[] p;
		}
};

int main()
{
	Array a1(10);

	a1.fill('a', 1);
	a1.show();

	Array a2(a1);
	a2.fill('A', 1);
	a2.show();
	a1.show();

	return 0;
}
