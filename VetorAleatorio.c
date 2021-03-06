#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int TAM =95000;

// codigos bubblesort
void bubble_sort (int v[], int tamanho)
{
    int i,j;

    for(i=tamanho-1; i>0; i--)
    {
        for(j=0; j<i; j++)
        {
            if(v[j]>v[j+1])
            {
                int temp;
                temp = v[j];
                v[j]= v[j+1];
                v[j+1]=temp;
            }

        }
    }
}

// codigos quicksort
void quick_sort(int v[], int began, int end)
{
    int i,j,temp, pivo;
    i = began;
    j = end-1;
    pivo = v[began];
    while(i<=j)
    {
        while(v[i]<pivo && i<end)i++;
        while(v[j]>pivo && j>began)j--;
        if(i<=j)
        {
            temp = v[i];
            v[i]= v[j];
            v[j] = temp;
            i++;
            j--;
        }
    }
    if(j>began)
        quick_sort(v, began, j+1);
    if(i<end)
        quick_sort(v, i, end);


}

// codigos selectionsort
void selection_sort (int v[])
{
    int i, j,menor,temp;
    for (i=0; i<TAM; i++)
    {
        menor =i;
        for(j=i+1; j<TAM; j++)
        {
            if(v[j]<v[menor])
            {
                menor= j;
            }
        }
        if(v[i]!=v[menor])
        {
            temp = v[menor];
            v[menor] = v[i];
            v[i] = temp;
        }
    }
}

// codigos insertionsort
void insertion_sort (int v[])
{
    int i,j,temp;
    for (i =1; i<TAM; i++)
    {
        temp = v[i];
        j=i-1;
        while (j>=0 && temp<v[j])
        {
            v[j+1]= v[j];
            j--;
        }
        v[j+1]=temp;
    }
}
// codigos mergesort

void merge (int v[], int vecSize);
void merge_sort(int v[], int vecSize)
{
    int mid;
    if(vecSize>1)
    {
        mid = vecSize/2;
        merge_sort(v, mid);
        merge_sort((v+mid), (vecSize-mid));
        merge (v, vecSize);
    }

}

void merge (int v[], int vecSize)
{
    int mid, i,j,k;
    int* temp;
    temp = (int*) malloc(vecSize * sizeof(int));
    if(temp == NULL)
    {
        exit(1);
    }
    mid = vecSize/2;
    i=0;
    j=mid;
    k=0;
    while(i<mid && j<vecSize)
    {
        if(v[i]<v[j])
        {
            temp[k]= v[i];
            ++i;
        }
        else
        {
            temp[k]= v[j];
            ++j;
        }
        ++k;
    }
    if (i == mid)
    {
        while (j < vecSize)
        {
            temp[k] = v[j];
            ++j;
            ++k;
        }
    }
    else
    {
        while (i < mid)
        {
            temp[k] = v[i];
            ++i;
            ++k;
        }
    }
    for(i=0; i<vecSize; i++)
    {
        v[i]= temp[i];
    }
    free(temp);

}

// codigos heapsort
void peneira(int *vet, int raiz, int fundo);

void heapsort(int *vet, int n) {
    int i, tmp;

    for (i = (n / 2); i >= 0; i--) {
        peneira(vet, i, n - 1);
    }

    for (i = n-1; i >= 1; i--) {
        tmp = vet[0];
        vet[0] = vet[i];
        vet[i] = tmp;
        peneira(vet, 0, i-1);
    }
}

void peneira(int *vet, int raiz, int fundo) {
    int pronto, filhoMax, tmp;

    pronto = 0;
    while ((raiz*2 <= fundo) && (!pronto)) {
        if (raiz*2 == fundo) {
            filhoMax = raiz * 2;
        }
        else if (vet[raiz * 2] > vet[raiz * 2 + 1]) {
            filhoMax = raiz * 2;
        }
        else {
            filhoMax = raiz * 2 + 1;
        }

    if (vet[raiz] < vet[filhoMax]) {
        tmp = vet[raiz];
        vet[raiz] = vet[filhoMax];
        vet[filhoMax] = tmp;
        raiz = filhoMax;
    }
    else {
      pronto = 1;
    }
  }
}


int main()
{
    srand(time(NULL));
    double inicio, fim;
    int vetor[TAM];
    for(int i=0; i<TAM; i++)
    {
        vetor[i]= rand() % 10000;
    }

    inicio = (double) clock() / CLOCKS_PER_SEC;
    //bubble_sort(vetor, TAM);
    //selection_sort(vetor);
    //insertion_sort(vetor);
    //merge_sort(vetor, TAM);
    //quick_sort(vetor, 0, TAM);
    //heapsort(vetor, TAM);
    fim = (double) clock() / CLOCKS_PER_SEC;
    printf("tempo: %f", fim-inicio);

    return 0;
}
