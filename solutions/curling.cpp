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
int n,r,xs[1005];
double ys[1005];
int main(){
	scanf("%d%d",&n,&r);
	for(int i= 0; i<n; i++){
		scanf("%d",&xs[i]);
	}
	ys[0]=r/1.0;
	for(int i = 1; i<n; i++){
		double ymax = 0;
		for(int j=0; j<i; j++){
			if(xs[i]-r<xs[j]+r||xs[i]+r>xs[j]-r){
				int xx = xs[i]-xs[j];
				xx = xx*xx;
				int R = 4*r*r;
				double y = sqrt(R-xx)+ys[j];
				ymax = max(ymax,y);

			}
		}
		if(ymax==0)ymax = r/1.0;
		ys[i]=ymax;
	}
	printf("%8f",ys[0]);
	for(int i = 1; i<n; i++)printf(" %8f",ys[i]);
	printf("\n");
	return 0;
}

