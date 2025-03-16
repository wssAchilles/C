#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
struct book2
{
	char id[20];
	time_t time;
};
struct yonghu
{
	long int zh;
	char name[20];
	char mm[128];
	int xy;
	int zt;
	struct book2 lend[3];
};
typedef struct yonghu YH;

struct book // ͼ����Ϣ
{
	int id;
	char name[10]; // ����
	char aut[10];  // ������
	char type[10]; // ����
	char pub[10];  // ���浥λ
	int time;	   // ����ʱ��
	double price;  // �۸�
	int num;	   // ����
	int x;
} cangshu[128];
int num = 0;
void menu();
void ghbook();
void jwbook();
void chbook();
void menu1();
void read();			  // ��ͼ����Ϣ����
void HideCursor();		  // ���ع��
void toxy(int x, int y);  // ������ƶ���X,Y���괦
void color(short x);	  // ������ɫ
void over();			  // �ο��˳�
void over1();			  // ����Ա�˳�
void input_book();		  // ͼ�����
void save();			  // ��ͼ����Ϣ�����ļ�
void find_book();		  // ��ѯ
void print_book();		  // ͼ������
void print();			  // �ο�����
void del_book();		  // ɾ��ͼ��
void amend_book();		  // �޸���Ϣ
void find_name_book();	  // ��������ѯ
void find_author_book();  // �����߲�ѯ
void find_publish_book(); // ���������ѯ
void fuzzy_search();	  // ģ������
void menu1()			  // ����Ա�˵�
{
	do
	{
		system("cls"); // ����
		HideCursor();  // ���ع��
		color(15);	   // ����һ���ÿ�����ɫ
		char t;
		toxy(50, 5); // ������ƶ�����50��5�����괦
		printf(" ͼ���ѯ����ϵͳ");
		toxy(48, 8);
		printf("|   1.ͼ�����   |");
		toxy(48, 10);
		printf("|   2.�޸���Ϣ   |");
		toxy(48, 12);
		printf("|   3.ɾ����Ϣ   |");
		toxy(48, 14);
		printf("|   4.ͼ���ѯ   |");
		toxy(48, 16);
		printf("|   5.ͼ������   |");
		toxy(48, 18);
		printf("|   6.�˳����   |");
		t = getch(); // �����Ժ���
		switch (t)
		{
		case '1':
			input_book();
			break;
		case '2':
			amend_book();
			break;
		case '3':
			del_book();
			break;
		case '4':
			find_book();
			break;
		case '5':
			print_book();
			break;
		case '6':
			over1();
			break;
		default:
			break;
		}
	} while (1);
}

void amend_book()
{
	system("cls");
	int n, a;
	double m;
	char str[40];
	toxy(48, 8);
	printf("��������Ҫ�޸ĵ�ͼ��id:");
	scanf("%d", &n);
	toxy(48, 10);
	printf("������������");
	scanf("%s", str);
	strcpy(cangshu[n].name, str);
	toxy(48, 12);
	printf("��������������");
	scanf("%s", str);
	strcpy(cangshu[n].aut, str);
	toxy(48, 14);
	printf("����������磺");
	scanf("%s", str);
	strcpy(cangshu[n].pub, str);
	toxy(48, 16);
	printf("���������");
	scanf("%s", str);
	strcpy(cangshu[n].type, str);
	toxy(48, 18);
	printf("���������ʱ�䣺");
	scanf("%d", &a);
	cangshu[n].time = a;
	toxy(48, 20);
	printf("������۸�");
	scanf("%lf", &m);
	cangshu[n].price = m;
	save();
	system("PAUSE");
	menu1();
}

