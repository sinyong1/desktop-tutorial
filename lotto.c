#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <Windows.h>
#include <time.h>
#include <string.h>
#include <mmsystem.h>    
#pragma comment(lib, "winmm.lib")
void setColor(unsigned short, unsigned short);
void gotoxy(int x, int y) {
	COORD Cur = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}
void move(char* s) {
	int i, l = strlen(s);
	char t = s[0];
	for (i = 0; i < l - 1; i++) {
		s[i] = s[i + 1];
	}
	s[i] = t;
}
void remove2(char* s) {
	int i, l = strlen(s);
	char t = s[l - 1];
	for (i = l; i > 0; i--) {
		s[i] = s[i - 1];
	}
	s[0] = t;
}
void reslide(char* str)
{
	remove2(str);
	gotoxy(1, 10);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), rand() % 5 + 10);
	printf("%s", str);
	Sleep(100);
}
void reslide2(char* str)
{
	remove2(str);
	gotoxy(1, 1);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), rand() % 5 + 10);
	printf("%s", str);
	Sleep(100);
}
void start(char* str) {
	char str2[500], str3[500];
	strcpy(str2, str);
	strcpy(str3, str);
	for (int i = 0; i < 20; i++) {
		reslide(str);
		reslide2(str);
		system("cls");
	}
}
int sun();
int main() {
	system("mode con cols=80 lines=30");
	int temp = 0;
	int rtemp = 0;
	// 5*6 30���� ���ڸ� ���� 2���� �迭�� ����
	int lottary[5][6];
	int count;
	int numCount = 0;
	int odd;
	int even;
	char x[400] = "�� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� ����\n��  ��         ��     �ߡߡ�   �ߡߡ�    ��     ��\n��  ��       ��  ��     ��       ��    ��  ��   ��\n��  ��       ��  ��     ��       ��    ��  ��   ��\n��  �ߡߡߡ�   ��       ��       ��      ��     ��\n�� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� ����\n";
	char str[200] = "�ζ� ���� �� ";
	sun();
	start(str);
	srand((unsigned int)time(NULL));
	start(x);
	setColor(15, 0);
	printf("             �ڷζ� ��ŵ� ��÷ �� �� �ִ� ��\n\n");
	printf("�� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� ����\n");
	// 5�� ����
	for (int k = 0; k < 5; k++) {
		// ¦��, Ȧ��, ���� �� ���� Ȯ���� ���� �ʱ�ȭ
		odd = 0;
		count = 0;
		even = 0;
		// 6���� ���� ������ ���� �ݺ���
		for (int i = 0; i < 6; i++) {
			lottary[k][i] = rand() % 45 + 1;
			// ������ �迭 ���� ���� �˻��� �ݺ���
			for (temp = 0; temp < i; temp++) {
				// ���� �� �迭��� ���Ͽ� ������ �ٽõ��ư��� ������ �ٽ� ����
				if (lottary[k][i] == lottary[k][temp]) {
					i--;
					break;
				}
				// ���� �� �迭�� �� ���̳ʽ� ���밪�� 1�̸� ī��Ʈ ������ ������� ��
				if (abs(lottary[k][i] - lottary[k][temp]) == 1) {
					count += 1;
				}
			}
			// ������ ¦������ Ȧ�� ���� �˻��ϴ� �ڵ�
			if (lottary[k][i] % 2 == 0) {
				even++;
			}
			else {
				odd++;
			}
		}
		// ���� ���ӵ� ������ 1�� �ʰ��ϸ� ������ �ٽ� ���ư��� �ٽ� ���� ����
		if (count > 1) {
			k--;
			continue;
		}
		// ���� �� ��ҵ��� ¦�� ������ Ȧ�� ������ 6���� ������ �ٽ� ���ư��� �ٽ� ���� ����
		if (even == 6) {
			k--;
		}
		else if (odd == 6) {
			k--;
		}
	}
	// ����(��������)
	// ������ ���� i�� 1�� �����ؼ� ó�� �迭 ���� i-1�� ��ұ��� ��
	for (int k = 0; k < 5; k++) {
		for (int i = 5; i >= 0; i--) {
			for (int j = 0; j < i; j++) {
				if (lottary[k][i] < lottary[k][j]) {
					rtemp = lottary[k][i];
					lottary[k][i] = lottary[k][j];
					lottary[k][j] = rtemp;
				}
			}
		}
	}
	// ���(1~ 650ȸ�� ���� ���̳��� 5���� �� ���� ���� 5���� ���� �������� ���� ä��)
	for (int k = 0; k < 5; k++) {
		numCount = 0;
		for (int i = 0; i < 6; i++) {
			if (lottary[k][i] == 27 || lottary[k][i] == 18 || lottary[k][i] == 17 || lottary[k][i] == 34 || lottary[k][i] == 43) {
				numCount += 15;
			}
			else if (lottary[k][i] == 9 || lottary[k][i] == 22 || lottary[k][i] == 41 || lottary[k][i] == 23 || lottary[k][i] == 32) {
				numCount += 5;
			}
			else {
				numCount += 10;
			}
			if (i == 5) {
				printf("%d                     ��", lottary[k][i]);
			}
			else if (i == 0) {
				printf("��\t%d       ", lottary[k][i]);
			}
			else {
				printf("%d\t", lottary[k][i]);
			}
		}
		printf("\n��    ���� ���� �Ǵ��� �� ��ȣ ������ ������ 100�� ������ : %d ���Դϴ�.��\n", numCount);
	}
	printf("�� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� ����\n");
	system("pause > nul");
	return 0;
}
void setColor(unsigned short text, unsigned short back) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text | (back << 4));
}
int sun(void)
{
	sndPlaySoundA("D:\\���۸�����.wav", SND_ASYNC | SND_NODEFAULT);
}
