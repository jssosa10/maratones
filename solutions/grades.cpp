#include <bits/stdc++.h>
using namespace std;
int t1,t2,f,a,ct1,ct2,ct3,T;
char grade(int n){
 if(n>=90)
 	return 'A';
 if(n>=80)
 	return 'B';
 if(n>=70)
 	return 'C';
 if(n>=60)
 	return 'D';
 return 'F';
}
int main(){
	scanf("%d",&T);
	for(int i =1; i<=T; i++){
		scanf("%d %d %d %d %d %d %d",&t1,&t2,&f,&a,&ct1,&ct2,&ct3);
		int m = max((ct1+ct2)/2,max((ct1+ct3)/2, (ct2+ct3)/2));
		printf("Case %d: %c\n",i,grade(t1+t2+f+a+m));
	}
	return 0;
} 