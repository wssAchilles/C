#include <stdio.h>

int main() {
  int n, a = 0, b = 1, c;

  printf("请输入数字 n：");
  scanf("%d", &n);

  printf("斐波那契数列的前 %d 项为：\n", n);

  for (int i = 0; i < n; i++) {
    printf("%d ", a);
    c = a + b;
    a = b;
    b = c;
  }

  return 0;
}