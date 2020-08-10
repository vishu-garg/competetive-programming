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

bool is_eq(string a, string b)
{
    ll len=a.length();
    if(len%2!=0)
    {
        rep(i,0,len)
        if(a[i]!=b[i])
        return false;
        
        return true;
    }
    else 
    {
        bool chk=true;
        rep(i,0,len)
        if(a[i]!=b[i])
        {chk=false;break;}
        
        if(chk)
        return true;

        string a1="",a2="",b1="",b2="";
        rep(i,0,len/2)
        {
            a1+=a[i];b1+=b[i];
        }
        rep(i,len/2,len)
        {
            a2+=a[i];b2+=b[i];
        }

        cout<<a1<<" "<<b1<<" "<<a2<<" "<<b2<<endl;
        
        if(is_eq(a1,b1) && is_eq(a2,b2))
        return true;
        if(is_eq(a1,b2) && is_eq(a2,b1))
        return true;
        y
    }
}

int main()
{
    fast;
    ll T=1;
//     cin>>T;
    while(T--)
    {
        string a,b;
        cin>>a>>b;
        // sort(all(a));
        // sort(all(b));
        if(is_eq(a,b))
        {
            cout<<"YES"<<endl;
        }
        else 
        {
            cout<<"NO"<<endl;
        }
    }

}