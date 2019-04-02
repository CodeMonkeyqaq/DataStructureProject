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

class MinHeap{// T为关键码的数据类型，Item为记录的结构类型
public:
	MinHeap(int sz = DefaultSize);//构造函数：建立空堆
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

	void output() {//自定义函数，顺序输出最小堆元素
		for (int i = 0; i < currentSize; i++)
			cout << heap[i].head << "-<" << heap[i].key << ">-" << heap[i].tail << " ";
		cout << endl;
	}

private:
	ed *heap;                        //存放最小堆中元素的数组
	int currentSize;                //最小堆中当前元素个数
	int maxHeapSize;                //最小堆最多允许元素个数
	void siftDown(int start, int m);//从start到m下滑调整成为最小堆
	void siftUp(int start);            //从start到0上滑调整成为最小堆
};

// 构造函数：建立空堆
MinHeap::MinHeap(int sz) {
	maxHeapSize = (DefaultSize < sz) ? sz : DefaultSize;
	heap = new ed[maxHeapSize];
	assert(heap);
	currentSize = 0;
}

//私有函数：最小堆的下滑调整算法
void MinHeap::siftDown(int start, int m) {
	int i = start, j = 2 * i + 1;//j是i的左子女位置
	ed temp = heap[i];
	while (j <= m) {//检查是否到最后位置
					//让j指向两子女中的小者
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
	heap[i] = temp;    //回放temp中暂存的元素
}

// 私有函数：最小堆的上滑调整算法
void MinHeap::siftUp(int start) {
	int j = start, i = (j - 1) / 2;
	ed temp = heap[j];
	while (j > 0) { //沿父结点路径向上直达根
		if (heap[i].key <= temp.key) {
			break;
		}
		else {
			heap[j] = heap[i];
			j = i;
			i = (i - 1) / 2;
		}
	}
	heap[j] = temp;    //回放temp中暂存的元素
}

// 公共函数: 将x插入到最小堆中
bool MinHeap::Insert(const ed &x) {
	if (currentSize == maxHeapSize) {    //堆满
		cerr << "Heap Full" << endl;
		return false;
	}
	heap[currentSize] = x;    //插入
	siftUp(currentSize);    //向上调整
	currentSize++;            //堆计数加1
	return true;
}

// 公共函数：最小堆的删除算法
bool MinHeap::RemoveMin(ed &x) {
	if (!currentSize) {    //堆空, 返回false
		cout << "Heap empty" << endl;
		return false;
	}
	x = heap[0];        // 返回最小元素
	heap[0] = heap[currentSize - 1];    //最后元素填补到根结点
	currentSize--;
	siftDown(0, currentSize - 1);        //自上向下调整为堆
	return true;
}

#endif
