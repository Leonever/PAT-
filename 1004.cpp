#include<iostream>
#define maxsize 101
using namespace std;
int node[maxsize][maxsize]={0};   //节点数组
int queue[maxsize];               //队列数组
int main()
{
    int N,M,ID,K;
    cin>>N>>M;
    for(int i=0;i<M;i++){
        cin>>ID>>K;
        for(int j=0;j<K;j++){
            cin>>node[ID][j];
        }
    }
    queue[0]=1;                     //树中根节点编号为0根节点第一个孩子编号为1
    int front=0,rear=1;             //最开始队列中只有一个根节点
    bool flag=true;
    while(front<rear){
        int tag=rear;               //该层最后一节点所在下标
        int count =0;
        for(;front<tag;front++){
            int i=0;
            if(node[queue[front]][0]==0)
                count++;            //找到叶节点
            else{
                while(node[queue[front]][i]){
                    queue[rear++]=node[queue[front]][i++]; //加入队列
                }
            }
        }
        if(flag){
            flag=false;
            printf("%d",count);
        }  
        else
            printf(" %d",count);
    }
    return 0;
}