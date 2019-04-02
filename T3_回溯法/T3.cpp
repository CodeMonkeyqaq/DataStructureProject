/*
**author:王星洲_1652977
**theme:数据结构课程设计_T3
**question:勇闯迷宫游戏
**application:回溯法
*/
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int maze[7][7] =    //迷宫地图 0为路径 1为围墙
{
	1,1,1,1,1,1,1,
	1,0,1,0,0,0,1,
	1,0,1,0,1,1,1,
	1,0,0,0,1,0,1,
	1,0,1,0,0,0,1,
	1,0,1,0,1,0,1,
	1,1,1,1,1,1,1
};

int mark[7][7] = { 0 };  //标记数组，记录某处是否已经经过

struct path {    //三元组
	int x;
	int y;
	int dir;
};

struct offsets{      //方向
	int a, b;
};

void setOffsets(offsets move[])   //设置每一步前进方向的四种可能
{
	move[0].a = 0; move[0].b = 1;//上
	move[1].a = 0; move[1].b = -1;//下
	move[2].a = 1; move[2].b = 0;//右
	move[3].a = -1; move[3].b = 0;//左
}

void printMap(int maze[7][7])   //打印地图
{
	cout << "迷宫地图：" << endl << endl;
	cout << '\t' << "0列" << '\t' << "1列" << '\t' << "2列" << '\t' << "3列" << '\t' << "4列" << '\t' << "5列" << '\t' << "6列" << endl;
	for (int j = 0; j < 7; j++)
	{
		cout << j << "行" << '\t';
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

void result(stack<path> st)   //根据栈中内容输出结果
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
	cout << endl << "迷宫路径：" << endl << endl;
	auto iter = a.rbegin();
	auto iter2 = b.rbegin();
	for (iter; iter != a.rend(); iter++, iter2++)
	{
		cout << "<" << *iter << "," << *iter2 << "> ---> ";
	}
	cout << "<5,5>" << endl;
}

void findPath(int m, int p, offsets move[])   //搜索路径函数
{
	int i, j, d;//当前x，y，dir
	int g, h;//改变后x，y
	mark[1][1] = 1;//入口
	stack<path> st;//工作栈及工作元
	path tmp;
	tmp.x = 1;
	tmp.y = 1;
	tmp.dir = 0;
	st.push(tmp);//初始坐标方向三元组进栈
	while (st.empty() == false)//栈不空，持续走下去
	{
		tmp = st.top();
		st.pop();//退栈
		i = tmp.x;
		j = tmp.y;
		d = tmp.dir;
		while (d < 4)//还有没进行完的移动
		{
			g = i + move[d].a;
			h = j + move[d].b;//下一位置
			if (g == m && h == p) {//找到出口
				tmp.x = i;
				tmp.y = j;
				st.push(tmp);//进栈
				result(st);
				return;
			}
			if (maze[g][h] == 0 && mark[g][h] == 0)//有新的位置可通
			{
				mark[g][h] = 1;//标记为访问过
				tmp.x = i;
				tmp.y = j;
				tmp.dir = d;
				st.push(tmp);//进栈
				i = g;//开始试探
				j = h;
				d = 0;
			}
			else
			{
				d++;//试探下一个方向
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