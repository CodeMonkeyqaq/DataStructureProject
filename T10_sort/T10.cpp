/*
**author:������_1652977
**theme:���ݽṹ�γ����_T10
**question:8�������㷨�ıȽϰ���
**application:�����㷨
*/
#include <time.h>
#include <stdlib.h>
#include <vector>
#include "MaxHeap.h"
#include "staticList.h"

int number;//������������ĸ���
const int radix = 10;//����


/*
*@brief: ��ʾ����ѡ��˵�
*/
void showMenu()
{
	cout << "**\t\t�����㷨�Ƚ�\t\t**" << endl;
	cout << "==========================================" << endl;
	cout << "**\t\t1 --- ð������\t\t**" << endl;
	cout << "**\t\t2 --- ѡ������\t\t**" << endl;
	cout << "**\t\t3 --- ֱ�Ӳ�������\t**" << endl;
	cout << "**\t\t4 --- ϣ������\t\t**" << endl;
	cout << "**\t\t5 --- ��������\t\t**" << endl;
	cout << "**\t\t6 --- ������\t\t**" << endl;
	cout << "**\t\t7 --- �鲢����\t\t**" << endl;
	cout << "**\t\t8 --- ��������\t\t**" << endl;
	cout << "**\t\t9 --- �˳�����\t\t**" << endl;
	cout << "==========================================" << endl << endl;
}


void setOrigin(vector<int>& original)
{
	cout << "������Ҫ������������ĸ�����";
	while (1)
	{
		if (!(cin >> number))
		{
			cout << "����Ƿ�������������" << endl;
			cin.clear();
			while (cin.get() != '\n')
			{
				continue;
			}
		}
		else
		{
			if (number > 100000)
			{
				cout << "�벻Ҫ���볬��100000������" << endl;
			}
			else if (number <= 0)
			{
				cout << "������һ��������" << endl;
			}
			else
			{
				break;
			}
		}
	}
	srand(time(NULL));
	for (int i = 0; i < number; i++)
	{
		original.push_back(rand());
	}
	/*for (int i = 0; i < original.size(); i++)
	{
	cout << original[i] << " ";
	}*/
}

//��������
void BubbleSort(vector<int>& original)
{
	bool exchange;
	int i, j;
	long long stepNumber = 0;
	clock_t start, end;
	start = clock();
	for (i = 1; i < original.size(); i++)
	{
		exchange = false;
		for (j = original.size() - 1; j >= i; j--)
		{
			if (original[j - 1] > original[j])
			{
				swap(original[j - 1], original[j]);
				stepNumber++;
				exchange = true;
			}
		}
		if (exchange == false)
			break;
	}
	end = clock();
	cout << "ð����������ʱ��:" << '\t' << (float)(end - start) * 1000 / CLOCKS_PER_SEC << "����" << endl;
	cout << "ð�����򽻻�����:" << '\t' << stepNumber << endl;
	/*for (int i = 0; i < original.size(); i++)
	{
	cout << original[i] << " ";
	}*/
}

//ѡ������
void SelectSort(vector<int>& original)
{
	long long stepNumber = 0;
	clock_t start, end;
	start = clock();
	for (int i = 0; i < original.size() - 1; i++)
	{
		int k = i;
		for (int j = i + 1; j < original.size() - 1; j++)
		{
			if (original[j] < original[k])
			{
				k = j;
			}
		}
		if (k != i)
		{
			swap(original[i], original[k]);
			stepNumber++;
		}
	}
	end = clock();
	cout << "ѡ����������ʱ��:" << '\t' << (float)(end - start) * 1000 / CLOCKS_PER_SEC << "����" << endl;
	cout << "ѡ�����򽻻�����:" << '\t' << stepNumber << endl;
	/*for (int i = 0; i < original.size(); i++)
	{
	cout << original[i] << " ";
	}*/
}

