#include <bits/stdc++.h>
using namespace std;
const int MAX = 50005;
int f[MAX];
int is[MAX];
int T,N,x,y,res,pos;
void allc(int i){
    for(int j = 1;j<=N;j++){
        if(is[j]==0)is[j]=i;
    }
}
void dfs(int i,int ct){
    is[i]=0;
    if(f[i]!=-1){

        if(is[f[i]]==-1){
            dfs(f[i],ct+1);
        }
        else if(is[f[i]]==0){
            allc(ct);
        }
        if(is[i]==0){
            is[i]=is[f[i]]+1;
        }
    }
     
}
void DFS (){
    for (int i = 1; i <= N; i++) {
        if(is[i]==-1)
        dfs(i,1);
    }
}

int main(){
    scanf("%d",&T);
    for(int i = 1;i<=T;i++){
        memset(is,-1,MAX);
        memset(f,-1,MAX);
        scanf("%d",&N);
        int m = N;
        while(m--){
            scanf("%d %d",&x,&y);
            f[x]=y;
        }
        DFS();
        res = 0;
        pos = 0;
        for(int j=1; j<= N;j++){
            if(is[j]>res){
                res = is[j];
                pos = j;
            }
        }
        printf("Case %d: %d\n",i,pos);
        
    }
}