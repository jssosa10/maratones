#include <bits/stdc++.h>
using namespace std;
int n;
int mod(int a, int b)
{
	return (b + (a%b)) % b;
}
int main(){
	scanf("%d",&n);
	int points[n];
	int act;
	int pos = -1;
	for (int i = 0; i<n; i++){
		scanf("%d",&act);
		points[i]=act;
		pos = (pos==-1||points[i]>points[pos])? i : pos;
	}
	if(pos>0&&pos<n-1)
		printf("%d %d %d\n",pos,pos+1,pos+2);
	else if(pos==0)
		printf("%d %d %d\n",n,1,2);
	else
		printf("%d %d %d\n",n-1,n,1);
	return 0;
}