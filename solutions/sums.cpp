#include <bits/stdc++.h>
using namespace std;
int k,t;
long long n;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%lld",&k,&n);
		printf("%d %lld %lld %lld\n",k,n*(n+1)/2,n*n,n*(n+1));
	}
	return 0;
}