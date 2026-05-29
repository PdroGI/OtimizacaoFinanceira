#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    char nomes[MAX][30];
    float valores[MAX];
    int pode_cortar[MAX];
    int despesa=0;
    float renda, saldo=0.0, total=0;
    int escolha;

                
        do{
                system("cls || clear");//limpa a tela antes do loop reiniciar
                printf("=== Otimizador de Gastos Mensais ===\n\n");
//adicionei o menu
                printf("Escolha a alternativa desejada\n");
                printf("1.Adicionar renda\n");
                printf("2.Ver saldo\n");
                printf("3.Adicionar Despesa\n");
                printf("4.Otimizar gastos\n");
                printf("0.Sair\n");
                
                        scanf("%d", &escolha);
                        limpar_buffer()
                        switch(escolha){

                          case 1:
                            printf("Digite o valor da Renda R$");
                            scanf("%f", &renda);
                               if(renda > 0){
                                printf("Adicionado com sucesso\n\n");
                                saldo+=renda;
                               }else{
                                printf("Valor invalido\n");
                                }
                                printf("Pressione Enter para continuar");
                                limpar_buffer()
                            break;
                          case 2:
                                printf("Saldo: R$%.2f\n", saldo);
                                printf("Pressione Enter para continuar");
                                limpar_buffer()
                            break;
                          case 3:
                                printf("Adicionar Despesa(max %d)\n", MAX);
                                    scanf("%d", &despesa);
                                    limpar_buffer()
                                        for (int i = 0; i < despesa; i++){
                                            printf("\nDespesa %d\n", i + 1);
                                            printf("Nome:");
                                            scanf(" %29[^\n]", nomes[i]);
                                            limpar_buffer()
                                            printf("Valor: R$ ");
                                            scanf("%f", &valores[i]);
                                            limpar_buffer()
                                            printf("Pode cortar? (1=Sim / 0=Nao): ");
                                            scanf("%d", &pode_cortar[i]);
                                            limpar_buffer()
                                            total += valores[i];
                                        }
                                         printf("Pressione Enter para continuar");
                                    limpar_buffer()
                            break;
                          case 4: 
                                printf("\n=== Seus Gastos ===\n");
                                    for (int i = 0; i < despesa; i++){
                                        printf("%20s  R$ %.2f\n", nomes[i], valores[i]);}
                                        printf("Total: R$ %.2f\n", total);
                                        printf("Saldo: R$ %.2f\n", saldo);
                                        printf("Saldo menos depesas: R$ %.2f\n", saldo-total);
                                        printf("\n=== Analise do Orcamento ===\n");
                                            if (total <= saldo) {
                                             printf("Seus gastos estao dentro da renda. Sem cortes necessarios!\n");
                                                      } else {
                                                        float falta = total - saldo;
                                                        printf("Voce esta gastando R$ %.2f a mais do que ganha.\n\n", falta);
                                            int resposta;
                                                    printf("Deseja reduzir cada gasto proporcionalmente para caber na renda? (1=Sim / 0=Nao): ");
                                                    scanf("%d", &resposta);
                                                       limpar_buffer() 
                                                        if (resposta == 1) {
                                                         float percentual_corte = (falta / total) * 100.0f;
                                                         float fator = saldo / total;
                                                            printf("\nCorte necessario: %.1f%% em cada despesa\n", percentual_corte);
                                                            printf("\n%-20s  %-12s  %-12s  %s\n", "Despesa", "Valor Atual", "Novo Valor", "Reducao");
                                                            printf("------------------------------------------------------------\n");

                                                         float novo_total = 0;
                                                         for (int i = 0; i < despesa; i++) {
                                                         float novo_valor = valores[i] * fator;
                                                         float reducao = valores[i] - novo_valor;
                                                            printf("%-20s  R$ %8.2f  R$ %8.2f  -R$ %.2f\n", nomes[i], valores[i], novo_valor, reducao);
                                                            novo_total += novo_valor;
                                                         }
                                                         printf("------------------------------------------------------------\n");
                                                         printf("Novo total: R$ %.2f  (renda: R$ %.2f)\n", novo_total, saldo);
                                                         } else {
                                                            printf("Ok! Nenhuma reducao aplicada.\n");
                                                         }
                                                       }
                                                    printf("Pressione Enter para continuar");
                                                       limpar_buffer()
                                                       break;
                case 0:       printf("Saindo do Sistema\n");
                            break;
                           default: printf("Valor invalido\n");
                         }

                }while (escolha != 0);

 return 0;
 }
