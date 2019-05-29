#include <bits/stdc++.h>
#define L(a) (cuvant[a]-'a')
using namespace std;

struct nod{
    nod* litera[26];
    char minim1[32];
    char minim2[32];
    nod()
    {
        for (int i=0;i<26;i++)
             litera[i]=0;
        minim1[0]=minim2[0]='z'+1;
        minim1[1]=0;
        minim2[1]=0;
    }
};
nod * Trie = new nod;

char cuvant[32];
char cuvant2[32];
int lg;
bool ok;

void add(nod * T, int poz)
{
    if (poz==lg)
    {
        if (strcmp(cuvant2,T->minim1)<0)//e mai mic decat cel mai mic
    {
        strcpy(T->minim2,T->minim1);
        strcpy(T->minim1,cuvant2);
    }
    else if (strcmp(cuvant2,T->minim2)<0)//e aproape cel mai mic :)
    {
        strcpy(T->minim2,cuvant2);
    }
        return ;
    }
    int urm=L(poz);
    if (strcmp(cuvant2,T->minim1)<0)//e mai mic decat cel mai mic
    {
        strcpy(T->minim2,T->minim1);
        strcpy(T->minim1,cuvant2);
    }
    else if (strcmp(cuvant2,T->minim2)<0)//e aproape cel mai mic :)
    {
        strcpy(T->minim2,cuvant2);
    }
    if (!T->litera[urm])
        T->litera[urm]=new nod;
    add(T->litera[urm],poz+1);
}

void query(nod* T, int poz)
{
    if (poz==lg)
    {
        if (!strcmp(cuvant2, T->minim1)&&T->minim2[0]==('z'+1))
            return ;
        //if (T->minim2[0]==('z'+1))
         //   return ;
        if (!strcmp(cuvant2,T->minim1))
            cout<<T->minim2<<'\n';
            else cout<<T->minim1<<'\n';
        ok=1;
        return ;
    }
    int urm=L(poz);
    if (T->litera[urm])
        query(T->litera[urm],poz+1);
        else return ;
    //cout<<cuvant2[poz]<<" Poz "<<poz<<' '<<T->minim1<<' '<<T->minim2<<'\n';
    if (!ok)
    {
        if (!strcmp(cuvant2,T->minim1))
            {
             if (T->minim2[0]==('z')+1) return ;
             cout<<T->minim2<<'\n';ok=1;}
            else {
                cout<<T->minim1<<'\n';
                ok=1;
            }
    }
}

void rever(char *s)
{
    for (int st=0, dr=lg-1;st<=dr;st++,dr--)
        swap(*(s+st),*(s+dr));
}

int main()
{
    while (cin.getline(cuvant,30))
    {
        if (cuvant[0]==0)
            break;
        lg=strlen(cuvant);
        strcpy(cuvant2,cuvant);
        rever(cuvant);
        add(Trie,0);
    }
    while (cin>>cuvant)
    {
        ok=0;
        lg=strlen(cuvant);
        strcpy(cuvant2,cuvant);
        rever(cuvant);
        query(Trie,0);
    }
    return 0;
}