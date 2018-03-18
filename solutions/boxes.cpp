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
int n,arr[5005];
using namespace std;
int main(){
	scanf("%d",&n);
	for(int i = 0; i<n; i++)
		scanf("%d",arr+i);
	sort(arr, arr+n);
	vector<int> v;
	v.push_back(1);
	int i = 0;
	for(int j = 1; j<n; j++){
		if(arr[j-1]!=arr[j]){
			v.push_back(1);
			i++;
		}
		else{
			v[i]++;
		}

	}	
	int res = 0;
	for(int j = 0; j<v.size(); j++){
		res = max(res,v[j]);
	}
	printf("%d\n",res);

	return 0;
}

