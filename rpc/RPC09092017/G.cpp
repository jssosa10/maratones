#include <bits/stdc++.h>
using namespace std;
int T,res;
int main()
{ 
    string l;
    getline(cin,l);
    T = stoi(l);
    while(T--){
        int m = 0;
        vector<int> vec;
        res = 0;
        string line;
        getline(cin,line);
        int i;
        istringstream ss(line);
        while(ss >> i){
            vec.push_back(i);
            m = max(m,i);
       } //Extract integers from line
       bool is = false;
       for(vector<int>::iterator it = vec.begin(); it!=vec.end();++it){
        if(*it==m && !is){
            is =true;
            res++;
        }
        else if(*it==m && is){
            is = false;
            res++;
        }
        else if(is){
            res++;
        }
    }
    printf("%d\n",res);
}

}