import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String input = sc.nextLine();

        int ln = input.length();

        if (ln<=2)
        {
            System.out.println("0");
            return;
        }

        int ans = 0;
        for (int i=0;i<ln-2;++i)
        {
            for (int j=i+1;j<ln-1;++j)
            {
                for (int k=j+1;k<ln;++k)
                {
                    if (input.charAt(i) == 'Q' && input.charAt(j) == 'A' && input.charAt(k) == 'Q')
                    {
                        ++ans;
                    }
                }
            }
        }

        System.out.println(ans);
    }
}
