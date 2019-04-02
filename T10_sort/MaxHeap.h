#ifndef MAXHEAP_H
#define MAXHEAP_H
#include <iostream>
#include <cassert>
using namespace std;
const int DefaultSize = 50;


class MaxHeap {    // KΪ�ؼ�����������ͣ�intΪ��¼�Ľṹ����
private:
	int *heap;                        //���������Ԫ�ص�����
	int currentSize;                //�����е�ǰԪ�ظ���
	int maxHeapSize;                //�����������Ԫ�ظ���
public:
	MaxHeap(int sz = DefaultSize);//���캯���������ն�
	MaxHeap(vector<int> arr, int n);    //���캯����ͨ��һ�����齨��
	~MaxHeap()
	{
		delete[]heap;
	}
	bool Insert(const int &x);
	bool RemoveMax(int &x);
	bool IsEmpty()const
	{
		if (currentSize == 0)
			return true;
		else
			return false;
	}
	bool IsFull()const
	{
		if (currentSize == maxHeapSize)
			return true;
		else
			return false;
	}
	void MakeEmpty()
	{
		currentSize = 0;
	}
	void Swap(int i, int j)
	{
		int tmp = heap[i];
		heap[i] = heap[j];
		heap[j] = tmp;
	}

	void output() {//�Զ��庯����˳���������Ԫ��
		for (int i = 0; i < currentSize; i++)
		{
			cout << heap[i] << " ";
		}
		cout << endl;
	}
	void siftDown(int start, int m);//��start��m�»�������Ϊ����
	void siftDown(int start, int m, long long& swapTimes);//��start��m�»�������Ϊ����
	void siftUp(int start);            //��start��0�ϻ�������Ϊ����

};

#endif

// ���캯��
MaxHeap::MaxHeap(int sz) {
	maxHeapSize = (DefaultSize < sz) ? sz : DefaultSize;
	heap = new int[maxHeapSize];
	assert(heap);//���Ժ���
	currentSize = 0;
}
MaxHeap::MaxHeap(vector<int> arr, int n) {
	maxHeapSize = (DefaultSize < n) ? n : DefaultSize;
	heap = new int[maxHeapSize];
	assert(heap);
	for (int i = 0; i < n; i++)
	{
		heap[i] = arr[i];
	}
	currentSize = n;
}


//���ѵ��»������㷨
void MaxHeap::siftDown(int start, int m) {
	int i = start, j = 2 * i + 1;//j��i������Ůλ��
	int temp = heap[i];
	while (j <= m) {//����Ƿ����λ��
					//��jָ������Ů�е�С��
		if (j < m && heap[j] < heap[j + 1])
		{
			j++;
		}
		if (temp >= heap[j])
		{
			break;
		}
		else
		{
			heap[i] = heap[j];
			i = j;
			j = 2 * j + 1;
		}
	}
	heap[i] = temp;    //�ط�temp���ݴ��Ԫ��
}

//���ѵ��»������㷨����ͳ�Ƶ��������еĽ�������
void MaxHeap::siftDown(int start, int m, long long& swapTimes) {
	int i = start, j = 2 * i + 1;//j��i������Ůλ��
	int temp = heap[i];
	while (j <= m) {//����Ƿ����λ��
					//��jָ������Ů�е�С��
		if (j < m && heap[j] < heap[j + 1]) {
			j++;
		}
		if (temp >= heap[j]) {
			break;
		}
		else {
			heap[i] = heap[j];  swapTimes++;
			i = j;
			j = 2 * j + 1;
		}
	}
	heap[i] = temp;    //�ط�temp���ݴ��Ԫ��
}

// ���ѵ��ϻ������㷨
void MaxHeap::siftUp(int start) {
	int j = start, i = (j - 1) / 2;
	int temp = heap[j];
	while (j > 0) { //�ظ����·������ֱ���
		if (heap[i] >= temp) {
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

// ��x���뵽������
bool MaxHeap::Insert(const int &x) {
	if (currentSize == maxHeapSize) {    //����
		cerr << "Heap Full" << endl;
		return false;
	}
	heap[currentSize] = x;    //����
	siftUp(currentSize);    //���ϵ���
	currentSize++;            //�Ѽ�����1
	return true;
}

// ���ѵ�ɾ���㷨
bool MaxHeap::RemoveMax(int &x) {
	if (!currentSize) {    //�ѿ�, ����false

		cout << "Heap empty" << endl;
		return false;
	}
	x = heap[0];        // �������Ԫ��
	heap[0] = heap[currentSize - 1];    //���Ԫ����������
	currentSize--;
	siftDown(0, currentSize - 1);        //�������µ���Ϊ��
	return true;
}



