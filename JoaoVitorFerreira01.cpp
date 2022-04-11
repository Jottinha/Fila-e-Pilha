#include <stdio.h>
#include <iostream>
#include <ctype.h>
#include <conio.h>

#ifdef __unix__
    #include <unistd.h>
    #include <stdlib.h>

#elif defined(_WIN32) || defined(WIN32)

   #define OS_Windows

   #include <windows.h>

#endif

typedef struct pilha{
    int site;
    struct pilha *proximo;
}Pilha;

void apagarTela();
Pilha* criandoPilhaVazia(Pilha *mainPilha);
Pilha* novaPilhaPrincipal(Pilha *mainPilha);
Pilha* novaPilhaAvan(Pilha *mainPilha);
Pilha* novaPilhaRec(Pilha *mainPilha);
int top(Pilha *mainPilha);
int menuPrimario(Pilha *pilhaPrincipal, Pilha *pilhaAvan, Pilha *pilhaRecuar, int resposta);
int menuSecundario(Pilha *pilhaPrincipal, Pilha *pilhaAvan, Pilha *pilhaRecuar, int resposta);
int menuTerciario(Pilha *pilhaPrincipal, Pilha *pilhaAvan, Pilha *pilhaRecuar, int resposta);
int ultimoMenu(Pilha *pilhaPrincipal, Pilha *pilhaAvan, Pilha *pilhaRecuar, int resposta);
void desenfileirar(Pilha *pilhaDesejada);

int siteNumeroTotalPrincipal = 0;
int siteNumeroTotalRec = 0;
int siteNumeroTotalAvan = 0;

int main(int argc, char *const argv[ ])
{
    int resposta = 0;

    //iniciando as pilhas
    Pilha *pilhaPrincipal = NULL;
    Pilha *pilhaAvan = NULL;
    Pilha *pilhaRecuar = NULL;

    pilhaPrincipal = criandoPilhaVazia(pilhaPrincipal);
    pilhaAvan = criandoPilhaVazia(pilhaAvan);
    pilhaRecuar = criandoPilhaVazia(pilhaRecuar);

    //inicializando o programa já em um primeiro link
    pilhaPrincipal = novaPilhaPrincipal(pilhaPrincipal);
    std::cout <<"SUA PAGINA\n\nSite: https://www.atividade.com/";
    std::cout <<pilhaPrincipal -> proximo -> site <<"\n\n";
    std::cout <<"\n\n\nAperte qualquer tecla para continuar";
    getch();
    apagarTela();
    do{
        if(pilhaRecuar -> proximo == NULL && pilhaAvan -> proximo == NULL)
        {
            resposta = menuPrimario(pilhaPrincipal, pilhaAvan, pilhaRecuar, resposta);
            std::cout <<"SUA PAGINA\n\nSite: https://www.atividade.com/";
            std::cout <<pilhaPrincipal -> proximo -> site << std::endl;
            std::cout <<"\n\n\nAperte qualquer tecla para continuar";
            getch();
            apagarTela();
        }
        else if(pilhaRecuar -> proximo != NULL && pilhaAvan -> proximo == NULL)
        {
            resposta = menuSecundario(pilhaPrincipal, pilhaAvan, pilhaRecuar, resposta);
            std::cout <<"SUA PAGINA\n\nSite: https://www.atividade.com/";
            std::cout <<pilhaPrincipal -> proximo -> site << std::endl;
            std::cout <<"\n\n\nAperte qualquer tecla para continuar";
            getch();
            apagarTela();
        }
        else if(pilhaRecuar -> proximo != NULL && pilhaAvan -> proximo != NULL)
        {
            resposta = menuTerciario(pilhaPrincipal, pilhaAvan, pilhaRecuar, resposta);
            std::cout <<"SUA PAGINA\n\nSite: https://www.atividade.com/";
            std::cout <<pilhaPrincipal -> proximo -> site << std::endl;
            std::cout <<"\n\n\nAperte qualquer tecla para continuar";
            getch();
            apagarTela();
        }
        else
        {
            resposta = ultimoMenu(pilhaPrincipal, pilhaAvan, pilhaRecuar, resposta);
            std::cout <<"SUA PAGINA\n\nSite: https://www.atividade.com/";
            std::cout <<pilhaPrincipal -> proximo -> site << std::endl;
            std::cout <<"\n\n\nAperte qualquer tecla para continuar";
            getch();
            apagarTela();
        }
    }while(resposta != 1);
}
Pilha* criandoPilhaVazia(Pilha *mainPilha){
    mainPilha = (Pilha*)malloc(sizeof(Pilha*));
    mainPilha -> proximo = NULL;

    return mainPilha;
}

Pilha* novaPilhaPrincipal(Pilha *mainPilha){

    Pilha *criandoPilha = criandoPilhaVazia(criandoPilha);

    siteNumeroTotalPrincipal++;

    criandoPilha -> site = siteNumeroTotalPrincipal;
    criandoPilha -> proximo = mainPilha -> proximo;
    mainPilha -> proximo = criandoPilha;

    return mainPilha;
}

Pilha* novaPilhaRec(Pilha *mainPilha){

    Pilha *criandoPilha = criandoPilhaVazia(criandoPilha);

    siteNumeroTotalRec++;

    criandoPilha -> site = siteNumeroTotalRec;
    criandoPilha -> proximo = mainPilha -> proximo;
    mainPilha -> proximo = criandoPilha;

    return mainPilha;
}