void del_book()
{
	system("cls");
	char n[20];
	int i, flag = 0;
	toxy(48, 10);
	printf("��������Ҫɾ����ͼ������");
	scanf("%s", n);
	for (i = 0; i < num - 1; i++)
	{
		if (strcmp(cangshu[i].name, n) == 1)
			flag = 1;
		if (flag)
		{

			strcpy(cangshu[i].name, cangshu[i + 1].name);
			strcpy(cangshu[i].aut, cangshu[i + 1].aut);
			strcpy(cangshu[i].pub, cangshu[i + 1].pub);
			strcpy(cangshu[i].type, cangshu[i + 1].type);
			cangshu[i].time = cangshu[i + 1].time;
			cangshu[i].price = cangshu[i + 1].price;
		}
	}
	num--;
	save();
	system("cls");
	toxy(46, 10);
	printf("����ɾ�������Ժ�....");
	Sleep(500);
	system("cls");
	toxy(46, 8);
	printf("-------------------------");
	toxy(46, 9);
	printf("|            |");
	toxy(46, 10);
	printf("| ɾ���ɹ����Ƿ������ |");
	toxy(46, 12);
	printf("| 1.��       2.�� |");
	toxy(46, 13);
	printf("|            |");
	toxy(46, 14);
	printf("-------------------------");
	do
	{
		char c = getch();
		if (c == '1')
		{
			del_book();
		}
		else if (c == '2')
		{
			menu1();
		}
	} while (1);
}

void print_book() // ͼ������
{
	system("cls");
	int i;
	toxy(0, 5);
	printf("***********************************************ͼ������******************************************************");
	toxy(0, 8);
	printf("-------------------------------------------------------------------------------------------------------------");
	toxy(0, 9);
	printf("���    ����    ����    ������    ���    ����ʱ��    �۸�\n");
	for (i = 0; i < num; i++)
	{
		printf("%-6d  ", cangshu[i].id);
		printf("%-6s  ", cangshu[i].name);
		printf("%-6s  ", cangshu[i].aut);
		printf("%-6s  ", cangshu[i].pub);
		printf("%-6s  ", cangshu[i].type);
		printf("%-6d  ", cangshu[i].time);
		printf("%12lf\n", cangshu[i].price);
	}
	system("PAUSE");
	menu1();
}
void print() // �ο�ͼ������
{
	system("cls");
	int i;
	toxy(0, 5);
	printf("***********************************************ͼ������******************************************************");
	toxy(0, 8);
	printf("-------------------------------------------------------------------------------------------------------------");
	toxy(0, 9);
	printf("���    ����    ����    ������    ���    ����ʱ��    �۸�\n");
	for (i = 0; i < num; i++)
	{
		printf("%-6d  ", cangshu[i].id);
		printf("%-6s  ", cangshu[i].name);
		printf("%-6s  ", cangshu[i].aut);
		printf("%-6s  ", cangshu[i].pub);
		printf("%-6s  ", cangshu[i].type);
		printf("%-6d  ", cangshu[i].time);
		printf("%12lf\n", cangshu[i].price);
	}
	system("PAUSE");
	return;
}
void read()
{
	FILE *fp;
	fp = fopen("book.txt", "rb");
	char ch;
	while (ch = fgetc(fp), ch != EOF)
	{
		fseek(fp, -1, SEEK_CUR);
		fscanf(fp, "%d", &cangshu[num].id);
		fscanf(fp, "%s", cangshu[num].name);
		fscanf(fp, "%s", cangshu[num].aut);
		fscanf(fp, "%s", cangshu[num].pub);
		fscanf(fp, "%s", cangshu[num].type);
		fscanf(fp, "%d", &cangshu[num].time);
		fscanf(fp, "%lf", &cangshu[num].price);
		num++;
		fgetc(fp);
	}
	fclose(fp);
}

void HideCursor() // ���ع��
{
	CONSOLE_CURSOR_INFO cursor_info = {1, 0};
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

void color(short x)
{
	if (x >= 0 && x <= 15)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
	}
	else
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
	}
}

void toxy(int x, int y) // ������ƶ���X,Y���괦
{
	COORD pos = {x, y};
	HANDLE Out = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(Out, pos);
}

void over(YH *yh) // �ο��˳����
{
	FILE *fp;
	fp = fopen("�ο�.txt", "rb+");
	if (fp == NULL)
	{
		printf("open file failed\n");
		exit(0);
	}
	int flag = 0;
	char t;
	toxy(48, 11);
	printf("-----------------------");
	toxy(48, 12);
	printf("|  ��ȷ��Ҫ�˳��� |");
	toxy(48, 14);
	printf("| 1.ȷ��   2.ȡ��  |");
	toxy(48, 15);
	printf("-----------------------");
	while (1)
	{
		t = getch(); // ����t
		switch (t)
		{
		case '1':
			system("cls");
			color(6);
			toxy(48, 10);
			printf("���ڰ�ȫ�˳�....");
			YH db;
			while (flag != 1)
			{
				fread(&db, sizeof(YH), 1, fp);
				if (db.zh == yh->zh)
					flag = 1;
				if (feof(fp))
					break;
			}
			fseek(fp, (-1) * (int)sizeof(YH), 2);
			fwrite(yh, sizeof(YH), 1, fp);
			Sleep(1000); // ��ͣ1��
			system("cls");
			color(8);
			toxy(48, 10);
			printf("�Ѱ�ȫ�˳����");
			toxy(48, 12);
			printf("ллʹ�ã�");
			toxy(48, 14);
			printf("by-by^_^");
			exit(0);
			break; // ��ֹ����
		case '2':
			menu1();
			break; // ���ú���������˵�
		default:
			break;
		}
	}
}

