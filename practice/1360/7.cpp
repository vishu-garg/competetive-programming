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
    cin>>T;
    while(T--)
    {
        ll n,m,a,b;
        cin>>n>>m>>a>>b;
        int mat[n][m];
        if(a>m || b>n)
        {
            cout<<"NO"<<endl;
            continue;
        }
        if(a*n != b*m)
        {
            cout<<"NO"<<endl;
            continue;
        }
        rep(i,0,n)
        {
            rep(j,0,a)
            {
                mat[i][j]=1;
            }
            rep(j,a,m)
            {
                mat[i][j]=0;
            }
        }
        ll flg=0;
        rep(i,0,m)
        {
            ll sum=0;
            rep(j,0,n)
            {
                sum+=mat[j][i];
            }
            if(sum==b)
            continue;
            ll req=sum-b;
            rep(j,0,n)
            {
                if(req==0)
                {
                    break;
                }
                if(mat[j][i]==1)
                {
                    rep(k,i+1,m)
                    {
                        if(mat[j][k]==0)
                        {
                            mat[j][i]=0;
                            req--;
                            mat[j][k]=1;
                            break;
                        }
                    }
                }
            }
            if(req!=0)
            {
                flg=1;
                break;
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
                rep(j,0,m)
                cout<<mat[i][j];
                cout<<endl;
            }
        }
    }

}