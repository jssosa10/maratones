#include <bits/stdc++.h>
using namespace std;
int h1,a1,c1,h2,a2;
vector<int> sol(){
	vector <int> p;
	while(h2>0){
		if(h1>=a2+1||h2<=a1){
			p.push_back(1);
			h1-=a2;
			h2-=a1;
		}
		else{
			p.push_back(0);
			h1+=c1;
			h1-=a2;
		}
	}
	return p;
}
int main(){
	scanf("%d%d%d%d%d",&h1,&a1,&c1,&h2,&a2);
	vector<int> s = sol();
	printf("%d\n",s.size());
	for (unsigned int i = 0; i < s.size(); ++i) {
		if(s[i]==1)
			printf("STRIKE\n");
	       else
	       		printf("HEAL\n");	       

	}
	return 0;
}

