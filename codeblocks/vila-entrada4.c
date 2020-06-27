#include <stdio.h>
#include <stdlib.h>

void fTaverna(){
    char decisaoT;
    printf("Voce dirige-se a taverna.\nEntrando, voce ve a bancada com o bartender atras, ve uma mesa repleta de guardas, em outra mesa senhores conversando e algumas crianças e adolecentes andando por ai.\n");
    system("pause");
    printf("Era um lugar interessante, voce ve uma oportunidade de conseguir alguma experiencia.\n\n");
    system("pause");
    printf("\nO que deseja fazer?\n 1- Ir falar com os guardas.\n 2- Falar com o bartender.\n 3- Pedir aos velhos informaçoes.\n F- Ficha do Personagem.\n : ");
    scanf("%s", &decisaoT);

   if(decisaoT == '1'){
        char vQuiz;
    printf("Voce se aproxima dos guardas. Eles olham pra voce e um deles diz:\n -O que o escolhido faz aqui?!\n -Preciso me fortalecer para o maldito torneio!\n O guarda, curioso, diz:\n -Bom, se voce conseguir resolver um pequeno probleminha, talvez um possa lhe ajudar.\n");
        system("pause");
    printf("\n-Vamos la entao.\n -Sera um problema que envolve um pouco de logica, pense bem antes de responder.\n\n");
    system("pause");
    printf("\nPara escrever um livro voce precisa de muitos pontos em  sabedoria.\nSendo assim qual o conectivo correto para a primemira oração?\n");
    printf(" A- B->A\n B- A->B\n C- A<->B\n D- A v B\n E- A ^ B\n : ");
    scanf("%s", &vQuiz);
        if(vQuiz == ('A' || 'a')){
            printf("Chegou perto parceiro...Hahahaha!");
            //nao incrementa nem decrementa
        }else if(vQuiz == ('B' || 'b')){
            printf("Na mosca! Voce acertou camarada!\nVenha vou lhe ensinar uns truques.");
            //incrementa 2 de força
        }else if(vQuiz == ('C' || 'c')){
            printf("De jeito nenhum cara!");
            //decrementa 1 de força
        }else if(vQuiz == ('D' || 'd')){
            printf("Acho qua nao parceiro. Pensa melhor da proxima vez.");
            //decrementa 1 de força
        }else if(vQuiz == ('E' || 'e')){
            printf("Nao cara. Nao esta certo!");
            //decrementa 1 de força
        }else
            printf("Escolha uma das alternativas!");
            //volta as alternativas


    }else if(decisaoT == '2'){
        printf("Voce dirige-se a bancada do bar. O bartender se aproxima.\n");
        system("pause");
        printf("\n -O que quer beber rapaz? Temos alguns importados incriveis aqui!\n\n");
        system("pause");
        printf("\nVoce diz:\n -Nao quero beber nada, preciso me fortalecer!\n");
        system("pause");
        printf("\nO bartender olha bem pra voce e diz:\n -Por que nao falar com os guardas ou entao os senhores sentados ali. Acho que podem te fornecer alguma experiencia.\n");
        //aqui mandaria de volta para o menu da taverna
    }else if(decisaoT == '3'){
        char vCharada;
        printf("\nVoce olha disfarçadamente os senhores sentados... Parecem sabios, vamos ver se tem algum truque de caçador para me ensinar.\n\n");
        system("pause");
        printf("\nVoce senta perto deles...\n\n");
        system("pause");
        printf("\nUm deles pergunta:\n -O que deseja meu jovem?.");
        system("pause");
        printf("\nVoce meio desconfortavel, responde:\n -Voces parecem sabios.Teriam algum truque para me ensinar? O maldito torneio e em alguns dias.\n\n");
        system("pause");
        printf("\nEles olham entre si e respondem:\n -Huummmm...Talvez, se voce resolver uma pequena questao, talvez lhe ajudemos com algo.\n\n");
        system("pause");
        printf("\nVoce diz:\n -Pode falar!\n\n");
        system("pause");
        printf("\nToda manha quando faz sol, eu e os rapazes vamos para a biblioteca ler e escrever algumas paginas de livros.\n\nQual seria o conectivo correto para a oraçao?\n");
        printf(" A- A->B\n B- B v A\n C- A<->B\n D- B->A\n : ");
        scanf("%s", &vCharada);

        if(vCharada == ('A' || 'a')){
            printf("Passou perto garotao...Hahaha");
            //nao decrementa nem incrementa
        }else if(vCharada == ('B' || 'b')){
            printf("Nao! Esta errada!");
            //decrementa 1 em sabedoria
        }else if(vCharada == ('C' || 'c')){
            printf("Naaaaaaaaao! Tem que estudar mais garoto!");
            //decrementa 1 em sabedoria
        }else if(vCharada == ('D' || 'd')){
            printf("Dale garotoo! Muito bem sabichao!\nAgora vou lhe contar uns truques que vc pode usar no torneio...");
            //incrementa 2 de sabedoria ou talvez vida
        }else
            printf("Escolha uma das alternativas!");
            //volta pras alternativas



    }


}


