#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <time.h>

using namespace std;

void limpaTela(){
    system("CLS");
}

string retornaPalavraAleatoria(){

    string palavras[5] = {"calend�rio", "jaleco", "bloco", "caneta", "cadeira"};

    int indiceAleatorio = rand() % 5;

    return palavras[indiceAleatorio];
}

string retornaPalavraComMascara(string palavra, int tamanhoDaPalavra){

    int cont = 0;
    string palavraComMascara;

    while(cont < tamanhoDaPalavra){
        palavraComMascara += "_";
        cont++;
    }

    return palavraComMascara;
}

void exibeStatus(string palavraComMascara, int tamanhoDaPalavra, int tentativasRestantes, string letrasJaArriscadas, string mensagem){

    cout << mensagem;
    cout << "\nPalavra:" << palavraComMascara << "(Tamanho:" << tamanhoDaPalavra << ")";
    cout << "\nTentativas Restantes:" << tentativasRestantes;

    int cont;
    cout << "\nLetras arriscadas:";
    for(cont = 0; cont < letrasJaArriscadas.size();cont++){
        cout << letrasJaArriscadas[cont] << ", ";
    }

}

int jogar(int numeroDeJogadores){

    string palavra;

    if(numeroDeJogadores == 1){

        palavra = retornaPalavraAleatoria();

    }else{

        cout << "\nDigite uma palavra:";
        cin >> palavra;

    }

    int tamanhoDaPalavra = palavra.size();

    string palavraComMascara = retornaPalavraComMascara(palavra, tamanhoDaPalavra);

    int tentativas = 0, maximoDeTentativas = 10;
    int cont = 0;
    char letra;
    int opcao;
    string letrasJaArriscadas;
    string mensagem = "Bem vindo ao jogo!";
    string palavraArriscada;
    bool jaDigitouLetra = false, acertouLetra = false;


    while(palavra != palavraComMascara && maximoDeTentativas - tentativas > 0){

        limpaTela();

        exibeStatus(palavraComMascara, tamanhoDaPalavra, maximoDeTentativas - tentativas, letrasJaArriscadas,mensagem);

        cout << "\nDigite uma letra (Ou digite 1 para arriscar a palavra):";
        cin >> letra;


        if(letra == '1'){
            cin >> palavraArriscada;
            if(palavraArriscada == palavra){
                 palavraComMascara = palavraArriscada;
            }else{
                 tentativas = maximoDeTentativas;
            }
        }

        for(cont = 0; cont < tentativas; cont++){

            if(letrasJaArriscadas[cont] == letra){

                mensagem = "Essa letra ja foi digitada!";

                jaDigitouLetra = true;

            }
        }

        if(jaDigitouLetra == false){

            letrasJaArriscadas += tolower(letra);


            for(cont = 0; cont < tamanhoDaPalavra; cont++){

                if(palavra[cont] == tolower(letra)){

                    palavraComMascara[cont] = palavra[cont];

                    acertouLetra = true;

                }
            }

            if(acertouLetra == false){

                mensagem = "Voce errou uma letra!";

            }else{

                mensagem = "Voce acertou uma letra!";

            }


            tentativas++;

        }

        jaDigitouLetra = false;
        acertouLetra = false;

    }

    if(palavra == palavraComMascara){

        limpaTela();
        cout << "Parab�ns, voc� venceu!";
        cout << "\nVamos Jogar Novamente?";
        cout << "\n1-Sim";
        cout << "\n2-Nao";
        cin >> opcao;
        return opcao;

    }else{

        limpaTela();
        cout << "Que pena! voc� perdeu!";
        cout << "\nVamos Jogar Novamente?";
        cout << "\n1-Sim";
        cout << "\n2-Nao";
        cin >> opcao;
        return opcao;
    }

}

void menuInicial(){

    int opcao = 0;

    while(opcao < 1 || opcao > 3){
        limpaTela();
        cout << "Bem vindo ao Jogo";
        cout << "\n1 - Jogar Sozinho";
        cout << "\n2 - Jogar em Dupla";
        cout << "\n3 - Sobre";
        cout << "\n4 - Sair";
        cout << "\nEscolha uma op��o e tecle ENTER:";

        cin >> opcao;

        switch(opcao){
            case 1:
                if(jogar(1) == 1){
                    menuInicial();
                }
                break;
            case 2:

                if(jogar(2) == 1){
                    menuInicial();
                }
                break;
            case 3:
                cout << "Informacoes do jogo";
                limpaTela();
                cout << "Jogo desenvolvido por Thaynara em 2019, para ser passado em sala para os alunos";
                cout << "\n1 - Voltar";
                cout << "\n2 - Sair";
                cin >> opcao;
                if(opcao == 1){
                    menuInicial();
                }

                break;
            case 4:
                cout << "Inte!";
                break;
        }
    }

}

int main(){
    setlocale(LC_ALL,"Portuguese_Brazil");

    srand( (unsigned)time(NULL));

    menuInicial();

    return 0;
}
