/*
**author:������_1652977
**theme:���ݽṹ�γ����_T2
**question:���������������еĽ���
**application:����
*/
#include <iostream>
#include <list>
using namespace std;

//Ϊlist<unsigned int>�趨����
typedef list<unsigned int> LISTUINT;
void searchInList(int temp, LISTUINT &listA, LISTUINT &listResult, LISTUINT::iterator &iter);
void printList(LISTUINT listResult);

int main()
{
	//��¼�������ݵ�����
	LISTUINT listA;
	LISTUINT::iterator iter;
	//����������������
	LISTUINT listResult;
	//���������ֵ
	int temp;
	int temp1;
	//�������룬��Ϊ����
	for (int i = 0; i < 2; i++)
	{
		temp1 = -1;
		//�ж�����Ϸ���
		while (1)
		{
			cin >> temp;
			if (!cin)
			{
				cout << "�����������������" << endl;
				i -= 1;
				cin.clear();
				while (cin.get() != '\n')
				{
					continue;
				}
				break;
			}
			//���ڵ�һ������
			if (i == 0)
			{
				//����-1ʱֹͣ��������
				if (temp == -1)
				{
					iter = listA.begin();
					break;
				}
				else
				{
					if (temp1 < temp)
					{
						temp1 = temp;
						//�����ݴ���listA
						listA.push_back(temp);
					}
					else
					{
						listA.clear();
						cout << "�밴�շǽ������룬��֤ÿ���������ֵ����ǰһ��ֵ��" << endl;
						i -= 1;
						cin.clear();
						while (cin.get() != '\n')
						{
							continue;
						}
						break;
					}
				}
			}
			//�ڶ�������
			else
			{
				if (temp == -1)
				{
					break;
				}
				else
				{
					if (temp1 < temp)
					{
						temp1 = temp;
						searchInList(temp, listA, listResult, iter);
					}
					else
					{
						listResult.clear();
						cout << "�밴�շǽ������룬��֤ÿ���������ֵ����ǰһ��ֵ��" << endl;
						i -= 1;
						cin.clear();
						while (cin.get() != '\n')
						{
							continue;
						}
						break;

					}
				}
			}
		}
	}

	printList(listResult);

	return 0;
}

void searchInList(int temp, LISTUINT &listA, LISTUINT &listResult, LISTUINT::iterator& iter)
{
	for (iter; iter != listA.end(); iter++)
	{
		if (temp == *iter)
		{
			listResult.push_back(temp);
			return;
		}
		else
		{
			continue;
		}
	}
	iter = listA.begin();
}

void printList(LISTUINT listResult)
{
	//���listResult�ǿ�����
	if (listResult.empty())
	{
		//���NULL���ո���Ϊ�˸�ʽ
		cout << "NULL ";
	}
	//listResult����
	else
	{
		//����listResult
		for (LISTUINT::iterator iterResult = listResult.begin(); iterResult != listResult.end(); iterResult++)
		{
			//�������
			cout << *iterResult << " ";
		}
	}

	//�������Ŀո�
	cout << "\b";
}
