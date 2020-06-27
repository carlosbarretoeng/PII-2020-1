/*
 v 0.5 - Restruturação do código
 v 0.6 - Avanço na restruturação
 v 0.7 - Inclusão dos treinamentos e desafios (Problemas com carregamento de arquivo externo JSON)

 v 1.0 - Versão Final
*/

#define VERSAO " v 1.0 "
#define TELA_LARGURA 80
#define TELA_ALTURA 26

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <thread>
#include <chrono>
#include <vector>

#include <io.h>
#include <fcntl.h>
#include <conio.h>

#include <windows.h>

#include "./json.hpp"

using namespace std;
using json = nlohmann::json;

vector<vector<wstring>> MATRIZ;

int DIFICULDADE = 1;
bool TESTE_SEGUNDA_CHANCE = true;

wstring PERSONAGEM_NOME = L"JOHN DOE";
int PERSONAGEM_VIDA = 10;
int PERSONAGEM_FORCA = 10;
int PERSONAGEM_SABEDORIA = 10;

wstring ADVERSARIO_NOME = L"Barhal Caham";
int ADVERSARIO_VIDA = 10;
int ADVERSARIO_FORCA = 10;
int ADVERSARIO_SABEDORIA = 10;

// BLOCO DE CONTROLE DE FLUXO DE ENTRADAS - INICIO
void gotoxy(int x, int y)
{
    COORD p = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}

char aguardaCaracter(char *opcoes)
{
    char caracter;
    bool existe = false;
    do
    {
        caracter = _getch();
        for (int i = 0; i < (int)strlen(opcoes); i++)
        {
            char caracterDeTeste = opcoes[i];
            if (caracterDeTeste == caracter)
            {
                existe = true;
                break;
            }
        }
    } while (!existe);

    return toupper(caracter);
}

void aguardarEnter()
{
    char opcoes[2] = {'\r', '\n'};
    aguardaCaracter(opcoes);
}

wstring aguradaEntradaDeDados(int posX, int posY, char *opcoesDeEntrada)
{
    gotoxy(posX, posY);
    if (opcoesDeEntrada != "")
    {
        wstring out = L"";
        out.push_back(aguardaCaracter(opcoesDeEntrada));
        return out;
    }
    else
    {
        wstring out = L"";
        do
        {
            if (out.length() == 0)
            {
                gotoxy(posX, posY);
            }
            getline(wcin, out);
        } while (out.length() == 0);
        return out;
    }
}

int StringToWString(std::wstring &ws, const std::string &s)
{
    std::wstring wsTmp(s.begin(), s.end());

    ws = wsTmp;

    return 0;
}

// BLOCO DE CONTROLE DE FLUXO DE ENTRADAS - INICIO

// BLOCO GERADOR DE TELAS - INÍCIO
void inicializaMatriz()
{
    MATRIZ.resize(TELA_ALTURA);
    for (int i = 0; i < TELA_ALTURA; i++)
    {
        MATRIZ[i].resize(TELA_LARGURA);
        for (int j = 0; j < TELA_LARGURA; j++)
        {
            MATRIZ[i][j] = L" ";
            if (i == 0)
            {
                if (j == 0)
                {
                    MATRIZ[i][j] = L"╔";
                }
                else if (j == (TELA_LARGURA - 1))
                {
                    MATRIZ[i][j] = L"╗";
                }
                else
                {
                    MATRIZ[i][j] = L"═";
                }
            }
            else if (i == (TELA_ALTURA - 1))
            {
                if (j == 0)
                {
                    MATRIZ[i][j] = L"╚";
                }
                else if (j == (TELA_LARGURA - 1))
                {
                    MATRIZ[i][j] = L"╝";
                }
                else
                {
                    MATRIZ[i][j] = L"═";
                }
            }
            else
            {
                if (j == 0 || j == (TELA_LARGURA - 1))
                {
                    MATRIZ[i][j] = L"║";
                }
            }
        }
    }

    for (int i = 0; i < 7 /* Tamanho de VERSAO */; i++)
    {
        MATRIZ[0][TELA_LARGURA - 9 + i] = VERSAO[i];
    }
}

void imprimirMatriz()
{
    for (int i = 0; i < TELA_ALTURA; i++)
    {
        for (int j = 0; j < TELA_LARGURA; j++)
        {
            wcout << MATRIZ[i][j];
        }
    }
}

void limparTela()
{
    system("cls");
}

int escreveBlocoDeTexto(wstring texto, int posX, int posY)
{
    // TODO: SEPARAR AS PALAVRAS E FAZER A DIVISÃO CONSIDERANDO APENAS PALAVRAS COMPLETAS
    int tamanhoFinal = posX + texto.length();
    if (tamanhoFinal > (TELA_LARGURA - 1))
    {
        wstring textoDessaLinha = L"";
        wstring textoProximaLinha = L"";
        int posicaoTexto = 0;
        for (int i = posX; i < (TELA_LARGURA - 2); i++)
        {
            textoDessaLinha += texto[posicaoTexto];
            posicaoTexto++;
        }
        for (int i = posicaoTexto; i < (int)texto.length(); i++)
        {
            textoProximaLinha += texto[posicaoTexto];
            posicaoTexto++;
        }
        escreveBlocoDeTexto(textoDessaLinha, posX, posY);
        return escreveBlocoDeTexto(textoProximaLinha, 2, posY + 1);
    }
    else
    {
        int posicaoTexto = 0;
        for (int i = posX; i < tamanhoFinal; i++)
        {
            MATRIZ[posY][i] = texto[posicaoTexto];
            posicaoTexto++;
        }
    }
    return posY + 1;
}

int escreveLinhaHorizontal(int posY)
{
    if (posY == 0 || posY == TELA_ALTURA - 1)
    {
        return posY;
    }

    for (int i = 0; i < TELA_LARGURA; i++)
    {
        MATRIZ[posY][i] = L"═";
        if (i == 0)
        {
            MATRIZ[posY][i] = L"╠";
        }
        if (i == TELA_LARGURA - 1)
        {
            MATRIZ[posY][i] = L"╣";
        }
    }
    return posY + 1;
}
// BLOCO GERADOR DE TELAS - FIM

void telaDeConfiguracaoDoTerminal()
{
    int linha = 11;
    limparTela();
    inicializaMatriz();
    linha = escreveBlocoDeTexto(L"CONFIGURE SEU TERMINAL PARA " + to_wstring(TELA_LARGURA) + L"x" + to_wstring(TELA_ALTURA) + L" OU ATÉ QUE", 17, linha);
    linha = escreveBlocoDeTexto(L"ESSE QUADRO SE ENCAIXE PERFEITAMENTE.", 21, linha);
    linha = escreveBlocoDeTexto(L"PARA RECARREGAR QUADRO, PRESSIONE 'R'.", 2, TELA_ALTURA - 3);
    linha = escreveBlocoDeTexto(L"PARA AVANÇAR, PRESSIONE ENTER", 2, linha);
    imprimirMatriz();

    char opcoes[4] = {'r', 'R', '\r', '\n'};
    char caracter = aguardaCaracter(opcoes);
    if (caracter == 'R')
    {
        telaDeConfiguracaoDoTerminal();
    }
}

