/*
**author:王星洲_1652977
**theme:数据结构课程设计_T6
**question:家谱管理系统
**application:树的建立查找等
*/
#include <iostream>
#include "tree.h"
using namespace std;

//显示功能菜单
void showMenu()
{
	cout << "**\t\t\t  家族管理系统\t\t\t\t**\n";
	cout << "==================================================================\n";
	cout << "**\t\t\t请选择要执行的操作:\t\t\t**\n";
	cout << "**\t\t\tA --- 完善家谱\t\t\t\t**\n";
	cout << "**\t\t\tB --- 添加家族成员\t\t\t**\n";
	cout << "**\t\t\tC --- 解散局部家庭\t\t\t**\n";
	cout << "**\t\t\tD --- 更改家庭成员姓名\t\t\t**\n";
	cout << "**\t\t\tE --- 显示完整家谱\t\t\t**\n";
	cout << "**\t\t\tF --- 退出程序\t\t\t\t**\n";
	cout << "==================================================================\n";
}

//初始化家谱
Tree& creatFamily()
{
	string name;
	cout << "首先建立一个家谱" << endl;
	cout << "请输入祖先的姓名:";
	cin >> name;
	Tree Family(name);
	cout << "此家谱的祖先是:";
	cout << Family.getRoot();
	cout << endl;
	return Family;
}

//响应a指令建立家庭
void addFamily(Tree& Family)
{
	string name, child_name;
	int number = 0;
	cout << "请输入要建立家庭的人的姓名：";
	cin >> name;
	TreeNode *member = Family.search(name);
	if (member == NULL)
	{
		cout << "没有找到该成员，请检查你的输入" << endl;
		return;
	}
	else
	{
		cout << "请输入" << name << "的儿女人数：";
		while (1)
		{
			if (!(cin >> number))
			{
				cout << "输入非法，请重新输入" << endl;
				cin.clear();
				while (cin.get()!='\n')
				{
					continue;
				}
			}
			else if (number < 0)
			{
				cout << "请输入大于等于0的数" << endl;
				cin.clear();
				while (cin.get() != '\n')
				{
					continue;
				}
			}
			else
			{
				break;
			}
		}
		if (number == 0)
		{
			cout << "该成员没有子女" << endl;
			return;
		}
		else
		{
			cout << "请依次输入" << name << "的儿女的姓名：";
			for (int i = 0; i < number; i++)
			{
				cin >> child_name;
				//添加子结点
				member->AddChild(child_name);
			}
			cout << name << "的第一代子孙是：";
			member->printChild();
		}
	}
}

//响应b指令添加子女
void addChild(Tree& Family)
{
	string name;
	cout << "请输入要添加儿子(或女儿)的人的姓名：";
	cin >> name;
	TreeNode *member = Family.search(name);
	if (member == NULL)
	{
		cout << "没有找到该成员，请检查你的输入" << endl;
		return;
	}
	else
	{
		cout << "请输入" << name << "新添加的儿子(或女儿)的姓名：";
		string child_name;
		cin >> child_name;
		member->AddChild(child_name);
		cout << name << "的第一代子孙是：";
		member->printChild();
	}
}

//响应c指令解散家庭
void deleteFamily(Tree& Family)
{
	string name;
	cout << "请输入要解散家庭的人的姓名：";
	cin >> name;
	TreeNode *member = Family.search(name);
	if (member == NULL)
	{
		cout << "没有找到该成员，请检查你的输入" << endl;
		return;
	}
	else
	{
		cout << "要解散家庭的人是：" << name << endl;
		cout << name << "的第一代子孙是：";
		member->printChild();
		member->deleteChild();
		cout << "解散成功！他的孩子都删除啦。" << endl;
	}
}

//响应d指令更改成员姓名
void updateName(Tree& Family)
{
	string name;
	cout << "请输入要更改姓名的人目前姓名：";
	cin >> name;
	TreeNode *member = Family.search(name);
	if (member == NULL)
	{
		cout << "没有找到该成员，请检查你的输入" << endl;
		return;
	}
	else
	{
		cout << "请输入更改后的姓名：";
		string new_name;
		cin >> new_name;
		member->updateName(new_name);
		cout << name << "已更名为" << new_name << endl;
	}
}

//响应e指令输出所有成员
void printTree(Tree& Family)
{
	cout << "家谱中所有成员为：";
	Family.print();
}

int main()
{
	char order;
	showMenu();
	Tree Family = creatFamily();
	while (1)
	{
		cout << "请选择要执行的操作：";
		cin >> order;
		switch (order)
		{
			//建立家庭
		case 'A':
		case 'a':
			addFamily(Family);
			break;
			//添加子女
		case 'B':
		case 'b':
			addChild(Family);
			break;
			//解散家庭
		case 'C':
		case 'c':
			deleteFamily(Family);
			break;
			//更改成员名字
		case 'D':
		case 'd':
			updateName(Family);
			break;
			//输出所有成员
		case 'E':
		case 'e':
			printTree(Family);
			break;
			//退出程序
		case 'F':
		case 'f':
			cout << "退出系统成功" << endl;
			system("pause");
			return 0;
			//指令有错误
		default:
			cout << "你输入的命令有误，请重新输入" << endl;
			break;
		}
	}
	system("pause");
	return 0;
}