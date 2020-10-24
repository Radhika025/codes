#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    cout<<"Enter the number of windows counted";
    int t, a=0, b=0, c=0, f=0, sum=0; // 15=(total number of windows)(3 + 5 + 7)
    cin>>t;
    for(int x=0; x<(t/3)+1; x++)
    {
        for(int y=0; y<(t/5)+1; y++)
        {
            for(int z=0; z<(t/7)+1; z++)
            {
                sum=(3*x)+(5*y)+(7*z);
                if(sum==t)
                {
                    f=1;
                    a=x;
                    b=y;
                    c=z;
                    break;
                }
            }
            if(f==1)
            break;
        }
        if(f==1)
        break;
    }
    if(f==0)
    cout<<"-1"<<endl;
    else
    cout<<a<<" "<<b<<" "<<c<<endl;
    
}