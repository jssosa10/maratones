#include <bits/stdc++.h>
using namespace std;
int n, arr[105];
int main(){
	scanf("%d", &n);
	for(int i = 0; i<n; i++){
		int act;
		scanf("%d",&act);
		arr[i]=act;
	}
	bool is = true;
	int ant = arr[1]-arr[0];
	for(int i = 2; i<n; i++){
		if((arr[i]-arr[i-1])!=ant){
			is =false; 
			break;
		}
	}
	if(is)printf("%d\n",arr[n-1]+ant);
	else printf("%d\n",arr[n-1]);
	return 0;
}