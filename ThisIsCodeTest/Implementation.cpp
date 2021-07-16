#include "Common.h"
#include <map>
#include <sstream>
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

int main(void) {
	//page110Solution();
	//page112Solution();
	//page112Solution2();
	page115Solution();
	return 0;
}

