#ifndef list_h
#define list_h

#include <iostream>
#include <string>
using namespace std;

class MyList; //提前声明
class LNode { //结点类
	friend MyList;  
public:
	string m_studentID; //表示学生考号
	string m_studentName;//表示学生姓名
	string m_sex;//表示学生性别
	int m_age;//表示学生年龄
	string m_category;//表示学生报考种类
	LNode *m_next;//链表结点的指针域
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
	void Update();//更改结点数据
	void print();//打印结点数据
};
class MyList { //链表类
public:
	int m_length = 0;
	void InitList(int); //头插法初始化带头结点的表,长度为n,不算头结点
	void ClearList(); //清空表
	bool ListEmpty(); //判空
	LNode* LocateElemByID(string ID); //找出学号为ID的元素并返回
	bool ListInsert(int i, string ID, string name, string sex, int age, string cate); //第i个位置插入元素e
	bool ListDelete(string ID); //删除学号为ID的元素
	void PrintList(); //输出链表
	LNode *head; //头指针
};
#endif


void LNode::Update()
{
	int age;
	string ID, name, sex, cate;
	cout << "请输入考生的考号，姓名，性别，年龄及报考类别！" << endl;
	cin >> ID >> name >> sex >> age >> cate;
	m_age = age;
	m_category = cate;
	m_sex = sex;
	m_studentID = ID;
	m_studentName = name;
	cout << "修改成功！" << endl;
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
	cout << "请依次输入考生的考号，姓名，性别，年龄及报考类别！" << endl;
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
		cout << "表已经空了，不能删除。" << endl;
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
	if (ListEmpty()) { cout << "表是空的！" << endl; }
	else
	{
		cout << "表中元素为:" << endl;
		LNode *p = head-> m_next;
		while (i < m_length)
		{
			p->print();
			p = p-> m_next;
			i++;
		}
	}
}