//ֱ�Ӳ�������
void InsertSort(vector<int>& original)
{
	long long stepNumber = 0;
	clock_t start, end;
	int i, j, temp;
	start = clock();
	for (i = 1; i <= original.size() - 1; i++)
	{
		if (original[i] < original[i - 1])
		{
			temp = original[i];
			j = i - 1;
			do
			{
				original[j + 1] = original[j];
				j--;
				stepNumber++;
			} while (j >= 0 && temp < original[j]);
			original[j + 1] = temp;
		}
	}
	end = clock();
	cout << "ֱ�Ӳ�����������ʱ��:" << '\t' << (float)(end - start) * 1000 / CLOCKS_PER_SEC << "����" << endl;
	cout << "ֱ�Ӳ������򽻻�����:" << '\t' << stepNumber << endl;
	/*for (int i = 0; i < original.size(); i++)
	{
	cout << original[i] << " ";
	}*/
}

//ϣ������
void ShellSort(vector<int>& original)
{
	int i, j, gap = original.size();
	int temp;
	long long stepNumber = 0;
	clock_t start, end;
	start = clock();
	do {
		gap = gap / 3 + 1;
		for (i = gap; i < original.size(); i++)
		{
			if (original[i] < original[i - gap])
			{
				temp = original[i];
				j = i - gap;
				do {
					original[j + gap] = original[j];
					j = j - gap;
					stepNumber++;
				} while (j >= 0 && temp < original[j]);
				original[j + gap] = temp;
				stepNumber++;
			}
		}

	} while (gap > 1);
	end = clock();
	cout << "ϣ����������ʱ��:" << '\t' << (float)(end - start) * 1000 / CLOCKS_PER_SEC << "����" << endl;
	cout << "ϣ�����򽻻�����:" << '\t' << stepNumber << endl;
	/*for (int i = 0; i < original.size(); i++)
	{
	cout << original[i] << " ";
	}*/
}

//���Ż��ֺ���
int Partition(vector<int>& original, const int low, const int high, long long & stepNumber)
{
	int pivotpos = low;
	int pivot = original[low];
	for (int i = low + 1; i <= high; i++)
	{
		if (original[i] < pivot)
		{
			pivotpos++;
			if (pivotpos != i)
			{
				swap(original[pivotpos], original[i]);
				stepNumber++;
			}
		}
	}
	original[low] = original[pivotpos];
	original[pivotpos] = pivot;
	stepNumber++;
	return pivotpos;
}

//��������
void QuickSort(vector<int>& original, const int left, const int right, long long &stepNumber)
{
	if (left < right)
	{
		int pivotpos = Partition(original, left, right, stepNumber);
		QuickSort(original, left, pivotpos - 1, stepNumber);
		QuickSort(original, pivotpos + 1, right, stepNumber);
	}
}

//������
void HeapSort(MaxHeap& a, int currentSize)
{
	long long stepNumber = 0;
	clock_t start, end;
	start = clock();
	for (int i = (currentSize - 2) / 2; i >= 0; i--)
	{
		a.siftDown(i, currentSize - 1, stepNumber);
	}
	for (int i = currentSize - 1; i >= 0; i--)
	{
		a.Swap(0, i);
		a.siftDown(0, i - 1, stepNumber);
	}
	end = clock();
	cout << "����������ʱ�䣺" << '\t' << (float)(end - start) * 1000 / CLOCKS_PER_SEC << "����" << endl;
	cout << "�����򽻻�������" << '\t' << stepNumber << endl;
	//a.output();
}

//��·�鲢�㷨
void merge(vector<int> &LeftSubArray, vector<int> &RightSubArray,const int left,const int mid,const int right, long long& stepNumber)
{
	for (int k = left; k <= right; k++)
	{
		RightSubArray[k] = LeftSubArray[k];
	}
	int s1 = left, s2 = mid + 1, t = left;
	while (s1 <= mid&&s2 <= right)
	{
		if (RightSubArray[s1] <= RightSubArray[s2])
		{
			LeftSubArray[t++] = RightSubArray[s1++];
			stepNumber++;
		}
		else
		{
			LeftSubArray[t++] = RightSubArray[s2++];
			stepNumber++;
		}
	}
	while (s1 <= mid)
	{
		LeftSubArray[t++] = RightSubArray[s1++];
		stepNumber++;
	}
	while (s2 <= right)
	{
		LeftSubArray[t++] = RightSubArray[s2++];
		stepNumber++;
	}
}

