#include <bits/stdc++.h>
using namespace std;
int w,t,M,act,profit[25];
set<int> need;
int main(){
	int newl=1;
	while(scanf("%d",&w)==1){
		if(w==0)break;
		M=0;
		need.clear();
		for(int ws=0;ws<w;ws++){
		scanf("%d",&t);
		int amax = 0;
		for (int i = 0; i<t; i++){
			scanf("%d", &act);
			int p = 10-act;
			if(i>0)
				profit[i]=profit[i-1]+p;
			else
				profit[i]=p;
			amax = max(amax,profit[i]);
		}
		M+=amax;
		set<int> acts;
		for(int i  = 0; i< t; i++){
			if(profit[i]==amax)
				acts.insert(i+1);
		}
		if(!acts.empty()&&amax==0)acts.insert(0);
		set<int> nuevo;
		for(set<int>::iterator it = acts.begin(); it != acts.end();++it){
			if(!need.empty()){
				for(set<int>::iterator itt = need.begin(); itt != need.end();++itt){
					nuevo.insert(*it+*itt);
				}
			}
		}
		if(!acts.empty()&&need.empty())
			need = acts;
		else if(!nuevo.empty())
			need = nuevo;	
		}
		if(newl>1)printf("\n");
		printf("Workyards %d\n",newl);
		printf("Maximum profit is %d.\n",M);
		printf("Number of pruls to buy:");
		int i = 1;
		for(set<int>::iterator it = need.begin(); it!= need.end() && i<=10;++it){
			printf(" %d", *it);
			i++;
		}
		if(need.empty())printf(" %d", 0);
		printf("\n");
		newl++;
	}
	return 0;

} 