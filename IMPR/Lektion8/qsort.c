#include <stdio.h>

#define LENGHT 3

int sammenligning(const void *p1, const void *p2);

int main(void)
{

    double priser[LENGHT], rabater[LENGHT];
    int i;
    double samlet_pris = 0, pris_med_rabat = 0;

    printf("indtast priserne på de ønskede varer\n");

    for (i = 0; i < LENGHT; i++)
    {
        scanf(" %lf", &priser[i]);
        scanf("%lf", &rabater[i]);
    }

    qsort(priser, LENGHT, sizeof(double), sammenligning);




    printf("dermed har du følgende priser for dit produkt\n");

    for (i = 0; i < LENGHT; i++)
    {
        printf("%lf\n%lg\n", priser[i], rabater[i]);
        samlet_pris += priser[i];
        pris_med_rabat += (priser[i] * (1 - rabater[i]));
    }

    printf("din samlede pris er %lf og med rabat er det %lf\n", samlet_pris, pris_med_rabat);

    return 0;
}

int sammenligning(const void *p1, const void *p2){ 
    int resultat;

    double *dp1 = (double *) p1;
    double *dp2 = (double *) p2;

    double d1 = *dp1;
    double d2 = *dp2;

    if(d1 < d2){
        resultat = -1;
    }else if (d1 > d2)      
    {
        resultat = 1;
    }else{
        resultat = 0;
    }
    

    return resultat;
}