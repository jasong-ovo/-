#dataStructure
## 向量
动态数组
1.#include<vector>
vector<typename> name
2.empty(), size()
3.尾部元素 push_back() pop_back()
4.元素访问迭代器或下标
5.insert，erase，clear
6.迭代器操作：返回第一个和最后一个元素的迭代器begin(), end()
定义迭代器：vector<int>::iterator it
## 队列
FIFO,一端入队一端出队
1.#include <queue>
queue<typename> name
2.empty(), size()
3.push()队尾入队，pop()队首出队
4.front(), back()获得首尾的元素
## 栈
只限于操作逻辑上的一端，LIFO
1.#include <stack>
stack<typename> name
2.empty(), size()
3.push, pop
4.用top()访问栈顶元素



在scanf中直接使用正则表达式
[]内是匹配的字符,^表示求反集，当遇到非集合内的字符时立即终止输入
scanf("%[a-z0-9]", str1);
scanf("%[^a-z]", str1);
%表示选择，%后面的是条件，比如"%s"，s是一个条件，表示任意字符，"%s"的意思是：只要输入的东西是一个字符，就把它拷贝给str。"%3s"又多了一个条件：只拷贝3
%* 与%刚好相反，表示过滤满足条件的字符，也就是跳过满足条件的字符，其后一定要有新的%语句，否则无法读入
scanf("%*[a-z0-9]%[^\n]",str1);

操作POP时要检查是否是empty
&&只要有一个条件不一样就是不满足，如果第一个条件就是不满足就不判断后面的条件。