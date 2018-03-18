#include <bits/stdc++.h>
using namespace std;
int x,y,r,T;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d %d %d",&x,&y,&r);
		double dist = sqrt(x*x+y*y);
		printf("%.2f %.2f\n",r-dist,r+dist);
	}
	return 0;
}