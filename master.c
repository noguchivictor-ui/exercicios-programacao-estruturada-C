#include <stdio.h>
void INICIALIZACAO(float tarifas[5], float totaisOperacao[5],int c, float desempenho[c][5],int contagemOperacao[5]);
void OPERACAO();
void CATEGORIA();
void TARIFAS_PERMANENTES(float tarifas[5]);
void IF_CATEGORIA(float tarifas[5], int codigo, int categoria);
void REGISTRO(float tarifas[5], float totaisOperacao[5],int c, float desempenho[c][5],int contagemOperacao[5], int codigo, int num);
float V_TOTAL(float totaisOperacao[5], float soma);
int QUANT_OP_MAIS_REALIZADA(int contagemOperacao[5], int maior);
int INDICE_OP_MAIS_REALIZADA(int contagemOperacao[5], int indice);
float V_OP_MAIOR_RECEITA(float totaisOperacao[5], float maior);
int INDICE_V_OP_MAIOR_RECEITA(float totaisOperacao[5], int indice);
void CADA_CAIXA(int c,float desempenho[c][5]);
float INDICE_CAIXA_MAIOR_ARRECADADO(int c,float desempenho[c][5], float soma, float maior, int maior_ind);
float CAIXA_MENOR_ARRECADADO(int c,float desempenho[c][5], float menor);
float CONTA(float p, int i, float totaisOperacao[5],float soma);
char C_OU_N(float p, char situacao);
void ANALISE(float totaisOperacao[5], float p, char situacao, float soma, int cont);
int main() {
    char situacao;
    int c, num, codigo, categoria, sair = 8, q_op_mais_realizada,indice_op_mais_realizada, indice, indice_v_op_maior_receita, i, cont, maior_ind;
    float v_total, soma, v_op_maior_receita, indice_caixa_maior_arrecadado,caixa_menor_arrecadado, menor, maior, p, conta, c_n;
    printf("Digite a quantidade de caixas ativos: ");
    scanf("%d", &c);
    float tarifas[5];
    float totaisOperacao[5];
    int contagemOperacao[5];
    float desempenho[c][5];
    INICIALIZACAO(tarifas, totaisOperacao, c, desempenho, contagemOperacao);
    do {
        printf("NUMERO DO CAIXA:");
        scanf("%d", &num);
        if (num < 1 || num > c) {
            printf("ERRO NUMERO DO CAIXA\n");
            return 0;
        }
        OPERACAO();
        scanf("%d", &codigo);
        CATEGORIA();
        scanf("%d", &categoria);
        TARIFAS_PERMANENTES(tarifas);
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
                printf("ERRO NUMERO DA OPERACAO\n");
                return 0;
        }
        IF_CATEGORIA(tarifas, codigo, categoria);
        REGISTRO(tarifas, totaisOperacao, c, desempenho, contagemOperacao, codigo, num);
        printf("TARIFA COBRADA: %f\n", tarifas[codigo]);
        printf("REGISTRADA NO CAIXA %d\n", num);
        printf("=========================================\n");
        printf("Digite 1 para continuar ou 0 para sair:");
        scanf("%d", &sair);
    } while (sair != 0);
    printf("===============================================\n");
    v_total = V_TOTAL(totaisOperacao, soma);
    printf("VALOR TOTAL REGISTRADO NO DIA: %f\n", v_total);
    q_op_mais_realizada = QUANT_OP_MAIS_REALIZADA(contagemOperacao, maior);
    indice_op_mais_realizada = INDICE_OP_MAIS_REALIZADA(contagemOperacao, indice);
    printf("OPERACAO MAIS REALIZADA: %d(%d vezes)\n",indice_op_mais_realizada,q_op_mais_realizada );
    v_op_maior_receita = V_OP_MAIOR_RECEITA(totaisOperacao, maior);
    indice_v_op_maior_receita = INDICE_V_OP_MAIOR_RECEITA(totaisOperacao, indice);
    printf("OPERACAO DE MAIOR RECEITA: %d(%f reais)\n", indice_v_op_maior_receita,v_op_maior_receita );
    printf("=================================================\n");
    CADA_CAIXA(c, desempenho);
    printf("======================================================================\n");
    indice_caixa_maior_arrecadado = INDICE_CAIXA_MAIOR_ARRECADADO(c, desempenho,soma, maior, maior_ind);
    caixa_menor_arrecadado = CAIXA_MENOR_ARRECADADO(c, desempenho, menor);
    printf("CAIXA COM MAIOR ARRECADADO: %f\n", indice_caixa_maior_arrecadado);
    printf("CAIXA COM MENOR ARRECADADO: %f\n", caixa_menor_arrecadado);
    printf("======================================================================\n");
    ANALISE(totaisOperacao, p, situacao, soma,cont);
    return 0;
}
void INICIALIZACAO(float tarifas[5], float totaisOperacao[5],int c, float desempenho[c][5],int contagemOperacao[5]) {
    tarifas[0] = 6.5;
    tarifas[1] = 4.0;
    tarifas[2] = 3.0;
    tarifas[3] = 25.0;
    tarifas[4] = 12.0;
    for (int i = 0; i < 5; i++) {
        totaisOperacao[i] = 0;
        contagemOperacao[i] = 0;
    }
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < 5; j++) {
            desempenho[i][j] = 0;
        }
    }
}
void OPERACAO() {
    printf("0- SAQUE EM ESPECIE\n");
    printf("1- TRANSFERENCIA\n");
    printf("2- PAGAMENTO EM BOLETO\n");
    printf("3- CONTRATO DE EMPRESTIMO\n");
    printf("4- INVESTIMENTO EM CDB\n");
    printf("INSIRA O CODIGO DE OPERACAO:");
}
void CATEGORIA() {
    printf("1 Comum Conta padrao sem beneficios\n");
    printf("2 Plus Saldo medio acima de R$ 5.000\n");
    printf("3 Premium Saldo medio acima de R$ 20.000\n");
    printf("INSIRA SUA CATEGORIA:");
}
void TARIFAS_PERMANENTES(float tarifas[5]) {
    tarifas[0] = 6.5;
    tarifas[1] = 4.0;
    tarifas[2] = 3.0;
    tarifas[3] = 25.0;
    tarifas[4] = 12.0;
}
void IF_CATEGORIA(float tarifas[5], int codigo, int categoria) {
    if (categoria == 1) {
        printf("CATEGORIA: comum | PERCENTUAL: 100\n");
        tarifas[codigo] = tarifas[codigo];
    } else if (categoria ==2) {
        printf("CATEGORIA: plus | PERCENTUAL: 70\n");
        tarifas[codigo] = tarifas[codigo] * 0.7 ;
    }else if (categoria ==3) {
        printf("CATEGORIA: premium | PERCENTUAL: 40\n");
        tarifas[codigo] = tarifas[codigo] * 0.4;
    }
}
void REGISTRO(float tarifas[5], float totaisOperacao[5],int c, float desempenho[c][5],int contagemOperacao[5], int codigo, int num) {
    totaisOperacao[codigo] += tarifas[codigo];
    contagemOperacao[codigo] += 1;
    desempenho[num][codigo] += tarifas[codigo] ;
}
float V_TOTAL(float totaisOperacao[5], float soma) {
    soma = 0;
    for (int i = 0; i < 5; i++) {
        soma += totaisOperacao[i];
    }
    return soma;
}
int QUANT_OP_MAIS_REALIZADA(int contagemOperacao[5], int maior) {
    maior = contagemOperacao[0];
    for (int i = 1; i < 5; i++) {
        if (contagemOperacao[i] > maior) {
            maior = contagemOperacao[i];
        }
    }
    return maior;
}
int INDICE_OP_MAIS_REALIZADA(int contagemOperacao[5], int indice) {
    indice = 0;
    for (int i = 0; i < 5; i++) {
        if (contagemOperacao[i] > contagemOperacao[indice]) {
            indice = i;
        }
    }
    return indice;
}
float V_OP_MAIOR_RECEITA(float totaisOperacao[5], float maior) {
    maior = 0;
    for (int i = 0; i < 5; i++) {
       if (totaisOperacao[i] > maior) {
           maior = totaisOperacao[i];
       }
    }
    return maior;
}
int INDICE_V_OP_MAIOR_RECEITA(float totaisOperacao[5], int indice) {
    indice = 0;
    for (int i = 0; i < 5; i++) {
        if (totaisOperacao[i] > totaisOperacao[indice]) {
            indice = i;
        }
    }
    return indice;
}
void CADA_CAIXA(int c,float desempenho[c][5]) {
    for (int i = 0; i < c; i++) {
        printf("CAIXA %d\n", i);
        for (int j = 0; j < 5; j++) {
            printf("OP %d - SAQUE EM ESPECIE: %f\n", j, desempenho[i][j]);
        }
    }
}
float INDICE_CAIXA_MAIOR_ARRECADADO(int c,float desempenho[c][5], float soma, float maior, int maior_ind) {
    maior = 0;
    maior_ind = 0;
    for (int i = 0; i < 5; i++) {
        soma = 0;
        for (int j = 0; j < 5; j++) {
            soma += desempenho[i][j];
        }
        if (i == 0 || soma > maior) {
            maior = soma;
            maior_ind = i;
        }
    }
    return maior_ind;
}
float CAIXA_MENOR_ARRECADADO(int c,float desempenho[c][5], float menor) {
    menor = desempenho[0][0];
    for (int i = 1; i < c; i++) {
        for (int j = 0; j < 5; j++) {
            if (desempenho[i][j] < menor) {
                menor = desempenho[i][j];
            }
        }
    }
    return menor;
}
float CONTA(float p, int i, float totaisOperacao[5],float soma) {
    p = (100 * totaisOperacao[i]) / V_TOTAL(totaisOperacao, soma);
    return p;
}
char C_OU_N(float p, char situacao) {
    if (p >= 30) {
        situacao = 'C';
    } else {
        situacao = 'N';}
    return situacao;
}
int QUANT_C(float p, int cont) {
    if (p >= 30) {
        cont++;
    }
    return cont;
}
void ANALISE(float totaisOperacao[5], float p, char situacao, float soma, int cont) {
    cont = 0;
    for (int i = 0; i < 5; i++) {
        p = CONTA(p, i, totaisOperacao, soma);
        situacao = C_OU_N(p, situacao);
        cont = QUANT_C(p, cont);
        printf("OP %d: %f REAIS | %f porcento  %c\n", i, totaisOperacao[i], p, situacao);
    }
    printf("===============================================================================\n");
    printf("OPERECAOES CRITICAS: %d", cont);
}
