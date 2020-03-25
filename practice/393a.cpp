#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    string s;
    cin>>s;
    ll n=count(s.begin(),s.end(),'n');
    ll i=count(s.begin(),s.end(),'i');
    ll e=count(s.begin(),s.end(),'e');
    ll t=count(s.begin(),s.end(),'t');

    ll ans=0;
    while(n>=2 && t>=1 && i>=1 && e>=3){
        if(ans==0)
        n-=3;
        else 
        n=n-2;

        if(n<0){
        cout<<"0";
        return 0;}

        e-=3;
        i-=1;
        t-=1;
        ans++;
    }
    cout<<ans;
}