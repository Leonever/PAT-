#include<iostream>
#include<string.h>
#define maxsize 1001
using namespace std;
int road1[2][999999]={0};
int farther[1001]={0};
int find(int x){
    while(farther[x]!=0)
        x=farther[x];
    return x;
}
void Union(int a,int b){
    int ca=find(a),cb=find(b);
    if(ca!=cb)
        farther[cb]=ca;
}
int main()
{
    int N,M,K;
    cin>>N>>M>>K;
    int r,c;
    for(int i=1;i<=M;i++){
        cin>>r>>c;
        road1[0][i]=r;
        road1[1][i]=c;
    }
    int city;
    for(int i=1;i<=K;i++){
        cin>>city;
        int sum=0;
        memset(farther,0,sizeof(int)*(N+1));
        for(int j=1;j<=M;j++)
            if(road1[0][j]!=city&&road1[1][j]!=city)
                Union(road1[0][j],road1[1][j]);
        for(int p=1;p<=N;p++)
            if(farther[p]==0)
                sum++;
        cout<<sum-2<<endl;
    }
    return 0;
}