void over1() // ����Ա�˳����
{
	char t;
	toxy(48, 11);
	printf("-----------------------");
	toxy(48, 12);
	printf("|  ��ȷ��Ҫ�˳��� |");
	toxy(48, 14);
	printf("| 1.ȷ��   2.ȡ��  |");
	toxy(48, 15);
	printf("-----------------------");
	while (1)
	{
		t = getch(); // ����t
		switch (t)
		{
		case '1':
			system("cls");
			color(6);
			toxy(48, 10);
			printf("���ڰ�ȫ�˳�....");
			Sleep(1000); // ��ͣ1��
			system("cls");
			color(8);
			toxy(48, 10);
			printf("�Ѱ�ȫ�˳����");
			toxy(48, 12);
			printf("ллʹ�ã�");
			toxy(48, 14);
			printf("by-by^_^");
			exit(0);
			break; // ��ֹ����
		case '2':
			menu1();
			break; // ���ú���������˵�
		default:
			break;
		}
	}
}

void save()
{
	int i;
	FILE *fp;
	fp = fopen("book.txt", "wb");
	for (i = 0; i < num; i++)
	{
		fprintf(fp, "%d\n", cangshu[i].id);
		fprintf(fp, "%s\n", cangshu[i].name);
		fprintf(fp, "%s\n", cangshu[i].aut);
		fprintf(fp, "%s\n", cangshu[i].pub);
		fprintf(fp, "%s\n", cangshu[i].type);
		fprintf(fp, "%d\n", cangshu[i].time);
		fprintf(fp, "%lf\n", cangshu[i].price);
	}
	fclose(fp);
}

void input_book()
{
	system("cls");
	int a;
	char str[40];
	double m;
	toxy(48, 8);
	printf("������������ݣ�");
	cangshu[num].id = num;
	toxy(48, 10);
	printf("������������");
	scanf("%s", str);
	strcpy(cangshu[num].name, str);
	toxy(48, 12);
	printf("��������������");
	scanf("%s", str);
	strcpy(cangshu[num].aut, str);
	toxy(48, 14);
	printf("����������磺");
	scanf("%s", str);
	strcpy(cangshu[num].pub, str);
	toxy(48, 16);
	printf("���������");
	scanf("%s", str);
	strcpy(cangshu[num].type, str);
	toxy(48, 18);
	printf("���������ʱ�䣺");
	scanf("%d", &a);
	cangshu[num].time = a;
	toxy(48, 20);
	printf("������۸�");
	scanf("%lf", &m);
	cangshu[num].price = m;
	num++;
	save();
	menu1();
}

void find_book() // ��ѯͼ��
{
	do
	{
		system("cls"); // ����
		color(8);
		char t;
		toxy(50, 5);
		printf(" ͼ���ѯ");
		toxy(48, 8);
		printf("|   1.���� ��ѯ   |");
		toxy(48, 10);
		printf("|   2.���� ��ѯ   |");
		toxy(48, 12);
		printf("|   3.�������ѯ   |");
		toxy(48, 14);
		printf("|   4.ģ����ѯ   |");
		toxy(50, 16);
		printf("��0�������˵�");
		t = getch();
		switch (t)
		{
		case '0':
			menu1();
			break;
		case '1':
			find_name_book();
			break;
		case '2':
			find_author_book();
			break;
		case '3':
			find_publish_book();
			break;
		case '4':
			fuzzy_search();
			break;
		default:
			break;
		}
	} while (1);
}

