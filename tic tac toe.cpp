#include <stdio.h>
int main() {
char tt[3][3]={
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'}
};
int p=1;
int c;
int r;
int co;
int go=0;
int f;
int d=0;
while(go==0)
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("%c",tt[i][j]);
            if (j<2)
            printf("|");
        }
        printf("\n");
        if(i<2)
        printf("-|-|-\n");
    }
    printf("%d player choice(1-9):",p);
    scanf("%d",&c);
    if(c<1 || c>9 )
    {
    printf("Enter a number in the mentioned range\n");
    continue;
    }
    r=(c-1)/3;
    co=(c-1)%3;
       if (tt[r][co] == 'x' || tt[r][co] == 'o') 
	   {
            printf("This spot is already taken, try again.\n");
            continue;
        } 
    if(p==1)
    {
        tt[r][co]='x';
        p=2;
    }
    else
    {
        tt[r][co]='o';
        p=1;
    }

    for(int i=0;i<3;i++)
    {
    if((tt[i][0]==tt[i][1] && tt[i][1]== tt[i][2] )||(tt[0][i]==tt[1][i] && tt[1][i]== tt[2][i]) )
    {
        go=1;
        break;
    }
    }
    if((tt[0][0]==tt[1][1] && tt[1][1]== tt[2][2])||(tt[0][2]==tt[1][1] && tt[1][1]== tt[2][0]))
    {
        go=1;
        break;
    }
    f=1;
    for (int i = 0; i < 3; i++) 
    {
    for (int j = 0; j < 3; j++) 
    {
    if (tt[i][j] != 'x' && tt[i][j] != 'o') 
    {
    f = 0;
    break;
    }
    }
    if(f==0)
    {
    	break;
	}
    }
    if(f==1)
    {
        go=1;
        d=1;
    }
    
}
     printf("final board\n");
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("%c",tt[i][j]);
            if (j<2)
            printf("|");
        }
        printf("\n");
        if(i<2)
        printf("-|-|-\n");
    }
    if(d==1)
    printf("Draw");
    else
    {
        if(p==1)
        printf("winner:player 2");
        else
        printf("winner:player 1");
    }
    return 0;
}
