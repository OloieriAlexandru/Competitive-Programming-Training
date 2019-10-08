import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        char[] st = new char[200005];
        String input = sc.nextLine();
        int lg = 0;
        int ln = input.length();
        for (int i=0;i<ln;++i)
        {
            st[i] = input.charAt(i);
        }
        lg = ln;

        for (int i=0; i<lg-1; ++i)
        {
            if (st[i] == st[i+1])
            {
                st[i+1] = (char) (st[i+1]+1);
                if (st[i+1]>'z')
                {
                    st[i+1] = 'a';
                }
                if (i+2<lg)
                {
                    if (st[i+2] == st[i+1])
                    {
                        st[i+1] = (char)(st[i+1]+1);
                        if (st[i+1]>'z')
                        {
                            st[i+1] = 'a';
                        }
                    }
                }
            }
        }

        for (int i=0;i<lg;++i)
        {
            System.out.print(st[i]);
        }
        System.out.print("\n");
    }
}
