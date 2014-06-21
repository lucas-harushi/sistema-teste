#include<stdio.h>
#include<locale.h>
#include"007 - Funções Sistema de avião.c"
#include<stdlib.h>

int Menu();
int Preencher(int Aviao[]);
int Exibir (int Aviao[]);
int Janela (int Aviao[]);
int Livres (int Aviao[]);
int Reservar (int Aviao[]);
int Aleatorio (int Aviao[]);
int Salvar (int Aviao[]);
int Verificar_Char ();

int main () {
    int Aviao[25][4], Escolha, Verificar = 0, Fileira = 0, cont, Save, Load;
    int Linhas, Colunas;

    FILE *Arquivo;

    if (Verificar == 0) {
        Verificar = 1;
        Preencher(Aviao[0]);
    }

    Inicio:

    getch();
    system("CLS");

    Menu();
    //Verificar_Char (Escolha);
    //Escolha = Verificar_Char(Escolha);
    scanf("%d",&Escolha);


    switch(Escolha) {

    case 1:
        system("CLS");
        Exibir(Aviao[0]);
        break;

    case 2:
        system("CLS");
        Janela(Aviao[0]);
        break;

    case 3:
        system("CLS");
        Livres(Aviao[0]);
        break;

    case 4:
        system("CLS");
        Reservar(Aviao[0]);
        break;

    case 5:
        system("CLS");
        Aleatorio(Aviao[0]);
        break;

    case 6:
        system("CLS");
        Salvar(Aviao[0]);

        Arquivo = fopen("Avião.bin", "wb");

        if(Arquivo == NULL) {
            printf("Erro na abertura\n");
            goto Inicio;
        }

        Save = fwrite(Aviao, sizeof(int), 100, Arquivo);

        if(Save != 100) {
            printf("Erro na leitura do arquivo!");
            goto Inicio;
        }
        fclose(Arquivo);
        break;

    case 7:
        system("CLS");

        Arquivo = fopen("Avião.bin", "rb");

        if(Arquivo == NULL) {
            printf("Erro na abertura\n");
            goto Inicio;
        }

        Load = fread(Aviao, sizeof(int), 100, Arquivo);

        if(Load != 100) {
            printf("Erro na leitura do arquivo!");
            goto Inicio;
        }
        fclose(Arquivo);
        printf("Arquivo carregado!");
        break;

    case 8:
        printf("Salvar arquivos [1 - Sim, 2 - N%co]\n", 198);
        scanf("%d", &Escolha);

        if(Escolha == 1) {
            system("CLS");

        Arquivo = fopen("Avião.bin", "wb");

        if(Arquivo == NULL) {
            printf("Erro na abertura\n");
            goto Inicio;
        }

        Save = fwrite(Aviao, sizeof(int), 100, Arquivo);

        if(Save != 100) {
            printf("Erro na leitura do arquivo!");
            goto Inicio;
        }
        fclose(Arquivo);

        printf("Arquivo salvo com sucesso!");
        getch();
        Escolha = 0;
        }
        else exit(0);
    }
    if(Escolha > 0) goto Inicio;

 printf("Voce e viado cara '-'");
}
