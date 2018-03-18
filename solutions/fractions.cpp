#include <bits/stdc++.h>
using namespace std;
int k;
int main(){
	while(scanf("%d",&k)!=EOF){
		int k2 = k*k;
		vector<pair<int,int> > v;
		for(int i = 1; i<=k; i++){
			if(k2%i==0){
				v.push_back(make_pair(k+k2/i,k+i));
			}
		}
		int n = v.size();
		printf("%d\n",n);
		for(vector<pair<int,int> >::iterator it = v.begin(); it!= v.end(); ++it){
			pair<int, int> p = *it;
			printf("1/%d = 1/%d + 1/%d\n",k,p.first,p.second);
		}
	}
	return 0;
}