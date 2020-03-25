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
    ll n,m;
    cin>>n>>m;
    vector<string> s(n);
    rep(i,0,n){
    cin>>s[i];}
//    rep(i,0,n)
//    sort(s[i].begin(),s[i].end());
//    sort(s,s+n);
//    map<string,ll>mp;
//    rep(i,0,n)
//    {
//        mp[s[i]]++;
//    }
		string sw="",se="",sc="";
        ll k=0;
		rep(i,0,n)
		{
			string s3=s[i];
			reverse(s3.begin(),s3.end());
			if(s3!=s[i]){
			if(find(s.begin(),s.end(),s3)!=s.end())
            {sw+=s[i];se+=s[i];
//            cout<<s[i]<<"<<<"<<endl;
            s[i]="0";}}
            else 
            {
                ll f=0;
                rep(j,0,m)
                {
                    if(s[i][j]!=s[i][m-1-j])
                    {
                        f=1;break;
                    }
                }
                if(f==0 && k==0){
                sc+=s[i];k=1;}
            }
		}
        reverse(se.begin(),se.end());
//        cout<<sw<<" "<<sc<<" "<<se<<endl;
        string ans=sw;
        ans+=sc;
        ans+=se;
        if(ans.size()==0)
        {
            cout<<"0"<<endl;
            return 0;
        }
        cout<<ans.size()<<endl;
        cout<<ans;
}
    