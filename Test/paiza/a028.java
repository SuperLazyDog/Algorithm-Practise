import java.util.*;


public class Main {

    public static void main(String[] args) {
        // 自分の得意な言語で
        // Let's チャレンジ！！
        Scanner sc = new Scanner(System.in);
        String line = sc.nextLine();
        String data[] = line.split(" ");
        int power = Integer.valueOf(data[0]);
        int point = Integer.valueOf(data[1]);
        Test t = new Test(power, point);
        t.test();
    }


}

class Test {
  int power, point;
  int max = 0;
  Test(int power, int point) {
    this.power = power;
    this.point = point;
  }
  void computePower(int power, int point, int min) {
    if (point > 0) {
      for (int i = min; i <= point; i++) {
        computePower(power*(100+i)/100, point-i, i);
      }
    } else {
        // System.out.printf("max: %d, power: %d\n", max, power);
      if (this.max < power) {
        this.max = power;
      }
    }
  }
  void test() {
    computePower(power, point, 1);
    System.out.println(this.max);
  }
}
