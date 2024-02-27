#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define buffer_size 100
typedef struct krotka
{
    int x;
    int y;
    struct krotka *next;
} krotka;

char **rozmiary(int *x,int *y);
char **wypelnij_labirynt(char **buffer,char *wiersz_buffer,int *x,int *y);
bool walidacja(int *lenght,int *y,char *wiersz_buffer);
void *licz(char **buffer,int *x,int *y,bool *licznik);
bool walidacja_plik(int *lenght,int *y,char *wiersz_buffer1);
char **zpliku(int *x,int *len);
char **dodaj_sciany(char **labirynt,int *x, int *y);
char *rozwiazanie_labirynt(char **labirynt, int *x, int *y);
bool sprdroge(char c);
bool solve_maze(char **labirynt,int x,int y,char **solution);
krotka *wyswietlRozwiazanie(char **labirynt,int xpos,int ypos);
krotka *create_element(krotka *previous,int x,int y);
char *sekwencja(krotka *head);
void usunListe(krotka *head);
krotka printqueue(krotka *head);

int main()
{
    int x=0,y=0;
    int opcja = 0,koniec=2;
    char **labirynt,**labirynt_sciany,*ciag;
    do
    {
        x=0;
        y=0;
        opcja=0;
        koniec=2;
        printf("\nInstrukcja wprowadzania labiryntu:");
        printf("\nJedyne dozwolone znaki to: #-znak sciany, . -znak drogi, $-punkt startu, @-punkt docelowy\n");
        printf("------------------------------------------------------------------------------------------\n");
        printf("\nPrzykladowy wyglad labiryntu\n");
        printf("#$.####\n##..###\n###.###\n##..###\n#@.####\n");
        printf("Co chcesz robic. \nOpcja 1: Wpisac rozmiar i obraz labiryntu z klawiatury \nOpcja 2: Wczytac obraz labiryntu z pliku  ");
        printf("\nWybor: ");
        scanf("%d",&opcja);
        while(opcja != 1 && opcja != 2)
        {
            printf("\nPodaj prawidlowa opcje: ");
            scanf("%d",&opcja);
        }
        if(opcja== 1)
        {
            labirynt = rozmiary(&x,&y);
            printf("Wpisany labirynt \n");
            for(int i = 0; i < x; i++)
            {
                printf("%s \n",labirynt[i]);

            }
        }
        else if(opcja == 2)
        {
            labirynt = zpliku(&x,&y);
            printf("Twoj labirynt wczytany z pliku\n");
            for(int i = 0; i < x ; i++)
            {
                printf("%s \n",labirynt[i]);

            }
        }
        labirynt_sciany = dodaj_sciany(labirynt,&x,&y);
        ciag = rozwiazanie_labirynt(labirynt_sciany,&x,&y);
        if(ciag != NULL)
        {
            int dlugosc = strlen(ciag);
            for(int i = 0; i < dlugosc; i++)
            {
                printf("%c ",ciag[i]);
            }
        }
        else
        {
            printf("Labirynt nie ma rozwiazania.");
        }
        for(int i = 0; i < x; i++)
        {
        free(labirynt_sciany[i]);
        }
        free(labirynt_sciany);
        free(ciag);
        printf("\nCzy chcesz wprowadzic labirynt jeszcze raz? (1-Tak,2-Nie)");
        scanf("%d",&koniec);
        while(koniec != 1 && koniec != 2)
        {
            printf("Wprowadz poprawna opcje (1-Tak,2-Nie): ");
            scanf("%d",&koniec);
        }
        if(koniec == 1)
        {
            system("cls");
        }

    }while(koniec==1);
    return 0;
}
char **rozmiary(int *x,int *y)
{
    printf("Podaj rozmiar X labiryntu\n");
    scanf("%d", x);
    while((*x) <= 1)
    {
        printf("Podaj prawdilowa wartosc rozmiaru X: ");
        scanf("%d", x);
    }
    printf("Podaj rozmiar Y labiryntu\n");
    scanf("%d", y);
    while((*y) <= 0 )
    {
        if((*y) == 0)
        {
            printf("Podaj niezerową wartosc rozmiaru Y: ");
            scanf("%d", y);
        }
        else if((*y) < 0)
        {
            printf("Podaj prawdilowa wartosc rozmiaru Y: ");
            scanf("%d", y);
        }
    }
    char **buffer,**labirynt;
    char wiersz_buffer[buffer_size];
    buffer = malloc((*x) * sizeof(char*));
    if(buffer == NULL)
    {
        printf("Pamiec nie zostala zaalokowana");
        return NULL;
    }
    labirynt = wypelnij_labirynt(buffer,wiersz_buffer,x,y);
    return labirynt;
}
bool walidacja(int *lenght,int *y,char *wiersz_buffer)
{
    if((*lenght) != (*y+1))
    {
        return true;
    }
    for(int i = 0;i < (*y); i++)
    {
        if(wiersz_buffer[i] != '#' && wiersz_buffer[i] != '.' && wiersz_buffer[i] != '$' && wiersz_buffer[i] != '@')
        {
            return true;
        }
    }
    return false;

}
void *licz(char **buffer,int *x,int *y,bool *licznik)
{
    int liczkoniec=0,liczstart=0;
    for(int i = 0; i < (*x); i++)
    {
        for(int j = 0; j < (*y); j++)
        {

            if(buffer[i][j] == '$')
            {
                liczstart++;
            }
            else if(buffer[i][j] == '@')
            {
                liczkoniec++;
            }
        }

    }
    *licznik = (liczkoniec != 1 || liczstart != 1);

}
char **wypelnij_labirynt(char **buffer,char *wiersz_buffer,int *x,int *y)
{

    int lenght;
    bool licznik=false;
    do
        {
            while(getchar() != '\n');
            printf("\n");
                for(int i = 0; i < (*x); i++)
                {
                    printf("Wprowadz wyglad %d wiersza labiryntu: ",i+1);
                    fgets(wiersz_buffer,buffer_size,stdin);
                    lenght = strlen(wiersz_buffer);
                    while(walidacja(&lenght,y,wiersz_buffer))
                    {
                        printf("Wprowadz poprawny wyglad %d wiersza labiryntu: ",i+1);
                        fgets(wiersz_buffer,buffer_size,stdin);
                        lenght = strlen(wiersz_buffer);
                    }
                    wiersz_buffer[lenght-1] = '\0';
                    buffer[i] = malloc((*y+1) * sizeof(char));
                    strcpy(buffer[i],wiersz_buffer);
                }
                licz(buffer,x,y,&licznik);
                if(licznik)
                {
                    printf("Ilosc koncow i poczatkow labiryntu musi byc rowna jeden (kliknij enter aby wprowadzic ponownie)");
                }
        }while(licznik);
    return buffer;
}
bool walidacja_plik(int *length, int *y, char *wiersz_buffer1)
{
    if ((*length) != (*y))
    {
        return true;
    }

    for (int j = 0; j < (*y); j++)
    {
        if (wiersz_buffer1[j] != '#' && wiersz_buffer1[j] != '.' && wiersz_buffer1[j] != '$' && wiersz_buffer1[j] != '@')
        {
            return true;
        }
    }

    return false;
}
char **zpliku(int *z, int *len)
{
    FILE *plik;
    char nazwa[buffer_size],c;
    char **buffer;
    int y=0,lenght;
    bool valid = false , notalpha = false;
    do
    {
        buffer = malloc(sizeof(char*));
        buffer[0] = malloc(sizeof(char));
        valid = false;
        do
        {
            notalpha = false;
            printf("Podaj nazwe pliku z wraz z jego rozszerzeniem: ");
            scanf("%s",nazwa);
            lenght = strlen(nazwa);
            for(int i = 0; i < lenght; i++)
            {
                if((nazwa[i] < 'A' || nazwa[i] > 'Z') && (nazwa[i] < 'a' || nazwa[i] > 'z') && nazwa[i] != '.')
                {
                    notalpha = true;

                }
            }

        }while(notalpha);
        plik = fopen(nazwa,"r");
        if(plik == NULL)
        {
            printf("Nie udalo sie otworzyc pliku");
            return NULL;
        }
        do
        {
            c = fgetc(plik);
            if(c == '\n')
            {
                buffer[(*z)][y] = '\0';
                (*z)++;
                y = 0;
                buffer = realloc(buffer,(*z+1) * sizeof(char*));
                buffer[(*z)] = malloc(sizeof(char));

            }
            else
            {
                buffer[(*z)] = realloc(buffer[(*z)],(y+2) * sizeof(char));
                buffer[(*z)][y] = c;
                y++;
            }
             if(feof(plik))
            {
                break;
            }

        }while(true);
        y  = strlen(buffer[*z])-1;
        for(int i = 0; i < *z; i++)
        {
            lenght = strlen(buffer[i]);
            if(walidacja_plik(&lenght,&y,buffer[i]))
            {
                valid = true;
                break;
            }
        }

        ++(*z);
        licz(buffer,z,&lenght,&valid);
        if(valid)
        {
            printf("Ilosc koncow i poczatkow labiryntu musi byc rowna jeden \n");
            for (int i = 0; i < *z; i++)
            {
                free(buffer[i]);
            }
            free(buffer);
            *z = 0;
             y = 0;
        }
        fclose(plik);
    }while(valid);

    *len = lenght;
    return buffer;
}
char **dodaj_sciany(char **labirynt,int *x, int *y)
{
    int rx = (*x)+ 2, ry = (*y)+ 2;
    char **labirynt_sciany = malloc(rx * sizeof(char*));
    for(int i = 0; i < rx; i++)
    {
        labirynt_sciany[i] = malloc(ry * sizeof(char));
    }
    if(labirynt_sciany == NULL)
    {
        printf("Pamiec nie zostala zaalokowana");
        return NULL;
    }
    for(int i = 0; i < rx; i++)
    {
        for(int j = 0; j < ry; j++)
            {
                labirynt_sciany[i][j] = '#';
            }
    }
    for(int i = 1; i <= *x; i++)
    {
        for(int j = 1; j <= *y; j++)
            {
                labirynt_sciany[i][j] = labirynt[i-1][j-1];
            }
    }
    for(int i = 0; i < *x; i++)
    {
        free(labirynt[i]);
    }
    free(labirynt);
    *x = rx;
    *y = ry;

    return labirynt_sciany;
}
bool sprdroge(char c)
{
    return (c == '.'|| c == '$'||c == '@');
}

