#include "Common.h"

//Select Sort
void SelectSort() {
	int arr[10] = { 5,9,4,3,2,1,6,7,8,0 };
	// �������Ŀ� �ٽ��� min,max�� �̿��Ͽ� ���� ���� ���� ���� ����
	for (int i = 0; i < 10; i++)
	{
		int min = 99999999;
		int index = -1;
		for (int j = i; j < 10; j++)
		{
			int val = arr[j];
			if (val < min)
			{
				min = val;
				index = j;
			}
		}
		int temp = arr[i];
		arr[i] = min;
		arr[index] = temp;
	}
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << " ";
	}
}
//Insert Sort

//Quick Sort

//Bubble Sort
//
//
int main(void) {
	SelectSort();
	return 0;
}

