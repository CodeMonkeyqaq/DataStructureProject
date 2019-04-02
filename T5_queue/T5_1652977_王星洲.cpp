/*
**author:������_1652977
**theme:���ݽṹ�γ����_T5
**question:����ҵ��
**application:����
*/

#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
	//������������
	queue<int> qA;
	queue<int> qB;
	//�����û�������
	int N, number;
	//N�Ĵ���
	while(1)
	{
		//����Ƿ�
		if (!(cin >> N))
		{
			cout << "����ʧ�ܣ����������롣" << endl;
			cin.clear();
			while (cin.get() != '\n')
			{
				continue;
			}
		}
		//���븺����0
		else if (N <= 0)
		{
			cout << "��������������" << endl;
			cin.clear();
			while (cin.get() != '\n')
			{
				continue;
			}
		}
		//�����ֵ������ĿҪ��
		else if (N > 1000)
		{
			cout << "�����벻����1000������" << endl;
			cin.clear();
			while (cin.get() != '\n')
			{
				continue;
			}
		}
		//������ȷ
		else
		{
			break;
		}
	}
	
	//����number�Ĵ���
	for (int i = 0; i < N; i++)
	{
		//����Ƿ�
		while(!(cin >> number))
		{
			cout << "����ʧ�ܣ��Ѿ�֪����Ҫ����" << N << "���˿͵ı�ţ������������š�" << endl;
			cin.clear();
			while (cin.get() != '\n')
			{
				continue;
			}
			while (!qA.empty())
			{
				qA.pop();
			}
			while (!qB.empty())
			{
				qB.pop();
			}
			i = 0;
		}
		//����������A����
		if (number % 2 != 0)
		{
			qA.push(number);
		}
		//ż��������B����
		else
		{
			qB.push(number);
		}
	}


	//��A����B��Ϊ��ʱ������ѭ��
	while (!qA.empty() || !qB.empty())
	{
		//�������A�գ���B����ȫ�����
		if (qA.empty())
		{
			cout << qB.front() << " ";
			qB.pop();
		}
		//�������B�գ���A�������
		else if (qB.empty())
		{
			cout << qA.front() << " ";
			qA.pop();
		}
		//���߶���Ϊ��ʱ
		else
		{
			//���A�ĵ�һ��
			cout << qA.front() << " ";
			//����ֵ�Ƴ�����
			qA.pop();
			//�����ʱA�Ѿ��գ��򷵻�ѭ����ʼ
			if (qA.empty())
			{
				continue;
			}
			//��A�Բ�Ϊ�գ��������һ��AȻ�����B
			else
			{
				cout << qA.front() << " ";
				qA.pop();
				cout << qB.front() << " ";
				qB.pop();
			}
		}
	}
	//��ȥ���Ŀո�
	cout << "\b";
	cout << endl;
	system("pause");
	return 0;
}