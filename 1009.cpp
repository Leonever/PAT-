#include<iostream>
using namespace std;
#define minsize 10
#define maxsize 2001
float data1[minsize]={0};
float data2[minsize]={0};
float data3[maxsize]={0};
int k1[minsize]={0};
int k2[minsize]={0};
int main()
{
    int n1,n2;
    int k;
    float d;
    cin>>n1;
    for(int i=0;i<n1;i++){
        cin>>k>>d;
        k1[i]=k;
        data1[i]=d;
    }
    cin>>n2;
    for(int i=0;i<n2;i++){
        cin>>k>>d;
        k2[i]=k;
        data2[i]=d;
    }
    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++){
            data3[k1[i]+k2[j]]+=data1[i]*data2[j];
        }
    }
    int sum=0;
    for(int i=0;i<maxsize;i++)
        if(data3[i]!=0)
            sum++;
    printf("%d",sum);
    for(int i=maxsize;i>=0;i--)
        if(data3[i]!=0){
            printf(" %d %.1lf",i,data3[i]);
        }
    return 0;
}
