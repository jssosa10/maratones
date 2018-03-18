#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int M = 1000000007;
ll n,m;
int v;
ll p ( ll m, ll n ) {
	if ( n==0 ) return 1;
	ll ret = p(m, n/2);
	if ( n%2==0 )
		return (ret*ret)%M;
	else
		return (((ret*ret)%M)*m)%M;
}
ll solve(ll n,ll m, int v){
	if(n%2!=m%2 && v==-1)
		return 0;
	else if(n==1 || m==1)
		return 1;
	else
		return p(p(2,m-1),n-1);

}
int main(){
	cin>>n>>m>>v;
	cout<<solve(n,m,v)<<'\n';
	return 0;
}