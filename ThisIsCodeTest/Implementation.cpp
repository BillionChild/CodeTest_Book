#include "Common.h"
#include <map>
#include <sstream>
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

int main(void) {
	//page110Solution();
	//page112Solution();
	//page112Solution2();
	page115Solution();
	return 0;
}

