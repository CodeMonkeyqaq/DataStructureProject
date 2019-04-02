/*
**author:王星洲_1652977
**theme:数据结构课程设计_T7
**question:修理牧场
**application:霍夫曼树
*/

#include <iostream>

//为了使用greater模板
#include <functional>
#include <queue>
using namespace std;

int main()
{
	//定义优先级队列，greater<int>表示小顶
	priority_queue<int, vector<int>, greater<int> > q;
	//N姐搜用户输入的数量，length接收输入的长度
	int N, length;
	//对于N的输入
	while (1)
	{
		//N输入失败
		if (!(cin >> N))
		{
			cout << "输入非法，请重新输入。" << endl;
			cin.clear();
			while (cin.get() != '\n')
			{
				continue;
			}
			continue;
		}
		//N不是正整数
		else if (N <= 0)
		{
			cout << "请输入一个正整数。" << endl;
			cin.clear();
			while (cin.get() != '\n')
			{
				continue;
			}
			continue;
		}
		//N输入正确
		else
		{
			break;
		}
	}
	//接收length
	for (int i = 0; i < N; i++)
	{
		//length输入失败
		while (!(cin >> length))
		{
			cout << "输入非法，已知您要输入" << N << "个长度，请重新输入。" << endl;
			cin.clear();
			while (cin.get() != '\n')
			{
				continue;
			}
			//清空q队列
			while (!q.empty())
			{
				q.pop();
			}
			//i置回0
			i = 0;
		}
		if (length <= 0)
		{
			cout << "长度必须为正整数，已知您要输入" << N << "个长度，请重新输入。" << endl;
			cin.clear();
			while (cin.get() != '\n')
			{
				continue;
			}
			//清空q队列
			while (!q.empty())
			{
				q.pop();
			}
			//将i置为-1，再次进入循环时i变回0
			i = -1;
		}
		else
		{
			//输入正确，将length加入q队列
			q.push(length);
		}
	}
	//结果
	int sum = 0;
	//当q的元素个数大于1
	while (q.size() > 1) {
		//取出q中最小的两个值与sum相加作为sum，把结果加入队列，再将这两个值移出队列
		int first = q.top();
		q.pop();

		int second = q.top();
		q.pop();

		sum += first + second;
		q.push(first + second);
	}
	//输出sum
	cout << sum << endl;

	system("pause");
	return 0;
}