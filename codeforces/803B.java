import java.util.Scanner;

public class Main {

    private static final int LMAX = 200005;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int a[] = new int[LMAX];
        int ans[] = new int[LMAX];

        for (int i=1;i<=n;++i)
        {
            ans[i] = -1;
        }

        for (int i=1;i<=n;++i)
        {
            a[i] = sc.nextInt();
        }

        for (int i=1;i<=n;++i)
        {
            if (a[i] == 0)
            {
                ans[i] = 0;
                for (int j=i-1;j>=1;--j)
                {
                    int d = i-j;
                    if (ans[j]!=-1 && ans[j]<=d)
                    {
                        break;
                    }
                    ans[j] = d;
                }
                for (int j=i+1;j<=n;++j)
                {
                    int d = j-i;
                    if (a[j]==0)
                    {
                        break;
                    }
                    ans[j] = d;
                }
            }
        }

        for (int i=1;i<=n;++i)
        {
            System.out.print(ans[i] + " ");
        }
        System.out.print("\n");
    }
}
