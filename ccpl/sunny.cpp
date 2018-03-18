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
#define pdd pair<double, double>
#define x first
#define y second
pdd v[105];
int c,n;
double dist(pdd a, pdd b){
	double res = ((a.x-b.x)*(a.x-b.x))+((a.y-b.y)*(a.y-b.y));
	return sqrt(res);
}
int main(){
	scanf("%d",&c);
	while(c--){
		scanf("%d",&n);
		for(int i =0; i<n; i++){
			double x,y;
			scanf("%lf%lf",&x,&y);
			v[i]={x,y};
		}
		sort(v,v+n);
		double mx =0;
		double res = 0.0;
		for(int i = n-2; i>=0; i--){
			if(v[i].y<=mx)continue;
			res+=(dist(v[i],v[i+1])*(v[i].y-mx))/(v[i].y-v[i+1].y);
			mx = v[i].y;
		}
		printf("%.2f\n",res);
	}
	return 0;
}

