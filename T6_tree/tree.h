#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

//树的结点类
class TreeNode
{
public:
	//成员名字
	string m_name;
	//子结点数组
	vector<TreeNode *> m_children;
	//构造函数
	TreeNode() { m_name = "";}
	//添加子女
	void AddChild(string name);
	//输出子女
	void printChild();
	//删除子女
	void deleteChild();
	//更改姓名
	void updateName(string name);
};

//树类
class Tree 
{
	//友元树结点
	friend TreeNode;
public:
	//根结点
	TreeNode *m_root;
	//构造函数
	Tree() { m_root = new TreeNode; m_root->m_name = "";}
	Tree(string a) { m_root = new TreeNode; m_root->m_name = a; }
	//返回根结点
	string getRoot() { return m_root -> m_name; }
	//搜索姓名为name的结点
	TreeNode* search(string name);
	//输出全部成员
	void print();
};
#endif

//添加子女
void TreeNode::AddChild(string name)
{
		TreeNode *child = new TreeNode;
		child->m_name = name;
		m_children.push_back(child);
}

//输出子女
void TreeNode::printChild()
{
	int i = 0;
	for (i; i < m_children.size() ; i++)
	{
		cout << m_children[i]->m_name << "  ";
	}
	cout << endl;
}

//删除所有子女
void TreeNode::deleteChild()
{
	m_children.clear();
}

//更改姓名
void TreeNode::updateName(string name)
{
	m_name = name;
}

//深度搜索姓名为name的结点
TreeNode* Tree::search(string name)
{
	//栈用来存储经过的结点
	stack<TreeNode *> st;
	TreeNode * p;
	//将根结点入栈
	st.push(m_root);
	//当栈不空
	while (!st.empty())
	{
		//栈顶出栈
		p = st.top();
		st.pop();
		//找到结点
		if (p->m_name == name)
		{
			return p;
		}
		//没有找到对应结点
		else
		{
			//将p的子结点入栈
			for (int i = 0; i < p->m_children.size(); i++)
			{
				if (p->m_children[i] != NULL)
				{
					st.push(p->m_children[i]);
				}
			}	
		}
	}
	//没有找到
	return NULL;
}

//前序输出所有成员
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