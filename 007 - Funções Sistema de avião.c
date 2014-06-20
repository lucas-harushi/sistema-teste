#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>

int Verificar_Char (int Assento);


int Menu () {
    printf("(1) Exibir assentos\n");
    printf("(2) Exibir assentos na janela\n");
    printf("(3) Exibir assentos livres\n");
    printf("(4) Reservar assento\n");
    printf("(5) Assentos Aleat%crio\n", 162);
    printf("(6) Salvar\n");
    printf("(7) Carregar\n");
    printf("(8) Sair\n");

}


int Preencher (int Aviao[]) {
    int cont, *Ponteiro;
    srand(time(NULL));

    Ponteiro = Aviao;

    for(cont = 0; cont < 100; cont++) {
        *(Ponteiro + cont) = rand()%2;
    }
}


int Exibir (int Aviao[]) {
    int cont, *Ponteiro, Fileira = 1;

    Ponteiro = Aviao;

    printf("     A   B   C   D     \n");

    for(cont = 0; cont < 25; cont++) {

        if(Fileira < 10) printf("\n%d    ", Fileira);
        else printf("\n%d   ", Fileira);
        Fileira++;

        printf("%d   %d   %d   %d\n", *(Ponteiro + cont), *(Ponteiro + (cont + 25)), *(Ponteiro + (cont + 50)), *(Ponteiro + (cont + 75)));
    }
}


int Janela (int Aviao[]) {
    int cont, *Ponteiro, Fileira = 1;

    Ponteiro = Aviao;

    printf("     A   B   C   D     \n");

    for(cont = 0; cont < 25; cont++) {

        if(Fileira < 10) printf("\n%d    ", Fileira);
        else printf("\n%d   ", Fileira);
        Fileira++;

        printf("%d   %d\n", *(Ponteiro + cont), *(Ponteiro + (cont + 75)));
    }
}


int Livres (int Aviao[]) {
    int cont, *Ponteiro, Fileira = 0;

    Ponteiro = Aviao;

    for(cont = 0; cont < 100; cont++) {

        Fileira = cont/25;

        if(cont%25 == 0) printf("\n\n");

        if((Fileira + 1)%25 == 0 ) printf("\n\n%d",Fileira);

        if(*(Ponteiro + cont) == 0) {
            if (Fileira == 0) printf("A %d\n", cont + 1);
            if (Fileira == 1) printf("B %d\n", cont + 1 - 25);
            if (Fileira == 2) printf("C %d\n", cont + 1 - 50);
            if (Fileira == 3) printf("D %d\n", cont + 1 - 75);
        }
    }
}


int Reservar (int Aviao[]) {

    int Assento, *Ponteiro, Letra;
    char Caractere;

    Ponteiro = Aviao;

    Inicio:
    Assento = 0; Letra = 0;

    printf("Selecionar Fileira  [A, B, C, D]\n");
    fflush(stdin);
    scanf("%s", &Caractere);

    if      (Caractere == 'A' || Caractere == 'a') Letra = 1;
    else if (Caractere == 'B' || Caractere == 'b') Letra = 2;
    else if (Caractere == 'C' || Caractere == 'c') Letra = 3;
    else if (Caractere == 'D' || Caractere == 'd') Letra = 4;

    system("CLS");

    printf("Selecione um assento: [1 - 25]\n");
    //Verificar_Char(Assento);
    scanf("%d", &Assento);
    //printf("\n\n%d\n\n", Assento);
    getch();

    Assento--;

    if(Letra == 2) Assento += 25;
    if(Letra == 3) Assento += 50;
    if(Letra == 4) Assento += 75;

    if(*(Ponteiro + Assento) == 0) {
        printf("Assento reservado!");
        *(Ponteiro + Assento) = 1;
    }

    else {
        printf("Assento j%c est%c reservado\nEscolha outros", 160, 160);
        getch();
        system("CLS");
        goto Inicio;
    }
}


int Aleatorio (int Aviao[]) {
    int cont, *Ponteiro, Fileira = 0;

    Ponteiro = Aviao;

    for(cont = 0; cont < 100; cont++) {
        if(*(Ponteiro + cont) == 0) {
            *(Ponteiro + cont) = 1;
            Fileira = cont/25;

            cont++;
            if (Fileira == 0) printf("Acento reservado!\n Assento: A %d", cont);
            if (Fileira == 1) printf("Acento reservado!\n Assento: B %d", cont - 25);
            if (Fileira == 2) printf("Acento reservado!\n Assento: C %d", cont - 50);
            if (Fileira == 3) printf("Acento reservado!\n Assento: D %d", cont - 75);
            break;
        }
    }
}


int Salvar (int Aviao[]) {

    /*FILE *Arquivo;

    Arquivo = fopen("Avião.txt", "w");

    time_t currentTime;
    struct tm *timeinfo;
    char stringTime[51];

    currentTime= time(NULL);
    timeinfo= localtime(&currentTime);

    strftime(stringTime, 51, "%d/%m/%Y -- %H:%M:%S %p", timeinfo);

    fprintf(Arquivo, "\n%s\n",stringTime);

    fclose(Arquivo);*/


    printf("Arquivo salvo com sucesso!");
}


/*int Verificar_Char (int Assento) {

    char Caractere,texto[212];
    int cont=0, *Numero;

    Numero = Assento;

    //printf("\nVerificador\n\nDigite: ");

    do{
    Caractere=getch();

    if(isdigit(Caractere) && cont <10){
        texto[cont] = Caractere;
        printf("%c", texto[cont]);
        cont++;
    }

    else if(Caractere == 8 && cont){
        cont--;
        texto[cont]='\0';
        printf("\b \b");
    }
    else if (Caractere != 13)printf("\a");

    } while(Caractere != 13);

    texto[cont] = '\0';
    Numero = atol(texto);

    return Numero;
}*/
