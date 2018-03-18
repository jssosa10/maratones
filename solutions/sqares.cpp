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
int n,nr;
long long x,sqr,ans;
vector<long long> a,b;
int main(){
	scanf("%d",&n);
	for (int i = 0; i < n; ++i) {
		scanf("%lld",&x);
		sqr = sqrt(x);
		if(sqr*sqr==x)nr++,a.push_back(1+(sqr==0));
		else b.push_back(min(x-sqr*sqr,(sqr+1)*(sqr+1)-x));
	}
	ans = 0;
	if(nr>=n/2){
		sort(a.begin(),a.end());
		for (int i = 0; i < nr-n/2; ++i)
			ans+=a[i];		
	}
	else{
		sort(b.begin(),b.end());
		for(int i = 0; i<n/2-nr;++i)ans+=b[i];
	}
	printf("%lld\n",ans );
	return 0;
}

