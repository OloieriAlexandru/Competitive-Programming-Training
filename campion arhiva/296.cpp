#include <bits/stdc++.h>
#define nmax 100005
using namespace std;
char s[nmax], saux[nmax];
char s1[11], op;
int n, lg, poz, nr;
int main()
{
    freopen("ed.in","r",stdin);
    freopen("ed.out","w",stdout);
    cin>>s>>n;
    lg=strlen(s), poz=lg;
    for (int i=0; i<n; ++i) {
        cin>>op;
        if (op=='L'){
            if (poz>0){
                --poz;
            }
        } else if (op=='R') {
            if (poz<lg){
                ++poz;
            }
        } else if (op=='B') {
            if (poz>0) {
                s[poz-1]=0;
                strcat(s, s+poz);
                lg--, poz--;
            }
        } else if(op=='I') {
            cin>>s1;
            strcpy(saux, s+poz);
            s[poz]=0;
            strcat(s, s1);
            strcat(s, saux);
            lg+=strlen(s1);
        } else {
            cin>>nr;
            if (nr) {
                if (lg-poz<=nr){
                    s[poz]=0, lg=poz;
                } else {
                    s[poz]=0;
                    strcat(s, s+poz+nr);
                    lg-=nr;
                }
            }
        }
    }
    cout<<s<<'\n';
    fclose(stdin);
    fclose(stdout);
    return 0;
}

/*
18 ian 2017, 21:53
90 puncte

#include <fstream>
#include <cstring>
#define LGMAX 100010

using namespace std;
ifstream fin( "ed.in" );
ofstream fout( "ed.out" );

char sir[LGMAX];//sirul meu
char introduc[20],copie[LGMAX];
int lg, n, i, cursor, sterg, lgintroduc;
char c;

int main()
{
fin.getline(sir,LGMAX,'\n');//citesc sirul
lg=strlen(sir);//calculez lungimea lui
fin>>n;//citesc numarul de instructiuni
fin.get(c);//dupa 'n' este un '\n', asa ca il citesc in gol
cursor=lg;//cursorul este pe ultima pozitie
for (i=1;i<=n;i++)//citesc si execut instructiunile
    {fin.get(c);//citesc prima Litera din instructiune
     if (c=='L')//daca prima litera e L, inseamna ca nu mai urmeaza nimic dupa ea
         {fin.get(c);//citesc '\n' de dupa litera
          if (cursor>0)//daca pot sa ma misc la stanga
             cursor--;}//o fac
          else//altfel
          if (c=='R')//daca prima litera e R, inseamna ca nu mai urmeaza nimic dupa ea
              {fin.get(c);//citesc '\n' de dupa litera
               if (cursor<lg)//daca pot sa ma misc la dreapta
                   cursor++;//o fac
               }
               else//altfel
               if (c=='B')//daca prima litera e B
                   {fin.get(c);//citesc '\n'
                    if (cursor>0)//daca pot sa sterg caracterul din stanga mea,
                        strcpy(sir+cursor-1,sir+cursor);//fac asta
                    cursor--;//scad pozitia cursorului
                    lg--;//scade lungimea sirului
                    }
                    else//altfel
                    if (c=='D')//daca prima litera e D
                        {fin>>sterg;//citesc cate cifre trebuie sa sterg
                         fin.get(c);//citesc '\n'
                         if (cursor+sterg>lg)//daca am de sters mai multe cifre decat exista in sir
                             {sir[cursor]=0;lg=strlen(sir);//inseamna ca trebuie sa sterg tot, asa ca pot sa pun caracterul NULL pentru a arata ca aici se termina sirul
                              cursor=lg;}//cursorul e la finalul sirului
                             else//altfel, daca trebuie sa sterg niste caractere si mai ramane ceva in sir
                             {strcpy(sir+cursor,sir+cursor+sterg);//sterg
                              lg=strlen(sir);//calculez noua lungime a sirului
                             }
                        }
                        else//altfel
                        if (c=='I')//daca prima litera e I
                            {fin>>introduc;//citesc ce trebuie sa inserez
                             lgintroduc=strlen(introduc);//calculez lungimea la ce trebuie sa inserez
                             fin.get(c);//citesc '\n'
                             strcpy(copie,sir+cursor);//fac o copie la sirul de dupa pozitia curenta
                             strcpy(sir+cursor,introduc);//introduc ce trebuie sa introduc
                             strcat(sir,copie);//lipesc copia la noul sir
                             lg=strlen(sir);//calculez noua lungime a sirului
                            }
    }
fout<<sir<<'\n';//afisez sirul
fin.close();
fout.close();
return 0;
}
*/
