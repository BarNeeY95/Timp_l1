#include "stdafx.h"

struct List
{
    unsigned _int8 N;
    List *pNext, *pPred;
};

void add(List *&pF, List *p, bool first)
{
    if (pF == 0)
    {
        pF = p->pNext = p->pPred = p;
        return;
    }
    p->pNext = pF;
    p->pPred = pF->pPred;
    pF->pPred->pNext = p;
    pF->pPred = p;
    if (first) pF = p;
}

void print(List *pF)
{
    List *p = pF;
    do
    {
        printf("\n%d", p->N);
        p = p->pNext;
    } while (p != pF);
}

void addInList(List *pZad, List *p)
{
    p->pPred = pZad;
    p->pNext = pZad->pNext;
    pZad->pNext->pPred = p;
    pZad->pNext = p;
}

List *remove(List *&pF, List *p)
{
    if (pF == 0) return 0;
    if (pF->pNext == pF)
    {
        if (p == pF)
        {
            pF = 0;
            return p;
        }
        else return 0;
    }
    if (p == pF)
        pF = pF->pNext;
    p->pPred->pNext = p->pNext;
    p->pNext->pPred = p->pPred;
    return p;
}

int _tmain(int argc, _TCHAR* argv[])
{
    List *pF = 0, *p;
    int n;
    printf("Vvedite kol-vo elementov: ");
    fflush(stdin);
    scanf_s("%d", &n);
    for (int i = 0; i < n; i++)
    {
        p = new List;
        printf("\nChiclo No.%d: ", i + 1);
        fflush(stdin);
        scanf_s("%d", &p->N);
        add(pF, p, false);
    }
    printf("\n----- Sortirovki: -----");
    print(pF);
    if (pF == pF->pNext)
    {
        printf("\n\nOtsortirovan!!");
        printf("\n");
        system("pause");
        return 100;
    }
    
    // —ортировка
    while (1)
    {
        bool zamena = false;
        List *p1 = pF, *p2 = pF->pNext;
        do
        {
            if (p1->N > p2->N)
            {
                p1 = remove(pF, p1);
                if (p1 == 0)
                {
                    printf("List Error!!!!");
                    printf("\n");
                    system("pause");
                    return 0;
                }
                addInList(p2, p1); 
                p2 = p1->pNext;
                zamena = true; 
            }
            else 
            {
                p1 = p2;
                p2 = p2->pNext;
            }
        } while (p2 != pF);
        if (!zamena) 
            break;
    }
    //  end
    
    printf("\n----- Posle sortirovki: -----");
    print(pF);
    
    printf("\n");
    system("pause");
    
    return 0;
}
