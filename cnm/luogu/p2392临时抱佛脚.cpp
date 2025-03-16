#include<bits/stdc++.h>
using namespace std;

int len[4];
int sub[30];
int f[21][1201];

int main(){
    ios::sync_with_stdio(false);
    for(int i=0;i<4;i++) cin>>len[i];
    int tot=0;
    for(int i=0;i<4;i++){
        int v=0;
        for(int j=1;j<=len[i];j++) cin>>sub[j],v+=sub[j];
        sort(sub,sub+len[i]);
        int t1=0;
        for(int j=1;j<=len[i];j++)
            for(int k=0;k<=v/2;k++){
                f[j][k]=f[j-1][k];
                if(k>=sub[j])f[j][k]=max(f[j][k],f[j-1][k-sub[j]]+sub[j]);
                t1=max(f[j][k],t1);
            }
        tot+=max(t1,v-t1);
    }
    cout<<tot<<endl;
    return 0;
}