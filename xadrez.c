#include <stdio.h>

// Função recursiva para simular o movimento horizontal da Torre.
// Para cada "casa" (casas > 0), imprime "Direita" e chama a função novamente
// com o parâmetro decrementado, até que 'casas' seja 0.
void moverTorre(int casas) {
    if (casas > 0) {
        printf("Direita\n");
        moverTorre(casas - 1);
    }
}

// Função recursiva para simular o componente horizontal do movimento do Bispo.
// Essa função imprime "Direita" uma vez e decrementa o parâmetro até zerar.
void moverBispo(int casas) {
    if (casas > 0) {
        printf("Direita\n");
        moverBispo(casas - 1);
    }
}

// Função recursiva para simular o movimento horizontal da Dama.
// Imprime "Esquerda" para cada casa e decrementa o valor até que 'casas' seja 0.
void moverDama(int casas) {
    if (casas > 0) {
        printf("Esquerda\n");
        moverDama(casas - 1);
    }
}

int main() {
    // Variáveis:
    //  - movimento: armazena o número de casas ou a escolha de subopção informada pelo usuário.
    //  - opcao: guarda a opção escolhida no menu principal (representa a peça).
    //  - casa: utilizada para armazenar o número de casas para o movimento vertical do Bispo.
    //  - i: contador para os loops aninhados.
    int movimento, opcao, casa, i;
    
    // Loop principal do jogo:
    // Exibe o menu e repete caso o usuário digite uma opção inválida (opcao > 5).
    do {
        // Exibição do cabeçalho e do menu de peças.
        printf("\n*** Bem-vindo ao jogo de xadrez ***\n");
        printf("\nEscolha o número correspondente à peça que deseja jogar:\n");
        printf("1. Peão\n");
        printf("2. Bispo\n");
        printf("3. Torre\n");
        printf("4. Dama\n");
        printf("5. Cavalo\n");
        
        // Leitura da opção escolhida.
        scanf("%d", &opcao);
        
        // Se o usuário digitar uma opção inválida (maior que 5), exibe uma mensagem.
        if (opcao > 5) {
            printf("\nOpção inválida!!!\n");
        }
        
        // Seleção do comportamento com base na peça escolhida.
        switch(opcao) {
            
            case 1:
                // ----- Peão -----
                // O Peão pode andar somente 1 ou 2 casas.
                do {
                    printf("\n*** Peão ***\n");
                    printf("Digite o número de casas para o peão andar (1 ou 2):\n");
                    
                    scanf("%d", &movimento);
                    
                    if (movimento > 2) {
                        // Se o valor for maior que 2, o movimento é inválido.
                        printf("\nMovimento inválido!\n");
                        printf("O peão só pode andar 1 ou 2 casas.\n");
                    }
                    else {
                        // Para um movimento válido, imprime "Para cima" uma vez para cada casa.
                        for (i = 0; i < movimento; i++) {
                            printf("Para cima\n");
                        }
                    }
                } while (movimento > 2);
                break;
                
            case 2:
                // ----- Bispo -----
                // O movimento do Bispo possui dois componentes:
                //   a) Componente vertical: "Cima Vertical"
                //   b) Componente horizontal: "Direita" (simulado pela função recursiva moverBispo)
                // O usuário primeiro escolhe entre duas opções de movimento (1 ou 2).
                do {
                    printf("\n*** Bispo ***\n");
                    printf("Escolha o tipo de movimento do Bispo:\n");
                    printf("1. Cima Vertical\n");
                    printf("2. Cima, Direita Horizontal\n");
                    
                    scanf("%d", &movimento);
                    
                    if (movimento > 2) {
                        printf("\nMovimento inválido!\n");
                        printf("As únicas opções são 1 ou 2.\n");
                    }
                    else if (movimento == 1) {
                        // Se a opção for 1, solicita o número de casas para o movimento vertical.
                        printf("Digite o número de casas para o movimento vertical:\n");
                        scanf("%d", &casa);
                        
                        // Loop aninhado: o loop externo controla o componente vertical.
                        // Para cada casa movida verticalmente, imprime "Cima Vertical, " e,
                        // em seguida, chama a função recursiva moverBispo(1) para simular
                        // o movimento horizontal (imprimindo "Direita").
                        for (i = 0; i < casa; i++) {
                            printf("Cima Vertical, ");
                            moverBispo(1);
                        }
                    }
                    else {  
                        // Se a opção for 2, por exemplo, podemos solicitar o número de casas para
                        // outro tipo de movimento. Neste exemplo, vamos ajustar o texto para
                        // "Cima Horizontal" (apesar da mesma implementação, para fins de demonstração).
                        printf("Digite o número de casas para o movimento horizontal:\n");
                        scanf("%d", &casa);
                        
                        // Loop aninhado similar, mas com outra indicação textual.
                        for (i = 0; i < casa; i++) {
                            printf("Cima Horizontal, ");
                            moverBispo(1);
                        }
                    }
                } while (movimento > 2);
                break;
                
            case 3:
                // ----- Torre -----
                // A Torre pode andar de 1 a 5 casas para a direita.
                do {
                    printf("\n*** Torre ***\n");
                    printf("Digite o número de casas para a Torre andar (1 a 5):\n");
                    
                    scanf("%d", &movimento);
                    
                    if (movimento > 5) {
                        printf("\nMovimento inválido!\n");
                        printf("A torre só anda de 1 a 5 casas.\n");
                    }
                    else {
                        // Chama a função recursiva para simular o movimento.
                        moverTorre(movimento);
                    }
                } while (movimento > 5);
                break;
                
            case 4:
                // ----- Dama -----
                // A Dama pode andar de 1 a 9 casas para a esquerda.
                do {
                    printf("\n*** Dama ***\n");
                    printf("Digite o número de casas para a Dama andar (1 a 9):\n");
                    
                    scanf("%d", &movimento);
                    
                    if (movimento > 9) {
                        printf("\nMovimento inválido!\n");
                        printf("A dama só anda de 1 a 9 casas.\n");
                    }
                    else {
                        moverDama(movimento);
                    }
                } while (movimento > 9);
                break;
                
            case 5:
                // ----- Cavalo -----
                // Para o Cavalo, as únicas opções válidas são 1 ou 2:
                //   1. Baixo, Baixo, Esquerda
                //   2. Baixo, Baixo, Direita
                do {
                    printf("\n*** Cavalo ***\n");
                    printf("Escolha o movimento do Cavalo:\n");
                    printf("1. Baixo, Baixo, Esquerda\n");
                    printf("2. Baixo, Baixo, Direita\n");
                    
                    scanf("%d", &movimento);
                    
                    if (movimento > 2) {
                        printf("\nMovimento inválido!\n");
                        printf("As únicas opções são 1 ou 2.\n");
                    }
                    else if (movimento == 1) {
                        // Para a opção 1: utiliza laço de repetição para imprimir a sequência de
                        // movimento "Baixo, " seguida de "Esquerda".
                        for (i = 0; i < movimento; i++) {
                            movimento += 1; // Ajusta o valor para o controle da impressão
                            while (i < movimento) {
                                printf("Baixo, ");
                                i++;
                            }
                            printf("Esquerda\n");
                        }
                    }
                    else {
                        // Para a opção 2: similar, mas imprimindo "Direita" no final.
                        for (i = 0; i < movimento; i++) {
                            while (i < movimento) {
                                printf("Baixo, ");
                                i++;
                            }
                            printf("Direita\n");
                        }
                    }
                } while (movimento > 2);
                break;
        }
        
    } while (opcao > 5);  // Repete o menu se o usuário digitar uma opção inválida (maior que 5).
    
    return 0;
}
