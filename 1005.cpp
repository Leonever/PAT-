#include<iostream>
#include<string>
#define maxsize 10000
using namespace std;
int num[maxsize]={0};
void exchange(int n){
    switch (n)
    {
    case 0:
        cout<<"zero";
        break;
    case 1:
        cout<<"one";
        break;
    case 2:
        cout<<"two";
        break;
    case 3:
        cout<<"three";
        break;
    case 4:
        cout<<"four";
        break;
    case 5:
        cout<<"five";
        break;
    case 6:
        cout<<"six";
        break;
    case 7:
        cout<<"seven";
        break;
    case 8:
        cout<<"eight";
        break;
    case 9:
        cout<<"nine";
        break;
    default:
        break;
    }
}
int main()
{
    string n;
    cin>>n;
    int i=0,sum=0;
    int len=n.size();
    for(int p=0;p<len;p++){
        sum+=int(n[p]-'0');
    }
    if(sum==0)
        cout<<"zero";
    else{
        while(sum){
        num[i++]=sum%10;
        sum=sum/10;
        }
        for(int k=i-1;k>=0;k--){
            if(k==i-1)
                exchange(num[k]);
            else{
                cout<<" ";
                exchange(num[k]);
            }
        }
    }
    return 0;
}