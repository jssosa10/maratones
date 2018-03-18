#include <bits/stdc++.h>
using namespace std;
int n;
string data;
int main(){
    while(scanf("%d",&n)==1&&n!=0){
        data = bitset<32>(n).to_string();
        int r1,r2; r1=r2=0;
        bool sgn =false;
        int sg=0;
        bool first = true;
        for(int i = 0; i<32; i++){
            r1*=2;
            r2*=2;
            if(data[i]=='1'){
                sg++;
                if(first)
                    r1+=(data[i]-'0');
                else
                    r2+=(data[i]-'0');
                first = !first;

            }
        }
        if(sg%2==0)swap(r1,r2);
        printf("%d %d\n",r1,r2);
    }
    return 0;
}