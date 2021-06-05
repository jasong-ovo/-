# 图论
讨论并查集， 最小生成树， 最短路径， 拓扑排序等问题

## 概述
图定义： G=(V, E) (Vertex: 顶点， Edge：边) 由顶点集合和边集合构成图。
记v=|V|, e=|E|
边集中的(u,v)元素是否有次序来判断是有向图还是无向图。
e=(u, v), 则u,v邻接， 顶点u和顶点v与边e关联。与顶点关联的边数称为顶点的度。有向图中又分出度和入度。

## 表示方法
### 邻接矩阵
二维矩阵。matrix[u][v]的值代表u和v之间的权值。
缺点，遍历一个顶点的邻接边时，需要遍历该行，时间复杂度较高。

### 邻接表
动态分配的链表，为每个顶点建立一个单链表。
缺点，判断u,v有无关系时效率较低。（实际编码中采用向量的形式实现）

## 并查集(Union Find)（处理集合的交并查询问题）
用于处理一些不交集的合并和查询问题。判断任意两个元素是否属于同一个集合，按照要求合并不同的集合。
首先，将集合在逻辑上表示为树的结构，每个节点指向其父节点。只要在同一棵树上就在同一集合内。
查找：不断向上找到根节点，根据根节点判断是否在同一集合。
合并：使两个子集合并成同一集合，即一棵树作为另一颗树的子树。(其中可能退化成单链表，树的不同形态对查找效率影响巨大)

### 利用并查集判断连通图或求图的连通分量
find(x), union(x,y)

### 利用并查集 实现最小生成树
kruskal算法
1. 初始时所有节点属于孤立集合
2. 按边权递增遍历边集，如果两节点不属于同一集合则合并集合
3. 遍历完成后判断原图是否连通确定最小生成树的存在性

### 实现最短路径求解
dijkstra算法， 图不能是负权图，负权图使用Bellman--Ford算法
求解源点到终点的终点路径
我的理解：
1. S集：已找到最短路径的点的集合(且一直保持T集中的点的最短路径大于S集合中的最大值)
2. T集：T = V - S
3. 把T集中最小最短路径的点从T中放入S中(遍历S中的点，求最小最短路径)
实操：(一直遍历直到不能产生更小的情况)
void dijkstra(int s) {
    //init
    priority_queue<Point> myPriorityQueue;
    dis[s] = 0;
    myPriorityQueue.push(Point(s, dis[s]));

    //update
    while (!myPriorityQueue.empty()) {
        int u = myPriorityQueue.top().number;
        myPriorityQueue.pop();
        for (int i=0; i<graph[u].size(); i++) {

            //relaxation
            int v = graph[u].to;
            int d = graph[u].lenth;
            if (dis[v] > dis[u] + d) {
                dis[v] = dis[u] + d;
                myPriorityQueue.push(Point(v, dis[v]));
            }
        }
    }
}


### 拓扑排序DAG(Directed Acyclic Graph)
有向无环图排序，图中有多条有向边(U, V)。图中所有顶点排成一个线性序列,使得所有U排在V前面。
1. 从DAG中选择入度为0的顶点，并输出
2. 从图中删除入度为0的顶点，并消除它带来的入度
3. 重复1，2直到没有入度为0的顶点或图为空

### 关键路径(Critical Path)
AOE(Activity on edge),用边表示事件。DAG表示完成事件的前置事件关系图。
最早开始时间：保证末事件完成时间不变的，开始某事件的最早时间
最晚开始时间：保证末事件完成时间不变的，开始某事件的最晚时间
关键事件：该事件的完成时间的任何变动会影响末事件的完成时间，即没有时间裕度<==>latest 等于 earliest
1. 计算所有节点的最早开始时间(取最大的)(从而得到末节点的时间)
> 遍历当前度为0的节点u为它们的后继节点v进行inrelaxation(
    indegree[v] --;
    if (earliest[v] < earliest[u] + lenthu_v) earliest[v] = earliest[u] + lenthu_v;
    if (indegree[v] == 0) 入队(入度为0的节点队列) 
)
2. 反向计算所有节点的最晚开始时间
> 从末节点开始，末节点的最晚开始时间等于最早开始时间。其他节点的最晚开始时间设为INF
  依据后续节点的最晚开始时间更新自己的最晚开始时间，进行relaxation操作
  v遍历后继节点u：取最小的
  latest[v] = min (latest[v], latest[u] - lenth )






## 问题
getline()不吸收\n，要用getchar单独吸收
scanf %c会读取回车
scanf %c一定要小心！！！！！尽量避免】
涉及scanf %c会出现回车相关的问题。用cin读是最优的。

优先级队列重载小于
在sort,map,set中，重载小于 使其从小到大排序  (set 默认是小顶堆)
    struct Node {  
        int d, e;  
        bool operator < (const Node x) const {  
            return d < x.d;      //从小到大排序
        }   
        Node(int d, int e):d(d), e(e){}  
    }; 
 
在priority_queue中，优先队列默认是大顶堆. 所以 d<x.d 为真时 是从大到小排序的

    struct Node {  
        int d, e;  
        bool operator < (const Node x) const {  
            return d < x.d;         //从大到小排序
        }  
        Node(int d, int e):d(d), e(e){}  
    };

