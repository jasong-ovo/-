c++: str
#include <string.h>
初始化
string str = "hello world";
str.size()
元素访问1.通过下标 str[i]
       2, 用迭代器，类似指针
       for (string:iterator it = str.begin(); it != str.end(); ++it)

str中的元素操作
insert, erase, clear
运算符 +, =, < , <= ,>, >=

常用函数
str.find("world") //找不到返回string:npos
str.substr(3,5)
size_t copy (char* s, size_t len, size_t pos = 0) const;//string.copy

用>>输入输入输出，因为string是c++新增的。
>> 遇到空格，回车，TAB会停止
getline(cin, str) //接收一个字符串，可以接收空格并输出

^是异或不是指数，求幂用Pow
&&不分先后，因此不能 a=3 && a==3来判断

string作为函数参数进行的是深拷贝，应该使用指针传递。

printf("%s", p) //将一直打印，直到遇到'0'因此可能会把数组中下一行的信息打印出来

##字符查找中使用KMP算法
nextTable表的构建
void getNextTable(int m){
       int j = 0;
       nextTable[j] = -1;
       int i = -1;
       while(j < m){
              if (i==-1 || pattern[j] == pattern[i]){
                     i++;
                     j++;
                     nextTable[j] = i;
              }
              else {
                     i = nextTable[i];
              }
       }
       return;
}

KMP比较
int KMP(int n, int M){
       getNextTable(m);
       int i = 0;
       int j = 0;
       while(i < n && j < m){
              if (j == -1 || text[i] == pattern[j]){
                     i ++;
                     j ++;
              }
              else {
                     j = nextTable[j];
              }
       }

       if ( j == m) //匹配成功
       return i - j + 1;
       else return -1;
}