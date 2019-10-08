import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String s = sc.nextLine();
        int ln = s.length();

        int lowerC = 0;
        int upperC = 0;

        for (int i=0;i<ln;++i)
        {
            if (s.charAt(i)>='a'&&s.charAt(i)<='z')
            {
                ++lowerC;
            }
            else
            {
                ++upperC;
            }
        }
        if (lowerC>=upperC)
        {
            s = s.toLowerCase();
        }
        else
        {
            s = s.toUpperCase();
        }

        System.out.println(s);
    }
}
