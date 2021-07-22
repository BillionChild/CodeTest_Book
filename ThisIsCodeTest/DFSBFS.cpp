#include "Common.h"



bool page149DFS(int row,int col,int N,int M, vector<vector<bool>>& check)
{
	//범위 안인지 밖인지 체크
	if (!(row < N && row >= 0 &&col < M && col>= 0))
		return false;
	//방문한 기록이있는지 체크
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
	// 음료수 얼려 먹기 (BFS & DFS )
	// N X M
	int N =0;
	int M =0;
	cin >> N >> M;
	cin.ignore();
	int result =0;
	string input;
	//입력값 정리
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



void page152Solution() {
	//BFS
	int N, M;
	cin >> N >> M;
	vector<vector<int>> maze(N,vector<int>(M,0));
	string input;

	// 시작 값 입력
	for (int i = 0; i < maze.size(); i++)
	{
		string input;
		cin >> input;
		for (int j= 0; j < maze[i].size(); j++)
		{	
			maze[i][j] =(int)(input[j] - '0');
		}
	}
	//BFS에 활용할 큐 구현
	queue<pair<int,int>> q;
	q.push(make_pair(0, 0));
	int count = 1;
	while (!q.empty())
	{
		int row = q.front().first;
		int col = q.front().second;
		if (row+1< N) {
			if(maze[row + 1][col] == 1){
				q.push(make_pair(row + 1, col));
				maze[row + 1][col] = row+1+col+1;
			}
		}
		if (col+1<M) {
			if(maze[row][col + 1] == 1){
				q.push(make_pair(row, col+1));
				maze[row][col+1] = row + col+1 + 1;
			}
		}
		q.pop();
	}
	cout << maze[N - 1][M - 1];



}

//int main(void) {
//	//page149Solution();
//	//page152Solution();
//	return 0;
//}

