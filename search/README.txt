#搜索，有目的枚举
发现解空间某子集不存在解时便放弃对该子集的搜索
它的思想还是遍历枚举，不过分成子解空间、情况不对时可以放弃对某子解空间的搜索。
用队列FIFO实现宽度优先搜索
总结
1. 确定状态 ##重点
2. 确定状态扩展方式  ##重点
3. 确定有效状态
4. 队列进行宽度优先
5. 标记有效还是无效状态
6. 宽度优先搜索中，有效状态数往往和时间复杂度同级
7. 最优
8. 剪枝：丢弃某些状态空间

用栈FILO实现深度优先搜索，或者递归也能实现深度优先搜索

##宽度优先搜索
首先访问起点，依次访问尚未访问的邻居节点。
在邻居节点也进行类似操作。  

##深度优先搜索
从一个状态走到底。使用深度优先搜索常常是想知道有解没有。
不具有最优的特性。
深度优先要求从小到大输出时几乎不用排序，遍历的顺序已经排好了序；
警惕出现时间复杂度过高
9-2使用深度优先算法时间复杂度(n!)太大。一定不能有阶乘的复杂度
使用递归时可以cnt计数看看是否复杂度过大。






## c++ C++ 中 map 提供的是一种键值对容器，里面的数据都是成对出现的
初始化
#include <map> 
std::map<int , std::string> person;
插入
mapPerson.insert(pair < int,string > (1,"Jim"));
迭代器
it = mapPerson.begin();
itEnd = mapPerson.end();
元素查找
find() 函数返回一个迭代器指向键值为 key 的元素，如果没找到就返回指向 map 尾部的迭代器。  
删除
iterator erase（iterator it)	;//通过一个条目对象删除
iterator erase（iterator first，iterator last）；	//删除一个范围
size_type erase(const Key&key);	//通过关键字删除
clear()；//就相当于enumMap.erase(enumMap.begin(),enumMap.end());
排序
Map 中的元素是自动按 key 升序排序,所以不能对 map 用 sort 函数：

##sort 报错
sort((int**)ways, (int**)ways+N, compare);
分析：compare是比较的迭代器指向的元素即*iterator（此处就为每行的头指针）, 
交换的是连续迭代器里储存的内容，但int a[][]每行的头指针(迭代器里的内容)都是写死的因此不能交换。
用动态数组即可解决该问题。