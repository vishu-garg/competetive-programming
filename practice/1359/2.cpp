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
        ll n,m,x,y;
        cin>>n>>m>>x>>y;
        char mat[n][m];
        rep(i,0,n)
        {
            string s;
            cin>>s;
        rep(j,0,m)
        mat[i][j]=s[j];
        }
        ll i=0;
        ll ans=0;
        while(i<n)
        {
            ll j=0;
            ll t1=0,t2=0,t3=0;
            while(j<m)
            {
                if(j<m-1 && mat[i][j]=='.' && mat[i][j+1]=='.')
                {
                    t3+=2;
                    t2++;
                    j+=2;
                }
                else if(mat[i][j]=='.')
                {t1++;j++;t3++;}
                else 
                j++;
            }
            ans+=min((x*t1)+(y*t2),(x*t3));
            i++;
        }
        cout<<ans<<endl;
    }

}