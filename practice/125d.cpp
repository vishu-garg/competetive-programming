#include<cstdio>
#include<set>
using namespace std;
 
int n, al, bl, ff, i; 
int s[30000], a[30000], b[30000];
set<int> visa[30000], visb[30000];
 
void dfs(){
	if(al == n) return;
	if(al + bl == n) {ff = 1; return;}
	if(al < 2 || s[al+bl]-a[al-1] == a[al-1]-a[al-2] && (visb[al+bl].find(a[al-1]-a[al-2])==visb[al+bl].end())){
		a[al] = s[al+bl];
		if(al>1) visa[al+bl].insert(a[al]-a[al-1]);
		al++;
		dfs();
		if(ff) return;
		al--;
	}
	if(bl < 2 || s[al+bl]-b[bl-1] == b[bl-1]-b[bl-2] && (visa[al+bl].find(b[bl-1]-b[bl-2])==visa[al+bl].end())){
		b[bl] = s[al+bl];
		if(bl>1) visb[al+bl].insert(b[bl]-b[bl-1]);
		bl++;
		dfs();
		if(ff) return;
		bl--;
	}
}
 
int main(){
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &s[i]);
	ff = al = bl = 0;
	dfs();
	if(ff){
		printf("Yes");
// 		printf("\n");
	}
	else
		{printf("No");
// 		printf("\n");
		}
	return 0;
}