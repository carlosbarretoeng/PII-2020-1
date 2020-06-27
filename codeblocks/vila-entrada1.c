#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void fTaverna(){
    char decisaoT;
    printf("Voce dirige-se a taverna.\nEntrando, voce ve a bancada com o bartender atras, ve uma mesa repleta de guardas carrancudos, em outra mesa velhos bebendo e falando besteiras e algumas crianças e adolecentes trabalhando no recinto.\n");
    system("pause");
    printf("Voce repara um pouco mais e ve ratos e baratas peranbulando por todo o bar, pessoas urinando nos cantos, algumas brigas e sente o terrivel odor do recinto. Era um lugar repugnante, mas voce ve uma oportunidade de conseguir alguma experiencia.\n\n");
    system("pause");
    printf("\nO que deseja fazer?\n 1- Ir falar com os guardas.\n 2- Falar com o bartender.\n 3- Pedir aos velhos informaçoes.\n F- Ficha do Personagem.\n : ");
    scanf("%s", &decisaoT);

   if(decisaoT == '1'){
        char vQuiz;
    printf("Voce se aproxima dos guardas, sente um odor forte, mas avança mesmo assim. Eles olham pra voce e um deles diz:\n -Olha rapazes o escolhido! Todos ao redor caem em gargalhadas.\n -O que lhe tras aqui garoto? Pergunta outro guarda.\n -Preciso me fortalecer para o maldito torneio!\n O guarda, curioso, diz:\n -Bom, se voce conseguir resolver um pequeno probleminha, talvez um possa lhe ajudar.\n");
        system("pause");
    printf("\n-Vamos la entao.\n -Sera um problema que envolve um pouco de logica, entao...basta usar a cabeça.\n\n");
    system("pause");
    printf("\nPara fazer corretamente uma vigia em turnos, o primeiro guarda, no primeiro turno, so pode sair da sua vigia quando o segundo chegar na hora determinada e realizar a troca de turno.\nSendo assim qual o conectivo correto para a frase?\n");
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
        printf("\n -O que quer beber rapaz?\n\n");
        system("pause");
        printf("\nVoce diz:\n -Nao quero beber nada, preciso me fortalecer!\n");
        system("pause");
        printf("\nO bartender olha bem pra voce e diz:\n -Por que nao falar com os guardas ou entao os velhos ali. Acho que podem te fornecer alguma experiencia.\n");
        //aqui mandaria de volta para o menu da taverna
    }else if(decisaoT == '3'){
        char vCharada;
        printf("\nVoce analisa os velhos beberroes... Parecem sabios, vamos ver no que vai dar.\n\n");
        system("pause");
        printf("\nVoce senta perto deles e percebe o forte cheiro de alcool. Ja devem estar embriagados...\n\n");
        system("pause");
        printf("\nUm deles pergunta:\n -O que voce quer com a gente rapaz.");
        system("pause");
        printf("\nVoce meio sem paciencia, responde:\n -Voces parecem sabios.Teriam alguma coisa para me ajudar no maldito torneio?\n\n");
        system("pause");
        printf("\nEles olham entre si e respondem:\n -Huummmm...Talvez, se voce resolver a nossa charada, talvez lhe ajudemos com algo.\n\n");
        system("pause");
        printf("\nVoce diz:\n -Pode falar!\n\n");
        system("pause");
        printf("\nToda manha quando faz sol, eu e os rapazes descemos para a taverna beber umas cervejas.\n\nQual seria o conectivo correto para a frase?\n");
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


void fVelhos(){

    char decisaoT;
    printf("Voce primeiramente olha de longe o grupo, para ver com o que irá lidar. Parece ser apenas senhores conversando, nada de mais. Voce se aproxima e pede para juntar-se a eles.\n\n");
    system("pause");
    printf("\nO mais velho do grupo fica intrigado com a sua presença e pergunta:\n -O que lhe tras aqui rapaz?\n\n");
    system("pause");
    printf("\n -Estou em busca de experiencia. O grande torneio esta chegando, preciso me preparar!\n\n");
    system("pause");
    printf("\nO velho entao diz:\n -Entendo... Nesse caso vou continuar a historia que estava contando e depois quero que vc responda a uma pergunta. Se voce acertar lhe darei mais algumas informaçoes e ganhara alguns pontos de VIDA.\n\n");
    system("pause");
    printf("\nVoce escuta atentamente a historia do senhorzinho, sente-se inspirado e diz:\n\n -Muito bem, foi uma otima historia, muito obrigado por compartilhar comigo. Mas agora qual sua pergunta?\n\n");
    system("pause");
    printf("\nO velho entao lhe faz a pergunta:\n -Ela envolve raciocinio logico, meu caro. Cuidado com sua resposta.\n\n");
    system("pause");
    printf("\nImpaciente, voce diz:\n -Pode mandar!\n\n");
    system("pause");
    printf("A pergunta envolve uma parte da historia que contei. Vamos la.\nEu e meu amigo fomos a taverna, la eu pedi um caneco de cerveja enquanto ele pediu um prato de pe de porco assado. A pergunta e o seguinte:\n\n");
    printf("Qual o conectivo correto para a frase?\n A- A ∧ B\n B- A v B\n C- A -> B\n D- A <-> B\n Resposta: ");
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


void fFundicao(){

    char vArmas;
    printf("Voce olha de longe, ate onde os jovens levam as toras de madeira e os segue. Chegando na fundiçao, voce fica atordoado com o calor ali presente, mas nao te impede de continuar.\n\n");
    system("pause");
    printf("\nVoce depara-se com uma fornalha a todo vapor, expelindo muita fumaça e sujeira, homens trabalhando, todos sujos de fuligem, ferreiros moldando a prata, martelando o metal quente com as marretas e os adolecentes e crianças depositando a madeira perto da fornalha.\n\n");
    system("pause");
    printf("\nO ferreiro chefe da fundiçao percebe sua presença e se aproxima.\n -O que faz aqui rapaz? Esta em busca de um serviço?\n\n");
    system("pause");
    printf("\nVoce olha para ele meio confuso e diz:\n -Preciso de uma arma! O torneio se aproxima.\n\n");
    system("pause");
    printf("\nO ferreiro entao pede para que voce solucione um probleminha para ele. Em troca ele lhe dara uma pequena espada.\n\n");
    system("pause");
    printf("\nEle entao diz:\n -Aqui na fundiçao tenho 4 espadas, 6 machados, 2 clavas, 5 escudos e 1 adaga. Sabendo que são todas armas, qual o conjuto total de armas presente nesse arsenal?\n");
    printf(" A- 21 armas.\n B- 16 armas\n C- 18 armas\n D- 14 armas.\n : ");
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

   //descrição
   printf("\n\nVoce anda um pouco e depara-se com um vilarejo muito diferente dos demais. Era a Vila Prateada. Uma vila que vivia das suas ricas minas de prata, mas tinha um ar melancolico pairando sobre tudo. ");
   printf("Ao aproximar-se voce ve a esquerda, varias casas espalhadas, todas muito simples, uma igreja velha e aos pedaços e algumas barracas de vendedores, a direita voce ve uma grande fundiçao expelindo muita fumaça, uma taverna, um grupo de velhos reunidos em volta de uma fogueira e crianças carregando toras de madeira para a fundiçao.");
   printf("E uma vila sombria, que sobrevive das minas e do trabalho na prata. Voce sente a tristeza pairar no ar.\n\nVoce anseia por sair logo dessa vila sinistra.\n\n");
   system("pause");

   char decisao;

   printf("O que deseja fazer?\n 1- Ir a taverna\n 2- Ver o que sobre o que os velhos estao conversando.\n 3- Ir a fundiçao\n F- Ficha do Personagem.\n : ");
   scanf("%s", &decisao);


        switch(decisao){
            case '1':
                system("cls");
                fTaverna();
                break;

            case '2':
                system("cls");
                fVelhos();
                break;

            case '3':
                system("cls");
                fFundicao();
                break;

            case 'f':
            case 'F':
                //FichaDoPersonagem();
                break;


            }










    return 0;
}
