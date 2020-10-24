#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int t;
    cout<<"Enter test cases ";
    cin>>t;
    for(int j=0; j<t; j++)
    {
        int n, p, q, c=0;
        cout<<"Enter size ";
        cin>>n;
        vector <int> v;
        for(int i=0; i<n; i++)
        {
            cout<<"Enter element ";
            int x;
            cin>>x;
            v.push_back(x);
        }
        for(int i=0; i<n; i++)
        {
            if(v[i]==1)
            {
                p=i;
                break;
            }
        }
        for(int i=n-1; i>=0; i--)
        {
            if(v[i]==1)
            {
                q=i;
                break;
            }
        }
        for(int i=p; i<=q; i++)
        {
            if(v[i]==0)
            {
                c=c+1;
            }
        }
        cout<<c;
        cout<<endl;
    }
}
