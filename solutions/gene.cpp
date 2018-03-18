#include <bits/stdc++.h>
using namespace std;
int n,T,d1[100005],d2[100005];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for (int i = 0; i <n; ++i){
			scanf("%d",&d1[i]);
		}
		for (int i = 0; i <n; ++i){
			scanf("%d",&d2[i]);
		}
		int in = 1;
		set<int> s1;
		set<int> s2;
		for (int i = 0; i < n; ++i){
			s1.insert(d1[i]);
			s2.insert(d2[i]);
			if(s1==s2){


				if(in-1)
					printf(" %d-%d",in,i+1);
				else
					printf("%d-%d",in,i+1);
				in =i+2;
				s1.clear();
				s2.clear();
			}
		}
		printf("\n");

	}
	return 0;
}