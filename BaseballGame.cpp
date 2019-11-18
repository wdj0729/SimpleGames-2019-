#include<iostream>
#include<random>
using namespace std;

//���� 100~999 ����
int getRandomNumber() {
	random_device rn;
	mt19937_64 rnd(rn());

	uniform_int_distribution<int> range(1, 9);

	return range(rnd);
}

int main() {
	int ans[3] = { 0, };

	for (int i = 0; i < 3; i++)
	{
		int answer = getRandomNumber();
		ans[i] = answer;
	}

	//�ߺ� ����
	while (1) {
		if (ans[0] == ans[1]) {
			ans[1] = getRandomNumber();
		}
		else if (ans[0] == ans[2]) {
			ans[2] = getRandomNumber();
		}
		else if (ans[1] == ans[2]) {
			ans[2] = getRandomNumber();
		}
		else {
			break;
		}
	}

	cout << "���� : " << ans[0] << ans[1] << ans[2] << '\n';

	while (1)
	{
		cout << "100~999 ������ ���ڸ� ���ڸ� �Է��ϼ���: ";
		int num;
		cin >> num;

		int temp[3] = { 0, };
		int i = 2;
		while (num > 0) {
			temp[i] = num % 10;
			num /= 10;
			i--;
		}

		cout << "�Է� �� : " << temp[0] << temp[1] << temp[2] << "\n";

		int strike = 0;
		int ball = 0;

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (ans[i] == temp[j] && i==j) {
					strike++;
					break;
				}
				else if (ans[i] == temp[j] && i != j) {
					ball++;
					break;
				}
			}
		}

		if (strike == 3) {
			cout << "�����Դϴ�!" << '\n';
			return 0;
		}
		else
			cout << "���: " << strike << "S " << ball << "B" << '\n';
	}

	return 0;
}