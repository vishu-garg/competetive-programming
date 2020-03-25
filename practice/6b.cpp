#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
 
#define ll long long
#define ld long double
 
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repb(i,a,b) for(ll i=a;i>=b;i--)
 
#define err() cout<<"=================================="<<endl;
#define errA(A) for(auto i:A)   cout<<i<<" ";cout<<endl;
#define err1(a) cout<<#a<<" "<<a<<endl
#define err2(a,b) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<endl
#define err3(a,b,c) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<" "<<#c<<" "<<c<<endl
#define err4(a,b,c,d) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<" "<<#c<<" "<<c<<" "<<#d<<" "<<d<<endl
 
#define pb push_back
#define all(A)  A.begin(),A.end()
#define allr(A)    A.rbegin(),A.rend()
#define ft first
#define sd second
 
#define pll pair<ll,ll>
#define V vector<ll>
#define S set<ll>
#define VV vector<V>
#define Vpll vector<pll>
 
#define endl "\n"
 
const ll logN = 20;
const ll M = 1000000007;
const ll INF = 1e12;
#define PI 3.14159265

int main()
{
    int n,m;char c;
    cin>>n>>m>>c;
    string mat[n];
    vector<pair<int,int> > v;
    rep(i,0,n)
    {cin>>mat[i];}
    rep(i,0,n)rep(j,0,m){
    if(mat[i][j]==c)v.pb({i,j});}
    set<char> s;
    rep(i,0,v.size())
    {
        int r=v[i].first;int c2=v[i].second;
        // cout<<r<<" "<<c2<<" <==="<<endl;
        if((r-1)>=0)
        if(mat[r-1][c2]!='.' && mat[r-1][c2]!=c && (s.find(mat[r-1][c2])==s.end())) 
        s.insert(mat[r-1][c2]);
        if(r+1<n)
        if(mat[r+1][c2]!='.' && mat[r+1][c2]!=c && (s.find(mat[r+1][c2])==s.end()))
        s.insert(mat[r+1][c2]);
        if(c2+1<m)
        if(mat[r][c2+1]!='.' && mat[r][c2+1]!=c && (s.find(mat[r][c2+1])==s.end()))
        s.insert(mat[r][c2+1]);
        if(c2-1>=0)
        if(mat[r][c2-1]!='.' && mat[r][c2-1]!=c && (s.find(mat[r][c2-1])==s.end()))
        s.insert(mat[r][c2-1]);
    }
    cout<<s.size();
}