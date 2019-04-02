/*
**author:王星洲_1652977
**theme:数据结构课程设计_T1
**question:考试报名系统
**application:链表list
*/
#include "list.h"

int main()
{
	int number = 0;
	int order;
	MyList Students;
	cout << "首先请建立考生信息系统！" << endl;
	cout << "请输入考生人数：";
	while (1)
	{
		if (!(cin >> number))
		{
			cout << "输入非法，请重新输入" << endl;
			cin.clear();
			while (cin.get() != '\n')
			{
				continue;
			}
		}
		else
		{
			if (number < 0)
			{
				cout << "请输入一个非负整数" << endl;
			}
			else
			{
				break;
			}
		}
	}
	Students.InitList(number);
	Students.PrintList();
	cout << "请选择您要进行的操作（1为插入，2为删除，3为查找，4为修改，5为统计，0为取消操作）" << endl;
	cout << endl;
	while (1)
	{
		cout << "请选择您要进行的操作：";
		if (!(cin >> order))
		{
			cout << "输入非法，请重新输入" << endl;
			cin.clear();
			while (cin.get() != '\n')
			{
				continue;
			}
			continue;
		}
		else
		{
			switch (order)
			{
			case 1:
			{
				int position = 0;
				string ID, name, sex, cate;
				int age;
				cout << "请输入你要插入的考生的位置：";
				while (!(cin >> position))
				{
					cout << "输入有误，请重新输入。" << endl;
					cin.clear();
					while (cin.get() != '\n')
					{
						continue;
					}
				}
				while(position <= 0 || position > Students.m_length + 1)
				{
					cout << "您输入的位置超出范围，请重新输入" << endl;
					cin.clear();
					while (cin.get() != '\n')
					{
						continue;
					}
					cin >> position;
				}
				cout << "请输入考生的考号，姓名，性别，年龄及报考类别！" << endl;
				cin >> ID >> name >> sex >> age >> cate;
				if (Students.ListInsert(position, ID, name, sex, age, cate))
				{
					cout << "插入成功" << endl;
					Students.PrintList();
				}
				else
				{
					cout << "插入失败，请检查输入并重试" << endl;
				}
				break;
			}
			case 2:
			{
				string ID;
				cout << "请输入您要删除的考生的考号：";
				cin >> ID;
				if (Students.ListDelete(ID))
				{
					cout << "删除成功" << endl;
					Students.PrintList();
				}
				else
				{
					cout << "删除失败，请检查输入并重试" << endl;
				}
				break;
			}
			case 3:
			{
				string ID;
				cout << "请输入您要查找的考生的考号：";
				cin >> ID;
				LNode *p = Students.LocateElemByID(ID);
				if (p != Students.head)
				{
					p->print();
				}
				else
				{
					cout << "您查找的考生并不存在" << endl;
				}
				break;
			}
			case 4:
			{
				string ID;
				cout << "请输入您要更改的考生的考号：";
				cin >> ID;
				LNode *p = Students.LocateElemByID(ID);
				if (p != Students.head)
				{
					p->Update();
				}
				else
				{
					cout << "您查找的考生并不存在" << endl;
				}
				break;
			}
			case 5:
			{
				Students.PrintList();
				break;
			}
			case 0:
			{
				cout << "退出系统成功！欢迎下次使用" << endl;
				system("pause");
				return 0;
			}
			default:
				cout << "您输入的数值有误，请重新输入" << endl;
				break;
			}
		}
	}
	system("pause");
	return 0;
}