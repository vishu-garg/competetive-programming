#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,p,k;
        cin>>n>>p>>k;
        ll a[n];
        for(ll i=0;i<n;i++)
        cin>>a[i];
        sort(a,a+n);
        ll sumodd=0,sumeven=0,cnt=0,num,pnt=-1;
        for(ll i=0;i<n;i+=k)
        {
            cnt++;
            sumodd+=a[i];
            if(sumodd>p)
            {
                pnt=i;
                break;
            }
        }
        ll ans;
        if(pnt!=-1)
        {
            ans=k*(cnt-1)-1;
            ll rem=p-sumodd+a[pnt];
            ll k1=0;
            while(a[pnt-1+k1]<=rem)
            {rem=rem-a[pnt-1+k1];
            k1++;
            ans=ans+1;}
        }
        else
        {
            if(n%k==1)
            {
                ans=k*cnt-1;
                ll rem=p-sumodd;
                ll k1=0;
                ll pnt=((n)/k)*k;
                pnt+=k-1;
                while(a[pnt+k1+1]<p)
                {
                    rem=rem-a[pnt+k1+1];
                    k1++;
                    ans=ans+1;
                }
            }
            else
            {
                ans=k*cnt-1;
            }
        }
        
        cnt=0,pnt=-1;
        for(ll i=k-1;i<n;i+=k)
        {
            cnt++;
            sumeven+=a[i];
            if(sumeven>p)
            {
                pnt=i;
                break;
            }
        }
        ll ans2=0;
        if(pnt!=-1)
        {
            ans2=k*(cnt-1);
            ll rem=p-sumeven+a[pnt];
            ll k1=0;
            while(a[pnt-1+k1]<=rem)
            {
                rem=rem-a[pnt+k1-1];
                k1++;
                ans2=ans2+1;
            }
        }
        else
        {
            if (n%k!=0)
            {
                ans2=(k*cnt);
                ll rem=p-sumeven;
                pnt=(n/k)*k;
                ll k1=0;
                while(a[pnt+1+k1]<=rem)
                {ans2=ans2+1;
                rem=rem-a[pnt+1+k1];
                k1++;}
            }
            else
            {
                ans2=k*cnt;
            }
        }
        cout<<ans<<"<--";
        cout<<endl<<ans2<<"<---"<<endl;
        cout<<max(ans,ans2)<<endl;
    }
}