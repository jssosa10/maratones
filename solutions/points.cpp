#include<bits/stdc++.h>
using namespace std;
const int mx = 200;
pair<int,int> wss[mx];
pair<int,int> rs[mx];
int w,r,x,y;
int main(){
	scanf("%d",&w);
	for (int i = 0; i <w; ++i){
		scanf("%d %d",&x,&y);
		wss[i]=make_pair(x,y);
	}
	scanf("%d",&r);
	for (int i = 0; i <r; ++i){
		scanf("%d %d",&x,&y);
		rs[i]=make_pair(x,y);
	}
	int mxx = 0;
	for(int i=0; i<w; ++i){
		for(int j=i+1; j<w; ++j){
			for(int k=j+1; k<w;++k){
				if(abs((wss[j].first-wss[i].first)*(wss[k].second-wss[i].second)-(wss[j].second-wss[i].second)*(wss[k].first-wss[i].first))){
					double da,db,dc,au1,au2,d;
					da = wss[i].first*wss[i].first+wss[i].second*wss[i].second;
					db = wss[j].first*wss[j].first+wss[j].second*wss[j].second;
					dc = wss[k].first*wss[k].first+wss[k].second*wss[k].second;
					au1 = (da*(wss[k].second-wss[j].second)+db*(wss[i].second-wss[k].second));
					au1 = -(da*(wss[k].first-wss[j].first)+db*(wss[i].first-wss[k].first));
					d = (2*(wss[i].first*(wss[k].second-wss[j].second)+wss[j].first*(wss[i].second-wss[i].second)+wss[k].first*(wss[j].second-wss[i].second)));
					x = au1/d;
					y = au2/d;
					double rr = (x-wss[i].first)*(x-wss[i].first)+(y-wss[i].second)*(y-wss[i].second);
					int res =0;
					for(int l = 0; l<r; ++l){
						if((x-rs[l].first)*(x-rs[l].first)+(y-rs[l].second)*(y-rs[l].second)<=rr){
							res++;
						}
					}
					if(res>mxx){
						mxx=res;
					}
				}
			}
		}
	}
	printf("%d\n", mxx);
	return 0;
}
