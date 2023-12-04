#include <stdio.h>
#include <stdlib.h>
#include "./class/equipamentos.h"
#include "./class/tecnicos.h"
#include "./class/atendimentos.h"

//teste
void switchEquipamento(int op, Equipamento *e){
    switch(op) {
        case 0:
            break;
        case 1:
            *e = lerEquipamento(0);
            incluirEquipamento(*e);
            break;
        case 2:
            if (sizeof(Equipamento) == 0)
                printf("\nPor favor inserir um Equipamento antes. ");
            else
                todosEquipamentos();
            break;
        case 3:
            if (sizeof(Equipamento) == 0)
                printf("\nPor favor inserir um Equipamento antes. ");
            else
                apresentarEquipamentoManutencao();
            break;
        default:
            printf("\n Por favor inserir uma opcao valida. \n");
            break;
    }
}

void switchTecnico(int op, Tecnico *t){
    switch(op) {
        case 0:
            break;
        case 1:
            *t = lerTecnico(0);
            incluirTecnico(*t);
            break;
        case 2:
            if (sizeof(Tecnico) == 0)
                printf("\nPor favor inserir um Tecnico antes. ");
            else
                todosTecnicos();
            break;
        default:
            printf("\n Por favor inserir uma opcao valida. \n");
            break;
    }
}

void switchAtendimento(int op, Atendimento *a){
    switch(op) {
        case 0:
            break;
        case 1:
            if (sizeof(Tecnico) != 0 && sizeof(Equipamento) != 0) {
                *a = lerAtendimento(0);
                incluirAtendimento(*a);
            }
            else
                printf("\nPor favor adicionar pelo menos um Tecnico e Equipamento antes. ");
            break;
        case 2:
            if (sizeof(Atendimento) == 0)
                printf("\nNenhum atendimento cadastrado. ");
            else
                todosAtendimentos();
            break;
        case 3:
            if (sizeof(Atendimento) == 0)
                printf("\nNenhum atendimento cadastrado. ");
            else
                atendimentoTecnico();
            break;
        case 4:
            if (sizeof(Atendimento) == 0)
                printf("\nNenhum atendimento cadastrado. ");
            else
                atendimentoLab();
            break;
        case 5:
            if (sizeof(Atendimento) == 0)
                printf("\nNenhum atendimento cadastrado. ");
            else
                atendimentoEquipamento();
            break;
        case 6:
            if (sizeof(Atendimento) == 0)
                printf("\nNenhum atendimento cadastrado. ");
            else
                manutencaoMes();
            break;
        case 7:
            if (sizeof(Atendimento) == 0)
                printf("\nNenhum atendimento cadastrado. ");
            else
               finalizarAtendimento();
            break;
        default:
            printf("\n Por favor inserir uma opcao valida. \n");
            break;
    }
}

void menuEquipamentos(Equipamento *e){
    int op;

    do {
        printf("\n==================== Equipamentos ====================");
        printf("\n [1] - Incluir novo equipamento. ");
        printf("\n [2] - Apresentar todos os equipamentos. ");
        printf("\n [3] - Apresentar todos os equipamentos em manutencao. ");
        printf("\n [0] - Voltar. ");
        printf("\n======================================================\n");

        printf("\n Insira a opcao desejada: ");
        scanf("%d", &op);

        switchEquipamento(op, e);
    } while(op != 0);
}

void menuTecnicos(Tecnico *t){
    int op;

    do {
        printf("\n==================== Tecnicos ======================");
        printf("\n [1] - Incluir novo tecnico. ");
        printf("\n [2] - Apresentar todos os tecnicos. ");
        printf("\n [0] - Voltar. ");
        printf("\n====================================================\n");

        printf("\n Insira a opcao desejada: ");
        scanf("%d", &op);

        switchTecnico(op, t);

    } while (op != 0);
}

void menuAtendimentos(Atendimento *a){
    int op;

    do {
        printf("\n=================== Atendimentos ====================");
        printf("\n [1] - Abrir chamado de atendimento. ");
        printf("\n [2] - Apresentar todos os chamados. ");
        printf("\n [3] - Apresentar chamados de um tecnico especifico. ");
        printf("\n [4] - Apresentar chamados de um laboratorio especifico. ");
        printf("\n [5] - Apresentar chamados de um equipamento especifico. ");
        printf("\n [6] - Apresentar chamados de um mes especifico. ");
        printf("\n [7] - Finalizar chamados de um equipamento especifico. ");
        printf("\n [0] - Voltar. ");
        printf("\n=====================================================\n");

        printf("\n Insira a opcao desejada: ");
        scanf("%d", &op);

        switchAtendimento(op, a);

    } while(op != 0);
}

int menuGeral(){
    int opt;

    printf("\n=============== Sistema de Manutencao ================");
    printf("\n [1] - Equipamentos");
    printf("\n [2] - Tecnicos");
    printf("\n [3] - Atendimentos");
    printf("\n [0] - Sair");
    printf("\n======================================================\n");

    printf("\n Insira a opcao desejada: ");
    scanf("%d", &opt);

    return opt;
}

int main(){
    int opt;

    Equipamento e;
    Tecnico t;
    Atendimento a;

    do {
        opt = menuGeral();
        
        switch (opt) {
            case 0:
                break;
            case 1:
                menuEquipamentos(&e);
                break;
            case 2:
                menuTecnicos(&t);
                break;
            case 3:
                menuAtendimentos(&a);
                break;  
            default:
                printf("\nFavor inserir uma opcao valida. \n");
                break;
        }
    } while(opt != 0);

    return 0;
}