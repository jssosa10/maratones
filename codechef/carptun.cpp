/*
 * I won't be broken
 * I won't be tortured
 * I won't be beaten down
 * I have the answer
 * I can take the pressure
 * I will turn it all around
 * Lift me up above this
 * The flames and the ashes
 * Lift me up and help me to fly away
*/
#include <bits/stdc++.h>
using namespace std;
int t;
long long a[100005],c,n,d,s;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%lld",&n);
		for(int i = 0; i<n; i++)
			scanf("%lld",a+i);
		scanf("%lld%lld%lld",&c,&d,&s);
		long long first = a[0];
		long long last = c*a[0];
		for(int i = 1; i<n; i++){
			if(((c-1)*a[i])>(last-first))
				last+=(c*a[i]-last+first);
			else
				last+=a[i];
			first+=a[i];
		}
		double r = last-first;
		printf("%.8f\n",r);
			
	}

	return 0;
}

