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
    ll t=1;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        ll a[n][m],mat[n][m];
        ll cst[n+1][m+1];
        rep(i,0,n)
        {
            rep(j,0,m)
                cin>>a[i][j];
        }
        // err()
        ll ans=LLONG_MAX;
        rep(i,0,n)
        {
            rep(j,0,m)
            {
                ll fxd=a[i][j];
                ll flg2=0;
                rep(v,0,n)
                {
                    ll flg=0;
                    rep(h,0,m)
                    {
                        mat[v][h]=(fxd)+(h-j)+(v-i);
                        // if(i==0 && j==0)
                        // cout<<v<<" "<<h<<" "<<" "<<mat[v][h]<<"<----"<<endl;
                        
                    }
                    
                }
                

                // rep(v,0,n)
                // {rep(h,0,m)cout<<mat[v][h]<<" ";cout<<endl;}
                
                rep(v,0,n+1)
                rep(h,0,m+1)
                cst[v][h]=1e18; 
                
                rep(v,0,n)
                {
                    ll flg=0;
                    rep(h,0,m)
                    {
                        ll tmp=a[v][h]-mat[v][h];
                        if(tmp<0)
                        {
                            tmp=1e18;  // yahan humne break nahi kiya kyonki  ho sakta yeh cell jo hum change nahi kar sakte wo optimal path par ho hi nahi...toh us karan hum loop toh break nahi kareinge naa....
                            
                            // flg=1;
                            // err()
                            // break;
                        } 
                        // ll mn=1e18;
                        if(v==0 && h==0)
                        cst[v+1][h+1]=tmp;
                        if(v>0)
                        cst[v+1][h+1]=min(cst[v][h+1]+tmp,cst[v+1][h+1]);
                        if(h>0)
                        cst[v+1][h+1]=min(cst[v+1][h]+tmp,cst[v+1][h+1]);

                        // cout<<v<<" "<<h<<" "<<cst[v+1][h+1]<<"<=="<<endl;
                    }
                    if(flg==1)
                    {
                        flg2=1;
                        break;
                    }
                }
                // cout<<cst[n][m]<<" <---"<<endl;
                if(flg2==1)
                continue;
                ans=min(ans,cst[n][m]);
            }
        }
        cout<<ans<<endl;
    }

}