void find_name_book()
{
	int i;
	system("cls");
	char s[20];
	int you = 0;
	toxy(48, 8);
	printf("������������");
	scanf("%s", s);
	toxy(48, 10);
	printf("���ڲ�ѯ....");
	Sleep(500);
	for (i = 0; i < num; i++)
	{
		if (strcmp(cangshu[i].name, s) == 0)
		{
			you = 1;
			system("cls");
			toxy(0, 5);
			printf("***********************************************ͼ������******************************************************");
			toxy(0, 8);
			printf("-------------------------------------------------------------------------------------------------------------");
			toxy(0, 9);
			printf("���    ����    ����    ������    ���    ����ʱ��    �۸�\n");
			printf("%d %s %s %s %s %d %lf\n", cangshu[i].id, cangshu[i].name, cangshu[i].aut, cangshu[i].pub, cangshu[i].type, cangshu[i].time, cangshu[i].price);
		}
	}
	if (!you)
		printf("δ�ҵ���ͼ�飡\n");
	system("PAUSE");
	system("cls");
	find_book();
}

void find_author_book()
{
	int i;
	system("cls");
	char s[20];
	int you = 0;
	toxy(48, 8);
	printf("��������������");
	scanf("%s", s);
	toxy(48, 10);
	printf("���ڲ�ѯ....");
	Sleep(500);
	for (i = 0; i < num; i++)
	{
		if (strcmp(cangshu[i].aut, s) == 0)
		{
			you = 1;
			system("cls");
			toxy(0, 5);
			printf("***********************************************ͼ������******************************************************");
			toxy(0, 8);
			printf("-------------------------------------------------------------------------------------------------------------");
			toxy(0, 9);
			printf("���    ����    ����    ������    ���    ����ʱ��    �۸�\n");
			printf("%d %s %s %s %s %d %lf\n", cangshu[i].id, cangshu[i].name, cangshu[i].aut, cangshu[i].pub, cangshu[i].type, cangshu[i].time, cangshu[i].price);
		}
	}
	if (!you)
		printf("δ�ҵ���ͼ�飡\n");
	system("PAUSE");
	system("cls");
	find_book();
}

void find_publish_book()
{
	int i;
	system("cls");
	char s[20];
	int you = 0;
	toxy(48, 8);
	printf("����������磺");
	scanf("%s", s);
	toxy(48, 10);
	printf("���ڲ�ѯ....");
	Sleep(500);
	for (i = 0; i < num; i++)
	{
		if (strcmp(cangshu[i].pub, s) == 0)
		{
			you = 1;
			system("cls");
			toxy(0, 5);
			printf("***********************************************ͼ������******************************************************");
			toxy(0, 8);
			printf("-------------------------------------------------------------------------------------------------------------");
			toxy(0, 9);
			printf("���    ����    ����    ������    ���    ����ʱ��    �۸�\n");
			printf("%d %s %s %s %s %d %lf\n", cangshu[i].id, cangshu[i].name, cangshu[i].aut, cangshu[i].pub, cangshu[i].type, cangshu[i].time, cangshu[i].price);
		}
	}
	if (!you)
		printf("δ�ҵ���ͼ�飡\n");
	system("PAUSE");
	system("cls");
	find_book();
}

void fuzzy_search()
{
	int i;
	system("cls");
	char s[20];
	int you = 0;
	toxy(48, 8);
	printf("�����������Ϣ��");
	scanf("%s", s);
	toxy(48, 10);
	printf("���ڲ�ѯ....");
	Sleep(500);
	for (i = 0; i < num; i++)
	{
		if ((strcmp(cangshu[i].name, s) == 0) || (strcmp(cangshu[i].aut, s) == 0) || (strcmp(cangshu[i].pub, s) == 0))
		{
			you = 1;
			system("cls");
			toxy(0, 5);
			printf("***********************************************ͼ������******************************************************");
			toxy(0, 8);
			printf("-------------------------------------------------------------------------------------------------------------");
			toxy(0, 9);
			printf("���    ����    ����    ������    ���    ����ʱ��    �۸�\n");
			printf("%d %s %s %s %s %d %lf\n", cangshu[i].id, cangshu[i].name, cangshu[i].aut, cangshu[i].pub, cangshu[i].type, cangshu[i].time, cangshu[i].price);
		}
	}
	if (!you)
		printf("δ�ҵ���ͼ�飡\n");
	system("PAUSE");
	system("cls");
	find_book();
}

