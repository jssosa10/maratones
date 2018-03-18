#include <bits/stdc++.h>
using namespace std;
// first = y
//hallar los posibles intervalos para cada  en los que puede estar x
//ordene los intervalos y revise las intersecciones.
int n,d;
long double x,y;
pair<double,double> inter[1005];
pair<int,int> point[1005];
bool cmp(const pair<double, double> &i,const pair<double, double> &j){
        return (i.second == j.second) ? (i.first < j.first) : (i.second < j.second);
}
int main(){
	int cas =0;
	while(scanf("%d %d",&n,&d)==2&&(n+d)){
		bool paila = false;
		for(int i =0; i<n;i++){
			scanf("%Lf %Lf",&x,&y);
			if(y>d){
				paila =true;
			}
			else{
				long double sqrtd = sqrt( d * d - y * y );
				inter[i]=make_pair(x-sqrtd,x+sqrtd);
			}
		}
		if(paila){
			printf("Case %d: %d\n",++cas,-1);
			continue;

		}
			int res = 0;
			sort(inter,inter+n,cmp);
			for(int i = 0; i<n;){
				int j;
				for(j=0; j<n; j++){
					if(inter[j].first>inter[i].second)break;
				}
				i = j;
				res++;
			}
			printf("Case %d: %d\n",++cas,res);
		
	}
}