void telaDeApresentacao()
{
    int linha = 1;
    limparTela();
    inicializaMatriz();
    linha = escreveBlocoDeTexto(L"CENTRO UNIVERSITÁRIO GOVERNADOR OZANAN COELHO - UNIFAGOC", 11, linha);
    linha = escreveBlocoDeTexto(L"CIÊNCIA DA COMPUTAÇÃO - PROJETO INTEGRADOR I", 17, linha);
    linha = 7;
    linha = escreveBlocoDeTexto(L"8888888b.                   d8b          888                 8888888b. ", 5, linha);
    linha = escreveBlocoDeTexto(L"888   Y88b                  Y8P          888                 888   Y88b", 5, linha);
    linha = escreveBlocoDeTexto(L"888    888                               888                 888    888", 5, linha);
    linha = escreveBlocoDeTexto(L"888   d88P 888d888 .d88b.  8888  .d88b.  888888 .d88b.       888   d88P", 5, linha);
    linha = escreveBlocoDeTexto(L"8888888P'  888P'  d88''88b '888 d8P  Y8b 888   d88''88b      8888888P' ", 5, linha);
    linha = escreveBlocoDeTexto(L"888        888    888  888  888 88888888 888   888  888      888 T88b  ", 5, linha);
    linha = escreveBlocoDeTexto(L"888        888    Y88..88P  888 Y8b.     Y88b. Y88..88P      888  T88b ", 5, linha);
    linha = escreveBlocoDeTexto(L"888        888     'Y88P'   888  'Y8888   'Y888 'Y88P'       888   T88b", 5, linha);
    linha = escreveBlocoDeTexto(L"                            888                                        ", 5, linha);
    linha = escreveBlocoDeTexto(L"                           d88P                                        ", 5, linha);
    linha = escreveBlocoDeTexto(L"                         888P'                                         ", 5, linha);
    linha = 21;
    linha = escreveBlocoDeTexto(L"     Jogo RPG Text-Adventure para a disciplina de Projeto Integrador I     ", 2, linha);
    linha = escreveBlocoDeTexto(L"desenvolvido pelos alunos Carlos Barreto, Italo Rocha, Joao Pedro Thinassi ", 2, linha);
    linha = escreveBlocoDeTexto(L"                           e Matheus Drumond.                              ", 2, linha);

    linha = escreveBlocoDeTexto(L" PRESSIONE ENTER ", 61, TELA_ALTURA - 1);
    imprimirMatriz();
    aguardarEnter();
}

