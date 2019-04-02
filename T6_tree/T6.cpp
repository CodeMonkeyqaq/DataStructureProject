/*
**author:������_1652977
**theme:���ݽṹ�γ����_T6
**question:���׹���ϵͳ
**application:���Ľ������ҵ�
*/
#include <iostream>
#include "tree.h"
using namespace std;

//��ʾ���ܲ˵�
void showMenu()
{
	cout << "**\t\t\t  �������ϵͳ\t\t\t\t**\n";
	cout << "==================================================================\n";
	cout << "**\t\t\t��ѡ��Ҫִ�еĲ���:\t\t\t**\n";
	cout << "**\t\t\tA --- ���Ƽ���\t\t\t\t**\n";
	cout << "**\t\t\tB --- ��Ӽ����Ա\t\t\t**\n";
	cout << "**\t\t\tC --- ��ɢ�ֲ���ͥ\t\t\t**\n";
	cout << "**\t\t\tD --- ���ļ�ͥ��Ա����\t\t\t**\n";
	cout << "**\t\t\tE --- ��ʾ��������\t\t\t**\n";
	cout << "**\t\t\tF --- �˳�����\t\t\t\t**\n";
	cout << "==================================================================\n";
}

//��ʼ������
Tree& creatFamily()
{
	string name;
	cout << "���Ƚ���һ������" << endl;
	cout << "���������ȵ�����:";
	cin >> name;
	Tree Family(name);
	cout << "�˼��׵�������:";
	cout << Family.getRoot();
	cout << endl;
	return Family;
}

//��Ӧaָ�����ͥ
void addFamily(Tree& Family)
{
	string name, child_name;
	int number = 0;
	cout << "������Ҫ������ͥ���˵�������";
	cin >> name;
	TreeNode *member = Family.search(name);
	if (member == NULL)
	{
		cout << "û���ҵ��ó�Ա�������������" << endl;
		return;
	}
	else
	{
		cout << "������" << name << "�Ķ�Ů������";
		while (1)
		{
			if (!(cin >> number))
			{
				cout << "����Ƿ�������������" << endl;
				cin.clear();
				while (cin.get()!='\n')
				{
					continue;
				}
			}
			else if (number < 0)
			{
				cout << "��������ڵ���0����" << endl;
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
			cout << "�ó�Աû����Ů" << endl;
			return;
		}
		else
		{
			cout << "����������" << name << "�Ķ�Ů��������";
			for (int i = 0; i < number; i++)
			{
				cin >> child_name;
				//����ӽ��
				member->AddChild(child_name);
			}
			cout << name << "�ĵ�һ�������ǣ�";
			member->printChild();
		}
	}
}

//��Ӧbָ�������Ů
void addChild(Tree& Family)
{
	string name;
	cout << "������Ҫ��Ӷ���(��Ů��)���˵�������";
	cin >> name;
	TreeNode *member = Family.search(name);
	if (member == NULL)
	{
		cout << "û���ҵ��ó�Ա�������������" << endl;
		return;
	}
	else
	{
		cout << "������" << name << "����ӵĶ���(��Ů��)��������";
		string child_name;
		cin >> child_name;
		member->AddChild(child_name);
		cout << name << "�ĵ�һ�������ǣ�";
		member->printChild();
	}
}

//��Ӧcָ���ɢ��ͥ
void deleteFamily(Tree& Family)
{
	string name;
	cout << "������Ҫ��ɢ��ͥ���˵�������";
	cin >> name;
	TreeNode *member = Family.search(name);
	if (member == NULL)
	{
		cout << "û���ҵ��ó�Ա�������������" << endl;
		return;
	}
	else
	{
		cout << "Ҫ��ɢ��ͥ�����ǣ�" << name << endl;
		cout << name << "�ĵ�һ�������ǣ�";
		member->printChild();
		member->deleteChild();
		cout << "��ɢ�ɹ������ĺ��Ӷ�ɾ������" << endl;
	}
}

//��Ӧdָ����ĳ�Ա����
void updateName(Tree& Family)
{
	string name;
	cout << "������Ҫ������������Ŀǰ������";
	cin >> name;
	TreeNode *member = Family.search(name);
	if (member == NULL)
	{
		cout << "û���ҵ��ó�Ա�������������" << endl;
		return;
	}
	else
	{
		cout << "��������ĺ��������";
		string new_name;
		cin >> new_name;
		member->updateName(new_name);
		cout << name << "�Ѹ���Ϊ" << new_name << endl;
	}
}

//��Ӧeָ��������г�Ա
void printTree(Tree& Family)
{
	cout << "���������г�ԱΪ��";
	Family.print();
}

int main()
{
	char order;
	showMenu();
	Tree Family = creatFamily();
	while (1)
	{
		cout << "��ѡ��Ҫִ�еĲ�����";
		cin >> order;
		switch (order)
		{
			//������ͥ
		case 'A':
		case 'a':
			addFamily(Family);
			break;
			//�����Ů
		case 'B':
		case 'b':
			addChild(Family);
			break;
			//��ɢ��ͥ
		case 'C':
		case 'c':
			deleteFamily(Family);
			break;
			//���ĳ�Ա����
		case 'D':
		case 'd':
			updateName(Family);
			break;
			//������г�Ա
		case 'E':
		case 'e':
			printTree(Family);
			break;
			//�˳�����
		case 'F':
		case 'f':
			cout << "�˳�ϵͳ�ɹ�" << endl;
			system("pause");
			return 0;
			//ָ���д���
		default:
			cout << "�������������������������" << endl;
			break;
		}
	}
	system("pause");
	return 0;
}