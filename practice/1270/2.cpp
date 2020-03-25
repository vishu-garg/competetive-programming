#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll min=0,max=0,a[n];
        for(ll i=0;i<n;i++)
        {
            cin>>a[i];
        }
        ll temp;
        temp=a[0];
        min=temp;
        max=min;
        ll minp=1,maxp=1;
        ll ans=0;
        for(ll i=1;i<n && ans!=1;i++)
        {
            temp=a[i];
            if(temp<min){
            minp=i+1;
            min=temp;}
            else if(temp>max){
            maxp=i+1;
            max=temp;}
            ll k=0;
            if(minp>maxp){
            k=minp-maxp+1;}
            else {
            k=maxp-minp+1;}
            if(max-min>=k)
            {
                ans=1;
                cout<<"YES"<<endl;
                if(minp<maxp)
                cout<<minp<<" "<<maxp<<endl;
                else 
                cout<<maxp<<" "<<minp<<endl;
            }

        }
        if(ans!=1)
        cout<<"NO"<<endl;
    }
}