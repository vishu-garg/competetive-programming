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

int main()
{
    ll t;
    cin>>t;
    while(t--){
    ll n;
    cin>>n;
    string s;
    cin>>s;
    ll a=0,b=0,f=-1;
    for(ll i=0;i<s.length();i++)
    {
        if(s[i]=='1')
        {
        	if(i%2==0)
        	a++;
        	else 
        	b++;
		}
		if(i%2==0)
		{
			ll b_rem=(n-(i/2));
			ll a_rem=(b_rem-1);
			if(a>b){
			if(a-b>b_rem)
			{
				f=i+1;
				break;
			}
		}
		else if(b>a)
		{
			if(b-a>a_rem)
			{
				f=i+1;
				break;
			}
			
		}
		}
		else 
		{
			ll a_rem=(n-((i+1)/2));
			ll b_rem=a_rem;
			if(b>a){
			if(b-a>a_rem)
			{
				f=i+1;
				break;
			}
			}
			else if(a>b)
			{
				if(a-b>b_rem)
				{
					f=i+1;
					break;
				}
			}
		}
    }
    if(f==-1)
    {
        cout<<2*n<<endl;
    }
    else 
    cout<<f<<endl;
    }
}