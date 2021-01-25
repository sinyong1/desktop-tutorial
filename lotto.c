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
	// 5*6 30개의 숫자를 담을 2차원 배열을 생성
	int lottary[5][6];
	int count;
	int numCount = 0;
	int odd;
	int even;
	char x[400] = "┏ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━┓\n┃  ◆         ◆     ◆◆◆   ◆◆◆    ◆     ┃\n┃  ◆       ◆  ◆     ◆       ◆    ◆  ◆   ┃\n┃  ◆       ◆  ◆     ◆       ◆    ◆  ◆   ┃\n┃  ◆◆◆◆   ◆       ◆       ◆      ◆     ┃\n┗ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━┛\n";
	char str[200] = "로또 생성 중 ";
	sun();
	start(str);
	srand((unsigned int)time(NULL));
	start(x);
	setColor(15, 0);
	printf("             ★로또 당신도 당첨 될 수 있다 ★\n\n");
	printf("┏ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━┓\n");
	// 5줄 생성
	for (int k = 0; k < 5; k++) {
		// 짝수, 홀수, 연속 된 수를 확인할 변수 초기화
		odd = 0;
		count = 0;
		even = 0;
		// 6개의 난수 추출을 위한 반복문
		for (int i = 0; i < 6; i++) {
			lottary[k][i] = rand() % 45 + 1;
			// 생성된 배열 이전 까지 검사할 반복문
			for (temp = 0; temp < i; temp++) {
				// 만약 전 배열들과 비교하여 같으면 다시돌아가서 난수를 다시 추출
				if (lottary[k][i] == lottary[k][temp]) {
					i--;
					break;
				}
				// 만약 전 배열들 간 마이너스 절대값이 1이면 카운트 변수에 누산시켜 줌
				if (abs(lottary[k][i] - lottary[k][temp]) == 1) {
					count += 1;
				}
			}
			// 값들이 짝수인지 홀수 인지 검사하는 코드
			if (lottary[k][i] % 2 == 0) {
				even++;
			}
			else {
				odd++;
			}
		}
		// 만약 연속된 조합이 1개 초과하면 한줄을 다시 돌아가서 다시 난수 추출
		if (count > 1) {
			k--;
			continue;
		}
		// 만약 줄 요소들의 짝수 갯수와 홀수 갯수가 6개면 한줄을 다시 돌아가서 다시 난수 추출
		if (even == 6) {
			k--;
		}
		else if (odd == 6) {
			k--;
		}
	}
	// 순서(버블정렬)
	// 마지막 부터 i를 1씩 감소해서 처음 배열 부터 i-1의 요소까지 비교
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
	// 출력(1~ 650회차 까지 많이나온 5개의 수 적게 나온 5개의 수를 기준으로 점수 채점)
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
				printf("%d                     ┃", lottary[k][i]);
			}
			else if (i == 0) {
				printf("┃\t%d       ", lottary[k][i]);
			}
			else {
				printf("%d\t", lottary[k][i]);
			}
		}
		printf("\n┃    저희 조가 판단한 이 번호 조합의 점수는 100점 만점에 : %d 점입니다.┃\n", numCount);
	}
	printf("┗ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━┛\n");
	system("pause > nul");
	return 0;
}
void setColor(unsigned short text, unsigned short back) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text | (back << 4));
}
int sun(void)
{
	sndPlaySoundA("D:\\슈퍼마리오.wav", SND_ASYNC | SND_NODEFAULT);
}
