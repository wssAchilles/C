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

struct book // 图书信息
{
	int id;
	char name[10]; // 书名
	char aut[10];  // 作者名
	char type[10]; // 类型
	char pub[10];  // 出版单位
	int time;	   // 出版时间
	double price;  // 价格
	int num;	   // 数量
	int x;
} cangshu[128];
int num = 0;
void menu();
void ghbook();
void jwbook();
void chbook();
void menu1();
void read();			  // 将图书信息读入
void HideCursor();		  // 隐藏光标
void toxy(int x, int y);  // 将光标移动到X,Y坐标处
void color(short x);	  // 设置颜色
void over();			  // 游客退出
void over1();			  // 管理员退出
void input_book();		  // 图书入库
void save();			  // 将图书信息存入文件
void find_book();		  // 查询
void print_book();		  // 图书总览
void print();			  // 游客总览
void del_book();		  // 删除图书
void amend_book();		  // 修改信息
void find_name_book();	  // 按书名查询
void find_author_book();  // 按作者查询
void find_publish_book(); // 按出版社查询
void fuzzy_search();	  // 模糊查找
void menu1()			  // 管理员菜单
{
	do
	{
		system("cls"); // 清屏
		HideCursor();  // 隐藏光标
		color(15);	   // 设置一个好看的颜色
		char t;
		toxy(50, 5); // 将光标移动到（50，5）坐标处
		printf(" 图书查询管理系统");
		toxy(48, 8);
		printf("|   1.图书入库   |");
		toxy(48, 10);
		printf("|   2.修改信息   |");
		toxy(48, 12);
		printf("|   3.删除信息   |");
		toxy(48, 14);
		printf("|   4.图书查询   |");
		toxy(48, 16);
		printf("|   5.图书总览   |");
		toxy(48, 18);
		printf("|   6.退出软件   |");
		t = getch(); // 不回显函数
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
	printf("请输入需要修改的图书id:");
	scanf("%d", &n);
	toxy(48, 10);
	printf("请输入书名：");
	scanf("%s", str);
	strcpy(cangshu[n].name, str);
	toxy(48, 12);
	printf("请输入作者名：");
	scanf("%s", str);
	strcpy(cangshu[n].aut, str);
	toxy(48, 14);
	printf("请输入出版社：");
	scanf("%s", str);
	strcpy(cangshu[n].pub, str);
	toxy(48, 16);
	printf("请输入类别：");
	scanf("%s", str);
	strcpy(cangshu[n].type, str);
	toxy(48, 18);
	printf("请输入出版时间：");
	scanf("%d", &a);
	cangshu[n].time = a;
	toxy(48, 20);
	printf("请输入价格：");
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
	printf("请输入需要删除的图书名：");
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
	printf("正在删除，请稍后....");
	Sleep(500);
	system("cls");
	toxy(46, 8);
	printf("-------------------------");
	toxy(46, 9);
	printf("|            |");
	toxy(46, 10);
	printf("| 删除成功，是否继续？ |");
	toxy(46, 12);
	printf("| 1.是       2.否 |");
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

void print_book() // 图书总览
{
	system("cls");
	int i;
	toxy(0, 5);
	printf("***********************************************图书总览******************************************************");
	toxy(0, 8);
	printf("-------------------------------------------------------------------------------------------------------------");
	toxy(0, 9);
	printf("编号    书名    作者    出版社    类别    出版时间    价格\n");
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
void print() // 游客图书总览
{
	system("cls");
	int i;
	toxy(0, 5);
	printf("***********************************************图书总览******************************************************");
	toxy(0, 8);
	printf("-------------------------------------------------------------------------------------------------------------");
	toxy(0, 9);
	printf("编号    书名    作者    出版社    类别    出版时间    价格\n");
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

void HideCursor() // 隐藏光标
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

void toxy(int x, int y) // 将光标移动到X,Y坐标处
{
	COORD pos = {x, y};
	HANDLE Out = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(Out, pos);
}

void over(YH *yh) // 游客退出软件
{
	FILE *fp;
	fp = fopen("游客.txt", "rb+");
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
	printf("|  您确定要退出吗？ |");
	toxy(48, 14);
	printf("| 1.确定   2.取消  |");
	toxy(48, 15);
	printf("-----------------------");
	while (1)
	{
		t = getch(); // 输入t
		switch (t)
		{
		case '1':
			system("cls");
			color(6);
			toxy(48, 10);
			printf("正在安全退出....");
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
			Sleep(1000); // 暂停1秒
			system("cls");
			color(8);
			toxy(48, 10);
			printf("已安全退出软件");
			toxy(48, 12);
			printf("谢谢使用！");
			toxy(48, 14);
			printf("by-by^_^");
			exit(0);
			break; // 终止程序
		case '2':
			menu1();
			break; // 调用函数，进入菜单
		default:
			break;
		}
	}
}

void over1() // 管理员退出软件
{
	char t;
	toxy(48, 11);
	printf("-----------------------");
	toxy(48, 12);
	printf("|  您确定要退出吗？ |");
	toxy(48, 14);
	printf("| 1.确定   2.取消  |");
	toxy(48, 15);
	printf("-----------------------");
	while (1)
	{
		t = getch(); // 输入t
		switch (t)
		{
		case '1':
			system("cls");
			color(6);
			toxy(48, 10);
			printf("正在安全退出....");
			Sleep(1000); // 暂停1秒
			system("cls");
			color(8);
			toxy(48, 10);
			printf("已安全退出软件");
			toxy(48, 12);
			printf("谢谢使用！");
			toxy(48, 14);
			printf("by-by^_^");
			exit(0);
			break; // 终止程序
		case '2':
			menu1();
			break; // 调用函数，进入菜单
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
	printf("请输入你的数据：");
	cangshu[num].id = num;
	toxy(48, 10);
	printf("请输入书名：");
	scanf("%s", str);
	strcpy(cangshu[num].name, str);
	toxy(48, 12);
	printf("请输入作者名：");
	scanf("%s", str);
	strcpy(cangshu[num].aut, str);
	toxy(48, 14);
	printf("请输入出版社：");
	scanf("%s", str);
	strcpy(cangshu[num].pub, str);
	toxy(48, 16);
	printf("请输入类别：");
	scanf("%s", str);
	strcpy(cangshu[num].type, str);
	toxy(48, 18);
	printf("请输入出版时间：");
	scanf("%d", &a);
	cangshu[num].time = a;
	toxy(48, 20);
	printf("请输入价格：");
	scanf("%lf", &m);
	cangshu[num].price = m;
	num++;
	save();
	menu1();
}

void find_book() // 查询图书
{
	do
	{
		system("cls"); // 清屏
		color(8);
		char t;
		toxy(50, 5);
		printf(" 图书查询");
		toxy(48, 8);
		printf("|   1.书名 查询   |");
		toxy(48, 10);
		printf("|   2.作者 查询   |");
		toxy(48, 12);
		printf("|   3.出版社查询   |");
		toxy(48, 14);
		printf("|   4.模糊查询   |");
		toxy(50, 16);
		printf("按0返回主菜单");
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
	printf("请输入书名：");
	scanf("%s", s);
	toxy(48, 10);
	printf("正在查询....");
	Sleep(500);
	for (i = 0; i < num; i++)
	{
		if (strcmp(cangshu[i].name, s) == 0)
		{
			you = 1;
			system("cls");
			toxy(0, 5);
			printf("***********************************************图书总览******************************************************");
			toxy(0, 8);
			printf("-------------------------------------------------------------------------------------------------------------");
			toxy(0, 9);
			printf("编号    书名    作者    出版社    类别    出版时间    价格\n");
			printf("%d %s %s %s %s %d %lf\n", cangshu[i].id, cangshu[i].name, cangshu[i].aut, cangshu[i].pub, cangshu[i].type, cangshu[i].time, cangshu[i].price);
		}
	}
	if (!you)
		printf("未找到该图书！\n");
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
	printf("请输入作者名：");
	scanf("%s", s);
	toxy(48, 10);
	printf("正在查询....");
	Sleep(500);
	for (i = 0; i < num; i++)
	{
		if (strcmp(cangshu[i].aut, s) == 0)
		{
			you = 1;
			system("cls");
			toxy(0, 5);
			printf("***********************************************图书总览******************************************************");
			toxy(0, 8);
			printf("-------------------------------------------------------------------------------------------------------------");
			toxy(0, 9);
			printf("编号    书名    作者    出版社    类别    出版时间    价格\n");
			printf("%d %s %s %s %s %d %lf\n", cangshu[i].id, cangshu[i].name, cangshu[i].aut, cangshu[i].pub, cangshu[i].type, cangshu[i].time, cangshu[i].price);
		}
	}
	if (!you)
		printf("未找到该图书！\n");
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
	printf("请输入出版社：");
	scanf("%s", s);
	toxy(48, 10);
	printf("正在查询....");
	Sleep(500);
	for (i = 0; i < num; i++)
	{
		if (strcmp(cangshu[i].pub, s) == 0)
		{
			you = 1;
			system("cls");
			toxy(0, 5);
			printf("***********************************************图书总览******************************************************");
			toxy(0, 8);
			printf("-------------------------------------------------------------------------------------------------------------");
			toxy(0, 9);
			printf("编号    书名    作者    出版社    类别    出版时间    价格\n");
			printf("%d %s %s %s %s %d %lf\n", cangshu[i].id, cangshu[i].name, cangshu[i].aut, cangshu[i].pub, cangshu[i].type, cangshu[i].time, cangshu[i].price);
		}
	}
	if (!you)
		printf("未找到该图书！\n");
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
	printf("请输入基本信息：");
	scanf("%s", s);
	toxy(48, 10);
	printf("正在查询....");
	Sleep(500);
	for (i = 0; i < num; i++)
	{
		if ((strcmp(cangshu[i].name, s) == 0) || (strcmp(cangshu[i].aut, s) == 0) || (strcmp(cangshu[i].pub, s) == 0))
		{
			you = 1;
			system("cls");
			toxy(0, 5);
			printf("***********************************************图书总览******************************************************");
			toxy(0, 8);
			printf("-------------------------------------------------------------------------------------------------------------");
			toxy(0, 9);
			printf("编号    书名    作者    出版社    类别    出版时间    价格\n");
			printf("%d %s %s %s %s %d %lf\n", cangshu[i].id, cangshu[i].name, cangshu[i].aut, cangshu[i].pub, cangshu[i].type, cangshu[i].time, cangshu[i].price);
		}
	}
	if (!you)
		printf("未找到该图书！\n");
	system("PAUSE");
	system("cls");
	find_book();
}

void menu(YH *yh) // 游客菜单
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
		system("cls"); // 清屏
		HideCursor();  // 隐藏光标
		color(15);	   // 设置一个好看的颜色
		char t;
		toxy(50, 5); // 将光标移动到（50，5）坐标处
		printf(" 图书借阅系统");
		toxy(48, 8);
		printf("|   1.归还图书   |");
		toxy(48, 10);
		printf("|   2.借阅图书   |");
		toxy(48, 12);
		printf("|   3.图书查询   |");
		toxy(48, 14);
		printf("|   4.图书总览   |");
		toxy(48, 16);
		printf("|   5.退出软件   |");
		t = getch(); // 不回显函数
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

void ghbook(YH *yh) // 归还图书
{
	system("cls");
	int a;
	char str[40];
	double m;
	toxy(48, 8);
	printf("请输入归还信息：");
	cangshu[num].id = num;
	toxy(48, 10);
	printf("请输入书名：");
	scanf("%s", str);
	strcpy(cangshu[num].name, str);
	toxy(48, 12);
	printf("请输入作者名：");
	scanf("%s", str);
	strcpy(cangshu[num].aut, str);
	toxy(48, 14);
	printf("请输入出版社：");
	scanf("%s", str);
	strcpy(cangshu[num].pub, str);
	toxy(48, 16);
	printf("请输入类别：");
	scanf("%s", str);
	strcpy(cangshu[num].type, str);
	toxy(48, 18);
	printf("请输入出版时间：");
	scanf("%d", &a);
	cangshu[num].time = a;
	toxy(48, 20);
	printf("请输入价格：");
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

void jwbook(YH *yh) // 借阅图书
{
	while (1)
	{
		system("cls");
		if ((yh->zt) >= 3)
		{
			printf("您借书已达上限，无法继续借阅");
			Sleep(3000);
			return;
		}
		if ((yh->xy) != 1)
		{
			printf("您的信誉分数不达标，无法借阅");
			Sleep(3000);
			return;
		}
		char n[20];
		int i, flag = 0;
		toxy(48, 10);
		printf("请输入需要借阅的图书名：");
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
		printf("正在借阅，请稍后....");
		Sleep(500);
		system("cls");
		toxy(46, 8);
		printf("-------------------------");
		toxy(46, 9);
		printf("|            |");
		toxy(46, 10);
		printf("| 借阅成功，是否继续？ |");
		(yh->zt)++;
		strcpy(yh->lend[(yh->zt) - 1].id, cangshu[i].name);
		time(&(yh->lend[(yh->zt) - 1].time));
		toxy(46, 12);
		printf("| 1.是       2.否 |");
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
		system("cls"); // 清屏
		color(8);
		char t;
		toxy(50, 5);
		printf(" 图书查询");
		toxy(48, 8);
		printf("|   1.书名 查询   |");
		toxy(48, 10);
		printf("|   2.作者 查询   |");
		toxy(48, 12);
		printf("|   3.出版社查询   |");
		toxy(48, 14);
		printf("|   4.模糊查询   |");
		toxy(50, 16);
		printf("按0返回主菜单");
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
	printf("<注册>\n请输入您的账号(8至12位数字)\n");
	scanf("%ld", zh);
}

void input2(char mm[])
{
	printf("<注册>\n请输入您的密码(8至16位,需要字母和数字混合,不得有特殊符号)\n");
	gets(mm);
}

int cheak1(long int x) // 检查账号//
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

void cheak2(char s[], int *n, int *a, int *b, int *c) // 检查密码//
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
	fp = fopen("管理员.txt", "rb+");
	if (fp == NULL)
	{
		fp = fopen("管理员.txt", "wb");
		if (fp == NULL)
		{
			printf("open file failed\n");
			exit(0);
		}
	}
	fclose(fp);
	while (q == 0)
	{
		printf("输入对应序号选择想要执行的操作\n1.登录\n2.注册\n3.找回密码\n");
		scanf("%d", &p);
		getchar();
		if ((p != 1) && (p != 2) && (p != 3))
		{
			system("cls");
			printf("操作失败，请重新选择\n1.登录\n2.注册\n3.找回密码");
			continue;
		}

		if (p == 1) // 登录 //
		{
			system("cls");
			fp = fopen("管理员.txt", "r+");
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
				printf("账号:");
				scanf("%ld", &id);
				getchar();
				printf("密码:");
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
					printf("\n登录成功!");
					Sleep(2000);
					menu1();
				}
				else
				{
					system("cls");
					printf("\n密码或账号错误,请重试\n");
					continue;
				}
				fclose(fp);
			}
		}

		if (p == 2) // 注册 //
		{
			fp = fopen("管理员.txt", "rb+");
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
					printf("注册的账号不符合要求，请重新输入\n");
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
					printf("账号已被注册，请重新输入\n");
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
				if (n < 8 || n > 16) // 检查长度//
				{
					printf("注册的密码不符合要求，请重新输入\n");
					continue;
				}
				if (a == 0 || b == 0 || c != 0) 
				{
					printf("注册的密码不符合要求，请重新输入\n");
					continue;
				}
				else
					break;
			}
			system("cls");
			printf("请输入密保信息(限10个汉字或20个字符)\n");
			while ((ch = getchar()) != '\n')
			{
				yh.name[i] = ch;
				i++;
			}
			yh.name[i] = '\0';
			printf("账号注册完成，两秒后返回主菜单......");
			Sleep(2000);
			fwrite(&yh, sizeof(YH), 1, fp);
			fclose(fp);
			system("cls");
			continue;
		}

		if (p == 3) // 找回密码//
		{
			fp = fopen("管理员 .txt", "r+");
			if (fp == NULL)
			{
				printf("open file failed\n");
				exit(0);
			}
			system("cls");
			while (1)
			{
				printf("请输入账号信息以找回密码\n");
				long int id2;
				int l = 0, flag2 = 0;
				char xm[20];
				printf("账号:");
				scanf("%ld", &id2);
				getchar();
				printf("密保信息:");
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
					printf("\n您的密码如下,请妥善保存!!!\n%s\n按任意键返回登录...", mb.mm);
					char o = getchar();

					break;
				}
				else
				{
					system("cls");
					printf("账号信息错误,请重试\n");
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
	fp = fopen("游客.txt", "rb+");
	if (fp == NULL)
	{
		fp = fopen("游客.txt", "wb");
		if (fp == NULL)
		{
			printf("open file failed\n");
			exit(0);
		}
	}
	fclose(fp);
	while (q == 0)
	{
		printf("输入对应序号选择想要执行的操作\n1.登录\n2.注册\n3.找回密码\n");
		scanf("%d", &p);
		getchar();
		if ((p != 1) && (p != 2) && (p != 3))
		{
			system("cls");
			printf("操作失败，请重新选择\n1.登录\n2.注册\n3.找回密码\n");
			continue;
		}

		if (p == 1) // 登录 //
		{
			system("cls");
			fp = fopen("游客.txt", "r+");
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
				printf("账号:");
				scanf("%ld", &id);
				getchar();
				printf("密码:");
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
					printf("\n登录成功!");
					Sleep(2000);
					menu(&db);
				}
				else
				{
					system("cls");
					printf("密码或账号错误,请重试\n");
					continue;
				}
				fclose(fp);
			}
		}

		if (p == 2) // 注册 //
		{
			fp = fopen("游客.txt", "rb+");
			if (fp == NULL)
			{
				printf("open file failed\n");
				exit(0);
			}
			system("cls");
			int i = 0;
			char ch;						// 输入姓名用//
			int sum2 = 0;					// 检查注册账号用//
			int n = 0, a = 0, b = 0, c = 0; // 检查注册密码用//
			while (q == 0)					// 输入账号以及检查 //
			{
				input1(&yh.zh);
				system("cls");
				sum2 = cheak1(yh.zh);
				if ((sum2 < 8) || (sum2 > 12))
				{
					printf("注册的账号不符合要求，请重新输入\n");
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
					printf("账号已被注册，请重新输入\n");
					continue;
				}
				else
					break;
			}

			getchar();
			while (q == 0) // 输入密码以及检查 //
			{
				a = b = c = n = 0;
				input2(yh.mm);
				system("cls");
				cheak2(yh.mm, &n, &a, &b, &c);
				if (n < 8 || n > 16) // 检查长度//
				{
					printf("注册的密码不符合要求，请重新输入\n");
					continue;
				}
				if (a == 0 || b == 0 || c != 0) // a检查有没有字母  b检查有没有数字  c检查有没有特殊符号//
				{
					printf("注册的密码不符合要求，请重新输入\n");
					continue;
				}
				else
					break;
			}
			system("cls");
			printf("请输入密保信息(限10个汉字或20个字符)\n");
			while ((ch = getchar()) != '\n')
			{
				yh.name[i] = ch;
				i++;
			}
			yh.name[i] = '\0';
			yh.xy = 1;
			yh.zt = 0;
			printf("账号注册完成，两秒后返回主菜单......");
			Sleep(2000);
			fwrite(&yh, sizeof(YH), 1, fp);
			fclose(fp);
			system("cls");
			continue;
		}

		if (p == 3) // 找回密码//
		{
			fp = fopen("游客.txt", "r+");
			if (fp == NULL)
			{
				printf("open file failed\n");
				exit(0);
			}
			system("cls");
			while (1)
			{
				printf("请输入账号信息以找回密码\n");
				long int id2;
				int l = 0, flag2 = 0;
				char xm[20];
				printf("账号:");
				scanf("%ld", &id2);
				getchar();
				printf("密保信息:");
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
					printf("\n您的密码如下,请妥善保存!!!\n%s\n按任意键返回登录...", mb.mm);
					char o = getchar();
					break;
				}
				else
				{
					system("cls");
					printf("账号信息错误,请重试\n");
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
		printf("欢迎来到图书管理系统");
		toxy(48, 8);
		printf("管理员登录请按 1");
		toxy(48, 10);
		printf("游客登录请按 2");
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