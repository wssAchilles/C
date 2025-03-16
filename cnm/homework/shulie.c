#include <stdio.h>
int sum(int *arr, int length)
{
	int total = 0;
	for (int i = 0; i < length; i++)
	{
		total += arr[i];
	}
	return total;
}
int main()
{
	int arr[] = {1, 2, 3, 4, 5};
	int length = sizeof(arr) / sizeof(arr[0]);
	int total = sum(arr, length);
	printf("%d\n", total);
	return 0;
}
