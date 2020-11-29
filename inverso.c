#include <stdio.h>

void tabelinha(int aa, int bb, int quo[], int vlinear[], int i, int k, int j)
{
    if(j == k)
    {
        if(j % 2 == 0)
        {
            vlinear[j] = vlinear[j] * -1;
        }
        else
        {
            vlinear[j - 1] = vlinear[j - 1] * -1;
        }

        if(k == 0)
        {
            if(aa > bb)
            {
                printf("O inverso eh: 0\n");
            }
            else
            {
                printf("O inverso eh: 1\n");
            }
        }
        else
        {
            printf("O inverso eh: %d\n", vlinear[j - 1]);
        }
        
        return;
    }

    if(j == 0)
    {
        vlinear[j] = quo[i] * 1;
    }
    else if(j == 1)
    {
        vlinear[j] = (quo[i] * vlinear[j - 1]) + 1;
    }
    else
    {
        vlinear[j] = (quo[i] * vlinear[j - 1]) + vlinear[j - 2];
    }

    i--;
    j++;
    tabelinha(aa, bb, quo, vlinear, i, k, j);
}

int calcular_mdc(int a, int b, int aa, int bb, int quo[], int i)
{
    int resto;

    quo[i] = a / b;

    if(a % b == 0)
    {
        if(b == 1)
        {
            int vlinear[i];
            
            tabelinha(aa, bb, quo, vlinear, i-1, i-1, 0);
            
            return 1;
        }
        else
        {
            return 0;
        }
    }
    
    resto = a % b; 

    i++;
    return calcular_mdc(b, resto, aa, bb, quo, i);
}

int main()
{
    int aux, a, b, aa, bb, mdc;

    printf("Digite dois valores a e b: ");
    scanf("%d %d", &a, &b);

    int quo[a];
    
    aa = a;
    bb = b;

    if(a == 1 && b == 1)
    {
        printf("nao ha inverso para %d mod %d\n", a, b);

        return 0;
    }

    if(b == 1)
    {
        if(a > b)
        {
            aux = a;
            a = b;
            b = aux;
        }
    }
    
    mdc = calcular_mdc(a, b, aa, bb, quo, 0);

    if(mdc == 0)
    {
        printf("nao ha inverso para %d mod %d\n", a, b);
    }

    return 0;
}