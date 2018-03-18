#include <bits/stdc++.h>
using namespace std;
int n,r;
pairr<int,int> pt;
int main(){
	while(scanf("%d %d",&n,&r)==2&&(r+n)){
		vector<pair<int,int> > f;
		vector<pair<int,int> > s;
		while(n--){
			int x,y;
			char ty;
			scanf("%d %d %c",&x,&y,&ty);
			if(ty=='A')
				f.push_back(make_pair(x,y));
			else 
				s.push_back(make_pair(x,y));
			sort(f,f+sizeof(f));
			sort(s,s+sizeof(s));
			//convex hull :v:v

		}
	}
}
