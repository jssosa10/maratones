#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	scanf("%d",&n);
	bool end = false;
	for(int i=1; i<=n && !end; ++i){
		if(n%i!=0){
			printf("%d\n",i);
			end =true;
		}
	}
	if(!end)printf("%d\n",n+1);
	return 0;
}
