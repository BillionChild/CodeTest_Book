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

int main(void) {
	page110Solution();
	return 0;
}