char *rozwiazanie_labirynt(char **labirynt1, int *x, int *y)
{
    int xpos=0,ypos=0,xendpos=0,yendpos=0;
    char **solution;
    char *ciag;
    solution = malloc((*x) * sizeof(char*));
    krotka *head;
   for(int i = 0; i < (*x); i++)
    {
        solution[i] = malloc((*y) * sizeof(char));
    }
     for(int i = 0; i < (*x); i++)
    {
        for(int j = 0; j < (*y); j++)
            {
                solution[i][j] = '#';
            }
    }
    for(int i = 0; i < (*x); i++)
    {
        for(int j = 0; j < (*y); j++)
        {
            if(labirynt1[i][j] == '$')
            {
                xpos = i;
                ypos = j;
                break;
            }
            else if(labirynt1[i][j] == '@')
            {
                xendpos = i;
                yendpos = j;
            }
        }

    }
    if(solve_maze(labirynt1,xpos,ypos,solution))
    {
        solution[xpos][ypos] = '$';
        solution[xendpos][yendpos] = '@';
        printf("\nDroga do celu: \n");
        for(int i = 0; i < (*x); i++)
        {
            for(int j = 0; j <(*y); j++)
            {
                printf("%c",solution[i][j]);
            }
            printf("\n");
        }
        head = wyswietlRozwiazanie(solution,xpos,ypos);
        ciag = sekwencja(head);
        return ciag;
    }
    else
    {
        return NULL;
    }

}
bool solve_maze(char **labirynt,int xpos,int ypos,char **solution)
{
    if(labirynt[xpos][ypos] == '@')
    {
        return true;
    }
    if(sprdroge(labirynt[xpos][ypos]))
    {
        solution[xpos][ypos] = '.';
        labirynt[xpos][ypos] = '#';
        if(solve_maze(labirynt,xpos+1,ypos,solution)
           ||solve_maze(labirynt,xpos,ypos+1,solution)
           ||solve_maze(labirynt,xpos-1,ypos,solution)
           ||solve_maze(labirynt,xpos,ypos-1,solution))
           {
               return true;
           }
           else
           {
               solution[xpos][ypos] = '#';
               labirynt[xpos][ypos] = '.';
           }
    }
    return false;
}
krotka *wyswietlRozwiazanie(char **labirynt,int xpos,int ypos)
{
    krotka *last,*head;
    int i = 0;
    head = create_element(NULL,xpos,ypos);
    while(labirynt[xpos][ypos] != '@')
    {
        i++;
        labirynt[xpos][ypos] = '#';
         if (sprdroge(labirynt[xpos+1][ypos]))
         {
             ++xpos;
         }
         else if (sprdroge(labirynt[xpos][ypos+1]))
         {
             ++ypos;
         }
         else if (sprdroge(labirynt[xpos-1][ypos]))
         {
            --xpos;
         }
         else if (sprdroge(labirynt[xpos][ypos-1]))
         {
            --ypos;
         }
         else
         {
            labirynt[xpos][ypos] = '.';
         }
         if(i == 1)
         {
            last = create_element(head,xpos,ypos);
         }
         else
         {
            last = create_element(last,xpos,ypos);
         }
    }
    return head;
}
krotka *create_element(krotka *previous,int x,int y)
{
    krotka *list = malloc(sizeof(krotka));
    list->x = x;
    list->y = y;
    list->next = NULL;
    if(previous != NULL)
    {
        previous->next = list;
    }
    return list;
}
char *sekwencja(krotka *head)
{
    krotka *current = head;
    krotka *nextNode = current->next;
    char *ciag = malloc(2 * sizeof(char));
    ciag[0] = 'S';
    int i = 2;
    while(current->next != NULL)
    {

        if(current->x < nextNode->x)
        {
            ciag[i-1] = 'D';

        }
        else if(current->x > nextNode->x)
        {
            ciag[i-1] = 'G';

        }
        else if(current->y < nextNode->y)
        {
            ciag[i-1] = 'P';
        }
        else if(current->y > nextNode->y)
        {
            ciag[i-1] = 'L';
        }
        ciag = realloc(ciag, (i + 1) * sizeof(char));
        current = nextNode;
        nextNode = current->next;
        i++;

    }
    ciag[i-1] = 'K';
    ciag[i] = '\0';
    usunListe(head);
    return ciag;
}
void usunListe(krotka *head)
{
    krotka *temp;
    while(head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}
