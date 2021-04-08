#include <stdio.h>
#include <stdlib.h>
void Bomba(int m,int n,int x,char plansza[n][m])
{
    for (int i=0;i<n;i++)
    {
        if ((plansza[i+1][x]=='X')||(i+1==n))
        {
           if (i-1>=0)
           {
            if (x-1>=0)
                plansza[i-1][x-1]='.';
            if (x+1<=m-1)
                plansza[i-1][x+1]='.';
                plansza[i-1][x]='.';
           }
           if (i+1<=n-1)
           {
               if (x-1>=0)
                plansza[i+1][x-1]='.';
               if (x+1<=m-1)
                plansza[i+1][x+1]='.';
                plansza[i+1][x]='.';
           }
           if (x-1>=0)
           {
               plansza[i][x-1]='.';

           }
           if (x+1<=m-1)
           {
               plansza[i][x+1]='.';

           }
           plansza[i][x]='.';
           break;

        }

    }
}
void FiguraW (int m,int n,int x,char plansza[n][m])
{
    for (int i=0;i<n;i++)
    {
        if (((plansza[i+3][x]=='.')&&(plansza[i+3][x+1]=='.')&&(plansza[i+3][x+2]=='.')&&(plansza[i+3][x+3]=='.')&&(plansza[i+3][x+4]=='.')))
        {

        }
        else
        {
            plansza[i][x]='X';
            plansza[i][x+2]='X';
            plansza[i][x+4]='X';
            plansza[i+1][x]='X';
            plansza[i+1][x+2]='X';
            plansza[i+1][x+4]='X';
            plansza[i+2][x]='X';
            plansza[i+2][x+1]='X';
            plansza[i+2][x+2]='X';
            plansza[i+2][x+3]='X';
            plansza[i+2][x+4]='X';
            break;
        }
    }
}
void FiguraI (int m,int n,int x,char plansza[n][m])
{
    for (int i=0;i<n;i++)
    {
        if (plansza[i+4][x]=='.')
        {

        }
        else
        {
            plansza[i][x]='X';
            plansza[i+1][x]='X';
            plansza[i+2][x]='X';
            plansza[i+3][x]='X';
            break;
        }
    }
}
void FiguraT (int m,int n,int x,char plansza[n][m])
{
    for (int i=0;i<n;i++)
    {
        if ((plansza[i+1][x]=='.')&&(plansza[i+2][x+1]=='.')&&(plansza[i+1][x+2]=='.'))
        {

        }
        else
        {
            plansza[i][x]='X';
            plansza[i+1][x+1]='X';
            plansza[i][x+1]='X';
            plansza[i][x+2]='X';
            break;
        }
    }
}
void FiguraF (int m, int n,int x,char plansza[n][m])
{
    for (int i=0;i<n;i++)
    {
        if ((plansza[i+3][x]=='.')&&(plansza[i+1][x+1]=='.'))
        {

        }
        else
        {
            plansza[i+3][x]='X';
            plansza[i+2][x]='X';
            plansza[i+1][x]='X';
            plansza[i][x]='X';
            plansza[i][x+1]='X';
            break;
        }
    }
}
void linia(int m,int n,char plansza[n][m])
{
    int l,i=n-1;
    while (i>=0)
    {
        l=0;
        for (int j=0;j<m;j++)
        {
            if (plansza[i][j]=='X')
            {
                l++;
            }
        }
        if (l==m)
        {
            for (int k=i;k>0;k--)
            {
                for (int s=0;s<m;s++)
                {
                    plansza[k][s]=plansza[k-1][s];
                    plansza[0][s]='.';
                }
            }
        i++;
        }
    i--;
    }
}
void pisanie(int m,int n,char plansza[n][m])
{
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            printf("%c",plansza[i][j]);
        }
        printf("\n");
    }
}
void Kwadrat(int m,int n,int x,char plansza[n][m])
{

    for (int i=0;i<n;i++)
    {
        if ((plansza[i+1][x]=='.')&&(plansza[i+1][x+1]=='.'))
        {

        }
        else
        {
            plansza[i-1][x]='X';
            plansza[i][x+1]='X';
            plansza[i-1][x+1]='X';
            plansza[i][x]='X';
            break;
        }
    }
}


void czyszczenie(int m,int n,char plansza[n][m])
{
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            plansza[i][j]='.';
        }
    }
}

int main()
{
    int m,n,k,x;
    char c;
    scanf(" %d %d %d",&m,&n,&k);
    char plansza[n][m];
    czyszczenie(m,n,plansza);
    for (int i=0;i<k;i++)
    {

        scanf(" %c %d",&c,&x);

        switch (c)
        {
        case 'K':
            {
                Kwadrat(m,n,x,plansza);
                linia(m,n,plansza);


                break;
            }
        case 'F':
            {
               FiguraF(m,n,x,plansza);
               linia(m,n,plansza);

               break;
            }
        case 'T':
            {
                FiguraT (m,n,x,plansza);
                linia(m,n,plansza);

                break;
            }
        case 'I':
            {
                FiguraI(m,n,x,plansza);
                linia(m,n,plansza);

                break;
            }
        case 'W':
            {
                FiguraW(m,n,x,plansza);
                linia(m,n,plansza);

                break;
            }
        case '*':
            {
                Bomba(m,n,x,plansza);
                linia(m,n,plansza);

                break;
            }
        }
    }
pisanie(m,n,plansza);
return 0;
}