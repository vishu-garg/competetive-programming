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
//     cin>>T;
    while(T--)
    {
        ll n;
        cin>>n;
        string s;
        cin>>s;
        ll cnt1=0,cnt2=0,sum=0;
        rep(i,0,n/2)
        if(s[i]=='?')cnt1++;
        
        rep(i,n/2,n)
        if(s[i]=='?')cnt2++;

        if(cnt1>cnt2)
        {
            swap(cnt2,cnt1);
            string s2="";
            rep(i,n/2,n)s2+=s[i];
            rep(i,0,n/2)s2+=s[i];
            s=s2;
        }
            rep(i,0,n/2)
            {
                if(s[i]!='?')
                sum+=(s[i]-'0');
            }
            ll rem=cnt2-cnt1;
            ll sum2=0;
            rep(i,n/2,n)
            {
                if(s[i]!='?')
                sum2+=(s[i]-'0');
            }
            ll bi=((rem)/2);
            ll mono=((rem)-bi);
            if(sum<=sum2)
            {
                sum2+=(9*mono);
            }
            else 
            {
                if(sum2+(9*mono)>sum)
                sum2+=(9*mono);
            }
            ll mn=sum-sum2;
            ll mx=9*bi;
            if(mn>=0 && mn<=mx)
            {
                cout<<"Bicarp"<<endl;
            }
            else 
            {
                cout<<"Monocarp"<<endl;
            }


    }

}