#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

int main()
{
    char *names[] = {"����","�¼���","�����","��־��","����ͮ","���꺼","���ӽ�","�ƿ���","���","������",
"��С��","Ǯ����","ʩ����","����","�ƺ���","�����","������","������","κ����","���Ϻ�","����","������","��ܰ��","�Ż�",
"������","��ҫ��","����","֣л��","���",};
    int num_names =29;
    int select_index;

    srand(time(NULL));
    select_index = rand() % num_names;
    printf("���˹���:%s\n", names[select_index]);

    return 0;
}
