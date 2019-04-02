#ifndef STATICLIST_H
#define STATICLIST_H

#include <iostream>
using namespace std;
#define maxSize 100001

struct SLinkNode
{
	int data;
	int link;   //�������ָ��
};

class StaticList {
private:
	SLinkNode elem[maxSize];
	int m_length;
	int avil;     //��ǰ�ɷ���ռ��׵�ַ
public:
	void InitList();
	//���㾲̬����ĳ���
	int length();
	//�ھ�̬�����в��Ҿ��и���ֵ�Ľ��
	int Search(int x);
	//�ھ�̬�����в��ҵ�i�����
	int Locate(int i);
	//�ھ�̬����ı�β׷��һ���½��
	bool Append(int x);
	//�ھ�̬����ĵ�i���ڵ������½��
	bool Insert(int i, int x);
	//�ھ�̬�������ͷŵ�i�����
	bool Remove(int i);
	//�п�
	bool IsEmpty();
	//����linkNode
	void setLink(const int location, const int newLink);
	//���ؽ��data
	int getNode(const int location);
	//���ؽ��link
	int getLink(const int location);
	//���
	void print();
};

#endif // !STATICLIST_H

void StaticList::InitList() 
{
	elem[0].link = -1;
	avil = 1;
	for (int i = 1; i < maxSize - 1; i++)
	{
		elem[i].link = i + 1;
	}
	m_length = 0;
}

int StaticList::length()
{
	return m_length;
}

bool StaticList::IsEmpty()
{
	if (elem[0].link == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int StaticList::Search(int x)
{
	int p = elem[0].link;
	while (p != -1)
	{
		if (elem[p].data == x)
		{
			break;
		}
		else
		{
			p = elem[p].link;
		}
	}
	return p;
}

int StaticList::Locate(int i)
{
	if (i < 0)
	{
		return -1;
	}
	if (i == 0)
	{
		return 0;
	}
	int j = 1, p = elem[0].link;
	while (p != -1 && j < i)
	{
		p = elem[p].link;
		j++;
	}
	return p;
}

bool StaticList::Append(int x)
{
	if (avil == -1)
	{
		return false;
	}
	int q = avil;
	avil = elem[avil].link;
	elem[q].data = x;
	elem[q].link = -1;
	int p = 0;
	while (elem[p].link != -1)
	{
		p = elem[p].link;
	}
	elem[p].link = q;
	m_length++;
	return true;
}

bool StaticList::Insert(int i, int x)
{
	int p = Locate(i);
	if (p == -1)
	{
		return false;
	}
	int q = avil;
	avil = elem[avil].link;
	elem[q].data = x;
	elem[q].link = elem[p].link;
	elem[p].link = q;
	m_length++;
	return true;
}

bool StaticList::Remove(int i)
{
	int p = Locate(i - 1);
	if (p == -1)
	{
		return false;
	}
	int q = elem[p].link;
	elem[p].link = elem[q].link;
	elem[q].link = avil;
	avil = q;
	m_length--;
	return true;
}

void StaticList::setLink(const int location, const int newLink)
{
	elem[location].link = newLink;
}

int StaticList::getNode(const int location)
{
	return elem[location].data;
}

int StaticList::getLink(const int location)
{
	return elem[location].link;
}

void StaticList::print()
{
	int p = elem[0].link;
	while (p != 0)
	{
		cout << elem[p].data << " ";
		p = elem[p].link;
	}
}