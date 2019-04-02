/*
**author:王星洲_1652977
**theme:数据结构课程设计_T8
**question:电网建设造价模拟系统
**application:最小生成树
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
		cout << "您已经输入过结点，请勿重复输入" << endl;
		return;
	}
	string name;
	cout << "请输入顶点的个数：";
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
			if (number <= 1)
			{
				cout << "请至少输入两个点用于计算" << endl;
			}
			else
			{
				break;
			}
		}
	}
	cout << "请依次输入各顶点名称：" << endl;
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
		cout << "请先输入结点" << endl;
		return;
	}
	if (hasInput == true)
	{
		cout << "您已输入过边，请勿重复输入" << endl;
		return;
	}
	int number = points.size();
	for (int i = 0; i < number - 1; i++) {
		cout << "请输入给出的两个顶点间的距离，不存在路径则输入-1: ";
		edges[i][i] = 0;
		for (int k = i + 1; k < number; k++) {
			cout << name[i] << " ";
			cout << name[k] << " ";
			cin >> edges[i][k];
			if (edges[i][k] == -1)
				edges[i][k] = Max;
			if (k != number - 1)
				cout << "请输入给出的两个顶点间的距离，不存在路径则输入-1: ";
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
		cout << "请先输入结点" << endl;
		return;
	}
	if (hasInput == false)
	{
		cout << "请先输入边" << endl;
		return;
	}
	if (MST.size() != 0)
	{
		cout << "您已生成过最小生成树，赶快按d查看吧" << endl;
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
	cout << "请输入起始点:";
	cin >> first;
	for (i = 0; i < name.size(); i++)
	{
		if (first == name[i])
			break;
	}
	if (i == name.size())
	{
		cout << "没有找到该结点，请检查您的输入" << endl;
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
		cout << "生成Prim最小树！" << endl;
		return;
	}
}

void showMST(map<int, string>& points, vector<ed>& MST)
{
	if (MST.size() == 0)
	{
		cout << "并没有可见的最小生成树，请检查之前的步骤" << endl;
		return;
	}
	cout << "最小生成树的顶点及边为：" << endl;
	cout << endl;
	for (int i = 0; i < MST.size(); i++)
	{
		cout << points[MST[i].head] << "-<" << MST[i].key << ">-" << points[MST[i].tail] << '\t';
	}
	cout << endl;
}

void showMenu()
{
	cout << "**\t\t\t  电网造价模拟系统\t\t\t**\n";
	cout << "==================================================================\n";
	cout << "**\t\t\tA --- 创建电网顶点\t\t\t**\n";
	cout << "**\t\t\tB --- 添加电网的边\t\t\t**\n";
	cout << "**\t\t\tC --- 构造最小生成树\t\t\t**\n";
	cout << "**\t\t\tD --- 显示最小生成树\t\t\t**\n";
	cout << "**\t\t\tE --- 退出程序\t\t\t\t**\n";
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
		cout << "请选择操作：";
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
			cout << "退出程序成功" << endl;
			system("pause");
			return 0;
		}
		default:
		{
			cout << "您的指令输入有误，请重新输入" << endl;
			break;
		}
		}
	}
	system("pause");
	return 0;
}