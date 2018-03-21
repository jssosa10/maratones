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
int n,k,f,t;
int main(){
	scanf("%d%d%d%d",&n,&k,&f,&t);
	int res = f-max(0,t-k);
	for(int i =1; i<n; i++){
		scanf("%d%d",&f,&t);
		res = max(res,f-max(0,t-k));
	}
	printf("%d\n",res);
	return 0;
}

