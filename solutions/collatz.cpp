#include <bits/stdc++.h>
using namespace std;
int T;
long long n;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%lld",&n);
		long long sum1,sum2,m,mm,po;
		sum1=0;
		sum2=0;
		po = n/2;
		sum1 = n-po;
		m = (n-1)/3 +1;

		if((n-m+1)%2==0){
			sum2 = (n-m+1)/2;
		}
		else{
			if(m%2==0)
				sum2 = (n-m+1)/2;
			else
				sum2 = (n-m+1)/2 +1;
		}
		printf("%lld\n",sum2+sum1);
	}
	return 0;
}
