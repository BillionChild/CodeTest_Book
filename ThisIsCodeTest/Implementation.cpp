#include "Common.h"
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
	istringstream ss(plans);
	string Buffer;
	getline(ss, Buffer, ' ');
	int a = 0;
}

int main(void) {
	page110Solution();
	return 0;
}

