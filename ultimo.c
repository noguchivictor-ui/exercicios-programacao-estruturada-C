#include <stdio.h>
void INICIALIZACAO(float totaisOperacao[5],int c, float desempenho[c][5], int contagemOperacao[5]);
void TARIFAS(float tarifas[5]);
void OPERACAO();
void CATEGORIA(int categoria, int operacao, float tarifas[5]);
void ATUALIZACAO(float tarifas[5], float totaisOperacao[5], int contagemOperacao[5], int operacao,int c, float desempenho[c][5], int num);
float V_TOTAL(float totaisOperacao[5]);
void CODIGO_E_QUANT_DA_OP_MAIS_REALIZADA(int contagemOperacao[5]);
void CODIGO_E_VALOR_DA_OP_MAIOR_RECEITA(float totaisOperacao[5]);
void DESEMPENHO(int c,float desempenho[c][5]);
void CAIXA_MAIOR_ARRAC(int c ,float desempenho[c][5]);
float PERCENTUAL(float totaisOperacao[5], int i);
void ANALISE(float totaisOperacao[5]);
int main() {
    int c, num, operacao, categoria, sair;
    float v_total;
    printf("DIGITE A QUANTIDADE DE CAIXAS ATIVOS(1 - 10):");
    scanf("%d", &c);
    float tarifas[5];
    float totaisOperacao[5];
    int contagemOperacao[5];
    float desempenho[c][5];
    INICIALIZACAO(totaisOperacao,c,desempenho,contagemOperacao);
    do {
        TARIFAS(tarifas);
        printf("DIGITE O NUMERO DO CAIXA(1 - %d):", c);
        scanf("%d", &num);
        if(num < 1 || num > c) {
            printf("ERRO");
            return 0;
        }
        OPERACAO();
        printf("DIGITE O NUMERO DA OPERACAO DESEJADA");
        scanf("%d", &operacao);

        printf("DIGITE SUA CATEGORIA:");
        scanf("%d", &categoria);

        switch(operacao) {
            case 0:
                printf("OP: SAQUE EM ESPECIE\n");
                tarifas[operacao];
                break;
            case 1:
                printf("OP: TRANSFERENCIA\n");
                tarifas[operacao];
                break;
            case 2:
                printf("OP: PAGAMENTO EM BOLETO\n");
                tarifas[operacao];
                break;
            case 3:
                printf("OP: CONTRATO DE EMPRESTIMO\n");
                tarifas[operacao];
                break;
            case 4:
                printf("OP: INVESTIMENTO EM CDB\n");
                tarifas[operacao];
                break;
            default:
                printf("ERRO\n");
                break;
        }
        CATEGORIA(categoria,operacao,tarifas);
        ATUALIZACAO(tarifas, totaisOperacao, contagemOperacao, operacao,c, desempenho, num);
        printf("TARIFA COBRADA: %f\n", tarifas[operacao]);
        printf("REGISTRADA NO CAIXA %d\n", num);
        printf("1 para continuar ou 0 para sair");
        scanf("%d", &sair);
    }while (sair != 0);
    v_total = V_TOTAL(totaisOperacao);
    printf("============================================================\n");
    printf("ENCERRAMENTO DO EXPEDIENTE\n");
    printf("TOTAL ARRECADADO: %f\n", v_total);
    CODIGO_E_QUANT_DA_OP_MAIS_REALIZADA(contagemOperacao);
    CODIGO_E_VALOR_DA_OP_MAIOR_RECEITA(totaisOperacao);
    printf("============================================================\n");
    DESEMPENHO(c, desempenho);
    CAIXA_MAIOR_ARRAC(c, desempenho);
    printf("============================================================\n");
    ANALISE(totaisOperacao);
    return 0;
}
void INICIALIZACAO(float totaisOperacao[5],int c, float desempenho[c][5], int contagemOperacao[5]) {
    for(int i=0;i<5;i++) {
        totaisOperacao[i] = 0;
        contagemOperacao[i] = 0;
    }
    for(int i=0;i<c;i++) {
        for(int j=0;j<5;j++) {
            desempenho[i][j] = 0;
        }
    }
}
void TARIFAS(float tarifas[5]) {
    tarifas[0] = 6.5;
    tarifas[1] = 4;
    tarifas[2] = 3;
    tarifas[3] = 25;
    tarifas[4] = 12;
}
void OPERACAO() {
    printf("0- SAQUE EM ESPECIE\n");
    printf("1- TRANSFERENCIA\n");
    printf("2- PAGAMENTO EM BOLETO\n");
    printf("3- CONTRATO DE EMPRESTIMO\n");
    printf("4- INVESTIMENTO EM CDB\n");
}
void CATEGORIA(int categoria, int operacao, float tarifas[5]) {
    if(categoria == 0) {
        printf("CATEGORIA: COMUM | 100 PORCENTO\n");
        tarifas[operacao];
    } else if (categoria == 1) {
        printf("CATEGORIA: PLUS | 70 PORCENTO\n");
        tarifas[operacao] = tarifas[operacao] * 0.7;
    } else if (categoria == 2) {
        printf("CATEGORIA: PREMIUM | 40 PORCENTO\n");
        tarifas[operacao] = tarifas[operacao] * 0.4;
    } else {
        printf("ERRO");
    }


}
void ATUALIZACAO(float tarifas[5], float totaisOperacao[5], int contagemOperacao[5], int operacao,int c, float desempenho[c][5], int num) {
    totaisOperacao[operacao] += tarifas[operacao];
    contagemOperacao[operacao] += 1;
    desempenho[num][operacao] += tarifas[operacao];
}
float V_TOTAL(float totaisOperacao[5]) {
    float soma = 0;
    for(int i=0;i<5;i++) {
        soma += totaisOperacao[i];
    }
    return soma;
}
void CODIGO_E_QUANT_DA_OP_MAIS_REALIZADA(int contagemOperacao[5]) {
    float maior = contagemOperacao[0];
    int indice_maior = 0;
    for(int i=0;i<5;i++) {
        if(contagemOperacao[i] > maior) {
            maior = contagemOperacao[i];
            indice_maior = i;
        }
    }
    printf("OP MAIS REALIZADA: %d(%d)\n", indice_maior, maior);
}
void CODIGO_E_VALOR_DA_OP_MAIOR_RECEITA(float totaisOperacao[5]) {
    int maior_indice = 0;
    float maior = totaisOperacao[0];
    for(int i=0;i<5;i++) {
        if(totaisOperacao[i] > maior) {
            maior = totaisOperacao[i];
            maior_indice = i;
        }
    }
    printf("OP DE MAIS RECEITA: %d(%f)\n ", maior_indice, maior);
}
void DESEMPENHO(int c,float desempenho[c][5]) {
    float soma;
    for(int i=0;i<c;i++) {
        soma = 0;
        printf("CAIXA %d\n", i);
        for (int j=0;j<5;j++) {
            soma += desempenho[i][j];
            printf("OP %d - ... %f\n", j, desempenho[i][j]);
        }
        printf("TOTAL DO CAIXA: %f\n", soma);
    }

}
void CAIXA_MAIOR_ARRAC(int c ,float desempenho[c][5]) {
    float maior = desempenho[0][0];
    int indice_maior = 0;
    for(int i=0;i<c;i++) {
        for (int j=0;j<5;j++) {
            if (desempenho[i][j] > maior) {
                maior = desempenho[i][j];
                indice_maior = i;
            }
        }
    }
        printf("CAIXA COM MAIOR ARRACADACAO: %d\n", indice_maior);
        float menor = desempenho[0][0];
        int indice_menor = 0;
        for(int i=0;i<c;i++) {
            for (int j=0;j<5;j++) {
                if (desempenho[i][j] < menor) {
                    menor = desempenho[i][j];
                    indice_menor = i;
                }
            }
        }
    printf("CAIXA COM MENOR ARRACADACAO: %d\n", indice_menor);
    printf("==========================================================\n");

}
float PERCENTUAL(float totaisOperacao[5], int i) {
    float p;
    p =(100 * totaisOperacao[i])/V_TOTAL(totaisOperacao);
    return p;
}
void ANALISE(float totaisOperacao[5]) {
    float p;
    char situacao;
    int cont;
    printf("ANALISE\n");
    for (int i=0;i<5;i++) {
        p = PERCENTUAL(totaisOperacao, i);
        if (p > 30) {
            situacao = 'C';
            cont++;
        } else if (p < 30) {
            situacao = 'N';
        }
        printf("OP %d, %f reais, %f porcento, %c\n", i, totaisOperacao[i], p, situacao);
    }
    printf("QUANTIDADE DE OPERACOES CRITICAS: %d\n", cont);
}