Pilha* novaPilhaAvan(Pilha *mainPilha){

    Pilha *criandoPilha = criandoPilhaVazia(criandoPilha);

    siteNumeroTotalAvan++;

    criandoPilha -> site = siteNumeroTotalAvan;
    criandoPilha -> proximo = mainPilha -> proximo;
    mainPilha -> proximo = criandoPilha;

    return mainPilha;
}

int top(Pilha *mainPilha){

	return mainPilha -> proximo -> site;
}

int menuPrimario(Pilha *pilhaPrincipal, Pilha *pilhaAvan, Pilha *pilhaRecuar, int resposta){

    char respostaUser;
    resposta = 0;
    std::cout << "Abrir novo link - Sim (s) ou Nao (n): ";
    std::cin >> respostaUser;

    respostaUser = toupper(respostaUser);

    switch(respostaUser)
    {

    case 'S':
        pilhaPrincipal = novaPilhaPrincipal(pilhaPrincipal);
        pilhaRecuar = novaPilhaRec(pilhaRecuar);
        break;
    case 'N':
        resposta = 1;
        break;
    default:
        std::cout <<"Resposta invalida";
        break;
    }
    return resposta;
}

int menuSecundario(Pilha *pilhaPrincipal, Pilha *pilhaAvan, Pilha *pilhaRecuar, int resposta){

    char respostaUser;
    resposta = 0;
    std::cout << "Abrir novo link - Sim (s)\nVoltar link anterior(b)\nFechar programa (n): \n";
    std::cin >> respostaUser;

    respostaUser = toupper(respostaUser);

    switch(respostaUser)
    {

    case 'S':
        pilhaPrincipal = novaPilhaPrincipal(pilhaPrincipal);
        pilhaRecuar = novaPilhaRec(pilhaRecuar);
        break;
    case 'N':
        resposta = 1;
        break;
    case 'B':
        siteNumeroTotalAvan = siteNumeroTotalPrincipal;
        pilhaAvan = novaPilhaAvan(pilhaAvan);
        desenfileirar(pilhaPrincipal);
        desenfileirar(pilhaRecuar);
        siteNumeroTotalPrincipal --;
        siteNumeroTotalRec --;
        break;
    default:
        std::cout <<"Resposta invalida";
        break;
    }
    return resposta;
}

int menuTerciario(Pilha *pilhaPrincipal, Pilha *pilhaAvan, Pilha *pilhaRecuar, int resposta){

    char respostaUser;
    resposta = 0;

    std::cout << "Abrir novo link(s)\nVoltar link anterior(b)\nAvançar pagina(a)\nFechar programa(n): ";
    std::cin >> respostaUser;
    std::cout <<std::endl;

    respostaUser = toupper(respostaUser);

    switch(respostaUser)
    {

    case 'S':
        //apaga a pilha de avançado
        pilhaAvan -> proximo = NULL;
        siteNumeroTotalAvan = 0;
        pilhaPrincipal = novaPilhaPrincipal(pilhaPrincipal);
        pilhaRecuar = novaPilhaRec(pilhaRecuar);
        break;
    case 'N':
        resposta = 1;
        break;
    case 'B':
        siteNumeroTotalAvan --;
        pilhaAvan = novaPilhaAvan(pilhaAvan);
        desenfileirar(pilhaPrincipal);
        desenfileirar(pilhaRecuar);
        siteNumeroTotalPrincipal --;
        siteNumeroTotalRec --;
        break;
    case 'A':
        desenfileirar(pilhaAvan);
        pilhaPrincipal = novaPilhaPrincipal(pilhaPrincipal);
        pilhaRecuar = novaPilhaRec(pilhaRecuar);
        break;
    default:
        std::cout <<"Resposta invalida";
        break;
    }
    return resposta;
}

int ultimoMenu(Pilha *pilhaPrincipal, Pilha *pilhaAvan, Pilha *pilhaRecuar, int resposta){

    char respostaUser;
    resposta = 0;
    std::cout << "Abrir novo link(s)\nAvançar pagina(a)\nFechar programa(n): ";
    std::cin >> respostaUser;
    std::cout <<std::endl;

    respostaUser = toupper(respostaUser);

    switch(respostaUser)
    {

    case 'S':
        //apaga a pilha de avançado
        pilhaAvan -> proximo = NULL;
        siteNumeroTotalAvan = 0;
        pilhaPrincipal = novaPilhaPrincipal(pilhaPrincipal);
        pilhaRecuar = novaPilhaRec(pilhaRecuar);
        break;
    case 'N':
        resposta = 1;
        break;
    case 'A':
        desenfileirar(pilhaAvan);
        pilhaPrincipal = novaPilhaPrincipal(pilhaPrincipal);
        pilhaRecuar = novaPilhaRec(pilhaRecuar);
        break;
    default:
        std::cout <<"Resposta invalida";
        break;
    }
    return resposta;
}

void desenfileirar(Pilha *pilhaDesejada){
	Pilha *aux = NULL;

	aux = pilhaDesejada->proximo;
	pilhaDesejada -> proximo = aux -> proximo;
	free(aux);
}

void apagarTela()
{
    #ifdef OS_Windows
    /* Codigo Windows */
    system("cls");
    #else
    /* Codigo GNU/Linux */
    system("clear");
    #endif
}
