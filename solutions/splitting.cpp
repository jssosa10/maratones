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
int n,ones,dos,a;
int solv(){
	int ans =0;
	if(ones>=dos){
		ans+=dos;
		ones-=dos;
		return ans+ones/3;	
	}	
	else{
		return ones;
	}
}	
int main(){
	scanf("%d",&n);
	ones=0;
	dos=0;
	for (int i = 0; i < n; ++i) {
		scanf("%d",&a);
		if(a==1)ones++;
		else dos++;
	}
	printf("%d\n",solv());
	return 0;
}

