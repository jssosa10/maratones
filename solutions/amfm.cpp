#include <bits/stdc++.h>
#define eps 0.000000001
typedef long long ll;
using namespace std;
struct point {
    double x;
    double y;
    point(){
        x=0;
        y=0;
    }
    point(double a, double b){
        x=a;
        y=b;
    }
};
struct circle{
    point c;
    double r;
};
double dist(point p1, point p2){
    return (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y);
}
bool intersectC(point c1, double r1, point c2, double r2, pair<point, point> &ans){
    double a = c2.x-c1.x;
    double b = c2.y-c1.y;
    double c = ((r1*r1-c1.x*c1.x-c1.y*c1.y)-(r2*r2-c2.x*c2.x-c2.y*c2.y))/2.0;
    double d = sqrt(a*a+b*b);
    if(!(abs(r1-r2)<=d+eps && d<=abs(r1+r2)+eps)){
        return 0;
    }
    
    a/=d; b/=d; c/=d;
    double e = c -a*c1.x-b*c1.y;
    double h = sqrt(r1*r1-e*e);
    ans.first = point(c1.x+a*e-h*b,c1.y+b*e+h*a);
    ans.second = point(c1.x+a*e+h*b,c1.y+b*e-h*a);
    return 1;
}
int main(){
    int n;
    while (scanf("%d",&n)!=EOF){
        vector<circle> v;
        for(int i= 0; i<n; i++){
            circle cir;
            scanf("%lf %lf %lf",&cir.c.x,&cir.c.y,&cir.r);
            v.push_back(cir);
        }
        vector<point>cand;
        for(int i = 0; i<n; i++){
            cand.push_back(v[i].c);
            for(int j = i+1; j<n ; j++){
                pair<point, point> ans;
                if(intersectC(v[i].c, v[i].r,v[j].c,v[j].r,ans)){
                    cand.push_back(ans.first);
                    cand.push_back(ans.second);
                }
            }
        }
        int res = 0;
        for (int i = 0; i <cand.size(); i++) {
            int count = 0;
            for(int j=0; j<n; j++){
                double dif = v[j].r*v[j].r-dist(cand[i], v[j].c);
                if(dif>=eps)
                    count++;
                else if(abs(dif)<= eps)
                    count++;
            }
            res = max(res,count);
        }
        printf("%d\n",res);
    }
}