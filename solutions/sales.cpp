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
int t,n,arr[1005];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int res = 0;
		for(int i = 0; i<n ; i++)
			scanf("%d",arr+i);
		for(int i =1; i<n; i++){
			for(int j = 0; j<i; j++)
				if(arr[j]<=arr[i])
					res++;
		}
		printf("%d\n",res);
	}
	return 0;
}

