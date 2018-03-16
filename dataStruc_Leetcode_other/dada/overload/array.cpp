// 动态数组
//

#include <iostream>

using namespace std;

class Array {
	private:
		char *p;
		int len;

	public:
		// 构造函数
		Array(int n) : len(n), p(NULL) {
			resize(n); // 重置数组
		}

		// 调整数组的长度,正常写在类外面的，这里举例子就不这么规范写
		void resize(int n) {
			char *q = new char[n];
			int min = (n < len ? n : len); // 取小的那一个
			if (p != NULL) {
				for (int i = 0; i < min; i++) {
					q[i] = p[i];
				}
				delete []p;//旧数组删除
				p = q;//指向新数组
				// 下面的for循环写法兼容了两种情况的考虑
				for (int i = min; i < n; i++) {
					p[i] = '\0';
				}
				len = n;
			} else {
				p = q;
			}//if块结束
		}

		// 设置索引处的值
		void set(int index, char value) {
			if (index < 0 || index > len) {
				cout << "ERR: " << index << endl;

				return ; // 处理
			}
			p[index] = value;
		}

		// 获取字符
		char get(int index) {
			if (index < 0 || index > len) {
				cout << "ERR: " << index << endl;

				return '!'; // 处理
			}

			return p[index];
		}

		// 返回大小
		int size() {
			return len;
		}

		// 释放资源
		~Array() {
			if (p != NULL) {
				delete []p;
				p = NULL;
			}
		}
};

int main()
{
	Array a1(100);

	// 不断输入字符,遇到'$'就结束
	cout << "input chars(end by '$')";
	for (int i = 0; ; i++) {
		char ch;
		cin >> ch;
		if (ch == '$') {
			break;
		} else if (i++ < a1.size()) {
			a1.set(i, ch);
		}
	}

	// 循环输出字符
	for (int i = 0; i < a1.size(); i++) {
		cout << a1.get(i);
	}
		cout << endl;

	return 0;
}
