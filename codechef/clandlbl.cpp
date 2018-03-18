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
int D[1005],dp[1005][1005]={{0}};
void sieve(){
	for(int i = 1;i<=1000; i++){
		for(int j = i; j<=1000; j+=i)
			D[j]++;
	}
}
void fill(){
	for(int i =1; i<=1000; i++){
		for(int j = 1; j<=1000; j++)
			if(i!=j)
				dp[i][j]=dp[j][i]=D[__gcd(i,j)];
	}
}
int main(){
	return 0;
}

