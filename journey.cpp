#include <bits/stdc++.h>
using namespace std;
const int MAX = 100005;
vector<int> g[MAX];
bool is[MAX];
double res;
int n,x,y;
void DFS(int i,double p, int d){
    if(g[i].size()>0){
        int vis = 0;
        int s = g[i].size();
        s = (i==1)?s:s-1;
        if(s){
        is[i]=true;
            for (vector<int>::iterator it = g[i].begin(); it != g[i].end(); ++it) {
                if(!is[*it]){
                    DFS(*it,(p/s),d+1);
                    vis++;
                }
            }
        }
        else
            res += p*d;
        
    }
}
int main(){
    memset(is,false,MAX-1);
    scanf("%d",&n);
        int m=n-1;
        while(m--){
            scanf("%d %d",&x,&y);
            g[x].push_back(y);
            g[y].push_back(x);
        }
        DFS(1,1.0,0);
    printf("%.9f\n",res);
    return 0;
}