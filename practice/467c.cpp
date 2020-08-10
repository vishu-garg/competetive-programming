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
ll dp[5005][5005]; // answer with arr[1....i] and k as 'j'
int main()
{
    ll t=1;
//     cin>>t;
    while(t--)
    {
        ll n,m,k;
        cin>>n>>m>>k;
        ll vec[n+1];
        rep(i,1,n+1)
        cin>>vec[i];
        ll pref_sum[n+1];
        pref_sum[0]=0;
        // pref_sum[1]=vec[1];
        rep(i,1,n+1)
        {
            pref_sum[i]=vec[i]+pref_sum[i-1];
        }

        rep(i,m,n+1)
        {
            rep(j,1,k+1)
            {
                dp[i][j]=dp[i-1][j];
                dp[i][j]=max(dp[i][j],dp[i-m][j-1]+pref_sum[i]-pref_sum[i-m]);
            }
        }
        cout<<dp[n][k]<<endl;
        

        


    }   
}