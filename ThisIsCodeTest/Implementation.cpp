#include "Common.h"
#include <map>
#include <sstream>
#include <queue>
//Implementation
//Tip (cin ����)
//�켱 cin �� ���� ���ڸ� �Է¹��� ��� �ٷ� ������ ���� ����Ǵ� �� �ƴ�
//�Է��� ���ڰ� �Է¹��ۿ� ����ǰ� ���ۿ� ����� ���� �о�鿩 ������ �����մϴ�.
//�׸��� ���ڸ� �Է¹��� ��쿡�� �ٷ� ������ �����ϱ� ������ ���۰� �ʿ�����ϴ�.
//�׷��� cin�� ���ؼ� ���ڸ� �Է¹޾� ������ ������ �Է��ϴ� ���߿�
//���ڰ� �ԷµǸ� �� ���ڴ� �Է¹��ۿ� ����ǰ� cin�� ���� �� �Է¹��ۿ� �ִ� ���� �о�鿩 ������ ������ �����Ϸ��� �ϱ� ������ ���������� ������ ���� �ʰ� ��� failbit�� �����ϸ�
//���ۿ��� ���� ��� �����ְ� �Ǵ� ���Դϴ�.
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
				// �ϳ��� 3�� ���Եǵ� �ǹǷ�
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
	//���ڿ��� ���� �ع�
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
	//���ڿ��� �ް� ���� ���� ��ǥ ��ȯ
	pair<int, int> loc = make_pair(0, 0);
	loc.first = input[0] - 'a' + 1; // char�� int�� ��ȯ (���������� intĳ���� )
	loc.second = input[1] - '0' ;
	// {x, y} Knight�� �����ϼ� �ִ� ���ͰŸ� ����� �� 
	vector<pair<int, int>> moveCase = { {2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2} };
	for (int i = 0; i < moveCase.size(); i++)
	{
		pair<int, int> vecPos = loc;
		vecPos.first += moveCase[i].first;
		vecPos.second += moveCase[i].second;
		// ���� ������ ��ġ�� ü���� ���� ������ O
		if (vecPos.first > 0 && vecPos.second > 0)
			count++;
	}
	cout << count;
}

#define MIN 3
#define MAX 50

// Level : �ڡ�
struct CharacterState {
	int col = 0; //��
	int row = 0; //��
	int direction = 0; // ����
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
	cs man(col, row, dir); // ĳ���� ���� ����
	vector<vector<int>> matrix(N, vector<int>(M, 0)); //init 
	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix[i].size(); j++)
		{
			cin >> matrix[i][j];
		}
	}
	//~input
	// �÷��̾� ȸ�� ���� ���� ( 0 : North , 1 : East, 2 : South ,3 : West )
	queue<int> dirCycle;
	int currdir = man.direction; // �ʱ� �� ����
	matrix[man.row][man.col] = -1; // -1�� �湮�ߴٴ� ���,
	//queue�� ȸ�� ���� ����
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
	int dx[4] = {0,1,0,-1}; // �Է����� index 0 : ����, 1:����, 2:����, 3 : ����
	int dy[4] = {1,0,-1,0};
	int visited_count= 1; // visited
	int check_around = 0;
	//�˰��� ����
	while (true)
	{
		
		int current_dir = dirCycle.front(); // ť���ִ� ���� ������ ����
		dirCycle.pop();
		//step 1. �÷��̾��� �ٷ� ���� ���⿡ ������ ���� ĭ�� ������� �������� ȸ���� ���� �������� ��ĭ ����
		//���� ���� ������ ���� üũ
		int row = man.row + dy[dirCycle.front()];
		int col = man.col + dx[dirCycle.front()];
		//���� ������ ���� üũ
		if ((row >= 0 && row < N) && (col >= 0 && col < M)) {
			int checkNext = matrix[row][col];
			if (checkNext == 0) {
				matrix[row][col] = -1; // �湮ó�� �� ���� �÷��̾� ��ġ ����
				man.row = row;
				man.col = col;
				man.direction = dirCycle.front();
				visited_count++;
				check_around = 0;
			}
			//1�̰ų� -1 �ΰ�� �÷��̾� ���⸸ ��ȯ
			else {
				man.direction = dirCycle.front();
				check_around++;
			}
		}
		//�׳� �ʿ����� �������
		else {
			man.direction = dirCycle.front();
			check_around++;
		}


		if (check_around >= 4) {//���� �ؾ���
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

