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
int n,m;
vector<int>a,b;
int main(){
	while(scanf("%d",&n)!=EOF){
		scanf("%d",&m);
		a.clear();
		b.clear();
	map<int,int> mp;	
	while(n--){
		int x;
		scanf("%d",&x);
		a.push_back(x);
	}
	while(m--){
		int x;
		scanf("%d",&x);
		b.push_back(x);
	}
	for(int x : a)
		for(int y : b)
			if(y>=x)
				++mp[y-x];
	int mx = 0;
	for(auto it : mp){
		mx = max(mx,it.second);
	}
	int ans = 1e9+1e5+5;
	for(auto it : mp){
		if(it.second==mx){
			ans = min(ans,it.first);
		}
	}
	if(ans >=1e9+1e4+4){
		ans =0;
	}
	printf("%d\n",ans);
	}
	return 0;
}

