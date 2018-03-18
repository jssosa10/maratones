#include <bits/stdc++.h>
using namespace std;
int N,M,E,R,x,y,res,nodes,arcs;
bool is[1005];
vector<int> g[1005];
#define min(a,b)(((a)<(b))?(a):(b))
void dfs(int i,int p){
    is[i]=true;
    nodes++;
    arcs+=g[i].size();
    for(vector<int>::iterator it = g[i].begin(); it!=g[i].end();++it){
        int act = *it;
        if(!is[act]){
            dfs(act,i);
        }
    }
}
int main(){
    while(scanf("%d %d %d %d",&N,&M,&R,&E)!=EOF){
        memset(is,false,sizeof(is));
        res = 0;
        while(M--){
            scanf("%d %d",&x,&y);
            g[x].push_back(y);
            g[y].push_back(x);
        }
        for(int i = 1; i<=N ; i++){
            nodes = 0;
            arcs = 0;
            if(!is[i]){
                dfs(i,0);
                arcs /= 2; 
                res += min(E*nodes,(((nodes-1)*nodes/2)-arcs)*R);
            }
        }
        printf("%d\n",res);
        for (auto& v : g) {
               v.clear();
            }
    }
    return 0;
}