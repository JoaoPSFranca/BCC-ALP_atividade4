#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int pront;
    char nome[60];
    int ramal;
} Tecnico;

Tecnico lerTecnico(int codigo){
    Tecnico tecnico;

    printf("\nA seguir, insira as informacoes para cadastrar um tecnico: \n");

    printf("\n Prontuario: ");
    if (codigo != 0) {
        printf("%d\n", codigo);
        tecnico.pront = codigo;
    }
    else {
        scanf("%d", &tecnico.pront);

        printf(" Nome: ");
        fflush(stdin);
        fgets(tecnico.nome, 60, stdin);
        tecnico.nome[strcspn(tecnico.nome, "\n")] = '\0';

        do {
            printf(" Ramal: ");
            scanf("%d", &tecnico.ramal);

            if (tecnico.ramal <= 0)
                printf("\nNumero invalido! digite um numero positivo.\n");

        } while (tecnico.ramal <= 0);
    }
    return tecnico;
}

void incluirTecnico(Tecnico tecnico){
    FILE *file;

    file = fopen("tecnicos.dat", "ab");//ab incluir arquivo binario

    if (file == NULL)
       file = fopen("tecnicos.dat", "wb"); // whrite binary archive

    if (file == NULL)
        printf("\nNao foi possivel abrir 'tecnicos.dat' em incluirTecnico.\n");
    else {
        fwrite(&tecnico, sizeof(Tecnico), 1, file);//fwrite grava o tecnico no final do arquivo
        fclose(file);
    }
}

int localizarTecnico(int pront){
    FILE *file;
    Tecnico t;
    int posicao = -1, i = 0;

    file = fopen("tecnicos.dat", "rb");
    if(file == NULL)
        printf("\nNao foi possivel abrir 'tecnicos.dat' em localizarTecnico.\n");
    else {
        fread(&t, sizeof(Tecnico), 1, file);

        // no while eu verifico se nao chegou ao fim do arquivo
        // e tambem se nao encontrou
        while(!feof(file) && posicao == -1) {
            if (t.pront == pront)
                posicao = i;
            else {
                i++;
                fread(&t, sizeof(Tecnico), 1, file);
            }
        }
    }
    return posicao;
}

Tecnico getTecnico(int posicao){
    FILE *file;
    Tecnico t;

    file = fopen("tecnicos.dat", "rb");
    if(file == NULL) {
        printf("\nNao foi possivel abrir 'tecnicos.dat' em getTecnico.\n");
    }
    else {
        // parametros
        // 1 - identificador do arquivo
        // 2 - quantas posicoes vou deslocar
        // 3 - a partir de onde comeca o deslocamento
        //          SEEK_SET - inicio do arquivo
        //          SEEK_CUR - posicao atual
        //          SEEK_END - final do arquivo
        fseek(file, posicao*sizeof(Tecnico), SEEK_SET);
        fread(&t, sizeof(Tecnico), 1, file);
        fclose(file);
    }
    return t;
}

int getProntuarioTecnico(int pront){
    FILE *file;
    Tecnico t;
    int posicao = 0;

    file = fopen("tecnicos.dat", "rb");
    if (file == NULL) {
        printf("\nNao foi possivel abrir 'tecnicos.dat' em getProntuarioTecnico.\n");
    }
    else {
        posicao = localizarTecnico(pront);
        if (posicao == -1) {
            printf("\nNao existe tecnico com este prontuario. \n");
            return posicao;
        }
        else {
            t = getTecnico(posicao);

            // posiciono no registro correto
            fseek(file, posicao * sizeof(Tecnico), SEEK_SET);
            fread(&t, sizeof(Tecnico), 1, file);
            pront = t.pront;

            fclose(file);
            return pront;
        }
    }
    return -1;
}

void imprimirProntuario(){
    FILE *file;
    Tecnico t;

    file = fopen("tecnicos.dat", "rb");
    if(file == NULL)
        printf("\nNao foi possivel abrir 'tecnicos.dat' em imprimirProntuario.\n");
    else {
        fread(&t, sizeof(Tecnico), 1, file);
        while(!feof(file)) {
            printf("\n Prontuario: %d   Tecnico: %s", t.pront, t.nome);
            fread(&t, sizeof(Tecnico), 1, file);
        }

        fclose(file);
    }
}

void imprimirTecnicos(Tecnico t)
{
    printf("\n================= Dados dos Tecnicos =================");

    printf("\n Nome: %s", t.nome);
    printf("\n Prontuario: %d", t.pront);
    printf("\n Ramal: %d", t.ramal);

    printf("\n======================================================\n");
}

void todosTecnicos(){
    FILE *file;
    Tecnico t;

    file = fopen("tecnicos.dat", "rb");// ler arquivo binario
    if(file == NULL) {
        printf("\nNao foi possivel abrir 'tecnicos.dat' em todosTecnicos.\n");
    }
    else {
        fread(&t, sizeof(Tecnico), 1, file);
        while(!feof(file)) {
            imprimirTecnicos(t);
            fread(&t, sizeof(Tecnico), 1, file);
        }

        fclose(file);
    }
}