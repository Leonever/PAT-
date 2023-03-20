#include<iostream>
#include<algorithm>
using namespace std;
#define maxsize 500
#define longest 99999
int rescue[maxsize];
int road[maxsize][maxsize];
int dis[maxsize];
int weight[maxsize];
int num[maxsize];
bool visit[maxsize];
int main()
{
    int N,M,c1,c2;
    scanf("%d%d%d%d",&N,&M,&c1,&c2);
    for(int i=0;i<N;i++)
        scanf("%d",&rescue[i]);
    //fill(road[0],road[0]+maxsize*maxsize,longest);
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            road[i][j]=longest;
    //fill(dis[0],dis[0]+maxsize,longest);
    for(int i=0;i<N;i++)
        dis[i]=longest;
    int a,b,c;
    for(int i=0;i<M;i++){
        scanf("%d%d%d",&a,&b,&c);
        road[a][b]=road[b][a]=c;
    }
    weight[c1]=rescue[c1];//
    dis[c1]=0;//
    num[c1]=1;//
    for(int i=0;i<N;i++){
        int loc=-1,minlen=longest;
        for(int k=0;k<N;k++){
            if(!visit[k]&&dis[k]<minlen){
                loc=k;
                minlen=dis[k];
            }
        }
        if(loc==-1)
            break;
        visit[loc]=true;
        for(int p=0;p<N;p++){
            if(!visit[p]&&road[loc][p]!=longest){
                if(dis[loc]+road[loc][p]<dis[p]){
                    dis[p]=dis[loc]+road[loc][p];
                    num[p]=num[loc];
                    weight[p]=weight[loc]+rescue[p];
                }
                else if(dis[loc]+road[loc][p]==dis[p]){
                    num[p]=num[p]+num[loc];
                    if(weight[loc]+rescue[p]>weight[p])
                        weight[p]=weight[loc]+rescue[p];
                }                
            }
        }
    }
    printf("%d %d",num[c2],weight[c2]);
    return 0;
}