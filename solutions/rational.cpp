#include <bits/stdc++.h>
using namespace std;
int p,q,T,k;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d %d/%d",&k,&p,&q);
		long long n=1,res =0;
		while(p!=1||q!=1){
			if(p>q){
				p=p-q;
				res += 1*n;
			}
			else{
				q=q-p;
				res += 0*n;
			}
			n*=2;
		}
		printf("%d %lld\n",k,n+res);
	}
	return 0;
}