#include<bits/stdc++.h>
using namespace std;
int sum(int a[],int n){
	int sum=0;
	if(n==0||n==1) return 0;
	int lmax[n],rmax[n];
	lmax[0]=a[0];
	for(int i=1;i<n;i++){
		lmax[i]=max(lmax[i-1],a[i]);//从左到右，lmax[i]表示前i个数的最大值
		//i-1之前的最大值与当前值的最大值
	}
	rmax[n-1]=a[n-1];
	for(int i=n-2;i>=0;i--){
		rmax[i]=max(rmax[i+1],a[i]);//从右到左，rmax[i]表示后n-i个数的最大值
		//i+1之后的最大值与当前值的最大值
	}
	for(int i=0;i<n;i++){
		sum+=min(lmax[i],rmax[i])-a[i];//lmax[i]与rmax[i]的最小值减去当前值
	}
	return sum;
}
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	set<int>RainAmopunts;
	sort(a,a+n);
	do{
		int sum1=sum(a,n);
		RainAmopunts.insert(sum1);//将每次的sum值存入集合中
	}while(next_permutation(a,a+n));//next_permutation函数用于生成下一个排列，直到没有下一个排列为止
	for(int amount:RainAmopunts){
		cout<<amount<<" ";
	}
}
