#include <stdio.h>

int main() {
  int n, a = 0, b = 1, c;

  printf("���������� n��");
  scanf("%d", &n);

  printf("쳲��������е�ǰ %d ��Ϊ��\n", n);

  for (int i = 0; i < n; i++) {
    printf("%d ", a);
    c = a + b;
    a = b;
    b = c;
  }

  return 0;
}