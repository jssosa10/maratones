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
const int N = 5*1e5;
int n,q,tree[4*N],tt=1;
int gcd(int x, int y){
	return y==0 ? x : gcd(y,x%y);
}
void update(int p,int x){
	p+=tt-1;
	tree[p]=x;
	p/=2;
	while(p>0){
		tree[p]=gcd(tree[2*p],tree[2*p+1]);
		p/=2;
	}
}
bool query(int root, int u, int v, int x, int s, int e){
	if(e<s||v<u||e<u||v<s)
		return 1;
	else if(u<=s && e<=v){
		
	}
}
int main(){
	scanf("%d",&n);
	while(tt<n)
		tt*=2;
	for(int  i =tt; i<tt+n; i++){
		scanf("%d",&tree[i]);
	}
	for(int  i =tt-1; i>=1; i--)
		tree[i]=gcd(tree[2*i],tree[2*i+1]);
	scanf("%d",&q);
	while(q--){
		int t;
	}
	return 0;
}