//�鲢����
void MergeSort(vector<int> &leftSubArray, vector<int> &rightSubArray, int front, int end, long long& stepNumber) {
	if (front >= end)
		return;
	int mid = (front + end) / 2;
	MergeSort(leftSubArray, rightSubArray, front, mid, stepNumber);
	MergeSort(leftSubArray, rightSubArray, mid + 1, end, stepNumber);
	merge(leftSubArray, rightSubArray, front, mid, end, stepNumber);
}

//��ȡ��Ӧλ���ϵ���
int getDigit(int number, int digit)
{
	int result;
	for (int i = 0; i < (5 - digit); i++)
	{
		number /= radix;
	}
	result = number % radix;
	return result;
}

//��������
void RadixSort(StaticList& L, int d)
{
	long long stepNumber = 0;
	clock_t start, end;
	start = clock();
	int rear[radix], front[radix];
	int i, j, k, last, current, n = L.length();
	L.setLink(n, 0);
	current = 1;
	for (int i = d; i >= 1; i--)
	{
		for (j = 0; j < radix; j++)
		{
			front[j] = 0;
		}
		while (current != 0)
		{
			k = getDigit(L.getNode(current), i);

			if (front[k] == 0)
			{
				front[k] = current;
			}
			else
			{
				L.setLink(rear[k], current);
			}
			rear[k] = current;
			current = L.getLink(current);
		}
		j = 0;
		while (front[j] == 0)
		{
			j++;
		}
		L.setLink(0, front[j]);
		current = front[j];
		last = rear[j];
		for (k = j + 1; k < radix; k++)
		{
			if (front[k] != 0) {
				L.setLink(last, front[k]);
				last = rear[k];
			}
		}
		L.setLink(last, 0);
	}
	end = clock();
	cout << "������������ʱ��:" << '\t' << (float)(end - start) * 1000 / CLOCKS_PER_SEC << "����" << endl;
	cout << "�������򽻻�����:" << '\t' << stepNumber << endl;
	//L.print();
}

int main()
{
	char order;
	showMenu();
	vector<int> original;
	setOrigin(original);
	vector<int> original1 = original;
	while (1)
	{
		original1 = original;
		cout << "��ѡ�������㷨:" << '\t';
		cin >> order;
		switch (order)
		{
		case '1':
			BubbleSort(original1);
			break;
		case '2':
			SelectSort(original1);
			break;
		case '3':
			InsertSort(original1);
			break;
		case '4':
			ShellSort(original1);
			break;
		case '5':
		{
			long long stepNumber = 0;
			clock_t start, end;
			start = clock();
			QuickSort(original1, 0, original1.size() - 1, stepNumber);
			end = clock();
			cout << "������������ʱ��:" << '\t' << (float)(end - start) * 1000 / CLOCKS_PER_SEC << "����" << endl;
			cout << "�������򽻻�����:" << '\t' << stepNumber << endl;
			/*for (int i = 0; i < original.size(); i++)
			{
			cout << original1[i] << " ";
			}*/
			break;
		}
		case '6':
		{
			MaxHeap a = MaxHeap(original, number);
			HeapSort(a, number);
			break;
		}
		case '7': 
		{
			vector<int> temp(number);
			long long stepNumber = 0;
			clock_t start, end;
			start = clock();
			MergeSort(original1, temp, 0, original1.size() - 1, stepNumber);
			end = clock();
			/*for (int i = 0; i < original.size(); i++)
			{
				cout << original1[i] << " ";
			}*/
			cout << "�鲢��������ʱ��:" << '\t' << (float)(end - start) * 1000 / CLOCKS_PER_SEC << "����" << endl;
			cout << "�鲢���򽻻�����:" << '\t' << stepNumber << endl;
			break;
		}
		case '8':
		{
			StaticList a;
			a.InitList();
			clock_t start, end;
			start = clock();
			for (int i = 1; i <= original1.size(); i++)
			{
				a.Append(original1[i - 1]);
			}
			end = clock();
			cout << "�����������ݴ洢����ʱ��:" << '\t' << (float)(end - start) * 1000 / CLOCKS_PER_SEC << "����" << endl;
			RadixSort(a, 5);
			break;
		}
		case '9':
			cout << "�˳�ϵͳ�ɹ���" << endl;
			system("pause");
			return 0;
		default:
			cout << "�����ָ���������������롣" << endl;
			break;
		}
	}
	system("pause");
	return 0;
}