void menu(YH *yh) // �οͲ˵�
{
	int i;
	time_t currentTime;
	time(&currentTime);
	for (i = 0; i < (yh->zt); i++)
	{
		if (difftime(currentTime, (yh->lend[i].time)) > 2592000)
			(yh->xy)--;
	}
	do
	{
		system("cls"); // ����
		HideCursor();  // ���ع��
		color(15);	   // ����һ���ÿ�����ɫ
		char t;
		toxy(50, 5); // ������ƶ�����50��5�����괦
		printf(" ͼ�����ϵͳ");
		toxy(48, 8);
		printf("|   1.�黹ͼ��   |");
		toxy(48, 10);
		printf("|   2.����ͼ��   |");
		toxy(48, 12);
		printf("|   3.ͼ���ѯ   |");
		toxy(48, 14);
		printf("|   4.ͼ������   |");
		toxy(48, 16);
		printf("|   5.�˳����   |");
		t = getch(); // �����Ժ���
		switch (t)
		{
		case '1':
			ghbook(yh);
			break;
		case '2':
			jwbook(yh);
			break;
		case '3':
			chbook();
			break;
		case '4':
			print();
			break;
		case '5':
			over(yh);
		default:
			break;
		}
	} while (1);
}

void ghbook(YH *yh) // �黹ͼ��
{
	system("cls");
	int a;
	char str[40];
	double m;
	toxy(48, 8);
	printf("������黹��Ϣ��");
	cangshu[num].id = num;
	toxy(48, 10);
	printf("������������");
	scanf("%s", str);
	strcpy(cangshu[num].name, str);
	toxy(48, 12);
	printf("��������������");
	scanf("%s", str);
	strcpy(cangshu[num].aut, str);
	toxy(48, 14);
	printf("����������磺");
	scanf("%s", str);
	strcpy(cangshu[num].pub, str);
	toxy(48, 16);
	printf("���������");
	scanf("%s", str);
	strcpy(cangshu[num].type, str);
	toxy(48, 18);
	printf("���������ʱ�䣺");
	scanf("%d", &a);
	cangshu[num].time = a;
	toxy(48, 20);
	printf("������۸�");
	scanf("%lf", &m);
	cangshu[num].price = m;
	num++;
	save();
	int i;
	for (i = 0; strcmp(cangshu->name, yh->lend[i].id) != 0; i++)
	{
		;
	}
	strcpy(yh->lend[i].id, yh->lend[yh->zt - 1].id);
	yh->lend[i].time = yh->lend[yh->zt - 1].time;
	(yh->zt)--;
	return;
}

void jwbook(YH *yh) // ����ͼ��
{
	while (1)
	{
		system("cls");
		if ((yh->zt) >= 3)
		{
			printf("�������Ѵ����ޣ��޷���������");
			Sleep(3000);
			return;
		}
		if ((yh->xy) != 1)
		{
			printf("����������������꣬�޷�����");
			Sleep(3000);
			return;
		}
		char n[20];
		int i, flag = 0;
		toxy(48, 10);
		printf("��������Ҫ���ĵ�ͼ������");
		scanf("%s", n);
		for (i = 0; i < num - 1; i++)
		{
			if (strcmp(cangshu[i].name, n) == 1)
				flag = 1;
			if (flag)
			{
				strcpy(cangshu[i].name, cangshu[i + 1].name);
				strcpy(cangshu[i].aut, cangshu[i + 1].aut);
				strcpy(cangshu[i].pub, cangshu[i + 1].pub);
				strcpy(cangshu[i].type, cangshu[i + 1].type);
				cangshu[i].time = cangshu[i + 1].time;
				cangshu[i].price = cangshu[i + 1].price;
			}
		}
		num--;
		save();
		system("cls");
		toxy(46, 10);
		printf("���ڽ��ģ����Ժ�....");
		Sleep(500);
		system("cls");
		toxy(46, 8);
		printf("-------------------------");
		toxy(46, 9);
		printf("|            |");
		toxy(46, 10);
		printf("| ���ĳɹ����Ƿ������ |");
		(yh->zt)++;
		strcpy(yh->lend[(yh->zt) - 1].id, cangshu[i].name);
		time(&(yh->lend[(yh->zt) - 1].time));
		toxy(46, 12);
		printf("| 1.��       2.�� |");
		toxy(46, 13);
		printf("|            |");
		toxy(46, 14);
		printf("-------------------------");
		do
		{
			char c = getch();
			if (c == '1')
			{
				system("cls");
				break;
			}
			else if (c == '2')
			{
				return;
			}
		} while (1);
	}
}

