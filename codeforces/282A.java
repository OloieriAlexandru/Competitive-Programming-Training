import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int x = 0;
        int n = sc.nextInt();
        String s = sc.nextLine();

        for (int i=0;i<n;++i)
        {
            s = sc.nextLine();
            if (s.contains("-"))
            {
                --x;
            }
            else
            {
                ++x;
            }
        }
        System.out.println(x);
    }
}
