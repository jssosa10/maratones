#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
	scanf("%d",&n);
	int s = n%10;
	if(s<5)printf("%d\n",n-s);
	else printf("%d\n",n+10-s);
	return 0;
}

