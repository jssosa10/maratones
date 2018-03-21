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
int n,p;
double sum = 0.0;
int main(){
	scanf("%d",&n);
	for(int i = 0; i<n; i++){
		scanf("%d",&p);
		sum+=p;
	}
	printf("%.8f\n",sum/n);
	return 0;
}

