#include <stdio.h>
#include <stdlib.h>

                                /* THIS SOLUTION WAS CREATED BY AHMED BOULAHIA*/


void initial(int N , char **M)
{
    int i,j,k; int T[20];

    for (j=0;j<3;j++)
    {
        for(i=0;i<N;i++)
        {
            M[i][j]='|';
        }
    }

k=1;
    for (i=0;i<N;i++)
    {
            M[i][0]= k +'0';
k++;
    }

}


void hanoi (int N,char**M,char dep,char arr,char aux,int NF )
{ char C1,C2,C3,X;
int i,c1,c2;
    if (N>0)
    {
        C1=dep;C2=arr;C3=aux;
       hanoi(N-1,M,dep,aux,arr,NF);

       printf(" place un disque du tour %c vers le tour %c \n",dep,arr);

       if ((C1=='A') && (C2=='C'))
        {c1=0;
        c2=1;
        }
       else if ((C1=='A') && (C2=='B'))
          {c1=0 ;
          c2=2;}
      else if ((C1=='B') && (C2=='A'))
            {c1=2;
            c2=0 ;}
      else if ((C1=='B') && (C2=='C'))
            {c1=2;
            c2=1 ;}
       else if ((C1=='C') && (C2=='A'))
           {c1=1;
           c2=0 ;}
       else if ((C1=='C') && (C2=='B'))
            {c1=1;
       c2=2 ;}

i=0;
       do{
            X=M[i][c1];
            i++;
       }while (X=='|');
       M[i-1][c1]='|';
    for (i=0;i<NF;i++)
      { if (i+1<NF)
        {
         if ((M[i+1][c2]!='|')&&(M[i][c2]=='|')&&(i<NF-1))
           M[i][c2]=X;
        }
       }

       if (M[i-1][c2]=='|')
        M[i-1][c2]=X;

affichage(NF,M);



       hanoi(N-1,M,aux,arr,dep,NF);}
    }


void affichage(int N, char **M)
{int i,j;

    for (i=0;i<N;i++)
    {
        for(j=0;j<3;j++)
        {
           printf("%c",M[i][j]);
           printf("   ");
        }
        printf("\n");
    }
}



int main()
{
    int N,i,j ; char **M;

    printf("donner N");
    scanf("%d",&N);
printf("A   C   B \n \n");
    M=malloc(N*sizeof(char*));
    for(i=0;i<N;i++)
    {
        M[i]=malloc(3*sizeof(char));
    }

initial(N,M);
affichage(N,M);

hanoi (N,M,'A','C','B',N);


    return 0;
}
