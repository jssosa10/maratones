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
long long x,y;
int main(){
	scanf("%lld%lld",&x,&y);
	if((y<=1&&x!=0)||y==0){
		printf("No\n");
		return 0;
	}
	y--;
	if(y>x)
		printf("No\n");
	else{
		if((x-y)%2==0)
			printf("Yes\n");
		else
			printf("No\n");
	}

	return 0;
}

