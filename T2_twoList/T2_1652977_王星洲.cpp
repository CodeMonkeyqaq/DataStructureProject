/*
**author:王星洲_1652977
**theme:数据结构课程设计_T2
**question:两个有序链表序列的交集
**application:链表
*/
#include <iostream>
#include <list>
using namespace std;

//为list<unsigned int>设定别名
typedef list<unsigned int> LISTUINT;
void searchInList(int temp, LISTUINT &listA, LISTUINT &listResult, LISTUINT::iterator &iter);
void printList(LISTUINT listResult);

int main()
{
	//记录输入数据的链表
	LISTUINT listA;
	LISTUINT::iterator iter;
	//用于输出结果的链表
	LISTUINT listResult;
	//接收输入的值
	int temp;
	int temp1;
	//接收输入，分为两行
	for (int i = 0; i < 2; i++)
	{
		temp1 = -1;
		//判断输入合法性
		while (1)
		{
			cin >> temp;
			if (!cin)
			{
				cout << "输入错误，请重新输入" << endl;
				i -= 1;
				cin.clear();
				while (cin.get() != '\n')
				{
					continue;
				}
				break;
			}
			//对于第一行输入
			if (i == 0)
			{
				//输入-1时停止接收数据
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
						//将数据存入listA
						listA.push_back(temp);
					}
					else
					{
						listA.clear();
						cout << "请按照非降序输入，保证每个后输入的值大于前一个值。" << endl;
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
			//第二行数据
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
						cout << "请按照非降序输入，保证每个后输入的值大于前一个值。" << endl;
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
	//如果listResult是空链表
	if (listResult.empty())
	{
		//输出NULL，空格是为了格式
		cout << "NULL ";
	}
	//listResult不空
	else
	{
		//遍历listResult
		for (LISTUINT::iterator iterResult = listResult.begin(); iterResult != listResult.end(); iterResult++)
		{
			//输出数据
			cout << *iterResult << " ";
		}
	}

	//清除多余的空格
	cout << "\b";
}
