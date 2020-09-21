import java.util.Scanner;

public class PrimeNum {
    public static void main(String[] args) {
        // 记录质数总个数
        int count = 0;
        // 输入量级n
        Scanner scan = new Scanner(System.in);
        System.out.println("请输入量级n:");
        int n = scan.nextInt();
        scan.close();
        // 开始计时
        long start = System.currentTimeMillis();
        for (int i = 2; i <= n; i++) {
            boolean flag = true;
            double kf = Math.sqrt(i);// 先计算开方，在for循环里就不用每次都重新计算
            for (int j = 2; j <= kf; j++) {
                // for (int j = 2; j <= Math.sqrt(i); j++) { //每次循环都重新计算开方，效率低
                // for (int j = 2; j < i; j++) { //从2遍历到n-1，效率低
                if (i % j == 0) {
                    flag = false;
                    break;// 不加break效率也会降低
                }
            }
            if (flag) {
                count++;
                // System.out.println(i); // 动态输出所有的质数
            }
        }
        long end = System.currentTimeMillis();
        System.out.println("time:" + (end - start));
        System.out.println("number:" + count);
    }
}
