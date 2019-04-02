#ifndef MAXHEAP_H
#define MAXHEAP_H
#include <iostream>
#include <cassert>
using namespace std;
const int DefaultSize = 50;


class MaxHeap {    // K为关键码的数据类型，int为记录的结构类型
private:
	int *heap;                        //存放最大堆中元素的数组
	int currentSize;                //最大堆中当前元素个数
	int maxHeapSize;                //最大堆最多允许元素个数
public:
	MaxHeap(int sz = DefaultSize);//构造函数：建立空堆
	MaxHeap(vector<int> arr, int n);    //构造函数：通过一个数组建堆
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

	void output() {//自定义函数，顺序输出最大堆元素
		for (int i = 0; i < currentSize; i++)
		{
			cout << heap[i] << " ";
		}
		cout << endl;
	}
	void siftDown(int start, int m);//从start到m下滑调整成为最大堆
	void siftDown(int start, int m, long long& swapTimes);//从start到m下滑调整成为最大堆
	void siftUp(int start);            //从start到0上滑调整成为最大堆

};

#endif

// 构造函数
MaxHeap::MaxHeap(int sz) {
	maxHeapSize = (DefaultSize < sz) ? sz : DefaultSize;
	heap = new int[maxHeapSize];
	assert(heap);//断言函数
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


//最大堆的下滑调整算法
void MaxHeap::siftDown(int start, int m) {
	int i = start, j = 2 * i + 1;//j是i的左子女位置
	int temp = heap[i];
	while (j <= m) {//检查是否到最后位置
					//让j指向两子女中的小者
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
	heap[i] = temp;    //回放temp中暂存的元素
}

//最大堆的下滑调整算法，并统计调整过程中的交换次数
void MaxHeap::siftDown(int start, int m, long long& swapTimes) {
	int i = start, j = 2 * i + 1;//j是i的左子女位置
	int temp = heap[i];
	while (j <= m) {//检查是否到最后位置
					//让j指向两子女中的小者
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
	heap[i] = temp;    //回放temp中暂存的元素
}

// 最大堆的上滑调整算法
void MaxHeap::siftUp(int start) {
	int j = start, i = (j - 1) / 2;
	int temp = heap[j];
	while (j > 0) { //沿父结点路径向上直达根
		if (heap[i] >= temp) {
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

// 将x插入到最大堆中
bool MaxHeap::Insert(const int &x) {
	if (currentSize == maxHeapSize) {    //堆满
		cerr << "Heap Full" << endl;
		return false;
	}
	heap[currentSize] = x;    //插入
	siftUp(currentSize);    //向上调整
	currentSize++;            //堆计数加1
	return true;
}

// 最大堆的删除算法
bool MaxHeap::RemoveMax(int &x) {
	if (!currentSize) {    //堆空, 返回false

		cout << "Heap empty" << endl;
		return false;
	}
	x = heap[0];        // 返回最大元素
	heap[0] = heap[currentSize - 1];    //最后元素填补到根结点
	currentSize--;
	siftDown(0, currentSize - 1);        //自上向下调整为堆
	return true;
}



