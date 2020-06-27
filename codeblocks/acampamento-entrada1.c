#include <stdio.h>
#include <stdlib.h>

int main()
{
    char vgrupo
    printf("Ao chegar no acampamento voce e surpreendido com a presenca de um estrategista ,ele se oferece para treinar voce e assim cria um teste para sua sabedoria.");
    printf("o que e considerado mais vantajoso em uma batalha sao armas de maior alcance e uma posicao elevada logo sabendo isso me diga qual grupo tem a maior vantagem");
    printf("A - lanceiros em uma planicie. \n B - espadachins em um vale \n C - arqueiros em uma montanha \n D - lanceiros em uma montanha");
    scanf("%s", &vgrupo);
    //rolar dados
    if(vgrupo == ('A' || 'a')){
        printf("voce esta errado saia daqui nao vale gastar meu esforco com voce");
        // decrementa 1 sabedoria
    }else if (vgrupo == ('B' || 'b')){
        printf("saia daqui imediatamente seu idiotae nao volte ate aprender");
        //decrementa 1 sabedoria
    }else if (vgrupo == ('C' || 'c')){
        printf("correto , talvez voce nao seja um idiota como todos aqui");
        //incrementa 2 sabedoria
    }else if (vgrupo == ('D' || 'd')){
        printf("incorreto mas chegou proximo,precisa estudar um pouco mais");
        //sem mudancas
    }else
        printf("escolhauma das alternativas");
        //volta alternativas
    return 0;
}
