#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 
int T;
const int M = 100007;
ll tree[4*M];
ll lazy[4*M];
ll a;
void upd(ll x, ll y, ll val, ll node =1,ll lo = 1, ll hi =a){
	//printf("entro\n");
	ll l = node<<1, r = node<<1|1;
	if(lazy[node]){
		tree[node]+=lazy[node]*(hi-lo+1);
		if(hi!=lo){
			lazy[l]+=lazy[node];
			lazy[r]+=lazy[node];
		}
		lazy[node]=0;
	}
	if(lo>hi or lo>y or hi<x)
		return;
	if(lo>=x and hi<=y){
		tree[node]+=val*(hi-lo+1);
		if(hi!=lo){
			lazy[l]+=val;
			lazy[r]+=val;
		}
		return ;
	}
	ll mid = (hi+lo)>>1;
	upd(x,y,val,l,lo,mid);
	upd(x,y,val,r,mid+1,hi);
	tree[node]=tree[l]+tree[r];	
}
ll qe(ll x, ll y, ll node = 1, ll lo = 1, ll hi =a){
	if(lo>hi or lo>y or hi<x) return 0;
	ll l = node<<1, r=node<<1|1;
	if(lazy[node]){
		tree[node]+=lazy[node]*(hi-lo+1);
		if(hi!=lo){
			lazy[l]+=lazy[node];
			lazy[r]+=lazy[node];
		}
		lazy[node]=0;
	}
	if(lo>=x and hi<=y) return tree[node];
	ll mid = (hi+lo)>>1;
	return qe(x,y,l,lo,mid)+qe(x,y,r,mid+1,hi);
}
int main(){
	scanf("%d",&T);
	for(int i  = 1; i<=T; i++){
		ll c;
		//memset(lazy,0,sizeof(lazy))
		scanf("%lld%lld",&a,&c);
		memset(tree, 0 , sizeof(tree));
		memset(lazy, 0, sizeof(lazy));

		//printf("Scenario #%d:\n",i);
		//build(1,0,n-1);
		while(c--){
			ll cc;
			ll m,n;
			scanf("%lld %lld %lld",&cc,&m,&n);
			if(cc==0){
				//printf("updating\n");
				long long v;
				scanf("%lld",&v);
				upd(m,n,v);
				
			}
			else{
				//printf("OK\n");
				//printf("calculating\n");
				printf("%lld\n", qe(m,n));
			}
		}
	}
	return 0;

}