void telaDeIntroducaoDaHistoria()
{
    int linha = 1;
    limparTela();
    inicializaMatriz();
    linha = escreveBlocoDeTexto(L"CENTRO UNIVERSITÁRIO GOVERNADOR OZANAN COELHO - UNIFAGOC", 11, linha);
    linha = escreveBlocoDeTexto(L"CIÊNCIA DA COMPUTAÇÃO - PROJETO INTEGRADOR I - PROJETO R", 11, linha);
    linha = escreveLinhaHorizontal(linha);

    linha = escreveBlocoDeTexto(L"Nossa história começa em um tempo muito diferente do nosso. Por gerações e mais geracões, um pequeno feudo no limiar de dois impérios é disputado com sangue e inteligência por duas famílias nobres, os Caham e os Redmond.", 6, linha);
    linha = escreveBlocoDeTexto(L"O torneio é o divisor de águas na vida dos campeões eleitos. A vitória garante a honra e favores que só os mais altos nobres alcançam. A derrota desgraça a vida do vassalo e marca sua família por mais 40 anos de trabalhosinfindáveis.", 6, ++linha);
    linha = escreveBlocoDeTexto(L"A cada 40 anos, as dinastias elegem dentre seus vassalos um campeão. A  este, caberá a honra de defender seu Rei na disputa do Torneio Círculo do   Trono Prismático.", 6, ++linha);
    linha = escreveBlocoDeTexto(L"Para esta edição, os Redmond's tem um sério problema. Seu heroi eleito foi gravemente ferido em seu treinamento e não resistiu à recupeação. Agora,o que resta a família é escolher um novo guerreiro e torcer para que ele    esteja pronto dentro dos 4 meses que restam para o enclave.", 6, ++linha);

    linha = escreveBlocoDeTexto(L" PRESSIONE ENTER ", 61, TELA_ALTURA - 1);
    imprimirMatriz();
    aguardarEnter();

    limparTela();
    inicializaMatriz();
    linha = escreveBlocoDeTexto(L"CENTRO UNIVERSITÁRIO GOVERNADOR OZANAN COELHO - UNIFAGOC", 11, 1);
    linha = escreveBlocoDeTexto(L"CIÊNCIA DA COMPUTAÇÃO - PROJETO INTEGRADOR I - PROJETO R", 11, linha);
    linha = escreveLinhaHorizontal(linha);

    linha = escreveBlocoDeTexto(L"Por dias os senhores buscaram entre seus guardas um combatente à altura,mas sem sucesso. Se viram em uma situação crítica. Agora não mais restam 4  meses. A lua já completou mais um ciclo e os 3 que restam até a batalha     forçam Redmond a uma decisão final.", 6, ++linha);
    linha = escreveBlocoDeTexto(L"Em um lampejo desesperado, Lord Redmond ordena a seu escriba que lhe  traga uma travessa com os nomes de todos os nobres que porventura tenham   participado de treinamentos militares, que tenham estudado na academia      militar, mas que não seguiram carreira. Entre esses, ele iria sortear o escolhido e pedir ao universo que o heroi seja sábio e forte o suficiente.", 6, ++linha);
    linha = escreveBlocoDeTexto(L"O escriba correu aos seus alfarrapios e buscou nominalmente um a um. Eram tantos que logo pensou haver uma forma mais inteligente de      selecioná-los. Ele sabia que se achasse uma formula geral que localizasse  somente os que ele precisava, poderia pedir aos seus assistentes que        eliminassem da lista todos os outros. Assim, em um pedaço  de pergaminho fez as seguintes anoações:", 6, ++linha);

    linha = escreveBlocoDeTexto(L" PRESSIONE ENTER ", 61, TELA_ALTURA - 1);
    imprimirMatriz();
    aguardarEnter();

    limparTela();
    inicializaMatriz();
    linha = escreveBlocoDeTexto(L"CENTRO UNIVERSITÁRIO GOVERNADOR OZANAN COELHO - UNIFAGOC", 11, 1);
    linha = escreveBlocoDeTexto(L"CIÊNCIA DA COMPUTAÇÃO - PROJETO INTEGRADOR I - PROJETO R", 11, linha);
    linha = escreveLinhaHorizontal(linha);

    linha = escreveBlocoDeTexto(L"┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓", 2, linha);
    linha = escreveBlocoDeTexto(L"┃ Preciso selecionar com base em:            ┃", 2, linha);
    linha = escreveBlocoDeTexto(L"┃   * Homens;                                ┃", 2, linha);
    linha = escreveBlocoDeTexto(L"┃   * Que fizeram exercícios militares;      ┃", 2, linha);
    linha = escreveBlocoDeTexto(L"┃   * Que estudaram na academia militar;     ┃", 2, linha);
    linha = escreveBlocoDeTexto(L"┃   * Que não são militares;                 ┃", 2, linha);
    linha = escreveBlocoDeTexto(L"┃   * Que são n~~~~~;                        ┃", 2, linha);
    linha = escreveBlocoDeTexto(L"┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛", 2, linha);

    linha = escreveBlocoDeTexto(L"A caligrafia do escriba não", 50, 5);
    linha = escreveBlocoDeTexto(L"ajudou ao assistente que", 50, linha);
    linha = escreveBlocoDeTexto(L"(como nós) não entendeu o", 50, linha);
    linha = escreveBlocoDeTexto(L"último ponto. Fato é que", 50, linha);
    linha = escreveBlocoDeTexto(L"optou por ignorá-lo e", 50, linha);
    linha = escreveBlocoDeTexto(L"selecionou assim:", 50, linha);

    escreveBlocoDeTexto(L" PRESSIONE ENTER ", 61, TELA_ALTURA - 1);
    imprimirMatriz();
    aguardarEnter();
    limparTela();

    linha = escreveBlocoDeTexto(L"┏━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━┓", 2, ++linha);
    linha = escreveBlocoDeTexto(L"┃NOBRES            ┃CAMPONESES               ┃", 2, linha);
    linha = escreveBlocoDeTexto(L"┃┏━━━━━━━━━━━━━━━━━╋━━━━┓                    ┃", 2, linha);
    linha = escreveBlocoDeTexto(L"┃┃HOMENS           ┃    ┃                    ┃", 2, linha);
    linha = escreveBlocoDeTexto(L"┃┃┏━━━━━━━━━━━━━━━━╋━━━┓┃                    ┃", 2, linha);
    linha = escreveBlocoDeTexto(L"┃┃┃EXERCÍCIOS      ┃   ┃┃                    ┃", 2, linha);
    linha = escreveBlocoDeTexto(L"┃┃┃┏━━━━━━━━━━━━━━━╋━━┓┃┃                    ┃", 2, linha);
    linha = escreveBlocoDeTexto(L"┃┃┃┃ACADEMIA       ┃  ┃┃┃                    ┃", 2, linha);
    linha = escreveBlocoDeTexto(L"┃┃┃┃┏━━━━━━━━━━━━━━╋━┓┃┃┃                    ┃", 2, linha);
    linha = escreveBlocoDeTexto(L"┃┃┃┃┃NÃO MILITAR  █┃█┃┃┃┃                    ┃", 2, linha);
    linha = escreveBlocoDeTexto(L"┗┻┻┻┻━━━━━━━━━━━━━━┻━┻┻┻┻━━━━━━━━━━━━━━━━━━━━┛", 2, linha);

    linha = escreveBlocoDeTexto(L"Por não entender que o", 50, linha - 10);
    linha = escreveBlocoDeTexto(L"último item era o heroi", 50, linha);
    linha = escreveBlocoDeTexto(L"ser um nobre, agora até um", 50, linha);
    linha = escreveBlocoDeTexto(L"campones corre o risco", 50, linha);
    linha = escreveBlocoDeTexto(L"de ser o selecionado.", 50, linha);
    linha = escreveBlocoDeTexto(L"Será nosso heroi um", 50, ++linha);
    linha = escreveBlocoDeTexto(L"nobre ou um plebeu?", 50, linha);

    linha = escreveBlocoDeTexto(L" PRESSIONE ENTER ", 61, TELA_ALTURA - 1);
    imprimirMatriz();
    aguardarEnter();

    limparTela();
    inicializaMatriz();
    linha = escreveBlocoDeTexto(L"CENTRO UNIVERSITÁRIO GOVERNADOR OZANAN COELHO - UNIFAGOC", 11, 1);
    linha = escreveBlocoDeTexto(L"CIÊNCIA DA COMPUTAÇÃO - PROJETO INTEGRADOR I - PROJETO R", 11, linha);
    linha = escreveLinhaHorizontal(linha);

    linha = escreveBlocoDeTexto(L"Agora já não dava mais para corrigir o erro. O escriba listou  os nomes dos candidatos e os levou ao rei.", 6, ++linha);
    linha = escreveBlocoDeTexto(L"Com certo afobamento, Lord Redmond pôs a mão sobre a travessa e, sem   olhar para os pequenos pedaços de papel, selecionou um. Ao ler o nome ali   escrito, hesitou por um instante, mas, certo de que o universo enviaria a     melhor resposta, ordenou ao mensageiro que enviasse uma mensagem urgente àquele homem...", 6, ++linha);

    linha = escreveBlocoDeTexto(L" PRESSIONE ENTER ", 61, TELA_ALTURA - 1);
    imprimirMatriz();
    aguardarEnter();
}

