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
const ll M = 100000000 ;
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

int main()
{
    ll t=1;
//     cin>>t;
    while(t--)
    {
        ll k1,k2,n1,n2;

        cin>>n1>>n2>>k1>>k2;
        int dp[105][105][2];
        rep(i,0,n1+1)
        rep(j,0,n2+1)
        {
        	dp[i][j][0]=0;dp[i][j][1]=0;
		}
        dp[0][0][0]=1;
        dp[0][0][1]=1;
        rep(i,0,n1+1)
        {
            rep(j,0,n2+1)
            {
                for(int k=1;k<=k1 && k<=i;k++)
                {
                    (dp[i][j][0]+=dp[i-k][j][1])%=M;
                }
                for(int k=1;k<=k2 && k<=j ;k++)
                {
                    (dp[i][j][1]+=dp[i][j-k][0])%=M;
                }
            }
        }
        cout<<(dp[n1][n2][0]+dp[n1][n2][1])%M;
    }

}