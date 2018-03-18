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
int n,p[300];
int main(){
	scanf("%d%d%d",&n,&p[0],&p[1]);
	if(p[0]>p[1])
		swap(p[0],p[1]);
	if(p[1]==p[0]){
		printf("%d\n",(p[0]+p[1])/n);
		return 0;
	}
	for(int i =2; i<n; i++){
		p[i]=p[i-1]-(p[i-1]/2);
		p[i-1]=p[i-1]/2;
		sort(p,p+i+1);
	}
	printf("%d\n",p[0]);

	return 0;
}

