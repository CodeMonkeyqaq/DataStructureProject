#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

//���Ľ����
class TreeNode
{
public:
	//��Ա����
	string m_name;
	//�ӽ������
	vector<TreeNode *> m_children;
	//���캯��
	TreeNode() { m_name = "";}
	//�����Ů
	void AddChild(string name);
	//�����Ů
	void printChild();
	//ɾ����Ů
	void deleteChild();
	//��������
	void updateName(string name);
};

//����
class Tree 
{
	//��Ԫ�����
	friend TreeNode;
public:
	//�����
	TreeNode *m_root;
	//���캯��
	Tree() { m_root = new TreeNode; m_root->m_name = "";}
	Tree(string a) { m_root = new TreeNode; m_root->m_name = a; }
	//���ظ����
	string getRoot() { return m_root -> m_name; }
	//��������Ϊname�Ľ��
	TreeNode* search(string name);
	//���ȫ����Ա
	void print();
};
#endif

//�����Ů
void TreeNode::AddChild(string name)
{
		TreeNode *child = new TreeNode;
		child->m_name = name;
		m_children.push_back(child);
}

//�����Ů
void TreeNode::printChild()
{
	int i = 0;
	for (i; i < m_children.size() ; i++)
	{
		cout << m_children[i]->m_name << "  ";
	}
	cout << endl;
}

//ɾ��������Ů
void TreeNode::deleteChild()
{
	m_children.clear();
}

//��������
void TreeNode::updateName(string name)
{
	m_name = name;
}

//�����������Ϊname�Ľ��
TreeNode* Tree::search(string name)
{
	//ջ�����洢�����Ľ��
	stack<TreeNode *> st;
	TreeNode * p;
	//���������ջ
	st.push(m_root);
	//��ջ����
	while (!st.empty())
	{
		//ջ����ջ
		p = st.top();
		st.pop();
		//�ҵ����
		if (p->m_name == name)
		{
			return p;
		}
		//û���ҵ���Ӧ���
		else
		{
			//��p���ӽ����ջ
			for (int i = 0; i < p->m_children.size(); i++)
			{
				if (p->m_children[i] != NULL)
				{
					st.push(p->m_children[i]);
				}
			}	
		}
	}
	//û���ҵ�
	return NULL;
}

//ǰ��������г�Ա
void Tree::print()
{
	stack<TreeNode *> st;
	TreeNode * p;
	st.push(m_root);
	while (!st.empty())
	{
		p = st.top();
		st.pop();
		cout << p->m_name << " ";
		for (int i = p->m_children.size() - 1; i >= 0; i--)
		{
			if (p->m_children[i] != NULL)
			{
				st.push(p->m_children[i]);
			}
		}
	}
	cout << endl;
}