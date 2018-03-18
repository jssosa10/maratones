#include <bits/stdc++.h>
using namespace std;
void matt(unsigned long long a[], unsigned long long b[]){
	unsigned long long x,w,y,z;
	w = (a[0]*b[0]+a[1]*b[2])%1000000000;
	x = (a[0]*b[1]+a[1]*b[3])%1000000000;
	y = (a[2]*b[0]+a[3]*b[2])%1000000000;
	z = (a[2]*b[1]+a[3]*b[3])%1000000000;
	a[0]=w;
	a[1]=x;
	a[2]=y;
	a[3]=z;
}
int T,k;
int main(){
	scanf("%d",&T);
	while(T--){
		unsigned long long n;
		scanf("%d %llu",&k,&n);
		if(n==0){
			printf("%d 0\n",k);
			continue;
		}
		if(n==1||n==2){
			printf("%d 1\n",k);
			continue;
		}
		n = n-2;
		unsigned long long res[4]={1,1,1,0};
		unsigned long long base[4]={1,1,1,0};
		while(n>0){
			if(n%2)matt(res,base);
			matt(base,base);
			n = n>>1;
		}
		printf("%d %llu\n",k,res[0]%1000000000);
	}
	return 0;
}