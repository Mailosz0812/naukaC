#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
/*
typedef struct
{
    int value;
    struct Lifo *next;
} Lifo;
void push(Lifo **stack, int item);
Lifo *create(void);
bool is_empty(Lifo *stack);
int main()
{
    int tab[] = {1,2,3,4,5,6},item;
    Lifo *myStack = create();
    for(int i = 0; i < 6; i++)
    {
        item  = tab[i];
        push(&myStack,item);
    }
    while(myStack->next != NULL)
    {
        printf("%d",myStack->value);
        myStack = myStack->next;
    }
}
Lifo *create(void)
{
    Lifo *stack = malloc(sizeof(Lifo));
    stack->next = NULL;
    return stack;
}
bool is_empty(Lifo *stack)
{
    return (stack->value == NULL);
}

void push(Lifo **stack, int item)
{
    Lifo *newNode = malloc(sizeof(Lifo));
    newNode->value = item;
    newNode->next = *stack;
    *stack = newNode;
}


typedef struct krotka
{
    int x,y;
    struct krotka *next;

} krotka;
krotka *newkrotka(krotka *prev,int x,int y);
int main()
{
    int rx[]={1,2,3,4,5};
    int ry[]={1,2,3,4,5};
    krotka *head = NULL;
    head = newkrotka(head,rx[0],ry[0]);
    krotka *last = newkrotka(head,rx[1],ry[1]);
    for(int i = 2; i < 5; i++)
    {
        last = newkrotka(last,rx[i],ry[i]);
    }
    krotka *current = head;
    while(current!=NULL)
    {
        printf("x: %d, y: %d",current->x,current->y);
        current = current->next;
    }
}
krotka *newkrotka(krotka *prev,int x,int y)
{
    krotka *list_next;
    list_next = malloc(sizeof(krotka));
    list_next->x = x;
    list_next->y = y;
    list_next->next = NULL;
    if(prev != NULL)
    {
        prev->next = list_next;
    }
    return list_next;
}

typedef struct element {
    int dane;
    struct element *nast;
} element;
element *new_Element(element *previous, int dane);
element *add_item(element *queue);
element *switch_item(element *queue);
element *usunparzyste(element *queue);
int main()
{
    srand(time(NULL));
    int tab1[5];

    for(int i = 0; i < 5; i++)
    {
        tab1[i] = (rand()%10) + 1;

    }
    element *head = NULL,*last;
    head = new_Element(head,tab1[0]);
    last = new_Element(head,tab1[1]);
    for(int i = 2; i < 5; i++)
    {
        last = new_Element(last,tab1[i]);
    }
    printqueue(head);
    //int size = sizeoflist(head);
    //printf("%d",size);
    //int last1 = lastitem(head);
    //printf("%d",last1);
    //int usuniety = usundrugi(head);
    //printf("\n%d",usuniety);
    add_item(head);
    printqueue(head);
    switch_item(head);
    printqueue(head);
    usunparzyste(head);
    printqueue(head);
    return 0;

}
element *new_Element(element *previous, int dane)
{
    element *list_new = malloc(sizeof(element));
    list_new->nast = NULL;
    list_new->dane = dane;
    if(previous != NULL)
    {
        previous->nast = list_new;
    }
    return list_new;
}
void printqueue(element *queue)
{
    element *current = queue;
    while(current != NULL)
    {
        printf("%d \n",current->dane);
        current = current->nast;
    }
    printf("\n");
}
int sizeoflist(element *queue)
{
    int size = 0;
    element *current = queue;
    while(current != NULL)
    {
        current = current->nast;
        size++;
    }

    return size;
}
int lastitem(element *queue)
{
    element *current = queue;
    int last = 0;
    while(current != NULL)
    {
        last = current->dane;
        current = current->nast;
    }
    return last;
}
int usundrugi(element *queue)
{
    element *tmp;
    tmp = queue->nast;
    int usuniety = tmp->dane;
    queue->nast = tmp->nast;
    free(tmp);
    return usuniety;
}
element *add_item(element *queue)
{
    int randitem = (rand()%10) +1;
    element *tmp;
    tmp = queue->nast;
    element *newelement = new_Element(queue,randitem);
    newelement->nast = tmp;
    return queue;
}
element *switch_item(element *queue)
{
    int danetmp = queue->dane;
    element *tmp = queue->nast;
    queue->dane = tmp->dane;
    tmp->dane = danetmp;
    return queue;
}
element *usunparzyste(element *queue)
{
    element *current = queue;
    element *tmp;
    while(queue != NULL && queue->dane %2 == 0)
    {
       tmp = queue;
        queue = queue->nast;
        free(tmp);
    }
    while (current != NULL && current->nast != NULL) {
        if (current->nast->dane % 2 == 0) {
            tmp = current->nast;
            current->nast = tmp->nast;
            free(tmp);
        } else {
            current = current->nast;
        }
    }
    return queue;
}






typedef struct element {
    int liczba;
    struct element *nast;
} element;
element *create(int n);
void average(element *head,int *srednia);
void printstack(element *head);
bool checkValue(element *head,int value);
element *switchElement(element *head,int value);
element *addNew(element *head,int value);
void recursiveprintqueue(element *head);
void sizeofstack(element *head,int *i);
element *addInside(element *head,int value);
element *create_another(element *head);
element *reverseList(element *head);
int main()
{
    int srednia=0,ilosc=0,liczba = 11;
    bool isnumber;
    element *head = create(5),*head2;
    printstack(head);
    head = reverseList(head);
    printstack(head);
    sorting_list(head);
    printf("\n");
    printstack(head);
    //average(head,&srednia);
    //printf("\n%d",srednia);

    isnumber = checkValue(head,7);
    if(isnumber)
    {
        head = switchElement(head,8);
    }
    else
    {
        head = addNew(head,6);
    }
    element *temp = head;
    recursiveprintqueue(temp);
    //sizeofstack(temp,&ilosc);
    //printf("\nLiczba elementow listy: %d",ilosc);
    head = addInside(head,liczba);
    printstack(head);
    head2 = create_another(head);
    printf("\n Liczby parzyste");
    recursiveprintqueue(head2);
    return 0;

}
element *addNew(element *head,int value)
{
    element *newElement = malloc(sizeof(element));
    newElement->liczba = value;
    newElement->nast = head;
    return newElement;
}
element *create(int n)
{
    element *temp;
    element *head = NULL,*tail;
    srand(time(NULL));
    int liczba;
    for(int i = 0; i < n; i++)
    {
        liczba = (rand()%10)+1;
        if(i == 0)
        {
            head = addNew(head,liczba);
            tail = head;
        }
        else
        {
            head = addNew(head,liczba);
        }

    }
    return head;
}
void printstack(element *head)
{
    int i = 0;
    element *current = head;
    while(current != NULL)
    {
        printf("\nLiczba: %d",current->liczba);
        current = current->nast;
    }
}
void average(element *head,int *srednia)
{
    element *current = head;
    int licz=0;
    while(current != NULL)
    {
        (*srednia)+=current->liczba;
        licz++;
        current=current->nast;
    }
    *srednia=(*srednia)/licz;
}
bool checkValue(element *head,int value)
{
    element *current = head;
    while(current != NULL)
    {
        if(current->liczba == value)
        {
            return true;
        }
        current = current->nast;

    }
    return false;
}
bool destroyStack(element *head)
{
    element *current = head,*temp;
    while(current != NULL)
    {
        temp = current;
        current = current->nast;
        free(temp);
    }
    return 0;
}
bool isempty(element *head)
{
    return head == NULL;
}
element *switchElement(element *head,int value)
{
    element *current = head,*temp=head,*temp1=NULL;
    int licz=1;
    while(current != NULL)
    {
        if(current->liczba == value)
        {
            if(licz == 1)
            {
                return head;
            }
            else if(licz == 2)
            {
                head->nast = current->nast;
                current->nast = head;
                return current;
            }
            temp1 = head->nast;
            temp->nast = head;
            head->nast = current->nast;
            current->nast = temp1;
                return current;
        }
        temp = current;
        current = current->nast;
        licz++;
    }
    return head;
}
void recursiveprintqueue(element *head)
{
    if(head != NULL)
    {
        printf("\nliczba:%d",head->liczba);
        head = head->nast;
        recursiveprintqueue(head);
    }
}
void sizeofstack(element *head,int *i)
{
    if(head != NULL)
    {
        (*i)++;
        head = head->nast;
        sizeofstack(head,i);
    }
}
element *addInside(element *head,int value)
{
    element *current = head,*temp = NULL,*newElement;
    while(current != NULL)
    {
        if(current->liczba > value)
        {
            if(temp == NULL)
            {
                head = addNew(head,value);
                return head;
            }
            else
            {
                newElement = addNew(temp->nast,value);
                temp->nast = newElement;
                return head;
            }

        }
        temp = current;
        current = current->nast;
    }
    if(temp != NULL)
    {
        temp->nast = addNew(NULL, value);
    }
    return head;
}
element *create_another(element *head)
{
    element *current = head,*newElement = NULL;
    while(current != NULL)
    {
        if(current->liczba % 2 == 0)
        {
            newElement = addNew(newElement,current->liczba);
        }
        current = current->nast;
    }
    return newElement;
}
element *reverseList(element *head)
{
    element *temp=NULL,*current = head,*temp1;
    while(current != NULL)
    {
        temp1 = current->nast;
        current->nast = temp;
        temp = current;
        current = temp1;
    }
    return temp;
}
void sorting_list(element *head)
{
    element *end,*p,*q;
    int temp;
    for(end = NULL; end!=head->nast; end=p)
    {
        for(p=head; p->nast!=end; p=p->nast)
        {
            q = p->nast;
            if(p->liczba > q->liczba)
            {
                temp = p->liczba;
                p->liczba = q->liczba;
                q->liczba = temp;
            }
        }
    }
}

typedef struct osoba
{
    char nazwisko[41],imie[21];
    char obecny;
    struct osoba *nast;
} osoba;
osoba *addNode(osoba *head,char *nazwisko,char *imie,char obecny);
int main()
{
    osoba *head = NULL,*last;
    int i = 1;
    char next,nazwisko[100],imie[40],obecnytemp[10],obecny;
    do
    {

        printf("Podaj imie osoby: ");
        scanf("%s",imie);
        while(strlen(imie) > 20)
        {
            printf("Podaj imie w prawidlowym formacie: ");
            scanf("%s",imie);
        }
        printf("Podaj nazwisko: ");
        scanf("%s",nazwisko);
        while(strlen(nazwisko) > 40)
        {
            printf("Podaj nazwisko w prawidlowym formacie: ");
            scanf("%s",nazwisko);
        }
        while(strlen(obecnytemp) > 2 || obecnytemp[0] != 'T' && obecnytemp[0] != 'N')
        {
            printf("Pole obecny przyjmuje tylko wartosci T i N: ");
            scanf("%s",obecnytemp);
        }
        printf("%d",strlen(imie));
        printf("%d",strlen(nazwisko));
        imie[strlen(imie)] = '\0';
        nazwisko[strlen(nazwisko)] = '\0';
        obecny = obecnytemp[0];
        if(i == 1)
        {
            head = addNode(head,nazwisko,imie,obecny);
        }
        else if(i == 2)
        {
            last = addNode(head,nazwisko,imie,obecny);
        }
        else
        {
            last = addNode(last,nazwisko,imie,obecny);
        }
        printf("Czy chcesz podac kolejna osobe?(T/n)");
        scanf(" %c",&next);
        ++i;
    }while(next == 'T');
}
osoba *addNode(osoba *head,char *nazwisko,char *imie,char obecny)
{
    osoba *newNode = malloc(sizeof(osoba));
    if(newNode == NULL)
    {
        printf("Memory allocation failed");
        return 1;
    }
    if(head == NULL)
    {
        strncpy(newNode->nazwisko,nazwisko,sizeof(newNode->nazwisko));
        strncpy(newNode->imie,imie,sizeof(newNode->imie));
        newNode->obecny = obecny;
        newNode->nast = NULL;
        return newNode;
    }
    strncpy(newNode->nazwisko,nazwisko,sizeof(newNode->nazwisko));
    strncpy(newNode->imie,imie,sizeof(newNode->imie));
    newNode->obecny = obecny;
    newNode->nast = NULL;
    head->nast = newNode;
    return newNode;

}
void saveintoFile(osoba *head,char *nazwa)
{
    FILE *newFile;
    newFile = fopen(nazwa,"w");
    if(newFile == NULL)
    {
        printf("Otwieranie pliku nie powiodlo sie");
    }
    osoba *current = head;
    while(current != NULL)
    {
        fprintf(newFile,"%s %s %c \n",current->nazwisko,current->imie,current->obecny);
        current = current->nast;
    }
}
*/

