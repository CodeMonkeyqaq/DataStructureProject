/*
**author:������_1652977
**theme:���ݽṹ�γ����_T4
**question:���ʽת��
**application:��׺���ʽ
*/

#include<iostream>
#include<string>
#include<map>
#include<stack>
using namespace std;

int main()
{
	string a;          //��������
	stack<char>s;
	bool firstPrint = true;    //�ж��Ƿ���Ҫ����ո�
	map<char, int>p;    //Ϊ������ƶ����ȼ�
	p['*'] = p['/'] = 1;
	p['('] = p[')'] = 2;
	getline(cin, a);
	for (int i = 0; i < a.length(); i++)  //����a��ÿ���ַ�
	{
		if (a[i] == ' ')   //���Կո�
		{
			continue;
		}
		else if ((i<1 || a[i - 1] == '(' || (i>=2 && a[i - 2] == '(') && (a[i - 1] == ' ')) && (a[i] == '+' || a[i] == '-') || a[i] == '.' || a[i] >= '0'&&a[i] <= '9')
		{
			//�����ַ��������Ż�ΪС�����Ϊ����ʱ
			if (!firstPrint)     //���֮ǰ�й����
			{
				cout << " ";      //����ո�
			}
			firstPrint = false;    //���״������Ϊ��
			if (a[i] != '+')        //����÷��Ų�������
			{
				cout << a[i];        //�������
			}
			while (a[i + 1] == '.' || a[i + 1] >= '0'&&a[i + 1] <= '9')   //������ַ���һλ��С���������
			{
				i++;     //��������
				cout << a[i];      //���a[i]
			}
		}
		else   //���ַ�Ϊ�����������ʱ
		{
			if (a[i] == ')')     //������ַ���������
			{
				while (s.size()>0 && s.top() != '(')     //ջ������ջ������������ʱѭ�����
				{
					cout << " " << s.top();            //���ջ��
					s.pop();                           //ɾ��ջ��
				}
				s.pop();                      //ɾ��������
			}
			else if (s.size() == 0 || p[a[i]]>p[s.top()])     //���������Ŷ�ջ�ջ������ȼ�����ջ��ʱ
			{
				s.push(a[i]);     //�����ַ���ջ
			}
			else
			{
				while (s.size()>0 && s.top() != '(')        //��������£�ջ���գ�ջ����Ϊ������ʱ��ѭ�����
				{
					cout << " " << s.top();             //���ջ��
					s.pop();                           //ɾ��ջ��
				}
				s.push(a[i]);                         //�������ַ���ջ
			}
		}
	}
	while (s.size())                                 //���˳����������ջ
	{
		cout << " " << s.top();
		s.pop();
	}
	cout << endl;
	system("pause");
	return 0;
}