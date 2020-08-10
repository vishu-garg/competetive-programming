#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.length();
        map<char,int> arr[n];
        map<char,int> mp1,mp2;
        for(auto it:t)mp2[it]++;
        for(int i=0;i<n;i++)
        {
            mp1[s[i]]++;
            for(auto it:mp1)
            {
                arr[i][it.first]++;
            }
        }

        for(auto it:mp2)
        {
            if(arr[n-1][it.first]<it.second)
            {
                return("");
            }
        }

        int l=0,r=0;
        int l1,r1,ans=INT_MAX;
        while(l<n && r<n)
        {
            if(mp2[s[l]]==0)
            {
                l++;
                if(r<l)
                {
                    r=l;
                }
                continue;
            }
            bool ok=true;
            map<char,int>mp3;
            for(auto it:arr[r])
            {
                mp3[it.first]=it.second;
            }
            if(l>0)
            {
                for(auto it:arr[l-1])
                {
                    mp3[it.first]-=it.second;
                }
            }

            for(auto it:mp2)
            {
                if(mp3[it.first]<it.second)
                {
                    ok=false;
                }
            }

            if(!ok)
            {
                r++;
            }

            else 
            {
                
                if(r-l+1<ans)
                {
                    l1=l;
                    r1=r;
                }
                l++;
                if(r<l)
                r=l;
            }
        }

        string s1="";
        for(int i=l1;i<=r1;i++)
        s1+=s[i];

        return s1;

    }
};