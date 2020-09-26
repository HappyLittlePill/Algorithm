import java.util.Scanner;
public class huixingNum {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.print("请输入阶数：");
        int num = scan.nextInt();
        int[][] arr = new int[num][num];
        //顺着路径 用于每次数值+1再赋给二维数组 首先初始化为0
        int a = 0;
        //把方阵看作一个个“口”字形 包含4笔画 每4笔画作为一轮
        //下面四组定义是最外层“口”字 4笔画中每一笔画的头到尾（可以看图理解）
        //经过一轮(4笔画)后，一笔画的头和尾都会向中间靠近1格(阶数越大看得更明显)，表现为例如：topL++ topR--;
        //topL(topLeft)上笔画左起点 downR(downRight)下笔画右起点
        // rightT(rightTop)右笔画上起点 leftD(leftDown)左笔画下起点
        int topL = 0, topR = num - 1;
        int rightT = 1, rightD = num - 1;
        int downR = num - 2, downL = 0;
        int leftD = num - 2, leftT = 1;
        //通过手写可知，最终方阵笔画数 = 2×阶数-1
        int key = 2 * num - 1;
        //每一笔画看作循环的一次
        for (int k = 0; k < key; k++) {
            switch (k % 4) {
                case 0:// 口字形的上面一笔
                    for (int i = topL, j = topR; i <= j; i++) {
                        int line = k / 4;//行不动，列变换，从topL加到topR
                        a += 1;
                        arr[line][i] = a;
                    }
                    topL++;
                    topR--;
                    break;
                case 1:// 口字形的右面一笔
                    for (int i = rightT, j = rightD; i <= j; i++) {
                        int column = num - 1 - k / 4;//列不动，行变换，从rightT加到rightD
                        a += 1;
                        arr[i][column] = a;
                    }
                    rightT++;
                    rightD--;
                    break;
                case 2:// 口字形的下面一笔
                    for (int i = downR, j = downL; i >= j; i--) {
                        int line = num - 1 - k / 4;//行不动，列变换，从downR减到downL
                        a += 1;
                        arr[line][i] = a;
                    }
                    downL++;
                    downR--;
                    break;
                case 3:// 口字形的左面一笔
                    for (int i = leftD, j = leftT; i >= j; i--) {
                        int column = k / 4;//列不动，行变换，从leftD减到leftT
                        a += 1;
                        arr[i][column] = a;
                    }
                    leftD--;
                    leftT++;
                    break;
            }
        }
        //输出回形数方阵
        for (int i = 0; i < num; i++) {
            for (int j = 0; j < num; j++) {
                System.out.print(arr[i][j] + "\t");
            }
            System.out.println();
        }
        scan.close();
    }
}