typedef struct node
{
    int liczba;
    struct node *next;
}node;
node *createNode(node *head,int value);
node *printNode(node *head);
node *parzyste(node *head);
node *reverseList(node *head);
int main()
{
    int randomValue;
    node *head = NULL,*tail,*newHead;
    srand(time(NULL));
    for(int i = 0; i < 10; i++)
    {
        randomValue = (rand()%10)+1;
        if(i == 0)
        {
            head = createNode(head,randomValue);
        }
        else if(i == 1)
        {
            tail = createNode(head,randomValue);
        }
        else
        {
            tail = createNode(tail,randomValue);
        }
    }
    //printNode(head);
    newHead = parzyste(head);
    printNode(newHead);
    printf("\n");
    newHead = reverseList(newHead);
    printNode(newHead);
    return 0;

}
node *createNode(node *head,int value)
{
    node *newNode = malloc(sizeof(node));
    newNode->liczba = value;
    newNode->next = NULL;
    if(head != NULL)
    {
        head->next = newNode;
    }

    return newNode;
}
node *printNode(node *head)
{
    node *current=head;
    while(current != NULL)
    {
        printf("%d \n",current->liczba);
        current = current->next;
    }
}
node *parzyste(node *head)
{
    node *current=head,*newHead=NULL,*newTail;
    int i = 0,value = 0;
    while(current != NULL)
    {
        if(current->liczba %2 == 0)
        {
            ++i;
            value = current->liczba;
            if(i == 1)
            {
                newHead = createNode(newHead,value);
            }
            else if(i == 2)
            {
                newTail = createNode(newHead,value);
            }
            else
            {
                newTail = createNode(newTail,value);
            }
        }
        current = current->next;
    }
    return newHead;
}
//Napisz funkcję, która odwróci kolejność elementów listy. Np. dla listy 2->3->5->1 zostanie zwrócone 1->5->3->2.
node *reverseList(node *head)
{
    node *temp=NULL,*current = head,*temp1;
    while(current != NULL)
    {
        temp1 = current->next;
        current->next = temp;
        temp = current;
        current = temp1;
    }
    return temp;
}
//Napisz funkcję, która na podstawie dwóch list utworzy jedną, wstawiając na przemian elementy pierwszej i drugiej listy.
//Funkcja nie powinna "gubić" elementów, nawet jeśli długości list nie są identyczne.
//Np. jeśli jedna lista to 2->4->6, a druga to 1->5->3->9->7, to zostanie utworzona lista wynikowa: 2->1->4->5->6->3->9->7.
/*node *oneList(node *head,node *head2)
{
    node *newhead = NULL,*current1 = head,*current2 = head2,*tail;
    int i = 0,value = 0;
    while(current1 != NULL)
    {
        if(i == 0)
        {
            newhead = createNode(newhead,current->liczba);
        }
        else if(i == 1)
        {
            tail = createNode(newhead,current->liczba);
        }
        else
        {
            tail = createNode(tail,current->liczba);
        }
    }

    while(current2 != NULL)
    {

    }
}

*/
