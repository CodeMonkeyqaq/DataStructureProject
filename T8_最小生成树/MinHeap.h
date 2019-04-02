#ifndef MinHeap_H
#define MinHeap_H

#include <iostream>
#include <string>
#include <cassert>
using namespace std;
const int DefaultSize = 50;

struct ed {
	int tail;
	int head;
	int key;
};

class MinHeap{// TΪ�ؼ�����������ͣ�ItemΪ��¼�Ľṹ����
public:
	MinHeap(int sz = DefaultSize);//���캯���������ն�
	~MinHeap()
	{
		delete[]heap;
	}
	bool Insert(const ed &x);
	bool RemoveMin(ed &x);
	bool IsEmpty()const {
		return currentSize == 0;
	}
	bool IsFull()const {
		return currentSize == maxHeapSize;
	}
	void MakeEmpty() {
		currentSize = 0;
	}

	void output() {//�Զ��庯����˳�������С��Ԫ��
		for (int i = 0; i < currentSize; i++)
			cout << heap[i].head << "-<" << heap[i].key << ">-" << heap[i].tail << " ";
		cout << endl;
	}

private:
	ed *heap;                        //�����С����Ԫ�ص�����
	int currentSize;                //��С���е�ǰԪ�ظ���
	int maxHeapSize;                //��С���������Ԫ�ظ���
	void siftDown(int start, int m);//��start��m�»�������Ϊ��С��
	void siftUp(int start);            //��start��0�ϻ�������Ϊ��С��
};

// ���캯���������ն�
MinHeap::MinHeap(int sz) {
	maxHeapSize = (DefaultSize < sz) ? sz : DefaultSize;
	heap = new ed[maxHeapSize];
	assert(heap);
	currentSize = 0;
}

//˽�к�������С�ѵ��»������㷨
void MinHeap::siftDown(int start, int m) {
	int i = start, j = 2 * i + 1;//j��i������Ůλ��
	ed temp = heap[i];
	while (j <= m) {//����Ƿ����λ��
					//��jָ������Ů�е�С��
		if (j < m && heap[j].key > heap[j + 1].key)
		{
			j++;
		}
		if (temp.key <= heap[j].key) {
			break;
		}
		else {
			heap[i] = heap[j];
			i = j;
			j = 2 * j + 1;
		}
	}
	heap[i] = temp;    //�ط�temp���ݴ��Ԫ��
}

// ˽�к�������С�ѵ��ϻ������㷨
void MinHeap::siftUp(int start) {
	int j = start, i = (j - 1) / 2;
	ed temp = heap[j];
	while (j > 0) { //�ظ����·������ֱ���
		if (heap[i].key <= temp.key) {
			break;
		}
		else {
			heap[j] = heap[i];
			j = i;
			i = (i - 1) / 2;
		}
	}
	heap[j] = temp;    //�ط�temp���ݴ��Ԫ��
}

// ��������: ��x���뵽��С����
bool MinHeap::Insert(const ed &x) {
	if (currentSize == maxHeapSize) {    //����
		cerr << "Heap Full" << endl;
		return false;
	}
	heap[currentSize] = x;    //����
	siftUp(currentSize);    //���ϵ���
	currentSize++;            //�Ѽ�����1
	return true;
}

// ������������С�ѵ�ɾ���㷨
bool MinHeap::RemoveMin(ed &x) {
	if (!currentSize) {    //�ѿ�, ����false
		cout << "Heap empty" << endl;
		return false;
	}
	x = heap[0];        // ������СԪ��
	heap[0] = heap[currentSize - 1];    //���Ԫ����������
	currentSize--;
	siftDown(0, currentSize - 1);        //�������µ���Ϊ��
	return true;
}

#endif
