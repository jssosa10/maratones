#include <bits/stdc++.h>
using namespace std;
int n,a;
int main(){
 while(scanf("%d %d",&n,&a)!=EOF){

   int res = a*(n*pow(a,n+1)-(n+1)*pow(a,n)+1)/pow(a-1,2);
   if(a!=1)
   		printf("%d\n",res);
	else
		printf("%d\n",(n*(n+1)/2));

 }
 return 0;
}