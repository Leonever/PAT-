#include<iostream>
#include<cmath>
using namespace std;
int num[100]={0};
bool judge(int M){
    if(M<2)
        return false;
    for(int i=2;i*i<=M;i++)
        if(M%i==0)
            return false;
    return true;
}
int exchange(int M,int N){
    int i=0;
    while(M){
        num[i++]=M%N;
        M=M/N;
    }
    M=num[i-1];
    int mul=N;
    for(int j=i-2;j>=0;j--){
        M+=num[j]*mul;
        mul=mul*N;
    }
    return M;
}
int main()
{
    int M,N;
    while(cin>>M){
        if(M<0)
            break;
        cin>>N;
    if(!judge(M)){
        cout<<"No\n";
    }
    else{
        M=exchange(M,N);
        if(!judge(M)){
            cout<<"No\n";
        }
        else
            cout<<"Yes\n";
    }
    }
    return 0;
}