#ifndef list_h
#define list_h

#include <iostream>
#include <string>
using namespace std;

class MyList; //��ǰ����
class LNode { //�����
	friend MyList;  
public:
	string m_studentID; //��ʾѧ������
	string m_studentName;//��ʾѧ������
	string m_sex;//��ʾѧ���Ա�
	int m_age;//��ʾѧ������
	string m_category;//��ʾѧ����������
	LNode *m_next;//�������ָ����
	LNode() {}
	LNode(string ID, string name, string sex, int age, string cate, LNode *ptr = NULL)
	{
		m_age = age;
		m_category = cate;
		m_sex = sex;
		m_studentID = ID;
		m_studentName = name;
		m_next = ptr;
	}
	void Update();//���Ľ������
	void print();//��ӡ�������
};
class MyList { //������
public:
	int m_length = 0;
	void InitList(int); //ͷ�巨��ʼ����ͷ���ı�,����Ϊn,����ͷ���
	void ClearList(); //��ձ�
	bool ListEmpty(); //�п�
	LNode* LocateElemByID(string ID); //�ҳ�ѧ��ΪID��Ԫ�ز�����
	bool ListInsert(int i, string ID, string name, string sex, int age, string cate); //��i��λ�ò���Ԫ��e
	bool ListDelete(string ID); //ɾ��ѧ��ΪID��Ԫ��
	void PrintList(); //�������
	LNode *head; //ͷָ��
};
#endif


void LNode::Update()
{
	int age;
	string ID, name, sex, cate;
	cout << "�����뿼���Ŀ��ţ��������Ա����估�������" << endl;
	cin >> ID >> name >> sex >> age >> cate;
	m_age = age;
	m_category = cate;
	m_sex = sex;
	m_studentID = ID;
	m_studentName = name;
	cout << "�޸ĳɹ���" << endl;
}
void LNode::print()
{
	cout << m_studentID << " " << m_studentName << " " << m_sex << " " << m_age << " " << m_category << endl;
}
void MyList::InitList(int num)
{
	int age;
	string ID, name, sex, cate;
	head = new LNode;
	LNode* last = head;
	head -> m_next = NULL;
	cout << "���������뿼���Ŀ��ţ��������Ա����估�������" << endl;
	for (int i = 0; i<num; ++i)
	{
		cin >> ID >> name >> sex >> age >> cate;
		LNode *p = new LNode;
		p->m_age = age;
		p->m_category = cate;
		p->m_sex = sex;
		p->m_studentID = ID;
		p->m_studentName = name;
		last->m_next = p;
		last = p;
		m_length++;
	}
}
void MyList::ClearList()
{
	LNode *q;
	while (head->m_next != NULL)
	{
		q = head->m_next;
		head->m_next = q->m_next;
		delete q;
		q = NULL;
	}
	m_length = 0;
}
bool MyList::ListEmpty()
{
	if (m_length == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
LNode* MyList::LocateElemByID(string ID)
{
	int i = 1;
	LNode *p = head->m_next;
	while (i <= m_length && p->m_studentID != ID)
	{
		p = p->m_next;
		i++;
	}
	if (i > m_length)
	{
		return head;
	}
	else return p;
}
bool MyList::ListInsert(int i, string ID, string name, string sex, int age, string cate)
{
	LNode *p, *s;
	int j = 1;
	p = head;
	while (p&&j<i) { p = p->m_next; j++; }
	if (p == NULL) return false;
	if ((s = new LNode) == NULL) return false;
	s->m_age = age;
	s->m_category = cate;
	s->m_sex = sex;
	s->m_studentID = ID;
	s->m_studentName = name;
	s->m_next = p->m_next;
	p->m_next = s;
	m_length++;
	return true;
}
bool MyList::ListDelete(string ID)
{
	LNode *p, *q;
	int i = 1;
	if (ListEmpty())
	{
		cout << "���Ѿ����ˣ�����ɾ����" << endl;
		return false;
	}
	p = head->m_next;
	while (p && p->m_studentID != ID) { p = p->m_next; i++; }
	if (i > m_length)
	{
		return false;
	}
	else
	{
		if (i < m_length)
		{
			q = p->m_next;
			p->m_next = q->m_next;
			delete q;
			q = NULL;
			m_length--;
			return true;
		}
		else
		{
			delete p;
			p = NULL;
			m_length--;
		}
	}
}

void MyList::PrintList()
{
	int i = 0;
	if (ListEmpty()) { cout << "���ǿյģ�" << endl; }
	else
	{
		cout << "����Ԫ��Ϊ:" << endl;
		LNode *p = head-> m_next;
		while (i < m_length)
		{
			p->print();
			p = p-> m_next;
			i++;
		}
	}
}

