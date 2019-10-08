import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        String s = sc.nextLine();

        for (int i=0;i<n;++i)
        {
            s = sc.nextLine();
            if (s.length()<=10)
            {
                System.out.println(s);
                continue;
            }
            System.out.print(s.charAt(0));
            System.out.print(s.length()-2);
            System.out.print(s.charAt(s.length()-1));
            System.out.print('\n');
        }
    }
}
