#include<iostream>
using namespace std;
#define maxsize 10
int main()
{
    int n1,n2;
    float data1[maxsize];
    float data2[maxsize];
    float data3[maxsize];
    int k1[maxsize];
    int k2[maxsize];
    int k3[maxsize];
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
    int i=0,j=0,p=0;
    while(i<n1&&j<n2){
        if(k1[i]==k2[j]){
            k3[p]=k1[i];
            data3[p]=data1[i]+data2[j];
            p++;
            i++;
            j++;
        }
        else if(k1[i]>k2[j]){
            k3[p]=k1[i];
            data3[p]=data1[i];
            p++;
            i++;
        }
        else if(k1[i]<k2[j]){
            k3[p]=k2[j];
            data3[p]=data2[j];
            p++;
            j++;
        }
    }
    while(i<n1){
        k3[p]=k1[i];
        data3[p]=data1[i];
        p++;
        i++;
    }
    while(j<n2){
        k3[p]=k2[j];
        data3[p]=data1[j];
        p++;
        j++;
    }
    int sum=p;
    for(int q=0;q<p;q++)
        if(data3[q]==0)
            sum--;
    cout<<sum;
    for(int q=0;q<p;q++){
        if(data3[q]!=0){
            printf(" %d %.1f",k3[q],data3[q]);
        }
    }
    return 0;
}
