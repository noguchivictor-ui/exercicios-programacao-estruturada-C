#include <stdio.h>
void INICIO();
void OPERACAO();
void CATEGORIA();
void CATEGORIA2(int categoria,int codigo, float tarifas[5]);
void SOMA(float totaisOperacao[5], int codigo, float tarifas[5], int contagemOperacao[5],int c, float desempenho[c][5]);
float TOTAL(float totaisOperacao[5], float soma);
int MAIS_REALIZADA_QUANT(int contagemOperacao[5], int maior );
int MAIS_REALIZADA_INDICE(int contagemOperacao[5], int indice );
float MAIS_REALIZADA_VALOR(float totaisOperacao[5], float maior);
int MAIS_REALIZADA_INDICE2(float totaisOperacao[5], int indice);
int main() {

    int c, codigo, categoria, sair = 1,q_codigo,q_quant,op_codigo, indice, op_quant, i;
    float v_total, soma, maior;
    float tarifas[5] = {6.5,4,3,25,12};
    float totaisOperacao[5];
    int contagemOperacao[5];
    INICIO();
    scanf("%d", &c);
    float desempenho[c][5];

    do {
        printf("INFORME O NUMERO DO CAIXA:");
        scanf("%d", &desempenho[i][5]);
        OPERACAO();
        scanf("%d", &codigo);
        CATEGORIA();
        scanf("%d", &categoria);
        switch (codigo) {
            case 0:
                printf("OPERACAO: SAQUE EM ESPECIE\n");
                tarifas[codigo];
                break;
            case 1:
                printf("OPERACAO: TRANSFERENCIA\n");
                tarifas[codigo];
                break;
            case 2:
                printf("OPERACAO: PAGAMENTO EM BOLETO\n");
                tarifas[codigo];
                break;
            case 3:
                printf("OPERACAO: CONTRATO DE EMPRESTIMO\n");
                tarifas[codigo];
                break;
            case 4:
                printf("OPERACAO: INVESTIMENTO EM CDB\n");
                tarifas[codigo];
                break;
            default:
                printf("ERRO");
                break;
        }
        switch (categoria) {
            case 1:
                printf("Categoria: COMUM | Percentual: 100\n");
                CATEGORIA2(categoria,codigo,tarifas);
                break;
            case 2:
                printf("Categoria: Plus | Percentual: 70\n");
                CATEGORIA2(categoria,codigo,tarifas);
                break;
            case 3:
                printf("Categoria: Premium | Percentual: 40\n");
                CATEGORIA2(categoria,codigo,tarifas);
                break;
            default:
                printf("ERRO");
                break;
        }
        printf("TARIFA COBRADA, %f\n", tarifas[codigo]);
        printf("REGISTRADA NO CAIXA %d\n", c);
        SOMA(totaisOperacao,codigo,tarifas,contagemOperacao,c,desempenho);
        printf("----------------------------------------------\n");
        printf("1- para continuar\n");
        printf("0- para sair\n");
        printf("DIGITE:");
        scanf("%d", &sair);
    } while (sair != 0);
    v_total = TOTAL(totaisOperacao,soma);
    q_quant = MAIS_REALIZADA_QUANT(contagemOperacao, maior);
    q_codigo = MAIS_REALIZADA_INDICE(contagemOperacao, indice);
    op_codigo = MAIS_REALIZADA_INDICE2(totaisOperacao, indice);
    op_quant = MAIS_REALIZADA_VALOR(totaisOperacao, maior);
    printf("-----------------------------------------------------------\n");
    printf("TOTAL GERAL: %f\n", v_total);
    printf("OPERACAO MAIS REALIZADA: %d(%d)\n",q_codigo, q_quant);
    printf("OPERACAO DE MAIOR RECEITA: %d (%f)\n", op_codigo, op_quant);
    for (int i=0; i<c; i++) {
        for (int j=0; j<5; j++) {
            printf("MATRIZ[%d][%d]--->%f\n",i,j, desempenho[i][j]);
        }
    }
    return 0;
}





void INICIO() {
    int c;
    printf("INSIRA O NUMERO DE CAIXAS ATIVOS:");
    float totaisOperacao[5];
    int contagemOperacao[5];
    float desempenho[c][5];
    for (int i=0; i<5; i++) {
        totaisOperacao[i] = 0;
    }
    for (int i=0; i<5; i++) {
        contagemOperacao[i] = 0;
    }
    for (int i=0; i<c; i++) {
        for (int j=0; j<5; j++) {
            desempenho[i][j] = 0;
        }
    }
}

void OPERACAO() {
    printf("1- SAQUE EM ESPECIE\n");
    printf("2- TRANSFERENCIA\n");
    printf("3- PAGAMENTO EM BOLETO\n");
    printf("4- CONTRATO DE EMPRESTIMO\n");
    printf("5- INVESTIMENTO EM CDB\n");
    printf("INSIRA O CODIGO DE OPERACAO:");
}
void CATEGORIA() {
    printf("1 Comum Conta padrão sem benefícios\n");
    printf("2 Plus Saldo médio acima de R$ 5.000\n");
    printf("3 Premium Saldo médio acima de R$ 20.000\n");
    printf("INSIRA SUA CATEGORIA:");
}
void CATEGORIA2(int categoria,int codigo, float tarifas[5]) {
    if (categoria == 1) {
        tarifas[codigo] = tarifas[codigo];
    } else if (categoria == 2) {
        tarifas[codigo] = tarifas[codigo] * 0.7;
    } else {
        tarifas[codigo] = tarifas[codigo] * 0.4;
    }
}
void SOMA(float totaisOperacao[5], int codigo, float tarifas[5], int contagemOperacao[5],int c, float desempenho[c][5]) {
    totaisOperacao[codigo] = totaisOperacao[codigo] + tarifas[codigo];
    contagemOperacao[codigo]++;
    desempenho[c][codigo] = totaisOperacao[codigo];
}
float TOTAL(float totaisOperacao[5], float soma) {
    soma = 0;
    for (int i=0; i<5; i++) {
        soma += totaisOperacao[i];
    }
    return soma;
}
int MAIS_REALIZADA_QUANT(int contagemOperacao[5], int maior ) {
    maior = contagemOperacao[0];

    for (int i=1; i<5; i++) {
        if (contagemOperacao[i] > maior) {
            maior = contagemOperacao[i];
        }
    }
    return maior;
}
int MAIS_REALIZADA_INDICE(int contagemOperacao[5], int indice ) {
    indice = 0;
    for (int i=0; i<5; i++) {
        if (contagemOperacao[i] > contagemOperacao[indice]) {
            indice = i;
        }
    }
    return indice;
}
float MAIS_REALIZADA_VALOR(float totaisOperacao[5], float maior) {
    maior = totaisOperacao[0];
    for (int i=0; i<5; i++) {
        if (totaisOperacao[i] > maior) {
            maior = totaisOperacao[i];
        }
    }
    return maior;
}
int MAIS_REALIZADA_INDICE2(float totaisOperacao[5], int indice) {
    indice = 0;
    for (int i=0; i<5; i++) {
        if (totaisOperacao[i] > totaisOperacao[indice]) {
            indice = i;
        }
    }
    return indice;
}