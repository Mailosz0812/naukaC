#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define ops 4
//int *sortowaniewstaw(int *tab1,int len);
void sortowaniewstaw(int *tab1,int len);
void bobelkowy(int *tab1,int len);
void choicesort(int *tab1,int len);
void binarnie(int liczba);
void wyswietlBinarnie(int);
void wstawianie(int[],int);
void wybor(int[],int);
void coctailsort(int[],int);
void bubblesort(int[],int);
long rekurencja(int);
int silnia(int liczba);
int main()
{
   //printf("Program sortuje tablice przez wstawianie, wybor, coctailsort,bubblesort,rekurencja \n");
    int tab1[]={2,5,1,6},size1,choice,lenght;
    //char ciag[] = "acsrvmdvfinafnrn";
    //lenght = strlen(ciag);
   //int (*ptr2func[ops])(int[],int) = {wstawianie, wybor, coctailsort,bubblesort};
   //int liczba;
   size1 = sizeof(tab1) / sizeof(int);
    //printf("Podaj numer funkcji");
    //scanf("%d",&choice);
   //printf("%d",ptr2func[choice](tab1,size1));
   //printf("Podaj liczbe dziesietna nieujemna");
   //scanf("%d",&liczba);
   //if (liczba > 0)
   //{
      // binarnie(liczba);
   //}
   //bobelkowy(tab1,size1);
   wstawianie(tab1,size1);
    return 0;
}

void wstawianie(int tab1[],int leng)
{
    int klucz =0,i=1,j=0;
    //klucz = tab1[i+1];
    for(;i < leng;i++)
    {
        klucz = tab1[i];
        j = i-1;
        while(j>=0 && klucz < tab1[j])
        {
            tab1[j+1] = tab1[j];
            --j;
        }
        tab1[j+1] = klucz;
    }
    for(i = 0; i < leng; i++)
    {
        printf("%d ,",tab1[i]);
    }
    }
/*
void wybor(int tab1[], int leng)
{
    int najmniejszy,i = 0,j;
    najmniejszy = tab1[0];
    for(;i<leng - 1; i++)
    {
        j = i+1;
        for(;j<leng;j++)
        {
            if(tab1[j] < najmniejszy)
            {
                najmniejszy = tab1[j];
                tab1[j] = tab1[i];
                tab1[i] = najmniejszy;
            }
        }
        najmniejszy = tab1[i+1];
    }
    //printf("%d",najmniejszy);
        for(i = 0; i < leng; i++)
    {
        printf(",%d ",tab1[i]);
    }
}

void coctailsort(int tab2[], int leng)
{
    int j,end = leng - 1,temp,start = 0;
    bool swap = true;
    while(swap)
        {
            swap = false;
            j = start;
            for(;j <= end;j++)
            {
                temp = tab2[j];
                if(tab2[j+1] < tab2[j])
                {
                    tab2[j] = tab2[j+1];
                    tab2[j+1] = temp;
                    swap = true;
                }
            }

            if(!swap)
            {
                break;
            }
            swap = false;
            --end;
            j = end;
            for(;j >= start;j--)
            {
                temp = tab2[j];
                if(tab2[j] < tab2[j-1])
                {
                    tab2[j] = tab2[j-1];
                    tab2[j-1] = temp;
                    swap = true;
                }
            }
            ++start;
    }
            for(j = 0; j < leng; j++)
    {
        printf(",%d ",tab2[j]);
    }
}
void bubblesort(int tab2[],int leng)
{
    int i=0,j=0,temp;
    for(;i<leng;i++)
    {
        for(j=0 ;j < leng - i - 1; j++)
        {
            if(tab2[j]> tab2[j+1])
            {
                temp = tab2[j];
                tab2[j] = tab2[j+1];
                tab2[j+1] = temp;
            }
        }
    }
    for(j = 0; j < leng; j++)
        {
            printf(",%d ",tab2[j]);
        }
}

void wyswietlBinarnie(int liczba)
{
    if(liczba > 1)
    {
        wyswietlBinarnie(liczba / 2);
        printf("%d \n",liczba);
    }
    printf("\n %d",liczba%2);
}


int silnia(int liczba)
{
    if(liczba > 1)
    {
        return liczba *silnia(liczba-1);
    }
    else
    {
        return 1;
    }
}

void binarnie(int liczba)
{
    if(liczba > 1)
    {
        binarnie(liczba/2);
    }
    printf("%d",liczba%2);
}
2,5,6,1

void sortowaniewstaw(int *tab1,int len)
{
    int key,i,j;
    for(i = 1; i < len; i++)
    {
        key = tab1[i];
        j = i-1;
        while(j>=0 && key < tab1[j])
        {
            tab1[j+1] = tab1[j];
            --j;
        }
        tab1[j+1] = key;
    }
}
void choicesort(int *tab1,int len)
{
    int min,j;
    for(int i = 0; i < len; i++)
    {
        min = tab1[i];
        for(j = i; j < len; j++)
        {
            if(tab1[j] < min)
            {
                min = tab1[j];
                tab1[j] = tab1[i];
                tab1[i] = min;
            }
        }
    }
}
*/
void bobelkowy(int *tab1,int len)
{
    int i,j,temp;
    for(i = len; i>0;i--)
    {
        for(j = 0; j < i; j++)
        {
            if(tab1[j] > tab1[j+1])
            {
                temp = tab1[j];
                tab1[j] = tab1[j+1];
                tab1[j+1] = temp;
            }
        }
    }
}
