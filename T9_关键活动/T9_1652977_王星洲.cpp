/*
**author:������_1652977
**theme:���ݽṹ�γ����_T9
**question:�ؼ��
**application:AOE
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 2147483647;

struct node {
	int early;		//������Կ�ʼ��ʱ��
	int late;		//������뿪ʼ��ʱ��
	int inDegree;	//���
	int outDegree;  //����
	vector<int> next;//��̽��
	vector<int> pre; //ǰ�����
	node(int e, int l, int p, int n) ://���캯��
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
			cerr << "������������Ѿ�Խ�磬�����¼���������롣";
			system("pause");
			return 0;
		}
		if (a == b)
		{
			cerr << "���������д�������Ч����������¼���������롣";
			system("pause");
			return 0;
		}
		edges[a][b] = c;
		G[a].next.push_back(b);
		G[b].pre.push_back(a);
		G[b].inDegree++;	//��̽����ȼ�1
		G[a].outDegree++;	//ǰ�������ȼ�1
		M--;
	}

	//��ǰ�������ÿ�����������Կ�ʼ��ʱ��
	queue<int> q;
	int count = 0; //��¼��ӵĵ�ĸ������������N����˵���޽�
	for (int i = 1; i <= N; i++) {
		if (G[i].inDegree == 0) {
			G[i].early = 0;//��ʼʱ��Ϊ0
			q.push(i);	 //���Ϊ0�Ľ��������
			count++;
		}
	}
	while (!q.empty()) {
		int cur = q.front();//��ǰ������
		q.pop();
		//ÿ�����(*it)������Կ�ʼ��ʱ��������������ǰ��·����
		//����ʱ�����һ��
		for (auto it = G[cur].next.begin(); it != G[cur].next.end(); it++) {
			if (G[cur].early + edges[cur][*it] > G[*it].early)
				G[*it].early = G[cur].early + edges[cur][*it];//����
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
	int completeTime = -1;//��ɹ�����Ҫ���ѵ���ʱ��
	for (int i = 1; i <= N; i++) {
		if (G[i].early>completeTime)
			completeTime = G[i].early;
	}
	cout << completeTime << endl;
	//�Ӻ���ǰ����ÿ�����������뿪ʼ��ʱ��
	for (int i = 1; i <= N; i++) {
		if (G[i].outDegree == 0) {      //���Ľ��
			G[i].late = completeTime; //������뿪ʼ��ʱ��
			q.push(i);
		}
	}
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		//ÿ�����(*it)������뿪ʼ��ʱ�����������������·����
		//����ʱ�����һ������Ϊ��·����deadline��ǰ�Ƶ�Խ��
		for (auto it = G[cur].pre.begin(); it != G[cur].pre.end(); it++) {
			if (G[*it].late > G[cur].late - edges[*it][cur])
				G[*it].late = G[cur].late - edges[*it][cur];
			if (--G[*it].outDegree == 0)
				q.push(*it);
		}
	}

	vector<int> result;//�ؼ��¼�
	vector<bool> inResult(N + 1, false);
	for (int i = 1; i <= N; i++) {
		if (G[i].early == G[i].late) {
			result.push_back(i);
			inResult[i] = true;
		}
	}
	for (auto it = result.begin(); it != result.end(); ++it) {
		for (auto itt = G[*it].next.rbegin(); itt != G[*it].next.rend(); ++itt) {
			if (inResult[*itt] && (edges[*it][*itt] == G[*itt].early - G[*it].early))//�ؼ��
				cout << *it << "->" << *itt << endl;
		}
	}
	system("pause");
	return 0;
}