void telaDeSelecaoDeDificuldadeENomeDoPersonagem()
{
    int linha = 1;
    limparTela();
    inicializaMatriz();
    linha = escreveBlocoDeTexto(L"CENTRO UNIVERSITÁRIO GOVERNADOR OZANAN COELHO - UNIFAGOC", 11, linha);
    linha = escreveBlocoDeTexto(L"CIÊNCIA DA COMPUTAÇÃO - PROJETO INTEGRADOR I - PROJETO R", 11, linha);
    linha = escreveLinhaHorizontal(linha);

    linha = escreveBlocoDeTexto(L"O universo teria realmente sido bom com a familia Redmond? Vamos  descobrir na nossa jornada, mas primeiro, é preciso que escolhamos o quão   difícil será nosso caminho.", 6, ++linha);
    linha = escreveBlocoDeTexto(L"Selecione dentre as opções abaixo, a que melhor representa a dificuldade que quer enfrentar:", 6, ++linha);

    linha = TELA_ALTURA - 5;

    linha = escreveBlocoDeTexto(L"(1) Fácil", 2, linha);
    linha = escreveBlocoDeTexto(L"(2) Médio", 2, linha);
    linha = escreveBlocoDeTexto(L"(3) Difícil", 2, linha);
    linha = escreveBlocoDeTexto(L"Qual dificuldade deseja? (1, 2 ou 3): ", 2, linha);

    imprimirMatriz();

    char opcoes[3] = {'1', '2', '3'};
    wstring opcao = aguradaEntradaDeDados(40, --linha, opcoes);
    DIFICULDADE = stoi(opcao);

    linha = 1;
    limparTela();
    inicializaMatriz();
    linha = escreveBlocoDeTexto(L"CENTRO UNIVERSITÁRIO GOVERNADOR OZANAN COELHO - UNIFAGOC", 11, linha);
    linha = escreveBlocoDeTexto(L"CIÊNCIA DA COMPUTAÇÃO - PROJETO INTEGRADOR I - PROJETO R", 11, linha);
    linha = escreveLinhaHorizontal(linha);

    linha = escreveBlocoDeTexto(L"O universo teria realmente teria sido bom com a familia Redmond? Vamos  descobrir na nossa jornada, mas primeiro, é preciso que escolhamos o quão   difícil será nosso caminho.", 6, ++linha);
    linha = escreveBlocoDeTexto(L"Selecione dentre as opções abaixo, a que melhor representa a dificuldade que quer enfrentar:", 6, ++linha);
    linha = escreveBlocoDeTexto(opcao, 23, --linha);

    if (opcao == L"1")
    {
        linha = escreveBlocoDeTexto(L"Ok...Então FÁCIL será. Mesmo assim, não vá pensando que seus desafios   serão simplórios. Eles exigirão muita força e sabedoria para ultrapassar as dificuldades.", 6, ++linha);
    }
    else if (opcao == L"2")
    {
        linha = escreveBlocoDeTexto(L"Nem tão ao céu, nem tão ao inferno. No nível MÉDIO sua jornada será     árdua. Suas batalhas, davastadoras. Seu sucesso (se conseguir), lendário!", 6, ++linha);
    }
    else
    {
        linha = escreveBlocoDeTexto(L"De fortes e valentes é que são contadas as histórias. O nível DIFÍCIL   exigirá de você o máximo. Prepare-se para choro e ranger de dentes!!!.", 6, ++linha);
    }

    int linhaRetorno = linha;
    linha = escreveBlocoDeTexto(L"Uma vez que já sabemos como quer jogar, agora nos resta saber:", 6, ++linha);

    linha = TELA_ALTURA - 2;
    linha = escreveBlocoDeTexto(L"Qual o nome do seu personagem?: ", 2, linha);

    imprimirMatriz();

    PERSONAGEM_NOME = aguradaEntradaDeDados(34, --linha, "");

    // TODO: A depender do tamanho do nome, essa wstring será quebrada... RESOLVER COM QUEBRA DE PALAVRAS NA FUNÇÃO 'escreveBlocoDeTexto'
    wstring txt = L"Agora, por fim, sabemos o nome de nosso futuro heroi e a dificuldade de sua jornada. Que o hoje vassalo, " + PERSONAGEM_NOME + L" seja o campeão que o reino de Redmond procura.";
    linha = escreveBlocoDeTexto(txt, 6, ++linhaRetorno);
    linha = escreveBlocoDeTexto(L"                               ", 2, TELA_ALTURA - 2);

    limparTela();
    imprimirMatriz();
    aguardarEnter();
}

