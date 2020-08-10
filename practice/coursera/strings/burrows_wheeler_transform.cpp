#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,s,e) for(ll i=s;i<e;i++)
int main()
{
    string s;
    cin>>s;
    ll n=s.length();
    vector<string>vec;
    rep(i,0,n)
    {
        string tmp="";
        rep(j,0,n)
        {
            tmp+=s[(i+j)%n];
        }
        vec.push_back(tmp);
    }
    sort(vec.begin(),vec.end());
    string ans="";
    rep(i,0,n)
    ans+=vec[i].back();
    cout<<ans<<endl;
}