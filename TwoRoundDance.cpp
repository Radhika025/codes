#include<iostream>
#include<math.h>
using namespace std;
const int N=21;
long long f[N];
int main()
{
    int n;
    cin>>n;
    f[0]=1;
    for(int i=1; i<=n; i++)
    {
        f[i]=f[i-1]*i;
    }
    long long ans=f[n]/f[n/2]/f[n/2];
    ans=ans*f[(n/2)-1];
    ans=ans*f[(n/2)-1];
    ans=ans/2;
    cout<<ans;
    cout<<endl;
}