void tutorialDeJogabilidade()
{
    int linha = 1;
    limparTela();
    inicializaMatriz();
    linha = escreveBlocoDeTexto(L"CENTRO UNIVERSITÁRIO GOVERNADOR OZANAN COELHO - UNIFAGOC", 11, linha);
    linha = escreveBlocoDeTexto(L"CIÊNCIA DA COMPUTAÇÃO - PROJETO INTEGRADOR I - PROJETO R", 11, linha);
    linha = escreveLinhaHorizontal(linha);

    linha = escreveBlocoDeTexto(L"Chegando ao destino, o mensageiro depara-se com um casebre humilde, muito simples. A princípio, ele fica com pena do jovem rapaz. Bate à porta e chama:", 6, ++linha);
    linha = escreveBlocoDeTexto(L"  - Sir " + PERSONAGEM_NOME + L"! Sir " + PERSONAGEM_NOME + L"!", 6, ++linha);
    linha = escreveBlocoDeTexto(L"Sob o marco desgastado, um senhor já castigado pelo passar dos anos recebe o mensageiro:", 6, ++linha);
    linha = escreveBlocoDeTexto(L"  - Em que posso lhe ajudar? Disse o velho ao mensageiro", 6, ++linha);
    linha = escreveBlocoDeTexto(L"  - Venho em nome de Sua Alteza Lord Redmond. Trago essa mensagem urgente.", 6, ++linha);
    linha = escreveBlocoDeTexto(L"O mensageiro entrega o pequeno pedaço de papel. O senhor agradece e fecha a porta. De imediato, grita a toda a família que se reunam na cozinha.", 6, ++linha);

    linha = escreveBlocoDeTexto(L" PRESSIONE ENTER ", 61, TELA_ALTURA - 1);
    imprimirMatriz();
    aguardarEnter();

    limparTela();
    inicializaMatriz();
    linha = escreveBlocoDeTexto(L"CENTRO UNIVERSITÁRIO GOVERNADOR OZANAN COELHO - UNIFAGOC", 11, 1);
    linha = escreveBlocoDeTexto(L"CIÊNCIA DA COMPUTAÇÃO - PROJETO INTEGRADOR I - PROJETO R", 11, linha);
    linha = escreveLinhaHorizontal(linha);

    linha = escreveBlocoDeTexto(L"O mais rápido que pessoas podem se movimentar, todos se colocaram sentados à mesa. Eram não menos que sete. O pai, com a carta na mão, se aproxima da mãe heirarquicamente à esquerda da cabiceira da mesa. Desdobra o papel. Pousa os olhos por um segundo sobre as letras. Entrega o manuscrito à esposa e diz:", 6, ++linha);
    linha = escreveBlocoDeTexto(L"  - Ha pouco um mensageiro entregou uma convocação para o Torneio Círculo do Trono Prismático. Não sei ao certo o porquê.", 6, ++linha);
    linha = escreveBlocoDeTexto(L"Todos se entreolharam perplexos. Por quê haviam sido escolhidos? Qual a razão de convocarem um camponês para uma batalha? Ainda sem entenderem bem, o pai continuou:", 6, ++linha);
    linha = escreveBlocoDeTexto(L"  - Tivemos a honra de sermos lembrados por nosso lord. E mais, ele escolheu especificamente você, " + PERSONAGEM_NOME + L", para a competição. Pelo jeito, aquelas aulas na academia militar não foram de tudo perdidas.", 6, ++linha);
    linha = escreveBlocoDeTexto(L"Todos voltam os olhos para " + PERSONAGEM_NOME + L". Agora, ainda mais do que antes, perguntas são o que ha de mais, ou unicamente, abundante naquele lar.", 6, ++linha);

    linha = escreveBlocoDeTexto(L" PRESSIONE ENTER ", 61, TELA_ALTURA - 1);
    imprimirMatriz();
    aguardarEnter();

    limparTela();
    inicializaMatriz();
    linha = escreveBlocoDeTexto(L"CENTRO UNIVERSITÁRIO GOVERNADOR OZANAN COELHO - UNIFAGOC", 11, 1);
    linha = escreveBlocoDeTexto(L"CIÊNCIA DA COMPUTAÇÃO - PROJETO INTEGRADOR I - PROJETO R", 11, linha);
    linha = escreveLinhaHorizontal(linha);

    linha = escreveBlocoDeTexto(L"Ficaram algum tempo conversando e chegaram na conclusão obvia. Ele iria lutar! O pai poe a mão em seu ombro e diz:", 6, ++linha);
    linha = escreveBlocoDeTexto(L"  - " + PERSONAGEM_NOME + L" sinto muito por envia-lo a este torneio, mas é uma questão de vida ou morte e acima de tudo honra! O grande torneio do Circulo do Trono Prismatico decide quem vai reinar pelo proximos 40 anos. E a familia que vencer, alem de dar o controle do reino ao Lorde, vai receber bençãos e privilegios. Voce vai precisar de treinamento, vou explicar como vai funcionar.", 6, ++linha);
    linha = escreveBlocoDeTexto(L"Neste jogo, seu objetivo é vencer o grande torneio. Para isso deve-se coletar experiencia, na forma de VIDA, FORCA e SABEDORIA. Estas serão obtidas atraves da escolha de cenarios entre um a três. Cada um com suas peculiaridades, desafios e recompensas. Quando estiver forte o suficiente, você será levado ao Torneiro do Circulo do Trono Prismatico.", 6, ++linha);
    linha = escreveBlocoDeTexto(L"No torneio, voce será apresentado ao combate! Tera que duelar contra um inimigo que tera status baseados na dificuldade que você escolheu no começo do jogo.", 6, ++linha);

    linha = escreveBlocoDeTexto(L" PRESSIONE ENTER ", 61, TELA_ALTURA - 1);
    imprimirMatriz();
    aguardarEnter();

    limparTela();
    inicializaMatriz();
    linha = escreveBlocoDeTexto(L"CENTRO UNIVERSITÁRIO GOVERNADOR OZANAN COELHO - UNIFAGOC", 11, 1);
    linha = escreveBlocoDeTexto(L"CIÊNCIA DA COMPUTAÇÃO - PROJETO INTEGRADOR I - PROJETO R", 11, linha);
    linha = escreveLinhaHorizontal(linha);

    linha = escreveBlocoDeTexto(L"O combate  é baseado em turnos. Você escolhe a ação, ATACAR ou DEFENDER. Ao atacar voce causara dano igual a sua FORCA mais um incremento baseado aleatoriamente nos DADOS. Ao escolher DEFENDER, voce bloqueara, ou não, o ataque adversario usando sua SABEDORIA. Caso seja maior que a FORCA do oponente voce não levara DANOS e retornara o ataque ao oponente, causando dano à vida do adversário.", 6, ++linha);
    linha = escreveBlocoDeTexto(L"Agora que já conhece as regras basicas, voce deve buscar experiencia para se tornar forte e vencer o torneio. Você escolhe o seu caminho. Nele, encontrara pessoas, estabelecimentos, vilas, acampamentos e por ai vai... Resolva diversos desafios para aumentar seus atributos e vencer o torneio. A cada decisão, uma nova oportunidade lhe será dada. Aproveite-a!", 6, ++linha);

    linha = escreveBlocoDeTexto(L" PRESSIONE ENTER ", 61, TELA_ALTURA - 1);
    imprimirMatriz();
    aguardarEnter();
}

void telaDeGameOver() {
    int linha = 1;
    limparTela();
    inicializaMatriz();
    linha = escreveBlocoDeTexto(L"CENTRO UNIVERSITÁRIO GOVERNADOR OZANAN COELHO - UNIFAGOC", 11, linha);
    linha = escreveBlocoDeTexto(L"CIÊNCIA DA COMPUTAÇÃO - PROJETO INTEGRADOR I", 17, linha);
    linha = 7;
    linha = escreveBlocoDeTexto(L"8888888b.                   d8b          888                 8888888b. ", 5, linha);
    linha = escreveBlocoDeTexto(L"888   Y88b                  Y8P          888                 888   Y88b", 5, linha);
    linha = escreveBlocoDeTexto(L"888    888                               888                 888    888", 5, linha);
    linha = escreveBlocoDeTexto(L"888   d88P 888d888 .d88b.  8888  .d88b.  888888 .d88b.       888   d88P", 5, linha);
    linha = escreveBlocoDeTexto(L"8888888P'  888P'  d88''88b '888 d8P  Y8b 888   d88''88b      8888888P' ", 5, linha);
    linha = escreveBlocoDeTexto(L"888        888    888  888  888 88888888 888   888  888      888 T88b  ", 5, linha);
    linha = escreveBlocoDeTexto(L"888        888    Y88..88P  888 Y8b.     Y88b. Y88..88P      888  T88b ", 5, linha);
    linha = escreveBlocoDeTexto(L"888        888     'Y88P'   888  'Y8888   'Y888 'Y88P'       888   T88b", 5, linha);
    linha = escreveBlocoDeTexto(L"                            888                                        ", 5, linha);
    linha = escreveBlocoDeTexto(L"                           d88P                                        ", 5, linha);
    linha = escreveBlocoDeTexto(L"                         888P'                                         ", 5, linha);
    linha = 21;
    linha = escreveBlocoDeTexto(L"INFELIZMENTE VOCÊ NÃO RESISTIU À SUA JORNADA.", 2, linha);
    linha = escreveBlocoDeTexto(L"TENTE NOVAMENTE!.", 2, linha);

    linha = escreveBlocoDeTexto(L" PRESSIONE ENTER ", 61, TELA_ALTURA - 1);
    imprimirMatriz();
    aguardarEnter();
}

