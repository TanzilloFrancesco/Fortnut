#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct personaggio{
    int Hp;
    int Strenght;
};

typedef struct personaggio P;
P Combattimento(P Attaccante,P Difensore);

int main(){
    srand(time(NULL));
    P Eroe = {100, 1 + rand()%40}, Nemico = {100, 1 + rand()%25};
printf("\nVita iniziale nemico = %d\n\nVita iniziale eroe = %d\n", Nemico.Hp, Eroe.Hp);
printf("\nInizio Combattimento\n");
do{
Nemico = Combattimento(Eroe, Nemico);
Eroe = Combattimento(Nemico, Eroe);
if(Nemico.Hp <= 0){
    printf("\n\nNemico morto!!! Vittoria dell'Eroe\n");
}else{
    if(Eroe.Hp <= 0){
        printf("\n\nEroe morto!!! Vittoria del Nemico\n");
    }else{
        printf("\nDanno inflitto al nemico = %d\nVita nemico = %d\nDanno inflitto all'Eroe = %d\nVita eroe = %d",Eroe.Strenght, Nemico.Hp,Nemico.Strenght, Eroe.Hp);
    }
}
}while(Eroe.Hp>0 && Nemico.Hp>0);
return 0;

}
P Combattimento(P Attaccante,P Difensore){
    Difensore.Hp = Difensore.Hp - Attaccante.Strenght;
    return Difensore;
}
