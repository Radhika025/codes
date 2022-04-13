#include<iostream>
using namespace std;

int permutation(int n, int k){
    int fact[n+1];
    fact[0] = 1;
    for(int i=1; i<=n; i++)
        fact[i] = i * fact[i-1];
    return fact[n] / fact[n-k];
}

int main(){
    int n = 10, k = 3;
    cout<<"Value of permutation is "<<permutation(n, k);
    return 0;
}