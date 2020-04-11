// 递归快速幂
// 转载于https://zhuanlan.zhihu.com/p/95902286
// 可在上述专栏查看代码思想（二分法），递归虽然简洁，但会产生额外的空间开销。
// 把递归改写为循环，来避免对栈空间的大量占用，也就是非递归快速幂
#include <stdio.h>
int qpow(int a, int n);
int main()
{
    int out = qpow(2,5);//调用递归快速幂 a:底数 n:指数
    printf("out=%d\n",out);
    return 0;
}
int qpow(int a, int n)
{
    if (n == 0) //递归出口
        return 1;
    else if (n % 2 == 1) //n为奇数
        return qpow(a, n - 1) * a;
    else  //n为偶数
    {
        int temp = qpow(a, n / 2);
        return temp * temp;
    }
}