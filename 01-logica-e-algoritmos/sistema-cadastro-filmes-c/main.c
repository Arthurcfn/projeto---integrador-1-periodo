#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

#define Max_Filmes 50

struct Filme {
    int codigo;
    char  titulo[60];
    char genero[40];
    int ano;
    float nota;
    int disponivel;
    char locatario[50];
    int ativo;
    };

    int cadastrarfilme(struct Filme lista[], int total) {
        if (total >= Max_Filmes) {
            printf("Limite Maximo de Filmes atingidos");
            return total;
        }

        struct Filme novo;
        printf("\n\t--- Cadastrar Novo Filme---\n\n");
        printf("\t Codigo do Filme (número): ");
        scanf("%d", &novo.codigo);
        getchar();

        for (int i = 0; i <total; i++ ) {
            if (lista[i].codigo == novo.codigo && lista[i].ativo == 1){
                    printf("\n\tErro: Já existe um filme cadastrado com esse código!!\n");
                    return total;

                }
        }

        printf("\t Título do Filme: ");
        fgets(novo.titulo, sizeof(novo.titulo), stdin);

        printf("\t Genêro: ");
        fgets(novo.genero, sizeof(novo.genero), stdin);

        printf("\t Ano Lançamento: ");
        scanf("%d", &novo.ano);

        printf("\t Nota do Filme: ");
        scanf("%f", &novo.nota);
        getchar();

        novo.disponivel = 1;
        novo.locatario[0] = '\0';
        novo.ativo = 1;

        lista[total] = novo;
        total++;

        printf("\n\t Filme Cadastrado com sucesso!\n");

        return total;

    }

    void listarFilme(struct Filme lista[], int total) {
        int encontrou = 0;

        printf("\n\t---Catálago de Filmes---\n\n");
        for(int i = 0; i < total; i++) {
            if (lista[i].ativo == 1) {
            encontrou = 1;

            printf("\t Codigo: %d / Titulo: %s (%d)\n",
            lista[i].codigo, lista[i].titulo, lista[i].ano);

            printf("\t Gênero: %s / Nota: %.1f/10\n" ,
            lista[i].genero, lista[i].nota);

            if (lista[i].disponivel == 1) {
                printf("\t Status: Disponivel\n");
            } else {
                printf("\t Status: Alugado por %s\n", lista[i].locatario);
                }

                printf("\t---------------------------\n");

            }

    }

        if (encontrou == 0) {
            printf("\t Nenhum filme cadastrado no momento.\n");
        }


        }

    void movimentarLocacao(struct Filme lista[], int total){
        int cod, acao;

        printf("\n\t--- Alugar / Devolver Filme ---\n\n");
        printf("\t1. Alugar Filme\n");
        printf("\t2. Devolver filme\n");
        printf("\t Escolha: ");
        scanf("%d", &acao);
        getchar();

        printf("\t Digite o código do filme: ");
        scanf("%d", &cod);
        getchar();

        for(int i = 0; i < total; i++) {
            if (lista[i].codigo == cod && lista[i].ativo == 1) {
                if (acao == 1) {
                    if (lista[i].disponivel == 1) {
                    printf("\t Nome de quem vai alugar: ");
                    fgets(lista[i].locatario, sizeof(lista[i].locatario), stdin);
                    lista[i].disponivel = 0;
                    printf("\n\t Filme alugado com sucesso!\n");
                 } else {
                     printf("\n\t Este filme já está alugado por %s!\n", lista[i].locatario);
                 }
            }else if (acao == 2) {
                if (lista[i].disponivel == 0) {
                    lista[i].disponivel = 1;
                    lista[i].locatario[0] = '\0';
                    printf("\n\t Filme devolvido e disponível novamente!\n");

                } else {
                    printf("\n\t Este filme ja estava disponivel na prateleira!\n");
                }

            } else {
                printf("\n\t Opção inválida\n");
            }
            return;
        }

    }
        printf("\n\t Filme não encontrado com esse codigo.\n");
     }

     void atualizarFilme(struct Filme lista[], int total) {
         int cod;
         int encontrou = 0;

         printf("\n\t --- Atualizar Dados do Filme ---\n");
         printf("\t Digite o codigo do filme que deseja editar: ");
         scanf("%d", &cod);
         getchar();

         for(int i = 0; i < total; i++) {
            if(lista[i].codigo == cod && lista[i].ativo == 1) {
                encontrou = 1;

                printf("\n\t Editando o filme: %s", lista[i].titulo);
                printf("\t Novo Titulo: ");
                fgets(lista[i].titulo, sizeof(lista[i].titulo), stdin);

                printf("\t Novo Gênero: ");
                fgets(lista[i].genero, sizeof(lista[i].genero), stdin);

                printf("\t Novo Ano de Lançamento: ");
                scanf("%d", &lista[i].ano);

                printf("\t Nova nota: ");
                scanf("%f", &lista[i].nota);
                getchar();

                printf("\t\t Dados do filme atualizados com sucesso");
                break;
            }
         }

         if(encontrou == 0) {
            printf("\n\t Filme não encontrado no catálago");
         }
     }

     void excluirFilme(struct Filme lista[], int  total) {
         int cod, encontrou = 0;

         printf("\n\t--- Excluir Filme ---\n");
         printf("\t Digite o código do filme que deseja excluir: ");
         scanf("%d", &cod);
         getchar();

         for(int i = 0; i < total; i++) {
            if(lista[i].codigo == cod && lista[i].ativo == 1) {
                encontrou = 1;

                if(lista[i].disponivel == 0) {
                    printf("\n\t Error: Não é possivel excluir esse filme! Filme alugado por %s", lista[i].locatario);
                } else {
                    lista[i].ativo = 0;
                    printf("\n\t Filme removido com suceso ");
                }
                break;
            }
         }

         if (encontrou == 0)
         printf("\n\t Filme não encontrado.\n");

        }



    int main () {
        setlocale(LC_ALL, "Portuguese");

        struct Filme catalogo[Max_Filmes];
        int total_filmes = 0;
        int opcao;

        do {
                printf("\t===========================\n");
                printf("\n\t--- Locadora e Catálogo de Filmes ---\n\n");
                printf("\t===========================\n");
                printf("\t1 Cadastrar Filme\n");
                printf("\t2 Listar Filme\n");
                printf("\t3 Alugar ou Devolver Filme\n");
                printf("\t4 Atualizar Filme\n");
                printf("\t5 Excluir Filme\n");
                printf("\t0 Sair\n");
                printf("\t===========================\n");
                printf("\n\t Escolha uma opção\n");
                scanf("%d", &opcao);
                getchar();

                switch (opcao) {
                case 1:
                    total_filmes = cadastrarfilme(catalogo, total_filmes);
                    break;
                case 2:
                    listarFilme(catalogo, total_filmes);
                    break;
                case 3:
                    movimentarLocacao(catalogo, total_filmes);
                    break;
                case 4:
                    atualizarFilme(catalogo, total_filmes);
                    break;
                case 5:
                    excluirFilme(catalogo, total_filmes);
                    break;
                case 0:
                    printf("\n\t Saindo");
                    break;
                default:
                    printf("\n Opção inválida!\n");

                }

        } while (opcao != 0);


    return 0;
    }

