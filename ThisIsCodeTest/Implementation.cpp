#include "Common.h"
#include <map>
#include <sstream>
#include <queue>
//Implementation
//Tip (cin 관련)
//우선 cin 을 통해 문자를 입력받을 경우 바로 변수에 값이 저장되는 게 아닌
//입력한 문자가 입력버퍼에 저장되고 버퍼에 저장된 값을 읽어들여 변수에 저장합니다.
//그리고 숫자를 입력받을 경우에는 바로 변수에 저장하기 때문에 버퍼가 필요없습니다.
//그런데 cin을 통해서 숫자를 입력받아 정수형 변수에 입력하는 도중에
//문자가 입력되면 이 문자는 입력버퍼에 저장되고 cin을 통해 이 입력버퍼에 있는 값을 읽어들여 정수형 변수에 저장하려고 하기 때문에 정상적으로 저장이 되지 않고 계속 failbit를 설정하며
//버퍼에도 값이 계속 남아있게 되는 것입니다.
void page110Solution() {
	int range = 0;
	cin >> range;
	string plans;
	cin.ignore();
	getline(cin, plans);
	pair<int, int> loc(1, 1);
	for (int i = 0; i < plans.size(); i++)
	{
		char input;
		input = plans[i];
		switch (input)
		{
		case 'R':
			if (loc.first < range)
				loc.first++;
			break;
		case 'L':
			if (loc.first > 1)
				loc.first--;
			break;
		case 'U':
			if (loc.second > 1)
				loc.second--;
			break;

		case 'D':
			if (loc.second < range)
				loc.second++;
			break;
		default:
			break;
		}
	}
	cout << loc.second << " " << loc.first;
}

void page112Solution() {
	int N;
	cin >> N;
	int count = 0;
	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j < 60; j++)
		{
			for (int k= 0; k < 60; k++)
			{
				// 하나만 3이 포함되도 되므로
				if (k / 10 == 3 || k % 10 == 3)
				{
					count++;
				}
				else if (j / 10 == 3 || j % 10 == 3)
				{
					count++;
				}
				else if (i % 10 == 3) {
					count++;
				}
			}
		
		}
	
	}
	cout << count;
}
void page112Solution2() {
	//문자열을 통한 해법
	int N = 0;
	cin >> N;
	string input;
	int count = 0;
	for (int i = 0; i <=N; i++)
	{
		for (int j = 0; j < 60; j++)
		{
			for (int k = 0; k < 60; k++)
			{
				input = to_string(i) + to_string(j) + to_string(k);
				if (input.find("3")!=string::npos) 
				{
					count++;
				}
			}
		}
	}

	cout << count;
}


void page115Solution() {
	
	int count = 0;

	string input;
	cin >> input;
	//문자열로 받고 영문 가로 좌표 변환
	pair<int, int> loc = make_pair(0, 0);
	loc.first = input[0] - 'a' + 1; // char를 int로 변환 (묵시적으로 int캐스팅 )
	loc.second = input[1] - '0' ;
	// {x, y} Knight가 움직일수 있는 벡터거리 경우의 수 
	vector<pair<int, int>> moveCase = { {2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2} };
	for (int i = 0; i < moveCase.size(); i++)
	{
		pair<int, int> vecPos = loc;
		vecPos.first += moveCase[i].first;
		vecPos.second += moveCase[i].second;
		// 최종 움직인 위치가 체스판 위에 있으면 O
		if (vecPos.first > 0 && vecPos.second > 0)
			count++;
	}
	cout << count;
}

#define MIN 3
#define MAX 50

// Level : ★★
struct CharacterState {
	int col = 0; //열
	int row = 0; //행
	int direction = 0; // 방향
	CharacterState() {

	}
	CharacterState(int colA,int rowB,int dir) {
		col = colA;
		row = rowB;
		direction = dir;
	}
};
typedef CharacterState cs;
void page118Solution() {
	// input~
	int N, M;
	cin >> N >> M;
	int col, row, dir;
	cin >> row >> col >> dir;
	cs man(col, row, dir); // 캐릭터 상태 생성
	vector<vector<int>> matrix(N, vector<int>(M, 0)); //init 
	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix[i].size(); j++)
		{
			cin >> matrix[i][j];
		}
	}
	//~input
	// 플레이어 회전 방향 순서 ( 0 : North , 1 : East, 2 : South ,3 : West )
	queue<int> dirCycle;
	int currdir = man.direction; // 초기 값 저장
	matrix[man.row][man.col] = -1; // -1이 방문했다는 기록,
	//queue에 회전 순서 삽입
	for (int i = 0; i < 4; i++)
	{
		if (currdir % 4 < 0) {
			currdir = 3;
			dirCycle.push(currdir);
		}
		else {
			dirCycle.push(currdir);
		}
		currdir--;
	}
	int a = 0;
	int dx[4] = {0,1,0,-1}; // 입력조건 index 0 : 북쪽, 1:동쪽, 2:남쪽, 3 : 서쪽
	int dy[4] = {1,0,-1,0};
	int visited_count= 1; // visited
	int check_around = 0;
	//알고리즘 구현
	while (true)
	{
		
		int current_dir = dirCycle.front(); // 큐에있는 현재 방향을 추출
		dirCycle.pop();
		//step 1. 플레이어의 바로 왼쪽 방향에 가보지 않은 칸이 있을경우 왼쪽으로 회전한 다음 왼쪽으로 한칸 전진
		//지도 영역 내인지 조건 체크
		int row = man.row + dy[dirCycle.front()];
		int col = man.col + dx[dirCycle.front()];
		//지도 범위내 인지 체크
		if ((row >= 0 && row < N) && (col >= 0 && col < M)) {
			int checkNext = matrix[row][col];
			if (checkNext == 0) {
				matrix[row][col] = -1; // 방문처리 후 새로 플레이어 위치 갱신
				man.row = row;
				man.col = col;
				man.direction = dirCycle.front();
				visited_count++;
				check_around = 0;
			}
			//1이거나 -1 인경우 플레이어 방향만 전환
			else {
				man.direction = dirCycle.front();
				check_around++;
			}
		}
		//그냥 맵영역을 벗어났을때
		else {
			man.direction = dirCycle.front();
			check_around++;
		}


		if (check_around >= 4) {//후퇴 해야함
			int beforePos_row = man.row - dy[man.direction];
			int beforePos_col = man.col - dx[man.direction];
			man.row = beforePos_row;
			man.col = beforePos_col;
			if (matrix[man.row][man.col] == 1)
				break;
		}
		
		dirCycle.push(current_dir);
	}
	cout << visited_count;
	//t dx[4] = {}
		//int a = 0;
}
int main(void) {
	//page110Solution();
	//page112Solution();
	//page112Solution2();
	//page115Solution();
	page118Solution();
	return 0;
}

