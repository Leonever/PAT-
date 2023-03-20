#include<iostream>
#define maxsize 100
using namespace std;
int sum[maxsize]={0};
int main()
{
    int n,elevator=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>sum[i];
        if(i==0)
            elevator+=5+sum[i]*6;
        else{
            if(sum[i]>sum[i-1])
                elevator+=5+6*(sum[i]-sum[i-1]);
            else
                elevator+=5+4*(sum[i-1]-sum[i]);
        }
    }
    cout<<elevator;
    return 0;
}