void telaDeSucesso() {
    int linha = 1;
    limparTela();
    inicializaMatriz();
    linha = escreveBlocoDeTexto(L"CENTRO UNIVERSITÁRIO GOVERNADOR OZANAN COELHO - UNIFAGOC", 11, linha);
    linha = escreveBlocoDeTexto(L"CIÊNCIA DA COMPUTAÇÃO - PROJETO INTEGRADOR I", 17, linha);
    linha = 7;
    linha = escreveBlocoDeTexto(L"8888888b.                   d8b          888                 8888888b. ", 5, linha);
    linha = escreveBlocoDeTexto(L"888   Y88b                  Y8P          888                 888   Y88b", 5, linha);
    linha = escreveBlocoDeTexto(L"888    888                               888                 888    888", 5, linha);
    linha = escreveBlocoDeTexto(L"888   d88P 888d888 .d88b.  8888  .d88b.  888888 .d88b.       888   d88P", 5, linha);
    linha = escreveBlocoDeTexto(L"8888888P'  888P'  d88''88b '888 d8P  Y8b 888   d88''88b      8888888P' ", 5, linha);
    linha = escreveBlocoDeTexto(L"888        888    888  888  888 88888888 888   888  888      888 T88b  ", 5, linha);
    linha = escreveBlocoDeTexto(L"888        888    Y88..88P  888 Y8b.     Y88b. Y88..88P      888  T88b ", 5, linha);
    linha = escreveBlocoDeTexto(L"888        888     'Y88P'   888  'Y8888   'Y888 'Y88P'       888   T88b", 5, linha);
    linha = escreveBlocoDeTexto(L"                            888                                        ", 5, linha);
    linha = escreveBlocoDeTexto(L"                           d88P                                        ", 5, linha);
    linha = escreveBlocoDeTexto(L"                         888P'                                         ", 5, linha);
    linha = 21;
    linha = escreveBlocoDeTexto(L"PARABÉNS!!! VOCÊ VENCEU O TORNEIO E GARANTIU AOS REDMONDS MAIS 40 ANOS DE POSSES.", 2, linha);
    linha = escreveBlocoDeTexto(L"Agora aproveite o que aprendeu e volte a jogar obsevando o quanto o Raciocínio Lógico Matemático esta diluído em tudo o que fazemo!.", 2, linha);

    linha = escreveBlocoDeTexto(L" PRESSIONE ENTER ", 61, TELA_ALTURA - 1);
    imprimirMatriz();
    aguardarEnter();
}

void telaDeCreditos() {
    int linha = 1;
    limparTela();
    inicializaMatriz();
    linha = escreveBlocoDeTexto(L"CENTRO UNIVERSITÁRIO GOVERNADOR OZANAN COELHO - UNIFAGOC", 11, linha);
    linha = escreveBlocoDeTexto(L"CIÊNCIA DA COMPUTAÇÃO - PROJETO INTEGRADOR I", 17, linha);
    linha = 10;
    linha = escreveBlocoDeTexto(L"8888888b.                   d8b          888                 8888888b. ", 5, linha);
    linha = escreveBlocoDeTexto(L"888   Y88b                  Y8P          888                 888   Y88b", 5, linha);
    linha = escreveBlocoDeTexto(L"888    888                               888                 888    888", 5, linha);
    linha = escreveBlocoDeTexto(L"888   d88P 888d888 .d88b.  8888  .d88b.  888888 .d88b.       888   d88P", 5, linha);
    linha = escreveBlocoDeTexto(L"8888888P'  888P'  d88''88b '888 d8P  Y8b 888   d88''88b      8888888P' ", 5, linha);
    linha = escreveBlocoDeTexto(L"888        888    888  888  888 88888888 888   888  888      888 T88b  ", 5, linha);
    linha = escreveBlocoDeTexto(L"888        888    Y88..88P  888 Y8b.     Y88b. Y88..88P      888  T88b ", 5, linha);
    linha = escreveBlocoDeTexto(L"888        888     'Y88P'   888  'Y8888   'Y888 'Y88P'       888   T88b", 5, linha);
    linha = escreveBlocoDeTexto(L"                            888                                        ", 5, linha);
    linha = escreveBlocoDeTexto(L"                           d88P                                        ", 5, linha);
    linha = escreveBlocoDeTexto(L"                         888P'                                         ", 5, linha);

    linha = escreveBlocoDeTexto(L" PRESSIONE ENTER ", 61, TELA_ALTURA - 1);
    imprimirMatriz();
    aguardarEnter();
}

bool testeCondicoesParaTreinamento()
{
    if((PERSONAGEM_FORCA <= 1 || PERSONAGEM_FORCA >= 30) || (PERSONAGEM_SABEDORIA <= 1 || PERSONAGEM_SABEDORIA >= 30) || (PERSONAGEM_VIDA <= 1 || PERSONAGEM_VIDA >= 30)){
        return false;
    }
    return true;
}

bool testeCondicoesPreTorneio()
{
    if(PERSONAGEM_VIDA <= 0)
    {
        return false;
    }else{
        return true;
    }
}

bool testeCondicoesPosTorneio()
{
    return true;
}

void fichaDoPersonagem()
{
    int linha = 1;
    limparTela();
    inicializaMatriz();
    linha = escreveBlocoDeTexto(L"CENTRO UNIVERSITÁRIO GOVERNADOR OZANAN COELHO - UNIFAGOC", 11, linha);
    linha = escreveBlocoDeTexto(L"CIÊNCIA DA COMPUTAÇÃO - PROJETO INTEGRADOR I - PROJETO R", 11, linha);
    linha = escreveLinhaHorizontal(linha);
    linha = escreveBlocoDeTexto(L" __   ___  __   __   __             __   ___      ", 2, linha);
    linha = escreveBlocoDeTexto(L"|__) |__  |__) /__` /  \\ |\\ |  /\\  / _` |__   |\\/| ", 2, linha);
    linha = escreveBlocoDeTexto(L"|    |___ |  \\ .__/ \\__/ | \\| /~~\\ \\__> |___  |  |", 2, linha);
    linha = escreveLinhaHorizontal(++linha);

    linha = escreveBlocoDeTexto(L"Nome: " + PERSONAGEM_NOME, 2, ++linha);

    linha = escreveBlocoDeTexto(L"     Vida: " + to_wstring(PERSONAGEM_VIDA), 2, ++linha);
    linha = escreveBlocoDeTexto(L"    Força: " + to_wstring(PERSONAGEM_FORCA), 2, linha);
    linha = escreveBlocoDeTexto(L"Sabedoria: " + to_wstring(PERSONAGEM_SABEDORIA), 2, linha);

    linha = escreveBlocoDeTexto(L" PRESSIONE ENTER ", 61, TELA_ALTURA - 1);
    imprimirMatriz();
    aguardarEnter();
}

