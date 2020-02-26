#include <cstdio>

using namespace std;
FILE *fin=fopen("b2k.in","r");
FILE *fout=fopen("b2k.out","w");
int getc(FILE *fin);
int n,k,rest,i,inm,grupa,rez,x,j,cat;
char prt[128];
char c;

int main()
{
    fscanf(fin,"%d",&n);
    fscanf(fin,"%d",&k);
    x=0;
    while (k>1){
        k >>= 1;
        ++x;
    }
    for (int i=0;i<10;++i){
        prt[i]='0'+i;
    }
    for (int i=0;i<22;++i){
        prt[i+10]='a'+i;
    }
    rest=n%x;
    if (rest!=0) {
        rez = 0;
        for (i=0; i<rest; i++) {
            fscanf(fin," %c",&c);
            rez = (rez<<1)+(c=='1'?1:0);
        }
        fprintf(fout,"%c",prt[rez]);
    }
    int tm = n/x;
    for (j=0; j<tm; j++)
    {
        rez=0;
        for (i=0; i<x; i++){
            fscanf(fin," %c",&c);
            rez = (rez << 1) + (c=='1'?1:0);
        }
        fprintf(fout,"%c",prt[rez]);
    }
    fprintf(fout,"\n");
    return 0;
}


/*
15 feb 2015, 16:23
85 puncte

#include <cstdio>

using namespace std;
FILE *fin=fopen("b2k.in","r");
FILE *fout=fopen("b2k.out","w");int getc(FILE *fin);
int n,k,rest,i,inm,grupa,rez,x,j,cat;
char c;

int main()
{
fscanf(fin,"%d",&n);
fscanf(fin,"%d",&k);
x=0;
while (k>1)
    {k=k/2;
     x++;}
rest=n%x;
if (rest!=0)
    {grupa=0;
     for (i=0;i<rest;i++)
         {fscanf(fin," %c",&c);
          grupa=grupa*10+c-'0';}
     inm=1;
     while (grupa>0)
        {rez=rez+grupa%10*inm;
         inm=inm*2;
         grupa=grupa/10;}
     if (rez<=9)
         fprintf(fout,"%d",rez);
         else
         {rez=rez-10+'a';
          fprintf(fout,"%c",rez);}}
for (j=0;j<n/x;j++)
     {rez=0;
      grupa=0;
     for (i=0;i<x;i++)
         {fscanf(fin," %c",&c);
          grupa=grupa*10+(c-'0');}
     inm=1;
     while (grupa>0)
        {rez=rez+grupa%10*inm;
         inm=inm*2;
         grupa=grupa/10;}
     if (rez<=9)
          fprintf(fout,"%d",rez);
         else
         {rez=rez-10+'a';
          fprintf(fout,"%c",rez);}}
fprintf(fout,"\n");
return 0;
}
*/
