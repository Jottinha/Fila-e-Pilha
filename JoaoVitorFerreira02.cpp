#include <iostream>
#include <stdio.h>
#include<stdbool.h>

typedef struct fila{
    int senha;
    bool prioridade;
    struct fila *proximo;
}Fila;

void chamarProximo(Fila* pessoaFila);
void desenfileirar(Fila *fila);
Fila* novaFilaComum(Fila *mainList);
Fila* novaFilaPrioridade(Fila *mainList);
Fila* criandoFilaVazia();

int senhaComum = 0;
int senhaPrioridade = 1000;
int totalSenhas = 2;

int main(int argc, char const* argv[ ])
{
    Fila *filaPrioridade = NULL;
    filaPrioridade = criandoFilaVazia();

    Fila *filaComum = NULL;
    filaComum = criandoFilaVazia();

    int resposta = 0;
    do{
        std::cout <<"Atendimento prioritario (1)\nAtendimento comum (2)\nFinalizar senhas(4)\n";
        std::cin >> resposta;

        switch(resposta)
        {
            case 1:
                filaPrioridade = novaFilaPrioridade(filaPrioridade);
                break;
            case 2:
                filaComum = novaFilaComum(filaComum);
                break;
            case 4:
                break;
            default:
                std::cout <<"Invalido"<<std::endl;
                break;
        }
    }while(resposta != 4);

    int resposta1 = 0;

    do
    {
        std::cout <<"Chamar  alguem da fila (1)\nFinalizar programada (2)\n";
        std::cin >> resposta1;

        switch(resposta1)
        {
        case 1:
            if(filaPrioridade -> proximo -> senha == NULL)
            {
                totalSenhas = 0;
            }

            if(totalSenhas != 0)
            {
                if(filaPrioridade -> proximo -> senha != NULL)
                {
                    chamarProximo(filaPrioridade);
                    totalSenhas--;
                }
            }
            else
            {
                if(filaComum -> proximo -> senha != NULL)
                {
                    chamarProximo(filaComum);
                    totalSenhas = 2;
                }
            }
            if(filaComum -> proximo -> senha == NULL && filaPrioridade -> proximo -> senha == NULL)
            {
                exit(1);
            }
            break;
        case 2:
            break;
        default:
            std::cout <<"Invalido"<<std::endl;
            break;
        }
    }while(resposta1 != 2);

    std::cout <<"\n\nAtendimento finalizado";
}

Fila* criandoFilaVazia(){
    Fila *mainList = NULL;
    mainList = (Fila*)malloc(sizeof(Fila*));
    mainList -> proximo = mainList;

    return mainList;
}

Fila* novaFilaPrioridade(Fila *mainList){
    Fila* novaFila = NULL;
    novaFila = criandoFilaVazia();

    novaFila -> proximo = mainList -> proximo;
    mainList -> proximo = novaFila;

    senhaPrioridade++;
    mainList -> senha = senhaPrioridade;
    mainList ->prioridade = true;

    return novaFila;
}

Fila* novaFilaComum(Fila *mainList){
    Fila* novaFila = NULL;
    novaFila = criandoFilaVazia();

    novaFila -> proximo = mainList -> proximo;
    mainList -> proximo = novaFila;

    senhaComum++;
    mainList -> senha = senhaComum;
    mainList ->prioridade = false;

    return novaFila;
}

void desenfileirar(Fila *fila){
	Fila *aux = NULL;

	aux = fila->proximo;
	fila->proximo = aux->proximo;
	free(aux);
}

void chamarProximo(Fila* pessoaFila)
{
    std::cout <<"Chamando senha: "<<pessoaFila -> proximo -> senha;
    desenfileirar(pessoaFila);
}

