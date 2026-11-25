#include <stdio.h>
void INICIO();
void OPERACAO();
void CATEGORIA();
void CATEGORIA2(int categoria,int codigo, float tarifas[5]);
void SOMA(float totaisOperacao[5], int codigo, float tarifas[5], int contagemOperacao[5],int c, float desempenho[c][5]);
int main() {
    int c, codigo, categoria, sair = 1;
    float tarifas[5] = {6.5,4,3,25,12};
    float totaisOperacao[5];
    int contagemOperacao[5];
    float desempenho[c][5];
    INICIO();

    do {
        printf("INFORME O NUMERO DO CAIXA:");
        scanf("%d", &c);
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

    return 0;
}





void INICIO() {
    int c;
    printf("INSIRA O NUMERO DE CAIXAS ATIVOS:");
    scanf("%d", &c);
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