void apresentaCenario(int cenario, int id, int init)
{
    wifstream cenariosTxt("./cenarios.json");
    wstringstream buff;
    wstring lnString;
    if (cenariosTxt.is_open())
    {
        while (getline(cenariosTxt, lnString))
        {
            buff << lnString << endl;
        }
        cenariosTxt.close();
    }

    wstring bf = buff.str();

    string c = "cenario" + to_string(cenario) + "." + to_string(id);
    auto json = json::parse(bf);
    auto cen = json[c][init];

    bool reexibir = false;

    do{
        int linha = 1;
        limparTela();
        inicializaMatriz();
        linha = escreveBlocoDeTexto(L"CENTRO UNIVERSITÁRIO GOVERNADOR OZANAN COELHO - UNIFAGOC", 11, linha);
        linha = escreveBlocoDeTexto(L"CIÊNCIA DA COMPUTAÇÃO - PROJETO INTEGRADOR I - PROJETO R", 11, linha);
        linha = escreveLinhaHorizontal(linha);

        for (auto &element : cen["descricao"])
        {
            wstring linhaWSTR = L"";
            if(element.is_null()){
                linha = escreveBlocoDeTexto(L" PRESSIONE ENTER ", 61, TELA_ALTURA - 1);
                imprimirMatriz();
                aguardarEnter();

                linha = 1;
                limparTela();
                inicializaMatriz();
                linha = escreveBlocoDeTexto(L"CENTRO UNIVERSITÁRIO GOVERNADOR OZANAN COELHO - UNIFAGOC", 11, linha);
                linha = escreveBlocoDeTexto(L"CIÊNCIA DA COMPUTAÇÃO - PROJETO INTEGRADOR I - PROJETO R", 11, linha);
                linha = escreveLinhaHorizontal(linha);
                continue;
            }
            StringToWString(linhaWSTR, element.get<std::string>());
            linha = escreveBlocoDeTexto(L"" + linhaWSTR, 6, linha);
        }

        linha = (cen["opcoes"]).size() + 4;
        linha = TELA_ALTURA - linha;
        int opcao = 1;
        for (auto &element : cen["opcoes"])
        {
            wstring linhaWSTR = L"";
            StringToWString(linhaWSTR, element.get<std::string>());
            linha = escreveBlocoDeTexto(L"" + to_wstring(opcao) + L" - " + linhaWSTR, 2, linha);
            opcao++;
        }

        linha = escreveBlocoDeTexto(L"F - Ficha do Personagem", 2, linha);

        linha = escreveBlocoDeTexto(L"Qual a sua escolha?", 2, ++linha);

        imprimirMatriz();

        char opcoes[7] = {'1', '2', '3', '4', '5', 'F', 'f'};
        wstring op = aguradaEntradaDeDados(22, --linha, opcoes);

        if(op.compare(L"F") == 0){
            reexibir = true;
            fichaDoPersonagem();
        }else{
            reexibir = false;
            opcao = stoi(op) - 1;

            int numOpcoes = (cen["opcoes"]).size();
            if( opcao >= numOpcoes ){
                reexibir = true;
                linha = 1;

                limparTela();
                inicializaMatriz();
                linha = escreveBlocoDeTexto(L"CENTRO UNIVERSITÁRIO GOVERNADOR OZANAN COELHO - UNIFAGOC", 11, linha);
                linha = escreveBlocoDeTexto(L"CIÊNCIA DA COMPUTAÇÃO - PROJETO INTEGRADOR I - PROJETO R", 11, linha);
                linha = escreveLinhaHorizontal(linha);

                linha = escreveBlocoDeTexto(L"OPÇÃO INVÁLIDA. Tente novamente!", 2, linha);

                linha = escreveBlocoDeTexto(L" PRESSIONE ENTER ", 61, TELA_ALTURA - 1);
                imprimirMatriz();
                aguardarEnter();

                continue;
            }

            auto acao = cen["acoes"][opcao];

            if( acao["op"] != -1)
            {
                int proximoCenario = acao["op"];
                apresentaCenario(cenario, id, proximoCenario);
            } else {
                linha = 1;
                limparTela();
                inicializaMatriz();
                linha = escreveBlocoDeTexto(L"CENTRO UNIVERSITÁRIO GOVERNADOR OZANAN COELHO - UNIFAGOC", 11, linha);
                linha = escreveBlocoDeTexto(L"CIÊNCIA DA COMPUTAÇÃO - PROJETO INTEGRADOR I - PROJETO R", 11, linha);
                linha = escreveLinhaHorizontal(linha);

                if ((acao["caracteristica"].get<std::string>()).compare("FORCA") == 0){
                    PERSONAGEM_FORCA += stoi(acao["mod"].dump());
                }else if((acao["caracteristica"].get<std::string>()).compare("SABEDORIA") == 0){
                    PERSONAGEM_SABEDORIA += stoi(acao["mod"].dump());
                }else {
                    PERSONAGEM_VIDA += stoi(acao["mod"].dump());
                }

                if(acao["mod"] > 0){
                    linha = escreveBlocoDeTexto(L"    .-\"\"\"\"\"\"-.    ", 30, linha);
                    linha = escreveBlocoDeTexto(L"  .'          '.  ", 30, linha);
                    linha = escreveBlocoDeTexto(L" /   O      O   \\ ", 30, linha);
                    linha = escreveBlocoDeTexto(L":                :", 30, linha);
                    linha = escreveBlocoDeTexto(L"|                |", 30, linha);
                    linha = escreveBlocoDeTexto(L": ',          ,' :", 30, linha);
                    linha = escreveBlocoDeTexto(L" \\  '-......-'  / ", 30, linha);
                    linha = escreveBlocoDeTexto(L"  '.          .'  ", 30, linha);
                    linha = escreveBlocoDeTexto(L"    '-......-'    ", 30, linha);
                }
                if(acao["mod"] == 0){
                    linha = escreveBlocoDeTexto(L"    .-\"\"\"\"\"\"-.    ", 30, linha);
                    linha = escreveBlocoDeTexto(L"  .'          '.  ", 30, linha);
                    linha = escreveBlocoDeTexto(L" /   O      O   \\ ", 30, linha);
                    linha = escreveBlocoDeTexto(L":                :", 30, linha);
                    linha = escreveBlocoDeTexto(L"|                |", 30, linha);
                    linha = escreveBlocoDeTexto(L":                :", 30, linha);
                    linha = escreveBlocoDeTexto(L" \\  ---------   / ", 30, linha);
                    linha = escreveBlocoDeTexto(L"  '.          .'  ", 30, linha);
                    linha = escreveBlocoDeTexto(L"    '-......-'    ", 30, linha);
                }
                if(acao["mod"] < 0){
                    linha = escreveBlocoDeTexto(L"    .-\"\"\"\"\"\"-.    ", 30, linha);
                    linha = escreveBlocoDeTexto(L"  .'          '.  ", 30, linha);
                    linha = escreveBlocoDeTexto(L" /   O      O   \\ ", 30, linha);
                    linha = escreveBlocoDeTexto(L":                :", 30, linha);
                    linha = escreveBlocoDeTexto(L"|                |", 30, linha);
                    linha = escreveBlocoDeTexto(L":    .------.    :", 30, linha);
                    linha = escreveBlocoDeTexto(L" \\  '        '  / ", 30, linha);
                    linha = escreveBlocoDeTexto(L"  '.          .'  ", 30, linha);
                    linha = escreveBlocoDeTexto(L"    '-......-'    ", 30, linha);
                }


                for (auto &element : acao["mensagem"])
                {
                    wstring linhaWSTR = L"";
                    StringToWString(linhaWSTR, element.get<std::string>());
                    linha = escreveBlocoDeTexto(L"" + linhaWSTR, 6, linha);
                }

                linha = escreveBlocoDeTexto(L" PRESSIONE ENTER ", 61, TELA_ALTURA - 1);
                imprimirMatriz();
                aguardarEnter();
            }
        }
    }while(reexibir);
}

