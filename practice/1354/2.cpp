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
        string s;
        cin>>s;
        ll l1=-1,f1=-1,f2=-1,l2=-1,l3=-1,f3=-1;

        ll ans=s.length();
        rep(i,0,s.length())
        {
            if(s[i]=='1')
            {
                // if(l1==-1)
                l1=i;
                // f1=i;
            }
            else if(s[i]=='2')
            {
                // if(l2==-1)
                l2=i;
                // f2=i;
            }
            else if(s[i]=='3')
            {
                // if(l3==-1)
                l3=i;
                // f3=i;
            }

            if(l3!=-1 && l1!=-1 && l2!=-1)
            {
               ll ans1=max(l1,max(l2,l3))-min(l1,min(l2,l3));
               ans1+=1;
            //    cout<<ans1<<"<--"<<endl;
               ans=min(ans,ans1);
            }

        }
        if(l1==-1 || l2==-1 || l3==-1)
        {
            cout<<"0"<<endl;
            continue;
        }
        else 
        cout<<ans<<endl;

    }

}