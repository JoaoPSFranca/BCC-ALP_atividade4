# Sistema de Manutenção de Equipamentos de Laboratório

Projeto desenvolvido em **C** como parte de atividade acadêmica.  
O objetivo é praticar conceitos da linguagem e estruturar um sistema simples para **gerenciar manutenções de equipamentos de laboratório**, incluindo técnicos, equipamentos e atendimentos.

Este repositório funciona como um registro do meu progresso e aprendizado em programação em C.  

## Índice

- [Descrição](#descrição)
- [Funcionalidades](#funcionalidades)
- [Pré-requisitos](#pré-requisitos)
- [Compilação](#compilação)
- [Uso](#uso)
- [Estrutura do Projeto](#estrutura-do-projeto)
- [Arquivos de Dados](#arquivos-de-dados)
- [Possíveis Melhorias](#possíveis-melhorias)
- [Licença](#licença)

## 📖 Descrição

O sistema permite cadastrar técnicos, equipamentos e registrar atendimentos de manutenção.  
Serve como prática de:

- manipulação de arquivos binários em C (`.dat`)
- uso de structs
- criação de menus interativos
- persistência simples de dados

## Funcionalidades

- **Gestão de Técnicos**: cadastro, listagem e validação de dados  
- **Gestão de Equipamentos**: cadastro, listagem, controle de situação e histórico  
- **Gestão de Atendimentos**: abertura e finalização de chamados, consultas por técnico, laboratório, equipamento ou mês

## Pré-requisitos

- Compilador C (ex.: `gcc`)
- Funciona em Linux, macOS ou Windows (com MinGW/WSL)

## Compilação

### Compilação rápida

```bash
gcc main.c -o sistema_manutencao
```

### Execução
```bash
./sistema_manutencao   # Linux/macOS
sistema_manutencao.exe # Windows
```

> Também é possível criar um `Makefile` para facilitar, mas neste projeto não é obrigatório.”

## Uso 
O fluxo recomendado: 

  1. Cadastrar técnicos
  2. Cadastrar equipamentos
  3. Abrir chamados de manutenção
  4. Consultar e acompanhar chamados
  5. Finalizar quando resolvidos 

Menus foram implementados em modo texto e armazenam dados em arquivos binários (`.dat`).

## Estrutura do Projeto
```kotlin
.
├── main.c                # Programa principal e menus
├── class/
│   ├── tecnicos.h        # Estruturas e funções de técnicos
│   ├── equipamentos.h    # Estruturas e funções de equipamentos
│   └── atendimentos.h    # Estruturas e funções de atendimentos
├── tecnicos.dat          # Dados de técnicos (gerado em execução)
├── equipamentos.dat      # Dados de equipamentos (gerado em execução)
└── atendimentos.dat      # Dados de atendimentos (gerado em execução)
```

## Arquivos de Dados
O sistema gera automaticamente três arquivos binários:
 * tecnicos.dat
 * equipamentos.dat
 * atendimentos.dat

> Para “resetar” o sistema, basta apagar os .dat.
