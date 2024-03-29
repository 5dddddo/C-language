#include<stdio.h>
#include<conio.h>
#pragma warning (disable : 4996)
// 특수키 확장키코드값 지정 
#define COMMON_KEY 1 
#define SPECIAL_KEY 0 
#define F1 59 
#define F2 60 
#define F3 61 
#define F4 62 
#define F5 63 
#define F6 64 
#define F7 65 
#define F8 66 
#define F9 67 
#define F10 68 
#define UP_ARROW 72 
#define DOWN_ARROW 80 
#define LEFT_ARROW 75 
#define RIGHT_ARROW 77 
#define PAGEUP 73 
#define PAGEDOWN 81 
#define ENTER 13 
#define ESC 27 
char inKey(int *keyFlag);
int main()
{
	char ch;
	int kFlag; //일반키인지 특수키인지 확인하는 변수
	while(1)
	{
		ch = inKey(&kFlag);
		if(kFlag==COMMON_KEY && ch==ESC) {break;}  /* ESC 키 입력 시 종료 */

		if(kFlag==COMMON_KEY) /* 일반키 이면 */
		{
			printf("%c", ch);
		}
		else    /* 특수키 이면 */
		{
			/* 키 종류별 입력 상황 출력 */
			switch(ch)
			{
				case F1 : printf("F1 입력\n"); break;
				case F2 : printf("F2 입력\n"); break;
				case F3 : printf("F3 입력\n"); break;
				case F4 : printf("F4 입력\n"); break;
				case F5 : printf("F5 입력\n"); break;
				case F6 : printf("F6 입력\n"); break;
				case F7 : printf("F7 입력\n"); break;
				case F8 : printf("F8 입력\n"); break;
				case F9 : printf("F9 입력\n"); break;
				case F10 : printf("F10 입력\n"); break;
				case UP_ARROW : printf("위 화살표 입력\n"); break;
				case DOWN_ARROW : printf("아래 화살표 입력\n"); break;
				case LEFT_ARROW : printf("왼쪽 화살표 입력\n"); break;
				case RIGHT_ARROW : printf("오른쪽 화살표 입력\n"); break;
				case PAGEUP : printf("PageUp 입력\n"); break;
				case PAGEDOWN : printf("PageDown 입력\n"); break;
				default : printf("기타 특수 문자 입력(%d)\n", ch);
			}
		}
	}
	return 0;
}

char inKey(int *keyFlag) 
{ 
	char ascii, scan; 

	ascii=getch(); // 입력된 문자의 아스키코드를 입력받아옴 
	if(ascii==-32 || ascii==0){ // 입력된 문자의 아스키코드가 -32이거나 0이면 특수키가 입력된것임 
		scan=getch(); // 특수키가 입력되었을때에는 scan code값을 입력받아옴 
		*keyFlag=SPECIAL_KEY; 
		return (scan); 
	} 
	else { // 일반키가 입력되었으면 
		*keyFlag=COMMON_KEY; 
		return (ascii); 
	} 
	// getch()함수로 특수키를 입력받으면 Ascii, Scan code가 프로그램 내로 들어오고, 
	// getch()함수로 일반키를 입력받으면 그냥 Ascii code만 프로그램 내로 들어오게 됩니다. 
	// 참고하세요~	
}
