#include <bits/stdc++.h>
using namespace std;
string words[105];
string ord[105];
map<int, set<string>> mp;
char s[10000001];
const int A = 100000009;
int B,h,h2;
//a%b
int mod(int a,int b){
    return ((a%b)+b)%b;
}
int hashi(char val[]){
    h = 0;
    int l = strlen(val);
    for (int i = 0; i<l; i++ ) {
        h = mod(h*B+val[i],A);
    }
    return h;
} 
int  main(){
    iostream::sync_with_stdio(false); cin.tie(NULL);
    B = rand()%(A-2)+1; int i = 0;
    while(scanf("%s",s) == 1&& strcmp(s,"XXXXXX") ){
        words[i] = s;
        sort(s,s+strlen(s));
        ord[i]=s;
        //cout<<words[i]<<'\n';
        //cout<<ord[i]<<'\n';
        char temp[1000005];
        strcpy(temp,ord[i].c_str());
        h2 = hashi(temp);
        mp[h2].insert(words[i]);
        
    }
    while(scanf("%s",s) == 1&& strcmp(s,"XXXXXX") ){
         sort(s,s+strlen(s));
         int h2 = hashi(s);
         set<string> st = mp[h2];
         if(st.size()>0){
             for (set<string>::iterator it = st.begin() ; it != st.end(); ++it) {
             cout<<*it<<'\n';
             
            } 
         }
        else
        cout<<"NOT A VALID WORD\n";
         cout<<"******"<<'\n';
         
    }
    
    return 0;
}