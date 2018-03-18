#include <bits/stdc++.h>
using namespace std;
int T,k,s;
int main(){
	scanf("%d",&T);
	unsigned long long ans= 0, a[51][51];
	a[0][0]=1;
	a[1][0]=1;
	a[1][1]=1;
	for (int i = 2; i <=50; i++){
	 a[i][0]=1;
	 for (int j = 1; j <=50; j++){
	 	a[i][j]=a[i-1][j-1]+a[i-1][j];
	 }
	}
	while(T--){
		ans = 0;
		scanf("%d %d",&k,&s);
		s=s/2;
		for(int i = 0;i<=s/3;i++){
			if((s-i)%2==0){
				int x = (s-i)/2+i;
				ans+=a[x][i]*a[x][i];
			}
		}
		printf("%d %lld\n",k,ans);
	}
	return 0;
}