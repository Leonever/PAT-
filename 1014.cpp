#include<iostream>
#include<queue>
#define maxsize 1001
using namespace std;
struct consumer{
    int id;
    int time;
    int servetime;
    int leavetime;
}Con[maxsize];
queue<consumer> Queue[21];
int quest[maxsize]={0};
int main()
{
    int N,M,K,Q;
    cin>>N>>M>>K>>Q;
    for(int i=1;i<=K;i++){
        Con[i].id=i;
        cin>>Con[i].time;
        Con[i].servetime=Con[i].time;
    }
    int No=1,p=1;
    for(int i=1;i<=1080;i++){
        while(p<=M*N&&No<=K){
            for(int j=1;j<=N;j++)
                if(Queue[j].size()<M){
                    Queue[j].push(Con[No++]);
                    p++;
                }
        }
        for(int u=1;u<=N;u++){
            int x=Queue[u].front().id;
            Con[x].time--;
            if(Con[x].time==0){
                Con[x].leavetime=i;
                Queue[u].pop();
                p--;
            }
        }
    }
    for(int i=0;i<Q;i++){
        cin>>quest[i];
        if(Con[quest[i]].leavetime-Con[quest[i]].servetime<540)
            printf("%02d:%02d\n",(Con[quest[i]].leavetime+480)/60,(Con[quest[i]].leavetime+480)%60);
        else
            printf("Sorry\n");
    }
    return 0;
}