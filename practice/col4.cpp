#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    if(k>n)
    cout<<"WRONGANSWER"<<endl;
    else
    {
    
        ll arr[26]={0};
        for(ll i=0;i<s.size();i++)
        {
            arr[s[i]-'a']++;
        }
        char minch='a';
        ll min=arr[0];
        for(ll i=0;i<26;i++)
        {
            if(arr[i]<min && arr[i]!=0)
            {
                min=arr[i];
                minch=('a'+i);
            }
        }
        if(min<=k)
        {
            string temp="";
            for(ll i=0;i<n;i++)
            temp+=minch;
            ll cnt=0;
            ll i=0;
            while(cnt!=(k-min))
            {
                if(s[i]!=minch){
                temp[i]=s[i];
                cnt++;}
                i++;
            }
            cout<<temp;
        }
        else 
        {
            ll fnd=0;
            char t;
            for(ll i=0;i<26;i++)
            {
                if(arr[i]==0)
                {
                    t='a'+i;
                    fnd=1;
                    break;
                }
            }
            if(fnd!=1)
            cout<<"WRONGANSWER";
            else
            {
                string temp="";
                for(ll i=0;i<k;i++)
                temp+=minch;
                for(ll i=k;i<n;i++)
                temp+=t;

                cout<<temp;
            }
        }
    }
}