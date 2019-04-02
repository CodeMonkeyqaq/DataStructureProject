/*
**author:王星洲_1652977
**theme:数据结构课程设计_T9
**question:关键活动
**application:AOE
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 2147483647;

struct node {
	int early;		//最早可以开始的时间
	int late;		//最晚必须开始的时间
	int inDegree;	//入度
	int outDegree;  //出度
	vector<int> next;//后继结点
	vector<int> pre; //前驱结点
	node(int e, int l, int p, int n) ://构造函数
		early(e), late(l), inDegree(0), outDegree(0) {}
};

int main() {
	int N, M;
	cin >> N >> M;
	vector<vector<int> > edges(N + 1, vector<int>(N + 1, -1));
	vector<node> G(N + 1, node(0, MAX, 0, 0));//early=0,late=MAX
	int a, b, c;
	while (M > 0) {
		cin >> a >> b >> c;
		if (a > N || b > N)
		{
			cerr << "您的数组可能已经越界，请重新检查您的输入。";
			system("pause");
			return 0;
		}
		if (a == b)
		{
			cerr << "您的输入中存在了无效输出，请重新检查您的输入。";
			system("pause");
			return 0;
		}
		edges[a][b] = c;
		G[a].next.push_back(b);
		G[b].pre.push_back(a);
		G[b].inDegree++;	//后继结点入度加1
		G[a].outDegree++;	//前驱结点出度加1
		M--;
	}

	//从前往后计算每个结点最早可以开始的时间
	queue<int> q;
	int count = 0; //记录入队的点的个数，若最后不是N个，说明无解
	for (int i = 1; i <= N; i++) {
		if (G[i].inDegree == 0) {
			G[i].early = 0;//开始时间为0
			q.push(i);	 //入度为0的结点进入队列
			count++;
		}
	}
	while (!q.empty()) {
		int cur = q.front();//当前结点序号
		q.pop();
		//每个结点(*it)最早可以开始的时间受制于若干条前驱路径中
		//花费时间最长的一条
		for (auto it = G[cur].next.begin(); it != G[cur].next.end(); it++) {
			if (G[cur].early + edges[cur][*it] > G[*it].early)
				G[*it].early = G[cur].early + edges[cur][*it];//更新
			if (--G[*it].inDegree == 0) {
				q.push(*it);
				count++;
			}
		}
	}
	if (count != N) {
		cout << 0 << endl;
		system("pause");
		return 0;
	}
	int completeTime = -1;//完成工程需要花费的总时间
	for (int i = 1; i <= N; i++) {
		if (G[i].early>completeTime)
			completeTime = G[i].early;
	}
	cout << completeTime << endl;
	//从后往前计算每个结点最晚必须开始的时间
	for (int i = 1; i <= N; i++) {
		if (G[i].outDegree == 0) {      //最后的结点
			G[i].late = completeTime; //最晚必须开始的时间
			q.push(i);
		}
	}
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		//每个结点(*it)最晚必须开始的时间受制于若干条后继路径中
		//花费时间最长的一条，因为该路径把deadline往前推得越多
		for (auto it = G[cur].pre.begin(); it != G[cur].pre.end(); it++) {
			if (G[*it].late > G[cur].late - edges[*it][cur])
				G[*it].late = G[cur].late - edges[*it][cur];
			if (--G[*it].outDegree == 0)
				q.push(*it);
		}
	}

	vector<int> result;//关键事件
	vector<bool> inResult(N + 1, false);
	for (int i = 1; i <= N; i++) {
		if (G[i].early == G[i].late) {
			result.push_back(i);
			inResult[i] = true;
		}
	}
	for (auto it = result.begin(); it != result.end(); ++it) {
		for (auto itt = G[*it].next.rbegin(); itt != G[*it].next.rend(); ++itt) {
			if (inResult[*itt] && (edges[*it][*itt] == G[*itt].early - G[*it].early))//关键活动
				cout << *it << "->" << *itt << endl;
		}
	}
	system("pause");
	return 0;
}