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

int main()
{
    ll t=1;
   cin>>t;
    while(t--)
    {
        ll a,b,p;
        cin>>a>>b>>p;
        string s;
        cin>>s;
        ll n=s.length();
        ll cst[n-1];
        if(s[n-2]=='A')
        cst[n-2]=a;
        else 
        cst[n-2]=b;
        repb(i,n-3,0)
        {
            if(s[i]==s[i+1])
            {
                cst[i]=cst[i+1];
            }
            else 
            {
                if(s[i]=='A')
                cst[i]=cst[i+1]+a;
                else 
                cst[i]=cst[i+1]+b;
            }
        }
        ll flg=0;
        rep(i,0,n-1)
        {
//        	cout<<cst[i]<<" ### "<<i<<"<---"<<endl;
        	if(cst[i]<=p)
        	{
        		flg=1;
        		cout<<i+1<<endl;
        		break;
			}
		}
		if(flg==0)
        cout<<n<<endl;
    }

}