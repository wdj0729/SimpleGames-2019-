#include<iostream>
#include <random>
using namespace std;

//���� 1~100 ����
int getRandomNumber() {
	random_device rn;
	mt19937_64 rnd(rn());

	uniform_int_distribution<int> range(1, 100);

	return range(rnd);
}

int main() {
	int answer = getRandomNumber(); //����

	cout << "1~100 ������ ������ ���ڸ� 7�� �ȿ� ����������!" << "\n";
	cout << "��Ʈ�� ���亸�� ���� ���� Ȥ�� ���� �������� �˷��帳�ϴ�!" << "\n";

	for (int i = 0; i < 7; i++) {
		cout << "���ڸ� �����ּ���: ";
		int num;
		cin >> num;

		if (num == answer) {
			cout << "����ϳ׿�. �����Դϴ�!";
			return 0;
		}
		else {
			if (num < answer) {
				cout << "�� ���� �����Դϴ�!" << '\n';
			}
			else {
				cout << "�� ���� �����Դϴ�!" << '\n';
			}
		}
	}

	cout << "��Ÿ���Ե� �� ���߼̳׿�. ������ �� �����ϼ���!";

	return 0;
}