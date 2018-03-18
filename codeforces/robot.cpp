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
pair<int,int> v[100005];
char s[100005];
int n;
bool cmp(pair<int,int>f,pair<int,int>s){
	return f.first*s.second>s.first*f.second;
}
int main(){
	scanf("%d",&n);
	for(int i = 0; i<n; i++){
		scanf("%s",s);
		int ss = 0, h =0;
		for(int j = 0; s[j]; j++){
			if(s[j]=='h')
				h++;
			else
				ss++;

		}
		v[i]={ss,h};
	}
	sort(v,v+n,cmp);
	long long res = 0;
	long long h = 0;
	for(int i = n-1; i>=0; i--){
		h+=v[i].second;	
		res+=v[i].first*h;
	}



	return !printf("%lld\n",res);
}

