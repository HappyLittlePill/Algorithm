#include <stdio.h>
#include <math.h>
#include <time.h>
int main()
{
    clock_t op, ed;
    int n, count;
    count = 2;
    printf("请输入量级:\n");
    scanf("%d", &n);
    op = clock();
    printf("%d %d ", 2,3);
    for (long i = 4; i < n + 1; i++)
    {
        int sqrt_i = (int)sqrt(i);
        for (int j = 2; j < i; j++)
        {
            int yushu = i % j;
            if(yushu == 0){
                break;
            }
            if(j == sqrt_i)
            {
                printf("%ld ", i);
                count++;
            }
            // if(j == i -1){
            //     printf("%ld ", i);
            //     count++;
            // }
        }
    }
    printf("\ncount = %d ", count);
    ed = clock();
    printf("\n耗时：%fs\n", (double)(ed - op) / CLOCKS_PER_SEC);
    return 0;
}