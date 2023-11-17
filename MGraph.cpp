#include <iostream>

using namespace std;
int const Maxsize = 100;
typedef struct
{
    int no;    // # 顶点编号
    char info; // # 顶点其他信息，不做特殊要求可不写
} VertexType;  // # 顶点类型
typedef struct
{
    int edge[Maxsize][Maxsize]; // # 邻接矩阵定义
    int n, e;                   // # 顶点数和边数
    VertexType vex[Maxsize];    // # 存放顶点信息
} MGraph;                       // # 图的邻接矩阵类型
// # 普利姆算法（求最小生成树）
/*
    两个步骤：
    （1）以v0为开始结点将v0到其它所有边当作侯选边（即为初始化lowcost[]数组）
    （2）重复执行以下步骤n-1次，使剩下的n-1个顶点存入生成树中
        1.从侯选边中选出权值最小的边，将该边上另一端的顶点v放入生成树中
        2.考察剩余的所有结点，依据新的生成树更新侯选边
*/
void Prim(MGraph &G, int v0, int &sum) // # v0是开始结点，sum存放最短权值
{
    // # vset[i]==1表示顶点i已经被加入到生成树中,lowcost[]数组用于存放当前生成树到剩余各顶点最短边的权值
    int lowcost[Maxsize], vset[Maxsize], v;
    int i, j, k, min;
    v = v0;
    // # 初始化lowcost[]
    for (i = 0; i < G.n; i++)
    {
        lowcost[i] = G.edge[v0][i]; 
        vset[i] = 0;
    }
    vset[v0] = 1; // # 将开始结点放入生成树中
    sum = 0;      // # 初始时权值为0
    for (i = 0; i < G.n - 1; i++)
    {
        min = INT_MAX; // # INT_MAX是一个比图中所有边的权值都大的常量
        // # 下面的循环用于选出侯选边的最小权值者
        for (j = 0; j < G.n; j++)
        // # 选出当前生成树到其余顶点最短边中的最短的一条
            if (vset[j] == 0 && lowcost[j] < min)
            {
                min = lowcost[j];
                k = j;
            }
        vset[k] = 1;
        v = k;
        sum += min;
        // # 下面这个循环以刚进入的顶点v为媒介更新侯选边（权值最短的边）
        for (i = 0; i < G.n; i++)
            if (vset[j] == 0 && G.edge[v][j] < lowcost[j])
                lowcost[j] = G.edge[i][j];
    }
}

// # 迪杰特斯拉算法（求图中某一顶点到其余各顶点距离）
void Dijkstra(MGraph &G,int v,int dist[],int path[])
{
    int set[Maxsize];
    int min,i,j,u;
    // # 下面开始初始化
    for(i=0;i<G.n;i++)
    {
        dist[i]=G.edge[v][i];
        set[i]=0;
        if(G.edge[v][i]<INT_MAX)
            path[i]=v;
        else
            path[i]=-1;
    }
    set[v]=1;
    path[v]=-1;
    // # 初始化结束，关键工作开始
    for(i=0;i<G.n;i++)
    {
        min=INT_MAX;
        // # 下面的循环每次从剩余顶点中选出一个顶点，通往这个顶点的路径在通往所有剩余顶点的路径中是最短的
        for(j-0;j<G.n;j++)
        {
            if(set[j]==0&&dist[j]<min)
            {
                u=j;
                min=dist[j];
            }
            set[u]=1; // # 将选出的顶点并入最短路径中
            // # 下面的循环以刚并入的顶点作为中间点，对所有通往剩余顶点的路径进行检测
            for(j=0;j<G.n;j++)
            {
                // # 这个if语句判断顶点u的加入是否会出现通往顶点j的更短的路径，如果出现则该边原来路径及长度，否则什么也不做
                if(set[j]==0&&dist[u]+G.edge[u][j]<dist[j])
                {
                    dist[j]=dist[u]+G.edge[u][j];
                    path[j]=u;
                }
            }
        }
    }
    // # 关键操作结束，dist[]数组存放了v点到其余各顶点的最短路径长度，path[]中存放了v点到其余各顶点的最短路径
}
int main()
{
    return 0;
}