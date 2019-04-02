/*
**author:������_1652977
**theme:���ݽṹ�γ����_T3
**question:�´��Թ���Ϸ
**application:���ݷ�
*/
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int maze[7][7] =    //�Թ���ͼ 0Ϊ·�� 1ΪΧǽ
{
	1,1,1,1,1,1,1,
	1,0,1,0,0,0,1,
	1,0,1,0,1,1,1,
	1,0,0,0,1,0,1,
	1,0,1,0,0,0,1,
	1,0,1,0,1,0,1,
	1,1,1,1,1,1,1
};

int mark[7][7] = { 0 };  //������飬��¼ĳ���Ƿ��Ѿ�����

struct path {    //��Ԫ��
	int x;
	int y;
	int dir;
};

struct offsets{      //����
	int a, b;
};

void setOffsets(offsets move[])   //����ÿһ��ǰ����������ֿ���
{
	move[0].a = 0; move[0].b = 1;//��
	move[1].a = 0; move[1].b = -1;//��
	move[2].a = 1; move[2].b = 0;//��
	move[3].a = -1; move[3].b = 0;//��
}

void printMap(int maze[7][7])   //��ӡ��ͼ
{
	cout << "�Թ���ͼ��" << endl << endl;
	cout << '\t' << "0��" << '\t' << "1��" << '\t' << "2��" << '\t' << "3��" << '\t' << "4��" << '\t' << "5��" << '\t' << "6��" << endl;
	for (int j = 0; j < 7; j++)
	{
		cout << j << "��" << '\t';
		for (int i = 0; i < 7; i++)
		{
			if (maze[j][i] == 1)
			{
				cout << "#" << '\t';
			}
			else if(maze[j][i] == 2)
			{
				cout << "x" << '\t';
			}
			else
			{
				cout << "0" << '\t';
			}
		}
		cout << endl << endl;
	}
}

void result(stack<path> st)   //����ջ������������
{
	vector<int> a, b;
	while (st.empty() == false)
	{
		path t = st.top();
		maze[t.x][t.y] = 2;
		a.push_back(t.x);
		b.push_back(t.y);
		st.pop();
	}
	maze[5][5] = 2;
	printMap(maze);
	cout << endl << "�Թ�·����" << endl << endl;
	auto iter = a.rbegin();
	auto iter2 = b.rbegin();
	for (iter; iter != a.rend(); iter++, iter2++)
	{
		cout << "<" << *iter << "," << *iter2 << "> ---> ";
	}
	cout << "<5,5>" << endl;
}

void findPath(int m, int p, offsets move[])   //����·������
{
	int i, j, d;//��ǰx��y��dir
	int g, h;//�ı��x��y
	mark[1][1] = 1;//���
	stack<path> st;//����ջ������Ԫ
	path tmp;
	tmp.x = 1;
	tmp.y = 1;
	tmp.dir = 0;
	st.push(tmp);//��ʼ���귽����Ԫ���ջ
	while (st.empty() == false)//ջ���գ���������ȥ
	{
		tmp = st.top();
		st.pop();//��ջ
		i = tmp.x;
		j = tmp.y;
		d = tmp.dir;
		while (d < 4)//����û��������ƶ�
		{
			g = i + move[d].a;
			h = j + move[d].b;//��һλ��
			if (g == m && h == p) {//�ҵ�����
				tmp.x = i;
				tmp.y = j;
				st.push(tmp);//��ջ
				result(st);
				return;
			}
			if (maze[g][h] == 0 && mark[g][h] == 0)//���µ�λ�ÿ�ͨ
			{
				mark[g][h] = 1;//���Ϊ���ʹ�
				tmp.x = i;
				tmp.y = j;
				tmp.dir = d;
				st.push(tmp);//��ջ
				i = g;//��ʼ��̽
				j = h;
				d = 0;
			}
			else
			{
				d++;//��̽��һ������
			}
		}
		cout << "no path in Maze" << endl;
	}
}


int main()
{
	offsets move[4];
	setOffsets(move);
	findPath(5, 5, move);
	system("pause");
	return 0;
}