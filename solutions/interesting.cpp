#include <bits/stdc++.h>
using namespace std;
int k,n,m;
int fib[100];
void init(){
	fib[1]=1;fib[2]=1;
	for (int i = 3; i <= 46; ++i){
		fib[i]=fib[i-1]+fib[i-2];
	}
}
void solve(){
	for (int i =46; i >= 2; i--){
		for (int j = 1; j <k; j++){
			if(k-fib[i]*j<=0)break;
			int tmp = (k-fib[i]*j)/fib[i-1];
			if(k==fib[i]*j+fib[i-1]*tmp&&tmp<=j){
				printf("%d %d\n",tmp,j);
				return;
			}

		}
	}
}
int main(){
	init();
	scanf("%d",&n);
	while(n--){
		scanf("%d",&k);
		solve();
	}
	return 0;
}