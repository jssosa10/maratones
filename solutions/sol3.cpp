#include <bits/stdc++.h>
using namespace std;
const int M = 2005;
int n,a[M],gcds[M];
int main(){
	scanf("%d",&n);
	int tc = 0;
	int ones = 0;
	for(int i  =0; i<n; i++){
		scanf("%d",&a[i]);
		tc = __gcd(tc,a[i]);
		if(a[i]==1)
			ones++;
	}
	if(tc!=1)
		printf("-1\n");
	else{
		bool termino = false;
		int res = n-1;
		while(!termino&&n>1){

			for(int i  =0;i<n-1; i++){
				if(a[i]!=1){
					a[i]=__gcd(a[i],a[i+1]);
				}
				else
					termino = true;

			}
			res++;	
		}
		if(ones==0)
			printf("%d\n",res-1);
		else
			printf("%d\n", n-ones);
	}
	return 0;
}