void chbook()
{
	do
	{
		system("cls"); // ����
		color(8);
		char t;
		toxy(50, 5);
		printf(" ͼ���ѯ");
		toxy(48, 8);
		printf("|   1.���� ��ѯ   |");
		toxy(48, 10);
		printf("|   2.���� ��ѯ   |");
		toxy(48, 12);
		printf("|   3.�������ѯ   |");
		toxy(48, 14);
		printf("|   4.ģ����ѯ   |");
		toxy(50, 16);
		printf("��0�������˵�");
		t = getch();
		switch (t)
		{
		case '0':
			return;
			break;
		case '1':
			find_name_book();
			break;
		case '2':
			find_author_book();
			break;
		case '3':
			find_publish_book();
			break;
		case '4':
			fuzzy_search();
			break;
		default:
			break;
		}
	} while (1);
}

void input1(long int *zh)
{
	printf("<ע��>\n�����������˺�(8��12λ����)\n");
	scanf("%ld", zh);
}

void input2(char mm[])
{
	printf("<ע��>\n��������������(8��16λ,��Ҫ��ĸ�����ֻ��,�������������)\n");
	gets(mm);
}

int cheak1(long int x) // ����˺�//
{
	long int y = x;
	int sum1 = 0;
	do
	{
		y = y / 10;
		sum1++;
	} while (y != 0);
	return sum1;
}

void cheak2(char s[], int *n, int *a, int *b, int *c) // �������//
{
	int i;
	*n = strlen(s);
	for (i = 0; s[i] != '\0'; i++)
	{
		if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
			(*a)++;
		else if (s[i] >= '0' && s[i] <= '9')
			(*b)++;
		else
			(*c)++;
	}
}

