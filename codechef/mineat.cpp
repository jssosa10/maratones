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
int t,n,h,a[100005];
bool can(int k){
	int r = 0;
	for(int i = 0; i<n; i++){
		r+=a[i]/k;
		r+=(a[i]%k)>0;
	}
	if(r>h)
		return false;
	else
		return true;
}
int sol(int b, int e){
	int mid = (b+e)/2;
	if(b==e)
		return b;
	if(can(mid))
		return sol(b,mid);
	else
		return sol(mid+1,e);
}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&h);
		int mx = 0;
		for(int i = 0; i<n; i++){
			scanf("%d",a+i);
			mx = max(mx, a[i]);
		}
		printf("%d\n",sol(1,mx));
	}
	return 0;
}

