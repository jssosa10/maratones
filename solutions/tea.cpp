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
int t,n;
pair<pair<int,int>,int> s[1005];
int cmp (pair<pair<int,int>,int>f ,pair<pair<int,int>,int> s ){
	if(f.first.first!=s.first.first)
		return f.first.first<s.first.first;
	else
		return f.first.second < s.first.second;

}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int x,y;
		for(int i = 1; i<=n; i++){
			scanf("%d%d",&x,&y);
			s[i]={{x,i},y};
		}
		sort(s+1,s+n+1,cmp);
		//for(int i  =1; i<=n; i++)
			//printf("%d %d %d\n",s[i].first.first,s[i].first.second, s[i].second);
		int tt =  s[1].first.first+1;
		printf("%d", tt-1);
		for(int i =2; i<=n; i++){
			if(tt>s[i].second){
				printf(" 0");
			}
			else{
				tt = max(tt,s[i].first.first);
				printf(" %d",tt);
				tt++;
			}

		}
		printf("\n");
	}
	return 0;
}

