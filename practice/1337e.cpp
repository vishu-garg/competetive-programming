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
const ll M = 998244353;
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
ll dp[3005][3005];
int main()
{
    ll t=1;
    // cin>>t;
    while(t--)
    {
        string s,t;
        cin>>s>>t;
        int n=s.length();
        int m=t.length();
        rep(i,0,3005)
        {
            rep(j,0,3005)
            dp[i][j]=0;
        }
        rep(i,0,n)
        {
            if(i<m && t[i]==s[0])
            dp[0][i]=2;
            else if(i>=m)
            dp[0][i]=2;
        }

        rep(i,1,n)
        {
            for(int j=1;(i+j-1)<n;j++)
            {
                if((j-1)>=m)
                {dp[i][j-1]=dp[i][j-1]+dp[i-1][j];
                dp[i][j-1]%=M;}
                else if(s[i]==t[j-1])
                {dp[i][j-1]=dp[i][j-1]+dp[i-1][j];
                dp[i][j-1]%=M;}
                // cout<<i-1<<" "<<j<<" "<<dp[i-1][j]<<endl;
            }

            for(int j=0;(i+j)<n;j++)
            {
                if((i+j)>=m)
                {dp[i][j]=dp[i][j]+dp[i-1][j];
                dp[i][j]%=M;}
                else if(s[i]==t[i+j])
                {dp[i][j]=dp[i][j]+dp[i-1][j];
                dp[i][j]%=M;}
            }
        }
        ll ans=0;
        rep(i,m-1,n)
        {
            // cout<<i<<" "<<dp[i][0]<<"<--"<<endl;
            ans=(ans+dp[i][0])%M;
        }
        cout<<ans;
    }

}