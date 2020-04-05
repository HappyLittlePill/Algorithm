/*  快速幂--次方求模  */
#include <stdio.h>
#include <string.h>
#include <algorithm>
    using namespace std;
long long  fast(long long  a,long long  b ,long long c){
    long long  temp=1;
    if(b==0)
        return 1;
    if(b==1)
        return a%c;
    temp = fast(a,b/2,c);
    temp = temp*temp%c;
    if(b&0x1){
        temp = temp*a%c;
    }
    return temp;
 
}
int main(){
    int n;
    printf("n:");
    scanf("%d",&n);
    while(n--){
        long long   a,b,c;
        printf("a b c:");
        scanf("%lld",&a);
        scanf("%lld",&b);
        scanf("%lld",&c);
        long long x = fast(a,b,c);
        printf("结果：%lld\n",x);
    }
 
    return 0;
}