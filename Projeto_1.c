#include <stdio.h> //biblioteca de comunicação com o usuário (input e output)
#include <stdlib.h> //biblioteca de alocação de espaços de memória
#include <locale.h> //biblioteca de alocaçãp de texto por região

int registro()//Função responsável pelo registro
{
    setlocale(LC_ALL, "Portuguese"); 

    printf("### Registro ###\n\n");

    //Declaração de variáveis
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    
    //Atribuição de valores às variáveis
    printf("Digite o CPF a ser cadastrado: ");
    scanf("%s", cpf);
    printf("Digite o nome a ser cadastrado: ");
    scanf("%s", nome);
    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);
    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo);

    //Criação do arquivo
    FILE *file = fopen( cpf, "w");
    fprintf(file, "%s. %s. %s. %s.", cpf, nome, sobrenome, cargo);
    fclose(file);
    printf("\nRegistro finalizado com sucesso.\n\n");

    //Pausa no sistema
    system("read -p 'Pressione ENTER para continuar...\n' var");
}

int consulta()//Função responsável pela consulta
{
    setlocale(LC_ALL, "Portuguese"); 

    printf("### Consulta ###\n\n");

    //Declaração de variáveis
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];

    //Atribuição de valores às variáveis
    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);

    //Leitura do arquivo
    FILE *file = fopen( cpf, "r");
    if (file == NULL)
    {
        printf("\nCPF não encontrado nos registros.\n\n"); 
    }
    else
    {
        fscanf(file, "%s %s %s %s", &cpf, &nome, &sobrenome, &cargo);
        printf( "\nCPF: %s\n"
                "Nome: %s\n"
                "Sobrenome: %s\n"
                "Cargo: %s\n\n", 
                cpf, nome, sobrenome, cargo
        );
    }
    //Pausa no sistema
    system("read -p 'Pressione ENTER para continuar...\n' var");
}

int deletar()//Função responsável por deletar
{
    setlocale(LC_ALL, "Portuguese"); 

    printf("### Deleção ###\n\n");

    //Declaração de variáveis
    char cpf[40];

    //Atribuição de valores às variáveis
    printf("Digite o CPF a ser deletado: ");
    scanf("%s", cpf);

    //Deleção do arquivo
    if (remove(cpf) == 0)
    {
        printf("\nDeleção realizada com sucesso.\n\n");
    }
    else
    {
        printf("\nCPF não encontrado.\n\n");
    }
    
    system("read -p 'Pressione ENTER para continuar...\n' var");
}

int main()
{
    //Declaração de variáveis
    int opcao = 0; 
    int laco = 1;

    //Menu
    for ( laco = 1; laco == 1;)
    {
        //Definindo a linguagem
        setlocale(LC_ALL, "Portuguese"); 
        
        system("clear"); //Limpa a tela

        printf("### Cartório da EBAC ###\n\n"
            "Escolha a opção desejada no menu:\n\n"
            "\t1 - Registrar\n"
            "\t2 - Consultar\n"
            "\t3 - Deletar\n"
            "\t4 - Sair do sistema\n\n"
            "\nOpção:"
        ); 

        scanf("%d", &opcao); //Armazena seleção do usuário

        system("clear"); //Limpa a tela

            switch (opcao)
            { 
            case 1:
                registro();
                break;
            
            case 2:
                consulta();
                break;
            
            case 3:
                deletar();
                break;

            case 4:
                printf("Obrigado por utilizar o sistema.\n");
                return 0;
                break;

            default:
                printf("Comando não reconhecido. Por favor, digite novamente.\n\n");
                system("read -p 'Pressione ENTER para continuar...\n' var");
                break;
            }
    }
}