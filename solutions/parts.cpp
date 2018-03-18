#include <bits/stdc++.h>
using namespace std;
const int Max = 100001;
typedef vector<int> vi;
vi g[Max];
set<pair<int, int>> ele;
int gr[Max];
int bor[Max];

int main(){
    int N,M,A,B;
    while(scanf("%d %d %d %d",&N,&M,&A,&B)!=EOF){
        ele.clear();
        //cout<<ele.size()<<"\n";
        memset(bor,1,Max);
        memset(gr,0,Max);
        while(M--){
            int x,y;
            scanf("%d %d",&x,&y);
            g[x].push_back(y);
            gr[x]++;
            g[y].push_back(x);
            gr[y]++;
        }
        pair<int,int> p;
        for (int i = 1; i <= N; ++i) {
           ele.insert(pair<int,int>(gr[i],i));
        }
        set<pair<int,int>>::iterator itr;
        vector<int>::iterator it;
        pair<int,int> b;
        int borrados = 1;
        while(borrados && ele.size()>0) {
            itr = ele.begin();
            p = *itr;
            borrados = 0;
            if(p.first<A){
                //cout<<p.first<<","<<p.second<<" 1 "<<"\n";
                borrados++;
                ele.erase(itr++);
                bor[p.second]=0;
                for (it = g[p.second].begin(); it != g[p.second].end(); ++it) {
                    if(bor[*it]){
                        b = pair<int, int>(gr[*it], *it);
                        set<pair<int, int>>::iterator hint = ele.find(b);
                        hint++;
                        ele.erase(ele.find(b));
                        gr[*it]--;
                        b = pair<int, int>(gr[*it], *it);
                        ele.insert(hint, b);
                    }

                }
            }
            if(itr!=ele.end()){
                itr = prev(ele.end());
                p = *itr;
                //cout<<p.sec<<"\n";
                if(p.first>(ele.size()-B-1)){
                   // cout<<p.first<<","<<p.second<<"\n";
                    borrados++;
                    ele.erase(itr);
                    bor[p.second]=0;
                    for (it = g[p.second].begin(); it != g[p.second].end(); ++it) {
                        if(bor[*it]){
                            b = pair<int, int>(gr[*it], *it);
                            set<pair<int, int>>::iterator hint = ele.find(b);
                            hint++;
                            ele.erase(ele.find(b));
                            gr[*it]--;
                            b = pair<int, int>(gr[*it], *it);
                            ele.insert(hint, b);
                        }

                    }
                }
            }


        }
        printf("%d\n",ele.size());

    }
    return 0;
}