void glydl()
{
	system("cls");
	int p, q = 0;
	YH yh;
	FILE *fp;
	fp = fopen("����Ա.txt", "rb+");
	if (fp == NULL)
	{
		fp = fopen("����Ա.txt", "wb");
		if (fp == NULL)
		{
			printf("open file failed\n");
			exit(0);
		}
	}
	fclose(fp);
	while (q == 0)
	{
		printf("�����Ӧ���ѡ����Ҫִ�еĲ���\n1.��¼\n2.ע��\n3.�һ�����\n");
		scanf("%d", &p);
		getchar();
		if ((p != 1) && (p != 2) && (p != 3))
		{
			system("cls");
			printf("����ʧ�ܣ�������ѡ��\n1.��¼\n2.ע��\n3.�һ�����");
			continue;
		}

		if (p == 1) // ��¼ //
		{
			system("cls");
			fp = fopen("����Ա.txt", "r+");
			if (fp == NULL)
			{
				printf("open file failed\n");
				exit(0);
			}
			int flag = 0, i = 0;
			long int id;
			char an[128], e;
			while (q == 0)
			{
				printf("�˺�:");
				scanf("%ld", &id);
				getchar();
				printf("����:");
				while (1)
				{
					e = getch();
					if (e == 13)
						break;
					if (e == 8)
					{
						printf("\b \b");
						i--;
					}
					else
					{
						an[i] = e;
						i++;
						printf("*");
					}
					an[i] = '\0';
				}
				YH db;
				while (flag != 1)
				{
					fread(&db, sizeof(YH), 1, fp);
					if (id == db.zh && strcmp(an, db.mm) == 0)
						flag = 1;
					if (feof(fp))
						break;
				}
				if (flag == 1)
				{
					printf("\n��¼�ɹ�!");
					Sleep(2000);
					menu1();
				}
				else
				{
					system("cls");
					printf("\n������˺Ŵ���,������\n");
					continue;
				}
				fclose(fp);
			}
		}

		if (p == 2) // ע�� //
		{
			fp = fopen("����Ա.txt", "rb+");
			if (fp == NULL)
			{
				printf("open file failed\n");
				exit(0);
			}
			system("cls");
			int i = 0;
			char ch;						
			int sum2 = 0;					
			int n = 0, a = 0, b = 0, c = 0;
			while (q == 0)					
			{
				input1(&yh.zh);
				system("cls");
				sum2 = cheak1(yh.zh);
				if ((sum2 < 8) || (sum2 > 12))
				{
					printf("ע����˺Ų�����Ҫ������������\n");
					continue;
				}
				int flag = 0;
				YH db;
				while (flag != 1)
				{
					fread(&db, sizeof(YH), 1, fp);
					if (db.zh == yh.zh)
						flag = 1;
					if (feof(fp))
						break;
				}
				if (flag == 1)
				{
					printf("�˺��ѱ�ע�ᣬ����������\n");
					continue;
				}
				else
					break;
			}
			getchar();
			while (q == 0) 
			{
				a = b = c = n = 0;
				input2(yh.mm);
				system("cls");
				cheak2(yh.mm, &n, &a, &b, &c);
				if (n < 8 || n > 16) // ��鳤��//
				{
					printf("ע������벻����Ҫ������������\n");
					continue;
				}
				if (a == 0 || b == 0 || c != 0) 
				{
					printf("ע������벻����Ҫ������������\n");
					continue;
				}
				else
					break;
			}
			system("cls");
			printf("�������ܱ���Ϣ(��10�����ֻ�20���ַ�)\n");
			while ((ch = getchar()) != '\n')
			{
				yh.name[i] = ch;
				i++;
			}
			yh.name[i] = '\0';
			printf("�˺�ע����ɣ�����󷵻����˵�......");
			Sleep(2000);
			fwrite(&yh, sizeof(YH), 1, fp);
			fclose(fp);
			system("cls");
			continue;
		}

		if (p == 3) // �һ�����//
		{
			fp = fopen("����Ա .txt", "r+");
			if (fp == NULL)
			{
				printf("open file failed\n");
				exit(0);
			}
			system("cls");
			while (1)
			{
				printf("�������˺���Ϣ���һ�����\n");
				long int id2;
				int l = 0, flag2 = 0;
				char xm[20];
				printf("�˺�:");
				scanf("%ld", &id2);
				getchar();
				printf("�ܱ���Ϣ:");
				gets(xm);
				YH mb;
				while (flag2 != 1)
				{
					fread(&mb, sizeof(YH), 1, fp);
					if (id2 == mb.zh && strcmp(xm, mb.name) == 0)
						flag2 = 1;
					if (feof(fp))
						break;
				}
				if (flag2 == 1)
				{
					printf("\n������������,�����Ʊ���!!!\n%s\n����������ص�¼...", mb.mm);
					char o = getchar();

					break;
				}
				else
				{
					system("cls");
					printf("�˺���Ϣ����,������\n");
					continue;
				}
				fclose(fp);
				continue;
			}
		}
	}
}

