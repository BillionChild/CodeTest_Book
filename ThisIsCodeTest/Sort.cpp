#include "Common.h"

//Select Sort
void SelectSort() {
	int arr[10] = { 5,9,4,3,2,1,6,7,8,0 };
	// 선택정렬에 핵심은 min,max를 이용하여 오름 내림 차순 정렬 수행
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
//void InsertSort
//Quick Sort


bool compare(int a, int b) {
	return a > b;
}


void page178Solution() {
	//From up to Down..
	int N = 0;
	cin >> N;
	vector<int> list;
	for (int i = 0; i<N;i++)
	{
		int input;
		cin >> input;
		list.push_back(input);
	}

	//sort(list.begin(), list.end());
	sort(list.begin(), list.end(), greater<int>());
	for (int i = 0; i < list.size(); i++)
	{
		cout << list[i] << " ";
	}
	
}

bool page180Compare(pair<string, int> a, pair<string, int> b) {
	return a.second < b.second;
}
void page180Solution() {
	int N = 0;
	cin >> N;
	vector<pair<string, int>> members;
	for (size_t i = 0; i < N; i++)
	{
		pair<string, int> member;
		cin >> member.first >> member.second;
		members.push_back(member);
	}
	sort(members.begin(), members.end(), page180Compare);
	int test;
	for (size_t i = 0; i < members.size(); i++)
	{
		cout << members[i].first << " ";
	}	
}

void page182solution() {
	int N = 0;
	int K = 0;
	cin >> N >> K;
	
	int* arr1 = new int[N]; //min 하고 교체
	int* arr2 = new int[N]; //max 하고 교체 

	
	for (int j = 0; j < N; j++)
	{
		cin >> arr1[j];
	}
	for (int j = 0; j < N; j++)
	{
		cin >> arr2[j];
	}

	sort(arr1, arr1 + N); // 오름차순
	sort(arr2, arr2 + N, greater<int>()); //내림 차순

	int test = 0;
	for (int i = 0; i < K; i++)
	{
		int temp = arr1[i];
		arr1[i] = arr2[i];
		arr2[i] = temp;
	}

	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		sum += arr1[i];
	}
	cout << sum;
	delete[] arr1;
	delete[] arr2;

}

int main(void) {
	//SelectSort();
	//page178Solution();
	//page180Solution();
	//
	page182solution();
	return 0;
}

