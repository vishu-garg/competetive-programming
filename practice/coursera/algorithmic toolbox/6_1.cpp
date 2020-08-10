#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
 
#define ll long long
#define ld long double
 
#define rep(i,a,b) for(ll i=a;i<b;i++)
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
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int pow1(int a,int b){
    int res=1;
    while(b>0){
        if(b&1){
        	res=res*a;
		}
        a=a*a;
        b>>=1;
    }
    return res;
}

int main()
{
    fast;
    ll T=1;
//     cin>>T;
    while(T--)
    {
        ll W,n;
        cin>>W>>n;
        vector<ll>w(n+1);
        rep(i,1,n+1)
        cin>>w[i];
        vector<ll>v(n+1);
        vector<V> mat(W+1,V(n+1,0));
        // rep(i,1,n+1)v[i]=w[i];
        // for(ll wght=0;wght<=W;wght++)
        // {
        //     mat[wght][0]=0;
        // }
        // for(ll i=0;i<=n;i++)
        // {
        //     mat[0][i]=0;
        // }
        for(ll wght=1;wght<=W;wght++)
        {
            for(ll i=1;i<=n;i++)
            {
                mat[wght][i]=mat[wght][i-1];
                if(wght>=w[i])
                {
                    ll tmp=mat[wght-w[i]][i-1]+w[i];
                    if(tmp>mat[wght][i])
                    mat[wght][i]=tmp;
                }
            }
        }
        cout<<mat[W][n]<<endl;
    }

}