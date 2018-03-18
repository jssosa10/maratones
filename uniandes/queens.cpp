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
int q[8],p[8];
bool pos(int r,int c){
	for(int i=0; i<r;i++){
		if(p[i]==c||abs(r-i)==abs(c-p[i]))return 0;
	}
	return 1;
}
int back(int n){
	if(n==8) return 0;
	int cnt = 1e8;
	for(int i = 0; i<8; i++){
		if(pos(n,i)){
			p[n]=i;
			cnt = min(cnt,(i==q[n])?back(n+1):1+back(n+1));
		}
	}
	return cnt;
}
int tc  =0; 
int main(){
	while(++tc){
		for(int i=0; i<8; i++){
			if(scanf("%d",q+i)==1){
				q[i]--;
				p[i]=q[i];
			}
			else
				return 0;
		}
		printf("Case %d: %d\n",tc,back(0));
	}
	return 0;
}

