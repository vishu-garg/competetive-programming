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
const ll N=100005;
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

// struct segtree{
//     ll x,y;
//     ll tree[4*N];

//     void build_tree(vector<ll>&v , ll ind,ll l, ll r)
//     {
//         if(l==r)
//         {
//             tree[ind]=v[l];
//             return;
//         }
//         ll mid=(l+r)/2;
//         build_tree(v,2*ind,l,mid);
//         build_tree(v,2*ind+1,mid+1,r);
//         tree[ind]=max(tree[2*ind],tree[2*ind+1]);
//     }

//     ll query(ll ind, ll l, ll r)
//     {
//         // cout<<l<<" "<<r<<" "<<endl;
//         if(x>r || y<l)return -LLONG_MAX;
//         if(l>=x && r<=y)return tree[ind];
//         ll mid=(l+r)/2;
//         return max(query(2*ind,l,mid),query(2*ind+1,mid+1,r));
//     }
// }obj;

int main()
{
    fast;
    ll T=1;
    cin>>T;
    while(T--)
    {
        ll n,m;
        cin>>n>>m;
        ll a[n][m];
        rep(i,0,n)
        rep(j,0,m)cin>>a[i][j];
        
        ll flg=0;
        rep(i,0,n)
        {
            rep(j,0,m)
            {
                // err3(i,j,a[i][j]);
                if(i==0 || i==n-1)
                {
                    if(j==0 || j==m-1)
                    {
                        if(a[i][j]>2)
                        {
                            // err3(i,j,a[i][j]);
                            flg=1;
                        }
                        else 
                        {
                            a[i][j]=2;
                        }
                    }
                    else
                    {
                        if(a[i][j]>3)
                        {
                            // err3(i,j,a[i][j]);
                            flg=1;
                        }
                        else 
                        {
                            a[i][j]=3;
                        }
                    }
                }
                else 
                {
                    if(j==0 || j==m-1)
                    {
                        if(a[i][j]>3)
                        {
                            // err3(i,j,a[i][j]);
                            flg=1;
                        }
                        else 
                        {
                            a[i][j]=3;
                        }
                    }
                    else if(a[i][j]>4)
                    {
                        // err3(i,j,a[i][j]);
                        flg=1;
                    }   
                    else 
                    {
                        a[i][j]=4;
                    }
                }
            }
        }

        if(flg==1)
        {
            cout<<"NO"<<endl;
            continue;
        }
        else 
        {
            cout<<"YES"<<endl;
            rep(i,0,n)
            {
                rep(j,0,m)cout<<a[i][j]<<" ";
                cout<<endl;
            }
        }


    }

}