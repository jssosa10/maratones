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
int main(){
	int a=2, b=13, c=18;
	int x = (1<<31)-1;
	a = a^x,b=b^x,c=c^x;
	printf("%d %d %d %d",a,b,c,a&b&c);
	return 0;
}

