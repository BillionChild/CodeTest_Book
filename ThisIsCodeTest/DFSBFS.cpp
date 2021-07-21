#include "Common.h"

bool page149DFS(int row,int col,int N,int M, vector<vector<bool>>& check)
{
	//���� ������ ������ üũ
	if (!(row < N && row >= 0 &&col < M && col>= 0))
		return false;
	//�湮�� ������ִ��� üũ
	if (check[row][col])
		return false;
	else {
		check[row][col] = true;	
		page149DFS(row + 1, col, N, M, check);
		page149DFS(row , col+1, N, M, check);
		return true;
	}
	return false;
}

void page149Solution() {
	// ����� ��� �Ա� (BFS & DFS )
	// N X M
	int N =0;
	int M =0;
	cin >> N >> M;
	cin.ignore();
	int result =0;
	string input;
	//�Է°� ����
	vector<vector<bool>> check(N, vector<bool>(M, 0));
	
	for (int i = 0; i < check.size(); i++)
	{
		cin >> input;
		for (int j= 0; j< check[i].size(); j++)
		{
			check[i][j] = input[j] - '0';
		}
		cin.ignore();
	}
	int cc = 0;
	for(int i = 0; i < check.size(); i++)
	{
		for (int j = 0; j < check[i].size(); j++)
		{
			if (page149DFS(i, j,N,M, check))
				result++;
		}
	}
	cout << result;
}


int main(void) {
	page149Solution();
	return 0;
}

