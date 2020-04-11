// 蒙哥马利算法（非递归快速幂取模）
// 转自：https://www.cnblogs.com/zuilehongdou/p/5462484.html
// 蒙哥马利算法是一种快速的大数（通常达到几百个二进制）的模乘算法，由彼得·蒙哥马利在1985年提出。
// 也可参考专栏查看非递归快速幂：https://zhuanlan.zhihu.com/p/95902286
#include <stdio.h>
int get_mod(int a, int b, int c)
{
    long long res = 1; //声明为long long类型防止数据溢出
    int temp = a;
    while (b > 0)
    {
        if (b & 1) //将十进制的指数b 按照二进制展开后 与1做位与运算 相当于取最后一位 判断是否为1
        {
            res = (res * temp) % c;
        }
        temp = (temp * temp) % c;
        // temp = temp * temp; //当temp*temp的值不超过int的表示范围（2147483648）时，上下这两种都可以
        b >>= 1; //位运算右移 幂指数二进制向右移动一位
    }
    return static_cast<int>(res); //以int类型返回最终结果
}
int main()
{
    int out = get_mod(45, 55, 221); //调用蒙哥马利算法，a:底数 b:指数 c:模
    printf("out=%d\n", out);
    return 0;
}