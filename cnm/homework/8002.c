# include <stdio.h>
# include <stdlib.h>

void fileinit()
{
	char s[128] = "dE#Fg45#-)8[|}" ;	
	int i = 0;
	FILE *from;
	for(i = 0; s[i]; i ++)
		s[i] -= 3;
	from=fopen("from.txt","w");
	fputs(s, from);
	fclose(from);
}
int main()
{
	FILE *from,*to;
	char ch;
	fileinit();
	if((from=fopen("from.txt","r"))==NULL)
	{
		printf("NO");
		exit(0);
	}
	if((to=fopen("to.txt","w+"))==NULL)
	{
		printf("NO");
		exit(0);
	}
	while((ch=fgetc(from))!=-1)
	{
		if(!(ch>='0'&&ch<='9'))
		{
			fputc(ch,to);
		}
	}
	fclose(from);
	rewind(to);
	while((ch=fgetc(to))!=-1)
	{
		putchar(ch);
	}
	return 0;
}