void fAncioes(){


    char decisaoT;
    printf("Voce primeiramente olha de longe o circulo de conversas, para ver com o que iria lidar. Parece ser apenas velhos escribas conversando, nada de mais. Voce se aproxima e pede para juntar-se a eles.\n\n");
    system("pause");
    printf("\nO mais velho do grupo fica intrigado com a sua presença e pergunta:\n -O que lhe tras aqui rapaz?\n\n");
    system("pause");
    printf("\n -Estou em busca de experiencia. O grande torneio esta chegando, preciso me preparar!\n\n");
    system("pause");
    printf("\nO velho entao diz:\n -Entendo... Nesse caso, sente-se, vou continuar a historia que estava contando e depois quero que vc responda a uma pergunta. Se voce acertar lhe darei mais algumas informaçoes e ganhara alguns pontos de VIDA.\n\n");
    system("pause");
    printf("\nVoce escuta atentamente a historia do caçador, e inspirado diz:\n\n -Muito bem, foi uma otima historia, muito obrigado por compartilhar comigo. Mas agora qual sua pergunta?\n\n");
    system("pause");
    printf("\nO velho entao lhe faz a pergunta:\n -Ela envolve raciocinio logico, meu caro. Cuidado com sua resposta.\n\n");
    system("pause");
    printf("\nImpaciente, voce diz:\n -Pode mandar!\n\n");
    system("pause");
    printf("A pergunta envolve uma parte da historia que contei. Vamos la.\nEu e meu amigo fomos a biblioteca, la eu escrvi um livro de poesias enquanto ele escreveu um livro de contos de terror. A pergunta e o seguinte:\n\n");
    printf("Qual o conectivo correto para a oraçao?\n A- A ∧ B\n B- A v B\n C- A -> B\n D- A <-> B\n Resposta: ");
    scanf("%d", &decisaoT);
        if(decisaoT == ('A' || 'a')){
            printf("\n\nHahahaha...Garoto sortudo, voce acertou! Muito bem!\n");
            //aqui seria o rolar de dados ou simplesmente incrementar a vida do personagem em 2.
        }else if(decisaoT == ('B' || 'b')){
            printf("Ih rapaz...Parece que vc errou! Mas nao foi tao ruim. Se voce respondesse 3 ou 4 levaria um cascudo...Hahahahahaha.\n");
            //incrementa 1 de vida
        }else if(decisaoT == ('C' || 'c')){
            printf("Essa resposta nao faz sentido rapaz! Voce precisa pensar mais antes de responder!!\n");
            //perde 1 de vida
        }else if(decisaoT == ('D' || 'd')){
            printf("Essa resposta nao faz sentido rapaz! Voce precisa pensar mais antes de responder!!\n");
            //perde 1 de vida
        }else
            printf("Voce nao esta levando isso a serio rapaz...\n");
            //volta as alternativas



}


