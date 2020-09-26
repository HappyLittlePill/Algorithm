/*
* 问题：创建一个长度为6的int型数组，要求取值为1-6，同时元素值各不相同
*/
public class ArrayAssignment {
    public static void main(String[] args) {
        int[] arr = new int[6];
        for (int i = 0; i < arr.length; i++) {
            // 随机生成1-30之间的数
            // 公式：取[a,b]之间的随机数：(int) (Math.random() * (b - a + 1) + a)
            arr[i] = (int) (Math.random() * (6 - 1 + 1) + 1);
            // 核心部分：各元素值互不相同 每次生成的新元素都要与之前已有的数组元素进行比较

            // 方式一：
            for (int j = 0; j < i; j++) {
                while (arr[j] == arr[i]) {
                    arr[i] = (int) (Math.random() * (6 - 1 + 1) + 1);
                    j = 0;// 如果当前数组元素值与前面数组元素值相同 重新随机赋值后又要从第一个元素开始比较
                }
            }

            // 方式二：带标签的while循环
            // label: while (true) {
            // for (int j = 0; j < i; j++) {
            // if (arr[i] == arr[j]) {
            // arr[i] = (int) (Math.random() * (6 - 1 + 1) + 1);
            // continue label;
            // }
            // }
            // break;
            // }

            // 方式三：
            // for (int j = 0; j < i; j++) {
            //     if (arr[i] == arr[j]) {
            //         i--;
            //         break;
            //     }
            // }
            //ps!!!方法三需要在最外层for循环外单独打印整个数组
        
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }
}
