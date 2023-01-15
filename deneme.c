#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//P.Deitel Kitabi 7.bölüm alistirma 7.17 (Simülasyon: Kaplumbağa ve Tavşan Yarışı)
//1-70 kareli uzunlukta bir yarış pisti

int k_adim(int a)       //kaplumbaganın her bir adimi
{
    srand(time(NULL));
    a=1+rand()%10;
    int b;
    switch (a)      //gelen rastegele sayıya göre yapılacak 
    {               //işlem belirlenir
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        b=3;
        break;
    case 6:
    case 7:
        b=-6;
        break;
    case 8:
    case 9:
    case 10:
        b=1;
        break;
    }

    return b;
    
}

int t_adim(int a)       //tavşanın her bir adimi
{
    int c;
    srand(time(NULL));
    a=1+rand()%10;

    switch (a)
    {
    case 1:
    case 2:
        c=0;
        break;
    case 3:
    case 4:
        c=9;
        break;
    case 5:
        c=-12;
        break;
    case 6:
    case 7:
    case 8:
        c=1;
        break;
    case 9:
    case 10:
        c=-2;
        break;
    }
    return c;
}


int main(){

int x=0;
char tus;


int pist[80];      //yaris pisti

for (int i = 1; i < 80; i++)
{
    pist[i]=i;
}

int *K;
int *T;
K=malloc(79*sizeof(char));
T=malloc(79*sizeof(char));

K=&pist[1];     //başlangıç çizgisi 
T=&pist[1];     //başlangıç çizgisi

printf("%20s\n%28s","BANG !!!!!","VE YARIS BASLADI !!!!!");

do
{
    printf("\n\nDevam etmek icin ENTER'a basin!\n");
    scanf("%c",&tus);
    printf("k_adim: %d\n\n",k_adim(x));
    if (k_adim(x)<0 && *K<=6)
    {
        K=&pist[1];
    }
    else
        K+=k_adim(x);
    
    if ( t_adim(x)==-2 && *T<=2)
    {
        T=&pist[1];
    }
    else if (t_adim(x)==-12 && *T<=12)        //
    {
        T=&pist[1];
    }
    else
        T+=t_adim(x);
    
    

    for (int i = 1; i < 80; i++)
    {
        if (pist[i]==*K) 
            printf("K");
        else
         {
            printf("_");
         }

         if (pist[i]==69)
         {
            printf("%s","|");
         }
                     
    }
        
    puts("\n");

    printf("t_adim:%d\n",t_adim(x));
    for (int i = 1; i <80 ; i++)
    {
        if (pist[i]==*T)
        {
            printf("T");
        }
        else
            printf("_");

            if (pist[i]==69)
            {
                printf("%s","|");
            }
            
    }
    
    
    
    
    
if (*K>=70)
{
    printf("\n\nKAPLUMBAĞA KAZANDI !!! YAY!!!");
    break;
}
else if (*T>=70)
{
    printf("\n\nTAVŞAN KAZANDI. YUCH.");
    break;
}


} while (*K<70 && *T<70);







    return 0;
}