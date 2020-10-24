#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
int main()
{
    int t;
    //cout<<"Enter test cases ";
    cin>>t;
    for(int j=0; j<t; j++)
    {
        int n, m=0;
        //cout<<"Enter size ";
        cin>>n;
        vector <int> v;
        for(int i=0; i<n; i++)
        {
            //cout<<"Enter elements ";
            int x;
            cin>>x;
            v.push_back(x);
            m=max(m,x);
        }
        int id=-1;
        for(int i=0; i<n; ++i)
        {
            if(v[i]!=m)
            continue;
            if(i>0 && v[i-1]!=m)
            id=i+1;
            if(i<n-1 && v[i+1]!=m)
            id=i+1;
        }
        cout<<id<<endl;
        
    }
}
