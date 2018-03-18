#include <bits/stdc++.h>
using namespace std;
char s1[505], s2[505];
int res;
bool eq;
int main(){
    while(scanf("%s %s",&s1,&s2)==2&&s1[0]!='*'){
        res = 0;
        eq = true;
        int l = strlen(s1);
        for(int i = 0; i<l; i++){
            if(eq&&(s1[i]!=s2[i])){
                eq = !eq;
                res++;
            }
            else if(s1[i]==s2[i]){
                eq = true;
            }
        }
        printf("%d\n",res);
    }
    return 0;
}