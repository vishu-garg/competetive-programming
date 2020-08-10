#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
 
#define ll long long
#define ld double
 
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

int main()
{
    ll t=1;
//     cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ld mat[n][n+1];
        ld res[n];
        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<n+1;j++)
            {
                cin>>mat[i][j];
            }
        }

        for(ll i=0;i<n;i++)
        {
            for(ll j=i+1;j<n;j++)
            {   
                if(abs(mat[i][i])<abs(mat[j][i]))
                {
                    for(ll k=0;k<n+1;k++)
                    {
                        mat[i][k]=mat[i][k]+mat[j][k];
                        mat[j][k]=mat[i][k]-mat[j][k];
                        mat[i][k]=mat[i][k]-mat[j][k];
                    }
                }
            }
        }

        for(ll i=0;i<n;i++)
        {
            for(ll j=i+1;j<n;j++)
            {
                ld f=mat[j][i]/mat[i][i];
                for(ll k=0;k<n+1;k++)
                {
                    mat[j][k]=mat[j][k]-f*mat[i][k];
                }
            }
        }

//		rep(i,0,n){
//		rep(j,0,n+1)
//		{
//			cout<<mat[i][j]<<" ";
//		}
//		cout<<endl;
//		}

        for(ll i=n-1;i>=0;i--)
        {
            res[i]=mat[i][n];
            for(ll j=i+1;j<n;j++)
            {
                if(i!=j)
                res[i]=res[i]-mat[i][j]*res[j];
            }
            res[i]/=mat[i][i];
        }

        rep(i,0,n)
        cout<<fixed<<setprecision(10)<<res[i]<<" ";
    }

}