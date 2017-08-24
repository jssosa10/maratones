#include <bits/stdc++.h>
using namespace std;
int data[4];
int main(){
    while(scanf("%d %d %d %d",&data[0],&data[1],&data[2],&data[3])!=EOF){
        sort(data, data+4);
        printf("%d\n",abs((data[0]+data[3])-(data[1]+data[2])));
    }

    return 0;
}



