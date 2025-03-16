#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

int main()
{
    char *names[] = {"曹磊","陈佳明","陈晓楠","程志阳","丁羽彤","范雨杭","胡子健","黄俊凯","李保林","刘汶鑫",
"龙小涛","钱季清","施安娜","孙鹏","唐胡煜","王凡榛","王信哲","王永晴","魏铄苏","吴韵涵","邢嵘","杨怡轩","殷馨怡","张欢",
"张悟泽","张耀文","章攀","郑谢奇","周宇帆",};
    int num_names =29;
    int select_index;

    srand(time(NULL));
    select_index = rand() % num_names;
    printf("幸运观众:%s\n", names[select_index]);

    return 0;
}
