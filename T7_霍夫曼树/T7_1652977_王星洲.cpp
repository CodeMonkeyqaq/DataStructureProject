/*
**author:������_1652977
**theme:���ݽṹ�γ����_T7
**question:��������
**application:��������
*/

#include <iostream>

//Ϊ��ʹ��greaterģ��
#include <functional>
#include <queue>
using namespace std;

int main()
{
	//�������ȼ����У�greater<int>��ʾС��
	priority_queue<int, vector<int>, greater<int> > q;
	//N�����û������������length��������ĳ���
	int N, length;
	//����N������
	while (1)
	{
		//N����ʧ��
		if (!(cin >> N))
		{
			cout << "����Ƿ������������롣" << endl;
			cin.clear();
			while (cin.get() != '\n')
			{
				continue;
			}
			continue;
		}
		//N����������
		else if (N <= 0)
		{
			cout << "������һ����������" << endl;
			cin.clear();
			while (cin.get() != '\n')
			{
				continue;
			}
			continue;
		}
		//N������ȷ
		else
		{
			break;
		}
	}
	//����length
	for (int i = 0; i < N; i++)
	{
		//length����ʧ��
		while (!(cin >> length))
		{
			cout << "����Ƿ�����֪��Ҫ����" << N << "�����ȣ����������롣" << endl;
			cin.clear();
			while (cin.get() != '\n')
			{
				continue;
			}
			//���q����
			while (!q.empty())
			{
				q.pop();
			}
			//i�û�0
			i = 0;
		}
		if (length <= 0)
		{
			cout << "���ȱ���Ϊ����������֪��Ҫ����" << N << "�����ȣ����������롣" << endl;
			cin.clear();
			while (cin.get() != '\n')
			{
				continue;
			}
			//���q����
			while (!q.empty())
			{
				q.pop();
			}
			//��i��Ϊ-1���ٴν���ѭ��ʱi���0
			i = -1;
		}
		else
		{
			//������ȷ����length����q����
			q.push(length);
		}
	}
	//���
	int sum = 0;
	//��q��Ԫ�ظ�������1
	while (q.size() > 1) {
		//ȡ��q����С������ֵ��sum�����Ϊsum���ѽ��������У��ٽ�������ֵ�Ƴ�����
		int first = q.top();
		q.pop();

		int second = q.top();
		q.pop();

		sum += first + second;
		q.push(first + second);
	}
	//���sum
	cout << sum << endl;

	system("pause");
	return 0;
}