#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//page87
//Greedy
void page92Solution() 
{
	int N = 0 , M=0, K=0;
	cin >> N >> M >> K;

	int* arr = new int[N];

	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	
	sort(arr, arr+N,greater<int>());
	int count_K = K;
	for (int i = 0; i < M; i++)
	{
		if (count_K != 0) {
			sum += arr[0];
			count_K--;
		}
		else {
			sum += arr[1];
			count_K = K;
		}

	}
	delete[] arr;
	cout << sum;
}


int main(void) {
	page92Solution();
	return 0;
}