#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
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
			sum += *(arr+1);
			count_K = K;
		}

	}
	delete[] arr;
	cout << sum;
}

//page96
//Greedy 숫자 카드 게임
void page96Solution() {
	int N, M;
	cin >> N >> M;
	vector<vector<int>> card(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int input = 0;
			cin >> input;
			card[i][j] = input;
		}
	}

	vector<int> maxCard;
	for (int i = 0; i < card.size(); i++)
	{
		int input = *min_element(card[i].begin(), card[i].end()); // min val by range of vector[i]
		maxCard.push_back(input);
	}
	
	cout << *max_element(maxCard.begin(), maxCard.end());

}

int main(void) {
	//page92Solution();
	page96Solution();
	return 0;
}