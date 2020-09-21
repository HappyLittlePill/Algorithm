import java.util.Scanner;

public class PrimeNum2 {
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
        label: for (int i = 2; i <= n; i++) {
            double kf = Math.sqrt(i);// 先计算开方，在for循环里就不用每次都重新计算
            for (int j = 2; j <= kf; j++) {
                if (i % j == 0) {
                    continue label;//带标签的continue
                }
            }
            count++;
        }
        long end = System.currentTimeMillis();
        System.out.println("time:" + (end - start));
        System.out.println("number:" + count);
    }
}
