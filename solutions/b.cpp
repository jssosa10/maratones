#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
	scanf("%d",&n);
	int arr[n];
	for (int i = 0; i<n; i++){
		int act;
		scanf("%d",&act);
		arr[i]=act;
	}	
	bool used[n];
	vector<set <int> > sets;
	for(int i = 0; i<n; i++){
		bool inserto = false;
		for(vector<set<int> >::iterator it = sets.begin(); it!=sets.end()&&!inserto; ++it){
			set <int> pq = *it;
			if((*pq.rbegin())<arr[i]){
				pq.insert(arr[i]);
				inserto = true;
			}

		}
		if(!inserto){
			set <int> pq;
			pq.insert(arr[i]);
			sets.push_back(pq);
		}

	}
	for(vector<set<int> >::iterator it = sets.begin(); it!=sets.end(); ++it){
			set <int> pq = *it;
			bool f = true;
			for(set<int>::iterator itt = pq.begin(); itt!=pq.end();++itt){
				if(f){
					printf("%d",*itt);
					f != f;
				}
				else{
					printf(" %d", *itt);
				}

			}
			printf("\n");
		

		}


	return 0;
}