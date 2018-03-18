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
int minn, arr[100005],n;
int main(){
	scanf("%d",&n);
	minn = 1e9+5;
	for(int i = 0; i<n; i++){
		scanf("%d",&arr[i]);
		minn = min(minn, arr[i]);
	}
	int ant = 1e6;
	int act =1e6;
	int mind = 1e6;
	for(int i = 0; i<n; i++){
		if(arr[i]==minn){
			if(ant==1e6)ant = i;
			else{
				act = i;
				mind = min(mind,act-ant);
				ant = i;
			}
		}
	}
	printf("%d\n",mind);	
	return 0;
}

