#include <bits/stdc++.h>
using namespace std;
int T, a,b,c,n;
int main(){
	scanf("%d",&T);
	while(T--){
		int g =-1;
		double res = 0;
		scanf("%d",&n);
		for (int i = 1; i <= n; ++i){
			scanf("%d %d %d",&a,&b,&c);
			double tr = b*b/(4*a)+c;
			//printf("%.3f\n",tr );
			if(g==-1 || tr>res){
				res = tr;
				g = i;
			}
		}
		printf("%d\n",g);
	}
	return 0;
}