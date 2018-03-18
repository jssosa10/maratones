#include <bits/stdc++.h>
using namespace std;
long long a,b,n;
int main(){
	scanf("%lld%lld%lld",&n,&a,&b);
	for(long long i = 0; i*a<=n;i++){
		if((n-a*i)%b==0){
			printf("YES\n%lld %lld\n",i,(n-a*i)/b);
			return 0;

		}
			
	}
	printf("NO\n");
	return 0;
}

