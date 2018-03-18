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
int n,t;
char s[100005];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%s",s);
		vector<pair<char,int>> v[27];
		int n = 0;
		for(int i  = 0; s[i]; i++){
			v[s[i]-'a'].push_back({s[i],i+1});
			n++;
		}
		int imp  = -1;
		int nimp  =0;
		for(int i = 0;i<27; i++){
			if(v[i].size()%2){
				imp = i;
				nimp ++;
			}
		}
	//	printf("%d\n",'z'-'a');
	//	printf("%d %d\n",n%2,nimp);
		if(nimp>1)
			printf("-1\n");
		else if(n%2&&nimp==0)
			printf("-1\n");
		else if(n%2&&nimp==1){
			//printf("entro\n");
			int c=-1;
			for(int i=0; i<27; i++)
				if(v[i].size()>0&&v[i].size()%2==0){
					c=i;
					break;
				}
			if(c!=-1){
			printf("%d",v[c][0].second);
			for(unsigned int i =1; i<v[c].size()/2; i++)
				printf(" %d",v[c][i].second);
			for(int i =c+1; i<27; i++){
				if(i!=imp)
					for(unsigned int j = 0; j<v[i].size()/2; j++)
						printf(" %d",v[i][j].second);


			}
			for(unsigned int i = 0; i<v[imp].size(); i++)
				printf(" %d",v[imp][i].second);
			for(int i =26; i>=0; i--){
				if(i!=imp)
					for(unsigned int j = v[i].size()/2;j<v[i].size(); j++)
						printf(" %d",v[i][j].second);
			}
			}
			else{
				printf("%d",v[imp][0].second);
				for(unsigned int i = 1; i<v[imp].size(); i++)
					printf(" %d",v[imp][i].second);
			}

			printf("\n");
		}
		else if(n%2==0&&nimp>0)
			printf("-1\n");
		else{
			int c = -1;
			for(int i  =0;i<27; i++)
				if(v[i].size()>0&&v[i].size()%2==0){
					c=i;
					break;
				}
			printf("%d",v[c][0].second);
			for(unsigned int i = 1; i<v[c].size()/2; i++)
				printf(" %d",v[c][i].second);
			for(unsigned int  i = c+1; i<27; i++)
				for(unsigned int j = 0; j<v[i].size()/2;j++)
					printf(" %d",v[i][j].second);
			for(int i = 26; i>=0; i--){
				for(unsigned int j = v[i].size()/2;j<v[i].size();j++ )
					printf( " %d",v[i][j].second);
			}
			printf("\n");
		}
	}
	return 0;
}

