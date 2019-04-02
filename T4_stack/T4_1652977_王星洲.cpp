/*
**author:王星洲_1652977
**theme:数据结构课程设计_T4
**question:表达式转换
**application:后缀表达式
*/

#include<iostream>
#include<string>
#include<map>
#include<stack>
using namespace std;

int main()
{
	string a;          //接收输入
	stack<char>s;
	bool firstPrint = true;    //判断是否需要输出空格
	map<char, int>p;    //为运算符制定优先级
	p['*'] = p['/'] = 1;
	p['('] = p[')'] = 2;
	getline(cin, a);
	for (int i = 0; i < a.length(); i++)  //对于a中每个字符
	{
		if (a[i] == ' ')   //忽略空格
		{
			continue;
		}
		else if ((i<1 || a[i - 1] == '(' || (i>=2 && a[i - 2] == '(') && (a[i - 1] == ' ')) && (a[i] == '+' || a[i] == '-') || a[i] == '.' || a[i] >= '0'&&a[i] <= '9')
		{
			//当该字符是正负号或为小数点或为数字时
			if (!firstPrint)     //如果之前有过输出
			{
				cout << " ";      //输出空格
			}
			firstPrint = false;    //将首次输出置为假
			if (a[i] != '+')        //如果该符号不是正号
			{
				cout << a[i];        //将其输出
			}
			while (a[i + 1] == '.' || a[i + 1] >= '0'&&a[i + 1] <= '9')   //如果该字符下一位是小数点或数字
			{
				i++;     //计数增加
				cout << a[i];      //输出a[i]
			}
		}
		else   //该字符为运算符或括号时
		{
			if (a[i] == ')')     //如果该字符是右括号
			{
				while (s.size()>0 && s.top() != '(')     //栈不空且栈顶不是左括号时循环输出
				{
					cout << " " << s.top();            //输出栈顶
					s.pop();                           //删除栈顶
				}
				s.pop();                      //删除左括号
			}
			else if (s.size() == 0 || p[a[i]]>p[s.top()])     //不是右括号而栈空或者优先级大于栈顶时
			{
				s.push(a[i]);     //将该字符进栈
			}
			else
			{
				while (s.size()>0 && s.top() != '(')        //其他情况下，栈不空，栈顶不为左括号时，循环输出
				{
					cout << " " << s.top();             //输出栈顶
					s.pop();                           //删除栈顶
				}
				s.push(a[i]);                         //并将该字符进栈
			}
		}
	}
	while (s.size())                                 //最后顺序输出并清空栈
	{
		cout << " " << s.top();
		s.pop();
	}
	cout << endl;
	system("pause");
	return 0;
}