/*
**author:������_1652977
**theme:���ݽṹ�γ����_T1
**question:���Ա���ϵͳ
**application:����list
*/
#include "list.h"

int main()
{
	int number = 0;
	int order;
	MyList Students;
	cout << "�����뽨��������Ϣϵͳ��" << endl;
	cout << "�����뿼��������";
	while (1)
	{
		if (!(cin >> number))
		{
			cout << "����Ƿ�������������" << endl;
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
				cout << "������һ���Ǹ�����" << endl;
			}
			else
			{
				break;
			}
		}
	}
	Students.InitList(number);
	Students.PrintList();
	cout << "��ѡ����Ҫ���еĲ�����1Ϊ���룬2Ϊɾ����3Ϊ���ң�4Ϊ�޸ģ�5Ϊͳ�ƣ�0Ϊȡ��������" << endl;
	cout << endl;
	while (1)
	{
		cout << "��ѡ����Ҫ���еĲ�����";
		if (!(cin >> order))
		{
			cout << "����Ƿ�������������" << endl;
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
				cout << "��������Ҫ����Ŀ�����λ�ã�";
				while (!(cin >> position))
				{
					cout << "�����������������롣" << endl;
					cin.clear();
					while (cin.get() != '\n')
					{
						continue;
					}
				}
				while(position <= 0 || position > Students.m_length + 1)
				{
					cout << "�������λ�ó�����Χ������������" << endl;
					cin.clear();
					while (cin.get() != '\n')
					{
						continue;
					}
					cin >> position;
				}
				cout << "�����뿼���Ŀ��ţ��������Ա����估�������" << endl;
				cin >> ID >> name >> sex >> age >> cate;
				if (Students.ListInsert(position, ID, name, sex, age, cate))
				{
					cout << "����ɹ�" << endl;
					Students.PrintList();
				}
				else
				{
					cout << "����ʧ�ܣ��������벢����" << endl;
				}
				break;
			}
			case 2:
			{
				string ID;
				cout << "��������Ҫɾ���Ŀ����Ŀ��ţ�";
				cin >> ID;
				if (Students.ListDelete(ID))
				{
					cout << "ɾ���ɹ�" << endl;
					Students.PrintList();
				}
				else
				{
					cout << "ɾ��ʧ�ܣ��������벢����" << endl;
				}
				break;
			}
			case 3:
			{
				string ID;
				cout << "��������Ҫ���ҵĿ����Ŀ��ţ�";
				cin >> ID;
				LNode *p = Students.LocateElemByID(ID);
				if (p != Students.head)
				{
					p->print();
				}
				else
				{
					cout << "�����ҵĿ�����������" << endl;
				}
				break;
			}
			case 4:
			{
				string ID;
				cout << "��������Ҫ���ĵĿ����Ŀ��ţ�";
				cin >> ID;
				LNode *p = Students.LocateElemByID(ID);
				if (p != Students.head)
				{
					p->Update();
				}
				else
				{
					cout << "�����ҵĿ�����������" << endl;
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
				cout << "�˳�ϵͳ�ɹ�����ӭ�´�ʹ��" << endl;
				system("pause");
				return 0;
			}
			default:
				cout << "���������ֵ��������������" << endl;
				break;
			}
		}
	}
	system("pause");
	return 0;
}