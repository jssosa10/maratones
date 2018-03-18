#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> point_t;

long long crossProduct(point_t A, point_t B, point_t C) {
	return (B.first - A.first) * (long long)(C.second - A.second) - (B.second - A.second) * (long long)(C.first - A.first);
} 
pair< vector<point_t>, vector<point_t> > convexHull(vector<point_t> p) {
	sort(p.begin(), p.end());
 
	vector<point_t> hull, unused;
 
	if (p.size() < 3) return make_pair(unused, p);
 	//printf("init first\n");
	for (int zz=0; zz < p.size(); zz++) {
        point_t x=p[zz];
		while (hull.size() > 1 && crossProduct(hull[hull.size() - 2], hull.back(), x) > 0) hull.pop_back();
 		//printf("%d %d\n",x.first,x.second);
		hull.push_back(x);
	}
	//printf("end first\n");
	//printf("%d %d %d %d\n",hull[0].first,hull[0].second,hull[hull.size()-1].first,hull[hull.size()-1].second );
	hull.pop_back();
	//printf("%d %d %d %d\n",hull[0].first,hull[0].second,hull[hull.size()-1].first,hull[hull.size()-1].second );
 
	int f = hull.size() + 1;
	reverse(p.begin(), p.end());
	//printf("init second\n");
    for (int zz=0; zz < p.size(); zz++) {
        point_t x=p[zz];
		while ((int)hull.size() > f && crossProduct(hull[hull.size() - 2], hull.back(), x) > 0) hull.pop_back();
 		//printf("%d %d\n",x.first,x.second);
		hull.push_back(x);
	}
	//printf("end second\n");
 
	//printf("%d %d %d %d\n",hull[0].first,hull[0].second,hull[hull.size()-1].first,hull[hull.size()-1].second );
	hull.pop_back();
	
 
	set<point_t> s;
	for (int zz=0; zz < hull.size(); zz++)
    {
    	//printf("point # %d procesed: %d %d\n",zz+1,hull[zz].first,hull[zz].second);
        point_t x=hull[zz];
        s.insert(x);
    }
 
	for (int zz=0; zz < p.size(); zz++)
    {
        point_t x=p[zz];
        if (s.count(x) == 0) unused.push_back(x);
    }
 
	return make_pair(unused, hull);
}
 
vector<point_t> p, q, r;
 
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		p.clear();
 
		int n, m;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
 
			p.push_back(make_pair(x, y));
		}
        pair< vector<point_t>, vector<point_t> > kk=convexHull(p);
        p=kk.first;
        q=kk.second;
		if ((int)p.size() == 0) {
			printf("-1\n");
 
			continue;
		}
        kk=convexHull(p);
        p=kk.first;
        r=kk.second;
		n = q.size();
		m = r.size();
 
		long long area = 0, ans = 0;
		for (int i = 1; i + 1 < n; i++) area += crossProduct(q[0], q[i], q[i + 1]);
 
		q.push_back(q[0]);
		for (int i = 0, j = 0; i < n; i++) {
			while (abs(crossProduct(q[i], q[i + 1], r[j])) > abs(crossProduct(q[i], q[i + 1], r[(j + 1) % m]))) j = (j + 1) % m;
			while (abs(crossProduct(q[i], q[i + 1], r[j])) > abs(crossProduct(q[i], q[i + 1], r[(j + m - 1) % m]))) j = (j + m - 1) % m;
 
			ans = max(abs(area) - abs(crossProduct(q[i], q[i + 1], r[j])), ans);
		}
 
		printf("%lld\n", ans);
	}
 
	return 0;
}