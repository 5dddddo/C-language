#include<stdio.h>
#include<conio.h>
#include<windows.h>
void gotoxy(int x, int y) ;
int main()
{
	gotoxy(1,1);
	printf("*");
	gotoxy(3,20);
	printf("@");
	gotoxy(20,5);
	printf("#");
	getchar();
	return 0;
}

void gotoxy(int x, int y)
{
	COORD Pos = {x - 1, y - 1};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
