#include <stdio.h>
#define MAX 10

int main() {
    char nomes[MAX][30];
    float valores[MAX];
    int pode_cortar[MAX];
    int n=0;
    float renda, total=0;

            printf("=== Otimizador de Gastos Mensais ===\n\n");

                printf("Digite sua renda mensal: R$ ");
                scanf("%f", &renda);

                printf("Quantas despesas? (max %d): ", MAX);
                 scanf("%d", &n);

                            for (int i = 0; i < n; i++) {
                                 printf("\nDespesa %d\n", i + 1);
                                 printf("Nome:");
                                 scanf("%s", nomes[i]);
                                 printf("Valor: R$ ");
                                 scanf("%f", &valores[i]);
                                 printf("Pode cortar? (1=Sim / 0=Nao): ");
                                 scanf("%d", &pode_cortar[i]);
                                 total += valores[i];
                                }

                        printf("\n=== Seus Gastos ===\n");
                             for (int i = 0; i < n; i++) {
                                 printf("%20s  R$ %.2f\n", nomes[i], valores[i]);
                                }
                            printf("Total: R$ %.2f\n", total);
                            printf("Saldo: R$ %.2f\n", renda - total);

                            printf("\n=== Analise do Orcamento ===\n");

                            if (total <= renda) {
                                 printf("Seus gastos estao dentro da renda. Sem cortes necessarios!\n");
                                    } else {
                             float falta = total - renda;
                             printf("Voce esta gastando R$ %.2f a mais do que ganha.\n\n", falta);

                             int resposta;
                                 printf("Deseja reduzir cada gasto proporcionalmente para caber na renda? (1=Sim / 0=Nao): ");
                                 scanf("%d", &resposta);

                             if (resposta == 1) {
                                 float percentual_corte = (falta / total) * 100.0f;
                                 float fator = renda / total;

                                printf("\nCorte necessario: %.1f%% em cada despesa\n", percentual_corte);
                                printf("\n%-20s  %-12s  %-12s  %s\n", "Despesa", "Valor Atual", "Novo Valor", "Reducao");
                                printf("------------------------------------------------------------\n");

                                float novo_total = 0;
                                 for (int i = 0; i < n; i++) {
                                 float novo_valor = valores[i] * fator;
                                 float reducao = valores[i] - novo_valor;
                                 printf("%-20s  R$ %8.2f  R$ %8.2f  -R$ %.2f\n", nomes[i], valores[i], novo_valor, reducao);
                                         novo_total += novo_valor;
                                    }

                                printf("------------------------------------------------------------\n");
                                 printf("Novo total: R$ %.2f  (renda: R$ %.2f)\n", novo_total, renda);
                             } else {
                              printf("Ok! Nenhuma reducao aplicada.\n");
                             }
                }

    return 0;
}
