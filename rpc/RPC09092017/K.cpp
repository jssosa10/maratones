#include <bits/stdc++.h>
using namespace std;
const int M = 11;
bool conect[M][M]={false};
int n;
int main(){
	while(scanf("%d",&n)!=EOF){
		for(int i= 1 ; i<=n; i++){
			int m;
			scanf("%d",&m);
			while(m--){
				int act;
				scanf("%d",&act);
				conect[i][act]=true;
			}
		}
		vector<vector<int>> V;
		//V.push_back(vector<int> v.push_back(1));
		for(int i=1;i<=n;i++){
			bool inserto = false;
			for(vector<vector<int>>::iterator it = V.begin(); it!= V.end()&& !inserto; ++it){
			 vector<int> s = *it;
				for(vector<int>::iterator itt = s.begin(); itt!=s.end()&&!inserto; ++itt){
					if(!conect[*itt][i]){
						s.push_back(i);
						inserto = true;
					}
				}
			}
			if(!inserto){
			 	vector<int> v;
		 	 v.push_back(i);
		  	V.push_back(v);
			}
		
		}
		int res = V.size();
		printf("%d\n",res);

	}
	return 0;
}