void torneio()
{
    ADVERSARIO_VIDA = PERSONAGEM_VIDA;
    if (DIFICULDADE == 1)
    {
        ADVERSARIO_FORCA = PERSONAGEM_FORCA - 2;
        ADVERSARIO_SABEDORIA = PERSONAGEM_SABEDORIA - 2;
    }
    else if (DIFICULDADE == 2)
    {
        ADVERSARIO_FORCA = PERSONAGEM_FORCA;
        ADVERSARIO_SABEDORIA = PERSONAGEM_SABEDORIA;
    }
    else
    {
        ADVERSARIO_FORCA = PERSONAGEM_FORCA + 1;
        ADVERSARIO_SABEDORIA = PERSONAGEM_SABEDORIA + 1;
    }

    int linha = 1;
    limparTela();
    inicializaMatriz();
    linha = escreveBlocoDeTexto(L"CENTRO UNIVERSITÁRIO GOVERNADOR OZANAN COELHO - UNIFAGOC", 11, linha);
    linha = escreveBlocoDeTexto(L"CIÊNCIA DA COMPUTAÇÃO - PROJETO INTEGRADOR I - PROJETO R", 11, linha);
    linha = escreveLinhaHorizontal(linha);

    linha = escreveBlocoDeTexto(L"É chegada a hora do torneio. Sua jornada chega ao seu ponto mais importante. Agora você encontrará com seu adversário.", 6, ++linha);
    linha = escreveBlocoDeTexto(L"Do outro reino, Sir. " + ADVERSARIO_NOME + L" vem de uma longa linhagem de guerreiros implacáveis. Ele vem de um longo treinamento com os mestres de seu reino e acumula uma vitalidade invejável (" + to_wstring(ADVERSARIO_VIDA) + L" PONTOS). Sua força (" + to_wstring(ADVERSARIO_FORCA) + L" PONTOS) já lhe rendeu uma galeria inteira de prémios, mas nem mesmo isso tirou seu foco. Ele é sábio (" + to_wstring(ADVERSARIO_SABEDORIA) + L" PONTOS) como os anciões e forte como os jovens.", 6, ++linha);
    linha = escreveBlocoDeTexto(L"Tenha muito cuidado!!", 6, ++linha);

    linha = escreveBlocoDeTexto(L"Sua batalha será em turnos. A cada rodada, você terá a opção de escolher entre atacar ou defender. Assim que o fizer, o universo decidirá o quão bem sucedido você foi em um rolar de dados. Seu dano, infligido ou sofrido, será a combinação desse valor dos dados e da diferença entre a força do atacante e a sabedoria do defensor. Seja esperto e escolha bem!", 6, ++linha);

    linha = escreveBlocoDeTexto(L" PRESSIONE ENTER ", 61, TELA_ALTURA - 1);
    imprimirMatriz();
    aguardarEnter();

    int modificadorAtaque = PERSONAGEM_FORCA - ADVERSARIO_SABEDORIA;
    int modificadorDefesa = ADVERSARIO_FORCA - PERSONAGEM_SABEDORIA;

    bool torneioContinua = true;

    do
    {
        int rolarDeDados = rand() % 6 + 1;

        wcout << L"-----------------" << endl;
        wcout << L"Personagem vida: " << PERSONAGEM_VIDA << endl;
        wcout << L"Adversário vida: " << ADVERSARIO_VIDA << endl;
        wcout << L"Atacar ou defender?" << endl;
        char opcao = aguardaCaracter("aAdD");

        if (opcao == 'A')
        {
            int dano = rolarDeDados + modificadorAtaque;
            if (dano > 0)
            {
                ADVERSARIO_VIDA -= dano;
            }
            if (dano < 0)
            {
                PERSONAGEM_VIDA += dano;
            }
        }

        if (PERSONAGEM_VIDA <= 0 && TESTE_SEGUNDA_CHANCE)
        {
            TESTE_SEGUNDA_CHANCE = false;
            PERSONAGEM_VIDA = 0;
            torneioContinua = false;
            apresentaCenario(0, 0, 0);
            if (PERSONAGEM_VIDA > 0)
            {
                torneioContinua = true;
                PERSONAGEM_VIDA = 10;
            }
        }
        else
        {
            if (ADVERSARIO_VIDA <= 0)
            {
                torneioContinua = false;
            }
        }

    } while (torneioContinua);
}

int main()
{
    _setmode(_fileno(stdout), _O_U16TEXT);
    srand(time(NULL));

    telaDeConfiguracaoDoTerminal();
    telaDeApresentacao();
    telaDeIntroducaoDaHistoria();
    telaDeSelecaoDeDificuldadeENomeDoPersonagem();
    tutorialDeJogabilidade();

    bool treinamento = false;
    do
    {
        int numeroAleatorio = rand() % 100 + 1;
        if (numeroAleatorio <= 33)
        {
            numeroAleatorio = rand() % 3;
            apresentaCenario(1, numeroAleatorio, 0);
        }
        else if (numeroAleatorio <= 67)
        {
            numeroAleatorio = 0; // rand() % 3;
            apresentaCenario(2, numeroAleatorio, 0);
        }
        else
        {
            numeroAleatorio = rand() % 3;
            apresentaCenario(3, numeroAleatorio, 0);
        }
        treinamento = testeCondicoesParaTreinamento();
    } while (treinamento);

    if(!testeCondicoesPreTorneio()){
        telaDeGameOver();
        telaDeCreditos();
        return 0;
    }/**/

    torneio();

    if(PERSONAGEM_VIDA <= 0){
        telaDeGameOver();
        telaDeCreditos();
        return 0;
    }

    telaDeSucesso();
    telaDeCreditos();

    return 0;
}
