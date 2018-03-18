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
int t,n,a[100005]={0},res[100005]={0};
long long sum[100005]={0};
int bz(int b,int e, int i){
	if(e==b)
		return e;
	int mid = (e+b)/2;
	if(a[i]*(1LL)>=(sum[i-1]-sum[mid])){
		return bz(b,mid,i);
	}
	else
		return bz(mid+1,e,i);
}
int bd(int b,int e, int i){
	if(b==e){
		return e;
	}
	int mid = (e+b)/2;
	if(a[i]*(1LL)>=(sum[mid]-sum[i]))
		return bd(mid+1,e,i);
	else
		return bd(b,mid,i);	
}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i = 1;i<=n ; i++){
			scanf("%d",a+i);
			sum[i]=sum[i-1]+a[i];
		//	printf("%lld\n",sum[i]);
		}
		for(int i = 1; i<=n; i++){
			int l = bz(0,i-1,i);
			int r = bd(i+1,n+1,i);
			res[l]+=1;
			res[i]-=1;
			res[i+1]+=1;
			res[r+1]-=1;
		}
		int acm = 0;
		for(int i = 0; i<=n; i++){
			acm+=res[i];
			res[i]=acm;
		}
		printf("%d",res[1]);
		for(int i=2; i<=n; i++)
			printf(" %d",res[i]);
		printf("\n");
		for(int i= 0; i<=n+1; i++){
			sum[i]=0LL;
			res[i]=0;	
		}
	}
	return 0;
}

