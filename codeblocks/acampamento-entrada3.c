#include <stdio.h>
#include <stdlib.h>

int main()
{
    char vparte
    printf("no acampamento ao chegar um guerreiro de grande estatura se apresenta este lhe diz que foi ordenado a treinar sua constituicao");
    printf("me diga garoto qual a parte mais importamte de se defender durante um combate");
    printf("A - bracos \n B - pernas \n C - torco \n D - cabeca ");
    scanf("%s",&vparte)
    //rolar dados
    if(vparte == ('A' || 'a')){
       printf("os bracos sao importantes para manter suas armas em mao mas esta nao e a resposta");
       //decrementa 1 vida
    }else if(vparte == ('B' || 'b')){
       printf("as pernas devense manter firmes no chao para que seu oponente nao ganhe uma vantagem porem nao sao o mais importante");
       //decrementa 1 vida
    }else if(vparte == ('C' || 'c')){
       printf(" o  torco e uma parte que deve ser muito protegida para nao ocorrer grandes ferimentos, porem errado");
       //decrementa 1 vida
    }else if(vparte == ('D' || 'd')){
       printf("correto sua cabeca e o menbro do seu corpo que voce deve mais proteger se voce esquecer disso voce esta fadado a derrota");
       //incrementa 2 vida
    }else
        printf("escolhauma das alternativas");
        //volta alternativas
    return 0;
}
