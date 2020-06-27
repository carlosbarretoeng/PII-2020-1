#include <stdio.h>
#include <stdlib.h>

int main()
{
    char vpeso;
    printf("no acampamento voce se apresenta prontamente ao capitao o qual logo em seguida ja comecaum treinamento para melhorar sua forca.");
    printf("garoto pegue a melhor arma para voce treinar dentro do estoque ");
    printf("A - espada \n B - adaga \n C - lanca \n D - grande martelo de gurra");
    scanf("%s", &vpeso);
    //rolar dados
    if(vpeso == ('A' || 'a')){
        printf("esta arma e muito leve treinar comela nao vai te ajudar muito em seu fisico");
        //decrementa 1 forca
    }else if(vpeso == ('B' || 'b')){
        printf("uma adaga serio se continuar a treinar com armas leves assim voce nunca ficara forte");
        //decrementa 2 forca
    }else if(vpeso == ('C' || 'c')){
        printf("uma lanca boa arma mas ainda assim falta algo de forca");
        //incrementa 1 forca
    }else if(vpeso == ('D' || 'd')){
        printf("excelente escolha garoto vejo que sera um grande guerreiro no fulturo");
        //incrementa 2 forca
    }else
        printf("escolhauma das alternativas");
        //volta alternativas
    return 0;
}
