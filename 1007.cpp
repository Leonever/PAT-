#include<iostream>
#define maxsize 10001
using namespace std;
int queue[maxsize]={0};
int array[maxsize]={0};
int main()
{
    int n,first=0,last=0,sum,b=0,summ=0;
    int temp=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>queue[i];
    }
        sum=queue[0];
        array[0]=queue[0];
        for(int i=0;i<n;i++){
            array[i]=max(array[i-1]+queue[i],queue[i]);
            if(array[i]<0){
                temp=i+1;
            }
            else if(array[i]>sum){
                sum=array[i];
                first=temp;
                last=i;
            }
        }   
    if(sum<0){
        first=0;
        last=n-1;
        sum=0;
    }
    cout<<sum<<" "<<queue[first]<<" "<<queue[last];
    return 0;
}