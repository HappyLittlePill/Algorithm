// 递归快速幂（对大素数取模）
// 转载于https://zhuanlan.zhihu.com/p/95902286
// 原则是步步取模，如果MOD较大，还应当开long long
#include <stdio.h>
#define MOD 3337
typedef long long ll;
ll qpow(ll a, ll n)
{
    if (n == 0)
        return 1;
    else if (n % 2 == 1)
        return qpow(a, n - 1) * a % MOD;
    else
    {
        ll temp = qpow(a, n / 2) % MOD;
        return temp * temp % MOD;
    }
}
int main(){
    ll a,b;
    printf("请输入底数a，指数b：\n");
    scanf("%lld%lld",&a,&b);
    ll out = qpow(a, b);
    printf("%lld\n",out);
    return 0;
}