void ykdl()
{
	system("cls");
	int p, q = 0;
	YH yh;
	FILE *fp;
	fp = fopen("�ο�.txt", "rb+");
	if (fp == NULL)
	{
		fp = fopen("�ο�.txt", "wb");
		if (fp == NULL)
		{
			printf("open file failed\n");
			exit(0);
		}
	}
	fclose(fp);
	while (q == 0)
	{
		printf("�����Ӧ���ѡ����Ҫִ�еĲ���\n1.��¼\n2.ע��\n3.�һ�����\n");
		scanf("%d", &p);
		getchar();
		if ((p != 1) && (p != 2) && (p != 3))
		{
			system("cls");
			printf("����ʧ�ܣ�������ѡ��\n1.��¼\n2.ע��\n3.�һ�����\n");
			continue;
		}

		if (p == 1) // ��¼ //
		{
			system("cls");
			fp = fopen("�ο�.txt", "r+");
			if (fp == NULL)
			{
				printf("open file failed\n");
				exit(0);
			}
			int flag = 0, i = 0;
			long int id;
			char an[128], e;
			while (q == 0)
			{
				printf("�˺�:");
				scanf("%ld", &id);
				getchar();
				printf("����:");
				while (1)
				{
					e = getch();
					if (e == 13)
						break;
					if (e == 8)
					{
						printf("\b \b");
						i--;
					}
					else
					{
						an[i] = e;
						i++;
						printf("*");
					}
					an[i] = '\0';
				}
				YH db;
				while (flag != 1)
				{
					fread(&db, sizeof(YH), 1, fp);
					if (id == db.zh && strcmp(an, db.mm) == 0)
						flag = 1;
					if (feof(fp))
						break;
				}
				if (flag == 1)
				{
					printf("\n��¼�ɹ�!");
					Sleep(2000);
					menu(&db);
				}
				else
				{
					system("cls");
					printf("������˺Ŵ���,������\n");
					continue;
				}
				fclose(fp);
			}
		}

		if (p == 2) // ע�� //
		{
			fp = fopen("�ο�.txt", "rb+");
			if (fp == NULL)
			{
				printf("open file failed\n");
				exit(0);
			}
			system("cls");
			int i = 0;
			char ch;						// ����������//
			int sum2 = 0;					// ���ע���˺���//
			int n = 0, a = 0, b = 0, c = 0; // ���ע��������//
			while (q == 0)					// �����˺��Լ���� //
			{
				input1(&yh.zh);
				system("cls");
				sum2 = cheak1(yh.zh);
				if ((sum2 < 8) || (sum2 > 12))
				{
					printf("ע����˺Ų�����Ҫ������������\n");
					continue;
				}
				int flag = 0;
				YH db;
				while (flag != 1)
				{
					fread(&db, sizeof(YH), 1, fp);
					if (db.zh == yh.zh)
						flag = 1;
					if (feof(fp))
						break;
				}
				if (flag == 1)
				{
					printf("�˺��ѱ�ע�ᣬ����������\n");
					continue;
				}
				else
					break;
			}

			getchar();
			while (q == 0) // ���������Լ���� //
			{
				a = b = c = n = 0;
				input2(yh.mm);
				system("cls");
				cheak2(yh.mm, &n, &a, &b, &c);
				if (n < 8 || n > 16) // ��鳤��//
				{
					printf("ע������벻����Ҫ������������\n");
					continue;
				}
				if (a == 0 || b == 0 || c != 0) // a�����û����ĸ  b�����û������  c�����û���������//
				{
					printf("ע������벻����Ҫ������������\n");
					continue;
				}
				else
					break;
			}
			system("cls");
			printf("�������ܱ���Ϣ(��10�����ֻ�20���ַ�)\n");
			while ((ch = getchar()) != '\n')
			{
				yh.name[i] = ch;
				i++;
			}
			yh.name[i] = '\0';
			yh.xy = 1;
			yh.zt = 0;
			printf("�˺�ע����ɣ�����󷵻����˵�......");
			Sleep(2000);
			fwrite(&yh, sizeof(YH), 1, fp);
			fclose(fp);
			system("cls");
			continue;
		}

		if (p == 3) // �һ�����//
		{
			fp = fopen("�ο�.txt", "r+");
			if (fp == NULL)
			{
				printf("open file failed\n");
				exit(0);
			}
			system("cls");
			while (1)
			{
				printf("�������˺���Ϣ���һ�����\n");
				long int id2;
				int l = 0, flag2 = 0;
				char xm[20];
				printf("�˺�:");
				scanf("%ld", &id2);
				getchar();
				printf("�ܱ���Ϣ:");
				gets(xm);
				YH mb;
				while (flag2 != 1)
				{
					fread(&mb, sizeof(YH), 1, fp);
					if (id2 == mb.zh && strcmp(xm, mb.name) == 0)
						flag2 = 1;
					if (feof(fp))
						break;
				}
				if (flag2 == 1)
				{
					printf("\n������������,�����Ʊ���!!!\n%s\n����������ص�¼...", mb.mm);
					char o = getchar();
					break;
				}
				else
				{
					system("cls");
					printf("�˺���Ϣ����,������\n");
					continue;
				}
				fclose(fp);
				continue;
			}
		}
	}
}

int main()
{
	read();
	do
	{
		system("cls");
		HideCursor();
		color(3);
		char t;
		toxy(44, 5);
		printf("��ӭ����ͼ�����ϵͳ");
		toxy(48, 8);
		printf("����Ա��¼�밴 1");
		toxy(48, 10);
		printf("�ο͵�¼�밴 2");
		t = getch();
		switch (t)
		{
		case '1':
			glydl();
			break;
		case '2':
			ykdl();
			break;
		default:
			break;
		}
	} while (1);
}