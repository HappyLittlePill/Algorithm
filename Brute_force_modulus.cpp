// 暴力取模算法
// 转载于：https://www.cnblogs.com/zuilehongdou/p/5462484.html
// 密码学中RSA算法就经常要用到对一个数做高次幂运算后取余，我们称之为高次幂函数的取模运算。
/* 由于高次幂函数往往拥有很高的幂，而计算机中只有int、float、double、long long这几种变量类型，
远远不能满足对于大数字运算的要求，从而导致数据溢出无法完成运算。 
所以这里需要在每次迭代取模的过程中进行取模运算，从而保证数据不会溢出。
但是如果幂指数太大的话，需要耗费的时间就更多，直接导致运算效率低下，所以只适用于指数不大的情况. */
#include <stdio.h>
    int
    get_mod(int a, int b, int c)
{
    long long result = 1; //声明为long long类型防止溢出
    while (b--)
    {
        result = result * a % c; //这个算法的核心就是在运算过程中进行迭代取模(模运算基本规则：（a*b）%c=（(a%c)*b）%c)
    }
    return static_cast<int>(result);
}
int main(){
    int out = get_mod(2,7,221); //调用暴力取模函数 a：底数 b:指数 c:模
    printf("out=%d\n", out);
    return 0;
}