#数据结构2(非线性)
## 二叉树
###二叉树递归定义
struct treeNode {
    ElementType data; //数据
    treeNode *leftChild;
    treeNode *rightChild;
}
###二叉树遍历
序指的是根节点访问的顺序
前序(PreOrder) 1.节点空，返回 2.访问根节点 3.前序遍历左子树 4.前序遍历右子树
中序(InOrder)  1.节点空，返回 2.前序遍历左子树  3.访问根节点 4.前序遍历右子树
后序(PostOrder) 1.节点空，返回 2.前序遍历左子树 3.前序遍历右子树  4.访问根节点
先序和中序遍历可以唯一确定一棵树，后序和中序也行，但先序和后序不行(但满二叉的情况可以)。
以中序为例
void inOrder(treeNode * node) {
    if (!node == NULL) return;
    inOrder(node->leftChild);
    visit(node->data);
    inOrder(node->rightOrder);
    return;
}
可以看出以上是深度优先遍历。（或者它使用了递归）

层次遍历(levelOrder)，一种广度优先遍历。(使用队列)
每一层的值遍历完再遍历下一层。
queue<treeNode *> waitingList 
void levelOrder(treeNode *root){
    if (root == NULL) return;
    waitingList.push(root);
    while (!waitingList.empty()){
        visit(waitiongList.front());
        if (front()->left != NULL)
        push(front()->left);
        if (front()->right != NULL)
        push(front()->right);
        pop;
    }
}

## 二叉排序树
又称二叉搜索树。
1. 若左子树非空，则左子树上所有关键节点的值均小于根节点的值。
2. 右子树同理， 关键节点的值均大于根节点。
3. 左右子树本身也是一颗二叉排序树。
它的中序遍历必然是升序。
对二叉排序树，不同二叉排序树的前序遍历不同。输入元素相同则中序一定相同，即中序不用比较。

## 优先队列
FIGO(First-In Greatest-Out)
每次访问只能访问当前队列中优先级最高的元素。

STL-priority-queue
优先队列底层是用二叉堆实现的。

使用
#include <queue>
定义
priority_queue<typename> name
状态
.size(), .empty()
出入队
.push(), .pop()
访问
.top() 访问当前队列中优先级最高的元素
确定优先级，重写仿函数或重载<
//方法1
struct tmp1 //运算符重载<
{
    int x;
    tmp1(int a) {x = a;}
    bool operator<(const tmp1& a) const //一定要加const,这个const是修饰this指针的
    {
        return x < a.x; //大顶堆
    }
};
// 升序队列，小顶堆
priority_queue <int,vector<int>,greater<int> > q;
// 降序队列，大顶堆
priority_queue <int,vector<int>,less<int> >q;
// greater和less是std实现的两个仿函数（就是使一个类的使用看上去像一个函数，其实就是在类中实现一个operator()方法，这个类就有了类似函数的行为，就是一个仿函数类了）

应用
1. 顺序问题
2. 哈夫曼树
哈夫曼树：带权路径长度 和 最小的二叉树。带权路径：节点权值*路径长度（根节点到该节点的边数）
构造方法：{节点集}， 最小的两个节点构造树，树的根节点为两个节点之和。再将根节点加入节点集。(需要优先值最小的元素)

## 散列表
不论是线性结构还是树形结构查找时都需要关键字比较。
最小能做到O(log(N))
散列表根据关键字(key)直接进行访问，通过建立关键字和位置的直接映射。时间复杂度O(1)

使用
#include <map>
map<typename1 T1, typename2 T2> name
T1是关键字类型，T2是值类型

map的状态
.empty(), .size()

添加或删除元素
.insert(), .erase()

元素访问
1. map[key]
2. .at()
3. 通过迭代器访问

元素操作
.find() 查找特定元素
.clear() 清空映射

迭代器操作
.begin(), .end()

声明迭代器
map<string, int>::iterator it;
迭代器迁移， it++;
map会自动升序排列
####
substr(i, j) 从i开始提取j个字符
strcmp() 在string.h中
treeNode * root 时 root值不是NULL要手动置NULL
使用数据区时一定要memset不然会由于以前未清空产生许多bug。#######