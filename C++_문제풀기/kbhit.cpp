#include<stdio.h>
#include<conio.h>
#include<windows.h>
#define ESC 27

int main()
{
	char ch;
	while(1){
		if(kbhit()){
			ch=getch();
			if(ch=='b'){
				printf("쉬었다하자!!\n");
				Sleep(1000);
			}
			else if(ch==ESC){
				break;
			}
		}
		printf("공부하자~\n");
		Sleep(1000);
	}
	return 0;
}
