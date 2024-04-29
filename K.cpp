#include <bits/stdc++.h>
using namespace std;
vector<int> out;
bool check(vector<int>&arr,vector<int>&temp)
{
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]!=temp[i]) 
        return arr[i]>temp[i];
    }
    return true;
}
int main()
{
    int t=0;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        vector<int> arr;
        int i;
        for(i=0;i<s.size();i++)
        {
            arr.push_back(s[i]-'0');
        }
        vector<int> temp(arr.size(),arr[0]);
        int sum=0;//求和
        sum=(arr.size()-1)*9;
        if(check(arr,temp))
        sum+=arr[0];
        else
        sum+=arr[0]-1;
        out.push_back(sum);  
    }
    for(int i=0;i<out.size();i++)
    {
        cout<<out[i]<<endl;
    }
    return 0;
}