// 递归快速幂取模（对大素数取模）
// 转载于https://zhuanlan.zhihu.com/p/95902286
// 原则是步步取模，如果MOD较大，还应当开long long
// 原理是在递归快速幂算法(Recursively_fast_powers)的基础上增加取模运算，核心思想还是递归，以空间换时间，效率不如蒙哥马利算法
#include <stdio.h>
typedef long long ll;
ll qpow(ll a, ll n, ll MOD)
{
    if (n == 0)
        return 1;
    else if (n % 2 == 1)
        return qpow(a, n - 1, MOD) * a % MOD;
    else
    {
        ll temp = qpow(a, n / 2, MOD) % MOD;
        return temp * temp % MOD;
    }
}
int main()
{
    ll a, b, MOD;
    printf("请输入底数a：，指数b：，模c:\n");
    scanf("%lld%lld%lld", &a, &b, &MOD);
    ll out = qpow(a, b, MOD);
    printf("%lld\n", out);
    return 0;
}