vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B) {
    int n=A.size();
    int m=B.size();
    vector<int> ans;
    for(int i=0,j=0;i<n && j<m ;)
    {
        if(a[i]==b[j])
        {
            ans.push_back(a[i]);
            i++;
            j++;
        }
        else if(a[i]<b[j])
        i++;
        else 
        j++;
    }
    return ans;
}