void fBiblioteca(){

    char vArmas;
    printf("Voce olha de longe a biblioteca. Chegando, voce fica atordoado com o cheiro de livro velho, mas logo se acostuma...\n\n");
    system("pause");
    printf("\nVoce depara-se com estantes e mais estantes de livros antigos e atuais, homens limpando e recoloando os livros em seus lugares, todos muito bem vestidos, ve alguns escribas escrevendo livros, usando grandes penas.\n\n");
    system("pause");
    printf("\nO encarregado chefe percebe sua presença e se aproxima.\n -O que faz aqui rapaz? Esta em busca de algum livro?\n\n");
    system("pause");
    printf("\nVoce olha para ele meio confuso e diz:\n -Preciso de experiencia! O torneio se aproxima.\n\n");
    system("pause");
    printf("\nO encarregado entao pede para que voce solucione um probleminha para ele. Em troca ele lhe dara algumas dicas de sobrevivencia para usar no torneio.\n\n");
    system("pause");
    printf("\nEle entao diz:\n -Aqui na biblioteca tenho 9 livros de poemas, 15 livros de terror, 8 livros de ciencias, 16 livros de linguagem e 6 livros de matematica. Sabendo que são todas sao livros, qual o conjuto total de armaduras presente nessa coleçao?\n\n");
    scanf("%s", &vArmas);
    // rolar dados
    if(vArmas == ('A' || 'a')){
        printf("Resposta errada garoto! Pense bem da proxima vez.");
        //decrementa 1 na força
    }else if(vArmas == ('B' || 'b')){
        printf("Chegou perto, mas errou. Estude mais e volte depois.");
        //nao decrementa nada
    }else if(vArmas == ('C' || 'c')){
        printf("Acertou em cheio rapaz! Muito bem. Pegue sua espada.");
        //incrementa 2 na força
    }else if(vArmas == ('D' || 'd')){
        printf("Passou longe... Hahahahaha! Va estudar garoto!");
        //decrementa 1 na força
    }else
        printf("Escolha uma das alternativas!");
        //volta as alternativas




}






int main()
{
    printf("\n\t\t\t\tATENCAO\nESSE CENARIO SOFRERA MUDANCAS NA DESCRICAO E PUZZLE, ESTE E APENAS UM ESQUELETO BASEADO NO CENARIO MODELO, VILA PRATEADA\n\n\n");
    system("pause");
    system("cls");
   //descrição
   printf("\n\nVoce anda um pouco e depara-se com um vilarejo muito bonito e fino, com uma paisagem moderna. Era a Vila da tinta. Uma vila com o maior nivel intelectual e cultural.\n");
   printf("Ao aproximar-se voce ve a esquerda, grandes casas espalhadas, todas levantadas com blocos de tijolos, em suas portas e janelas viam-se muitas plantas e placas indentificando cada uma, uma grande escultura na forma de um homem segurando um livro, e mais a frente um mercado de tintas e livros com os mais variados titulos e cores..., a direita voce ve uma grande biblioteca, repleta de livros antigos e atuais feitos por intelectuais da vila e estrangeiros, ve uma taverna moderna e  aparentemente fina tocando musica classica, uma roda antigos escribas  aposentados em volta de uma fogueira e crianças brincando ao redor.");
   printf("E uma vila muito curiosa, que esbanja sabedoria e cultura...\n\n");
   system("pause");

   char decisao;

   printf("O que deseja fazer?\n 1- Ir a taverna\n 2- Consultar os antigos caçadores.\n 3- Ir a couraria\n F- Ficha do Personagem.\n : ");
   scanf("%s", &decisao);


        switch(decisao){
            case '1':
                system("cls");
                fTaverna();
                break;

            case '2':
                system("cls");
                fAncioes();
                break;

            case '3':
                system("cls");
                fBiblioteca();
                break;

            case 'f':
            case 'F':
                //FichaDoPersonagem();
                break;


            }










    return 0;
}
