#include <bits/stdc++.h>
using namespace std;
long long N,R,L,ans,r,l;
int main(){
	while(scanf("%lld %lld %lld",&N,&L,&R)==3){
		ans = 0;
		for (long long i  =31; i>=0; i--){
			if(N&(1LL<<i)){
				r = ans +(1LL<<i);
				if(r<=L)
					ans += 1LL<<i;
			}
			else{
				l = ans+(1LL<<i);
				if(l<= R)
					ans+=1LL<<i;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}