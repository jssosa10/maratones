#include <bits/stdc++.h>
using namespace std;
int main(){
	int a[1200];
	int f;
	int i,b[2],n,t,s,ss,y,g,gg;
	scanf("%d",&t);
	while(t--){
		s=147;
		ss=15;
		scanf("%d",&n);
		b[1]=b[0]=0;
		f=0;
		a[0]=0;
		y=n;
		g=0;
		gg=0;
		for(int i = 1; i<=n;i++){
			scanf("%d",&a[i]);
			if(ss==0)s-=a[i];
			else if(a[i]==1){
				if(b[f]>=b[1-f]){
					s-=8;
				}
				else{
					s-=1;
					g=1;
				}
			}
			if(a[i-1]==1){
				if(g==1){
					s-=7;g=0;
				}
				ss--;
			}
			b[f]+=a[i];
			if(abs(b[0]-b[1])>s)
				y=min(y,i);
			if(a[i]==0)f=1-f;
		}
		printf("%d\n", y);
	}
	return 0;
}