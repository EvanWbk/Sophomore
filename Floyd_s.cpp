#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

#define MAX 10
#define NOT_CONNECTED -1

int distance[MAX][MAX];

//number of nodes
int nodesCount;

//initialize all distances to
void Initialize(){
    memset(distance, NOT_CONNECTED , sizeof(distance));
    
    for (int i=0;i<MAX;++i)
        distance[i][i]=0;
}

int main(){
    
    Initialize();
    
    //get the nodes count
    printf("节点数:");
    scanf("%d", &nodesCount);
    
    //edges count
    int m;
    printf("边数:");
    scanf("%d", &m);
    
    while(m--){
        //nodes - let the indexation begin from 1
        int a, b;
        
        //edge weight
        int c;
        
        printf("节点-权值-节点:");
        scanf("%d-%d-%d", &a, &c, &b);
        distance[a][b]=c;
    }
    
    //Floyd-Warshall
    for (int k=1;k<=nodesCount;++k){
        for (int i=1;i<=nodesCount;++i){
            if (distance[i][k]!=NOT_CONNECTED){
                for (int j=1;j<=nodesCount;++j){
                    if (distance[k][j]!=NOT_CONNECTED && (distance[i][j]==NOT_CONNECTED || distance[i][k]+distance[k][j]<distance[i][j])){
                        distance[i][j]=distance[i][k]+distance[k][j];
                    }
                }
            }
        }
    }
    
    for (int i = 1; i <= nodesCount; ++i)
    {
        for (int j = 1; j <= nodesCount; ++j)
        {
            printf("%d ", distance[i][j]);
        }
        printf("\n");
    }
    return 0;
}