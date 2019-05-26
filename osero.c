	#include <stdio.h>
	#include <stdlib.h>
	#define PIXEL 8

	void ibyte(int bnum,int* n,int* r);

	int main(void)
	{
		int i,j,ch=0,str=1;
		int changer = 0;
		int MainLoop = 1;
		char turn[3] = "●\0";

		char** buf;
		buf = (char**)calloc(sizeof(char*), PIXEL);
		for(i=0;i<PIXEL;i++)
			buf[i] = (char*)calloc(sizeof(char), PIXEL);

		buf[4-1][4-1] = 0x01;
		buf[4-1][5-1] = 0x02;
		buf[5-1][4-1] = 0x02;
		buf[5-1][5-1] = 0x01;

		while(MainLoop)
		{
			system("cls");
			int fr,sr;
			for(i=1;i<=PIXEL;i++)
				printf("% d",i);
			printf("\n");

			for(i=0;i<PIXEL;i++)
			{
				printf("%d",i+1);
				for(j=0;j<PIXEL;j++)
				{
					switch(buf[i][j])
					{
						case 0x00:
							printf("・");
						break;
						case 0x01:
							printf("●");
						break;
						case 0x02:
							printf("〇");
						break;
					}
				}
				printf("\n");
			}

			printf("[%s]のターン(0で終了)\n",turn);

			while(str)
			{
				scanf("%d",&ch);
				if(!ch)
				{
					MainLoop = 0;
					return 0;
				}
				if(ch <= 10)
					printf("10以上の数字を入力してください");
				else
				{
					ibyte(ch,&fr,&sr);
					if(88 >= ch)
						str = 0;
					else{printf("89以下の数字を入力\n");}
				}
			}

			if(!(changer % 2))
			{
				buf[fr-1][sr-1] = 1;
				turn[0] = 0x81;
				turn[1] = 0x5A;
			}
			else
			{
				buf[fr-1][sr-1] = 2;
				turn[0] = 0x81;
				turn[1] = 0x9C;
			}
			changer++;
			str = 1;
		}

		free(buf);
		return 0;
	}

	void ibyte(int bnum,int* n,int* r)
	{
		char num[5];
		char tn;
		snprintf(num,5,"%d",bnum);
		tn = num[1];
		num[1] = '\0';
		num[2] = tn;
		num[3] = '\0';
		*n = atoi(&num[0]);
		*r = atoi(&num[2]);
	}
