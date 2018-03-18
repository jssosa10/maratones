#include <bits/stdc++.h>
using namespace std;
const int N = 10005;
int k,t,n;
int e[N];
void init(){
	e[1]=1;
	for (int i = 2; i <N; ++i){
		e[i]=i;
	}
	for (int i = 2; i < N; ++i){
		if(e[i]==i){
			for (int j = i; j < N; j+=i){
				e[j]=e[j]/i*(i-1);
			}
		}
	}
}
int main(){
	init();
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&k,&n);
		long long sum = 0;
		for (int i = 1; i <=n; ++i){
			sum+=e[i];
		}
		printf("%d %lld\n",k,sum+1 );
	}
	return 0;
}