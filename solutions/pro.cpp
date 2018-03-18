#include <bits/stdc++.h>
using namespace std;
int p,q,k1,k2,T;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d %d %d %d",&p,&q,&k1,&k2);
		double vp,vg;
		vp=vg=0.0;
		for(int i = 0; i<k2; i++){
			vg += (k1+i)*pow((p/q),i); 
		}
		for(int i = 0; i<k1; i++){
			vp += (k2+i)*pow((1-(p/q)),i); 
		}
		vg *= pow(1-(p/q),k1);
		vp *= pow(p/q,k2);
		printf("%.3f %.3f",vg,vp);
		printf("%.3f\n",vp+vg);

	}
	return 0;
}