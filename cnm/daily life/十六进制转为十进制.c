#include <stdio.h>
#include<string.h>
long htod(char s[]) {
    int len=0,i;
	for(i=0;s[i];i++)
	{
		len++;
	}
    long decimal = 0;
    int power = 1;

    
    for (i = len - 1; i >= 0; i--) {
        
        if (s[i] >= '0' && s[i] <= '9') {
            decimal += (s[i] - '0') * power;
        }
        
        else if (s[i] >= 'A' && s[i] <= 'F') {
            decimal += (s[i] - 'A' + 10) * power;
        }
        else if (s[i] >= 'a' && s[i] <= 'f') {
            decimal += (s[i] - 'a' + 10) * power;
        }
        power *= 16; 
    }

    return decimal;
}

int main() {
    char s[100];
    gets(s);

    long decimal = htod(s);

    printf("%ld\n", decimal);

    return 0;
}
