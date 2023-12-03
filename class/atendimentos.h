#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int dia;
    int mes;
    int cod_equip;
    int pront_tec;
    char problema[60];
    char solucao[60];
    char situ;

} Atendimento;

Atendimento lerAtendimento(){
    Atendimento atendimento;
    int dia2, mes2, posicao=0, pront, verificarCodigo, verificarProntuario, nr_equipamento;

    printf("\nA seguir, insira as informacoes para cadastrar um atendimento: \n");
    do{
        printf(" Dia: ");
        scanf("%d", &dia2);

        if(dia2 < 1 || dia2 > 31)
            printf("\nDia invalido! Tente novamente.\n");
    }while(dia2 < 1 || dia2 > 31);
    atendimento.dia = dia2;

    do{
        printf(" Mes: ");
        scanf("%d", &mes2);

        if(mes2 < 1 || mes2 > 12)
            printf("\nMes invalido! Tente novamente.\n");
    } while(mes2 < 1 || mes2 > 12);
    atendimento.mes = mes2;

    do{
        do
        {
            printf(" Equipamento: ");
            scanf("%d", &nr_equipamento);

            if (nr_equipamento < 0)
                printf("\n Codigo invalido! tente novamente.\n");
        } while (nr_equipamento < 0);

        verificarCodigo = localizarEquipamento(nr_equipamento);
        if(verificarCodigo != -1)
            atendimento.cod_equip = nr_equipamento;

        posicao = localizarEquipamento(nr_equipamento);
    } while (verificarCodigo == -1);

    printf("\n================ Tecnicos Disponiveis ================");
        imprimirProntuario();
    printf("\n======================================================\n");

    do
    {
        do
        {
            printf("\n Insira o protuario de um tecnico disponivel: ");
            scanf("%d", &pront);

            if (pront < 0)
                printf("\n Prontuario invalido! digite um numero positivo.\n");
        } while (pront < 0);

        verificarProntuario = getProntuarioTecnico(pront);

        if (verificarProntuario != -1)
            atendimento.pront_tec = verificarProntuario;

    } while (verificarProntuario == -1);

        printf(" Problema: ");
        fflush(stdin);
        fgets(atendimento.problema, 60, stdin);
        atendimento.problema[strcspn(atendimento.problema, "\n")] = '\0';

        printf(" Solucao: ");
        fflush(stdin);
        fgets(atendimento.solucao, 60, stdin);
        atendimento.solucao[strcspn(atendimento.solucao, "\n")] = '\0';

        atendimento.situ = 'P';

    
    alterarSituacaoEquipamento(posicao);
    
    return atendimento;
}

void incluirAtendimento(Atendimento at){
    FILE *file;

    file = fopen("atendimentos.dat", "ab");//ab incluir no arquivo binario
    if (file == NULL)
       file = fopen("atendimentos.dat", "wb"); // write binary archive 

    if (file == NULL)
        printf("\nNao foi possivel abrir 'atendimentos.dat' em incluirAtendimento.\n");
    else{
        fwrite(&at, sizeof(Atendimento), 1, file);//fwrite grava o tecnico no final do arquivo
        printf("\nAtendimendo cadastrado com sucesso!\n");
        fclose(file);
    }
}

void imprimirAtendimento(Atendimento a) {
    printf("\n================ Dados do Atendimento ================");

    printf("\n Data: %d/%d", a.dia, a.mes);
    printf("\n Numero do equipamento: %d", a.cod_equip);
    printf("\n Prontuario do Tecnico: %d", a.pront_tec);
    printf("\n Problema: %s", a.problema);
    printf("\n Solucao: %s", a.solucao);
    if (a.situ == 'P')
        printf("\n Situacao: Pendente");
    else
        printf("\n Situacao: Finalizado");

    printf("\n======================================================\n");
}

void todosAtendimentos(){
    FILE *file;
    Atendimento a;

    file = fopen("atendimentos.dat", "rb");// ler arquivo binario
    if(file == NULL)
        printf("\nNao foi possivel abrir 'atendimentos.dat' em todosAtendimentos.\n");
    else
    {
        fread(&a, sizeof(Atendimento), 1, file);
        while(!feof(file))
        {
            imprimirAtendimento(a);
            fread(&a, sizeof(Atendimento), 1, file);
        }

        fclose(file);
    }
}

int pegarPront(){
    int pront = 0, verificarProntuario = -1;

    printf("\n====================== Tecnicos ======================");
    imprimirProntuario();
    printf("\n======================================================\n");

    do
    {
        do
        {
            printf("\n Insira o protuario do tecnico que deseja procurar: ");
            scanf("%d", &pront);

            if (pront < 0)
                printf("\n Prontuario invalido! digite um numero positivo.\n");
        } while (pront < 0);

        verificarProntuario = getProntuarioTecnico(pront);

        if (verificarProntuario == -1)
            printf("\n Prontuario invalido! Tente novamente.\n");
    } while (verificarProntuario == -1);

    return pront;
}

void atendimentoTecnico(){
    FILE *file;
    Atendimento a;
    int pront = 0;

    file = fopen("atendimentos.dat", "rb");
    if(file == NULL)
        printf("\nNao foi possivel abrir 'atendimentos.dat' em atendimentoTecnico.\n");
    else{
        pront = pegarPront();

        fread(&a, sizeof(Atendimento), 1, file);
        while(!feof(file)){
            if(a.pront_tec == pront)
                imprimirAtendimento(a);

            fread(&a, sizeof(Atendimento), 1, file);
        }

        fclose(file);
    }
}

void atendimentoLab(){
    FILE *file;
    Atendimento a;
    int 
        lab = 0, 
        cont = 0,
        verificar = 0;

    file = fopen("atendimentos.dat", "rb");
    if(file == NULL)
        printf("\nNao foi possivel abrir 'atendimentos.dat' em atendimentoLab.\n");
    else{
        do{
            do {
                printf("\n Insira o laboratorio que deseja procurar: ");
                scanf("%d", &lab);

                if (lab < 0)
                    printf("\n Laboratorio invalido! Digite um numero positivo.\n");
            } while (lab < 0);

            verificar = verificarLaboratorios(lab);

            if (verificar == 0)
                printf("\n Laboratorio invalido! Digite um laboratorio existente.\n");
        } while (verificar == 0);

        fread(&a, sizeof(Atendimento), 1, file);
        while(!feof(file)){
            int posicao = localizarEquipamento(a.cod_equip);
            Equipamento e = getEquipamento(posicao);
            
            if(e.num_lab == lab){
                imprimirAtendimento(a);
                cont++;
            }

            fread(&a, sizeof(Atendimento), 1, file);
        }
    
        if (cont == 0)
            printf("\nNenhum chamado realizado no laboratorio especificado. \n");
        else
            printf("\nQuantidade de atendimentos no laboratorio: %d.\n", cont);

        fclose(file);
    }
}