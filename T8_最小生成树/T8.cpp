/*
**author:������_1652977
**theme:���ݽṹ�γ����_T8
**question:�����������ģ��ϵͳ
**application:��С������
*/
#include "MinHeap.h"
#include <vector>
#include <map>
#define Max 99999999

int number = 0;
bool hasInput = 0;

void inputPoint(map<int, string>& points, vector<string> & nameArray)
{
	if (number != 0)
	{
		cout << "���Ѿ��������㣬�����ظ�����" << endl;
		return;
	}
	string name;
	cout << "�����붥��ĸ�����";
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
			if (number <= 1)
			{
				cout << "�������������������ڼ���" << endl;
			}
			else
			{
				break;
			}
		}
	}
	cout << "������������������ƣ�" << endl;
	for (int i = 0; i < number; i++)
	{
		cin >> name;
		points.insert(pair<int, string>(i, name));
		nameArray.push_back(name);
	}
}

void inputEdges(map<int, string>& points, vector<vector<int> >& edges, vector<string>& name)
{
	if (number <= 0)
	{
		cout << "����������" << endl;
		return;
	}
	if (hasInput == true)
	{
		cout << "����������ߣ������ظ�����" << endl;
		return;
	}
	int number = points.size();
	for (int i = 0; i < number - 1; i++) {
		cout << "��������������������ľ��룬������·��������-1: ";
		edges[i][i] = 0;
		for (int k = i + 1; k < number; k++) {
			cout << name[i] << " ";
			cout << name[k] << " ";
			cin >> edges[i][k];
			if (edges[i][k] == -1)
				edges[i][k] = Max;
			if (k != number - 1)
				cout << "��������������������ľ��룬������·��������-1: ";
		}
	}
	for (int i = 0; i < number; i++) {
		for (int k = 0; k < i; k++) {
			edges[i][k] = edges[k][i];
		}
	}
	hasInput = true;
	cout << endl;
	/*for (int i = 0; i < number; i++)
	{
		for (int j = 0; j < number; j++)
		{
			cout << edges[i][j];
		}
		cout << endl;
	}*/
}

void Prim(map<int, string>& points, vector<vector<int> >& edges, vector<string>& name, vector<ed>& MST)
{
	if (number == 0)
	{
		cout << "����������" << endl;
		return;
	}
	if (hasInput == false)
	{
		cout << "���������" << endl;
		return;
	}
	if (MST.size() != 0)
	{
		cout << "�������ɹ���С���������Ͽ찴d�鿴��" << endl;
		return;
	}
	ed helper;
	string first;
	int count, v, col;
	int edgesNumber = number * (number - 1) / 2;
	int i = 0;
	vector<bool> Vmst(number);
	for (int j = 0; j < number; j++)
	{
		Vmst[j] = false;
	}
	MinHeap H(edgesNumber);
	cout << "��������ʼ��:";
	cin >> first;
	for (i = 0; i < name.size(); i++)
	{
		if (first == name[i])
			break;
	}
	if (i == name.size())
	{
		cout << "û���ҵ��ý�㣬������������" << endl;
		return;
	}
	else
	{
		Vmst[i] = true;
		count = 1;
		do {
			if (i != -1)
			{
				for (col = 0; col < number; col++)
				{
					if (edges[i][col] > 0 && edges[i][col] < Max)
					{
						v = col; break;
					}
				}
				if (col == number)
				{
					v = -1;
				}
			}
			while (v != -1)
			{
				if (Vmst[v] == false)
				{
					helper.tail = i; helper.head = v;
					helper.key = (edges[i][v]);
					H.Insert(helper);
				}
				if (i != -1 && v != -1)
				{
					for (col = v + 1; col < number; col++)
					{
						if (edges[i][col] > 0 && edges[i][col] < Max)
						{
							v = col;
							break;
						}
					}
					if (col == number)
					{
						v = -1;
					}
				}
			}
			while (H.IsEmpty() == false && count < number)
			{
				H.RemoveMin(helper);
				if (Vmst[helper.head] == false)
				{
					MST.push_back(helper);
					i = helper.head;
					Vmst[i] = true;
					count++; break;
				}
			}
		} while (count < number);
		cout << "����Prim��С����" << endl;
		return;
	}
}

void showMST(map<int, string>& points, vector<ed>& MST)
{
	if (MST.size() == 0)
	{
		cout << "��û�пɼ�����С������������֮ǰ�Ĳ���" << endl;
		return;
	}
	cout << "��С�������Ķ��㼰��Ϊ��" << endl;
	cout << endl;
	for (int i = 0; i < MST.size(); i++)
	{
		cout << points[MST[i].head] << "-<" << MST[i].key << ">-" << points[MST[i].tail] << '\t';
	}
	cout << endl;
}

void showMenu()
{
	cout << "**\t\t\t  �������ģ��ϵͳ\t\t\t**\n";
	cout << "==================================================================\n";
	cout << "**\t\t\tA --- ������������\t\t\t**\n";
	cout << "**\t\t\tB --- ��ӵ����ı�\t\t\t**\n";
	cout << "**\t\t\tC --- ������С������\t\t\t**\n";
	cout << "**\t\t\tD --- ��ʾ��С������\t\t\t**\n";
	cout << "**\t\t\tE --- �˳�����\t\t\t\t**\n";
	cout << "==================================================================\n";
}



int main()
{
	map<int, string> points;
	vector<vector<int> > edges(100, vector<int>(100, 0));
	vector<string> name;
	vector<ed> MST;
	char order;
	showMenu();
	while (1)
	{
		cout << "��ѡ�������";
		cin >> order;
		switch (order)
		{
		case 'a':
		case 'A':
		{
			inputPoint(points, name);
			break;
		}
		case 'b':
		case 'B':
		{
			inputEdges(points, edges, name);
			break;
		}
		case 'c':
		case 'C':
		{
			Prim(points, edges, name, MST);
			break;
		}
		case 'd':
		case 'D':
		{
			showMST(points, MST);
			break;
		}
		case 'e':
		case 'E':
		{
			cout << "�˳�����ɹ�" << endl;
			system("pause");
			return 0;
		}
		default:
		{
			cout << "����ָ��������������������" << endl;
			break;
		}
		}
	}
	system("pause");
	return 0;
}