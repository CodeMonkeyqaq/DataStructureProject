/*
**author:王星洲_1652977
**theme:数据结构课程设计_T5
**question:银行业务
**application:队列
*/

#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
	//创建两个队列
	queue<int> qA;
	queue<int> qB;
	//接收用户的输入
	int N, number;
	//N的处理
	while(1)
	{
		//输入非法
		if (!(cin >> N))
		{
			cout << "输入失败，请重新输入。" << endl;
			cin.clear();
			while (cin.get() != '\n')
			{
				continue;
			}
		}
		//输入负数或0
		else if (N <= 0)
		{
			cout << "请输入正整数。" << endl;
			cin.clear();
			while (cin.get() != '\n')
			{
				continue;
			}
		}
		//输入的值超过题目要求
		else if (N > 1000)
		{
			cout << "请输入不超过1000个数。" << endl;
			cin.clear();
			while (cin.get() != '\n')
			{
				continue;
			}
		}
		//输入正确
		else
		{
			break;
		}
	}
	
	//对于number的处理
	for (int i = 0; i < N; i++)
	{
		//输入非法
		while(!(cin >> number))
		{
			cout << "输入失败，已经知道您要输入" << N << "个顾客的编号，请重新输入编号。" << endl;
			cin.clear();
			while (cin.get() != '\n')
			{
				continue;
			}
			while (!qA.empty())
			{
				qA.pop();
			}
			while (!qB.empty())
			{
				qB.pop();
			}
			i = 0;
		}
		//奇数，加入A队列
		if (number % 2 != 0)
		{
			qA.push(number);
		}
		//偶数，加入B队列
		else
		{
			qB.push(number);
		}
	}


	//当A或者B不为空时，进入循环
	while (!qA.empty() || !qB.empty())
	{
		//如果队列A空，则将B按序全部输出
		if (qA.empty())
		{
			cout << qB.front() << " ";
			qB.pop();
		}
		//如果队列B空，则将A按序输出
		else if (qB.empty())
		{
			cout << qA.front() << " ";
			qA.pop();
		}
		//两者都不为空时
		else
		{
			//输出A的第一个
			cout << qA.front() << " ";
			//将该值移出队列
			qA.pop();
			//如果此时A已经空，则返回循环起始
			if (qA.empty())
			{
				continue;
			}
			//若A仍不为空，则再输出一个A然后输出B
			else
			{
				cout << qA.front() << " ";
				qA.pop();
				cout << qB.front() << " ";
				qB.pop();
			}
		}
	}
	//消去最后的空格
	cout << "\b";
	cout << endl;
	system("pause");
	return 0;
}