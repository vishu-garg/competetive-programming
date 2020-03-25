#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define rep(i,s,e) for(ll i=s;i<e;i++)
queue<pll> q[10];
char grd[1001][1001];
ll pwr[10],n,m,p;

bool check(ll x , ll y){
    return x>=0 && y>=0 && x<n && y<m;
}

void dfs(ll p)
{
    ll dx[4]={1,0,-1,0};
    ll dy[4]={0,1,0,-1};
    ll n1=pwr[p];
    rep(i,0,n1)
    {
        queue<pll> tmp;
        while(!q[p].empty())
        {
            pll a=q[p].front();
            q[p].pop();
            rep(j,0,4){
                ll nr= a.first + dx[j];
                ll nc= a.second + dy[j];
                if(check(nr,nc)){
                    if(grd[nr][nc]=='.'){
                    grd[nr][nc]=p+1+'0';
                    tmp.push({nr,nc});}
                }
            }
        }
        q[p]=tmp;
        if(q[p].empty()) break;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
cin>>n>>m>>p;
rep(i,0,p) cin>>pwr[i];
rep(i,0,n) rep(j,0,m) cin>>grd[i][j];

rep(i,0,n) rep(j,0,m){
    if(grd[i][j]-'0'>=1 && grd[i][j]-'0'<=p){
        q[grd[i][j]-'1'].push({i,j});
    }
}

bool f=1;
while(f)
{
    f=0;
    rep(i,0,p){
        if(!q[i].empty()){
            dfs(i);
        }
        if(!q[i].empty())
        f=1;
    }
}
ll cnt[p]={0};
rep(i,0,n) rep(j,0,m){
if(grd[i][j]-'0'>=1 && grd[i][j]-'0'<=p)
{
    cnt[grd[i][j]-'1']++;
}
}
rep(i,0,p) cout<<cnt[i]<<" ";
}