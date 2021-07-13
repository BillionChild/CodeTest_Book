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

int main(void) {
	page110Solution();
	return 0;
}

