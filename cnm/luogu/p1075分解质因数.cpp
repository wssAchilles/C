
// #include <bits/stdc++.h>
// using namespace std;
// int main() {
//     int n;
//     cin >> n;
//     for (int i =2; i<n; i++) if (n % i == 0) {
//         cout << n/i;
//         break;
//     }
//     return 0;
// }

#include <stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 2; i < n; i++)
	{
		if (n % i == 0)
		{
			printf("%d\n", n / i);
			break;
		}
	}
}