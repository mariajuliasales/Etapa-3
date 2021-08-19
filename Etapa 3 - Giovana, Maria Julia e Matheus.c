#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>


/*SISTEMA DE CONTROLE POUSADA GMM*/


struct Quarto {
    char nome_cliente[100];
    char numero_telefone[50];
    char check_in[100];
    char check_out[100];
    char situacao[20];
    int numero_quarto,animais,numero_pessoas;
    float valor;
              };

#define Q 10


void traco (){
    printf("\n -------------------------------------------------------------\n");
            }

void opc(){
    printf("\n\n DIGITE 1 CASO A RESPOSTA SEJA SIM;");
    printf("\n DIGITE QUALQUER OUTRO NUMERO CASO A RESPOSTA SEJA NÃO. \n\n");
          }

void agradecimento(){
    system("cls");
    printf("\n -------------------------------------------------------------");
    printf("\n\n\t OBRIGADA POR UTILIZAR NOSSO SISTEMA!\n");
    printf("\n -------------------------------------------------------------\n\n");
    system("pause");
    system("cls");
                    }


float pagamento(float diaria,int dias){
    return diaria*dias;
                                      }

int main()

{
    setlocale(LC_ALL,"");

    struct Quarto quartos[Q];

    float dias;
    char a;
    const float diaria=120;
    int i,acao,disp=10,ocup=0,manuten=0,animal;

    FILE *pont_arq;

    pont_arq=fopen("arquivo_ETAPA3-Giovana,Maria Julia e Matheus.txt","w");

    if(pont_arq==NULL){
            printf("FALHA DE ABERTURA DO ARQUIVO!");
            return 1;
                      }

    for (i=0;i<10;i++){
    strcpy(quartos[i].situacao,"DISPONIVEL");
    strcpy(quartos[i].check_out,"'NÃO ADICIONADO'");
                      }

    do {
        traco();
        printf("\n\n\t\t BEM VINDO(A) !!!\n");
        printf("\n\n\t- DIGITE 1 PARA VIZUALISAR QUARTOS DISPONÍVEIS;");
        printf("\n\n\t- DIGITE 2 PARA VIZUALISAR QUARTOS OCUPADOS;");
        printf("\n\n\t- DIGITE 3 PARA VIZUALISAR QUARTOS EM MANUTENÇÃO;");
        printf("\n\n\n SE DESEJA SAIR DO SISTEMA, DIGITE 0.\n");
        traco();
        scanf("%d",&acao);
        system("cls");


        switch (acao){

            case 1:{
                traco();
                printf("\n\n\t NO MOMENTO ESTAMOS COM %d QUARTOS DISPONIVEIS !",disp);
                traco();
                printf("\n\n\n DESEJA REALIZAR UMA RESERVA?\n");
                opc();
                scanf("%d",&acao);
                system("cls");

                if (acao==1){
                    traco();
                    printf("\n\n\t\t VOCE ESTÁ REALIZANDO UM CADASTRO!");
                    printf("\n\n VEJA A SITUAÇÃO DOS NOSSOS QUARTOS:\n");
                    for (i=0;i<10;i++){
                    printf("\n\t O QUARTO %d ESTÁ %s",i,quartos[i].situacao);
                                      }
                    printf("\n\n\n INFORME O NUMERO DO QUARTO:\n\n ");
                    scanf("%d",&quartos[i].numero_quarto);
                    fprintf(pont_arq,"\n\n %d",quartos[i].numero_quarto);
                    i=quartos[i].numero_quarto;
                    system("cls");
                    traco();
                    printf("\n\n\n INFORME O NOME DO CLIENTE:\n\n ");
                    scanf("%s",&quartos[i].nome_cliente);
                    gets(quartos[i].nome_cliente);
                    fprintf(pont_arq,"\n\n %s",quartos[i].nome_cliente);
                    printf("\n\n\n INFORME O NUMERO DO TELEFONE DO CLIENTE:\n\n ");
                    scanf("%s",&quartos[i].numero_telefone);
                    gets(quartos[i].numero_telefone);
                    fprintf(pont_arq,"\n\n %d",quartos[i].numero_telefone);
                    printf("\n\n\n INFORME O NUMERO DE PESSOAS NO QUARTO:\n\n ");
                    scanf("%d",&quartos[i].numero_pessoas);
                    fprintf(pont_arq,"\n\n %d",quartos[i].numero_pessoas);
                    system("cls");
                    traco();
                    printf("\n\n\n O CLIENTE POSSUI ANIMAIS?\n\n");
                    opc();
                    scanf("%d",&animal);

                    if (animal==1){
                        printf("\n\n\n INFORME O NUMERO DE ANIMAIS:\n\n");
                        scanf("%d",&quartos[i].animais);
                        fprintf(pont_arq,"\n\n %d",quartos[i].animais);
                                  }
                    else {
                        quartos[i].animais = 0;
                        fprintf(pont_arq,"\n\n %d",quartos[i].animais);
                        printf("\n\n BICHINHOS SÃO ADORAVEIS!\n");
                         };

                    printf("\n\n\n INFORME A DATA DO CHECK-IN:\n\n");
                    scanf("%s",&quartos[i].check_in);
                    gets(quartos[i].check_in);
                    fprintf(pont_arq,"\n\n %s",quartos[i].check_in);
                    system("cls");
                    traco();
                    printf("\n\n\n\t OBRIGADA POR REALIZAR UMA RESERVA EM NOSSA POUSADA\n\n");
                    printf("\n\n\n CONFIRA AS INFORMAÇÕES INSERIDAS NESSE CADASTRO:");
                    printf("\n\n O NOME DO CLIENTE É %s",&quartos[i].nome_cliente);
                    printf("\n\n O NUMERO DO CLIENTE É %s",quartos[i].numero_telefone);
                    printf("\n\n O NUMERO DE PESSOAS NO QUARTO É %d",quartos[i].numero_pessoas);
                    printf("\n\n O NUMERO DE ANIMAIS NO QUARTO É %d",quartos[i].animais);
                    printf("\n\n A DATA DE CHECK-IN É %s",quartos[i].check_in);
                    printf("\n\n A DATA DE CHECK-OUT É %s \n\n",quartos[i].check_out);
                    system("pause");
                    strcpy(quartos[i].situacao,"OCUPADO");
                    disp= disp-1;
                    ocup=ocup+1;
                    system("cls");

                            }
                else {
                agradecimento();
                     }
                   } break;
            case 2:{
                traco();
                printf("\n\n\t NO MOMENTO ESTAMOS COM %d QUARTOS OCUPADOS !",ocup);
                traco();
                printf("\n\n\n DESEJA REALIZAR ALGUMA ALTERAÇÃO?\n");
                opc();
                scanf("%d",&acao);
                system("cls");

                if (acao==1){
                    traco();
                    printf("\n\n\t\t VOCE ESTÁ REALIZADNO UMA ALTERAÇÃO!");
                    printf("\n\n\t VEJA A SITUAÇÃO DOS NOSSOS QUARTOS:\n");
                    for (i=0;i<10;i++){
                    printf("\n\t O QUARTO %d ESTÁ %s",i,quartos[i].situacao);
                      }
                    system("pause");
                    system("cls");
                    printf("\n\n\n INFORME O NUMERO DO QUARTO:\n\n ");
                    scanf("%d",&quartos[i].numero_quarto);
                    i=quartos[i].numero_quarto;
                    system("cls");
                    printf("\n\n\n CONFIRA AS INFORMAÇÕES INSERIDAS NESSE CADASTRO:");
                    printf("\n\n O NOME DO CLIENTE É %s",quartos[i].nome_cliente);
                    printf("\n\n O NUMERO DO CLIENTE É %s",quartos[i].numero_telefone);
                    printf("\n\n O NUMERO DE PESSOAS NO QUARTO É %d",quartos[i].numero_pessoas);
                    printf("\n\n O NUMERO DE ANIMAIS NO QUARTO É %d",quartos[i].animais);
                    printf("\n\n A DATA DE CHECK-IN É %s",quartos[i].check_in);
                    printf("\n\n A DATA DE CHECK-OUT É %s \n\n",quartos[i].check_out);
                    system("pause");
                    system("cls");
                    printf("\n\n DIGITE 1 PARA ALTERAR O NOME DO CLIENTE;");
                    printf("\n\n DIGITE 2 PARA ALTERAR O NUMERO DO CLIENTE;");
                    printf("\n\n DIGITE 3 PARA ALTERAR O NUMERO DE PESSOAS;");
                    printf("\n\n DIGITE 4 PARA ALTERAR O NUMERO DE ANIMAIS;");
                    printf("\n\n DIGITE 5 PARA ALTERAR O CHECK-IN;");
                    printf("\n\n DIGITE 6 PARA ALTERAR O CHECK-OUT;");
                    printf("\n\n DIGITE QUALQUER OUTRO NUMERO CASO DESEJE SAIR. \n\n");
                    scanf("%d",&acao);
                    system("cls");

                    switch(acao){

                        case 1:{
                            traco();
                            printf("\n\n VOCÊ ESTÁ ALTERANDO O NOME DO CLIENTE;");
                            printf("\n\n DIGITE O NOME DO CLIENTE: \n\n");
                            scanf("%s",&quartos[i].nome_cliente);
                            fprintf(pont_arq,"\n\n %s",quartos[i].nome_cliente);
                            system("cls");
                            agradecimento();
                               }break;

                       case 2:{
                            traco();
                            printf("\n\n VOCÊ ESTÁ ALTERANDO O NUMERO DO CLIENTE;");
                            printf("\n\n DIGITE O NUMERO DO CLIENTE: \n\n");
                            scanf("%s",&quartos[i].numero_telefone);
                            fprintf(pont_arq,"\n\n %s",quartos[i].numero_telefone);
                            system("cls");
                            agradecimento();
                               }break;

                       case 3:{
                            traco();
                            printf("\n\n VOCÊ ESTÁ ALTERANDO O NUMERO DE PESSOAS;");
                            printf("\n\n DIGITE O NUMERO DE PESSOAS:\n\n");
                            scanf("%d",&quartos[i].numero_pessoas);
                            fprintf(pont_arq,"\n\n %d",quartos[i].numero_pessoas);
                            system("cls");
                            agradecimento();
                               }break;

                       case 4:{
                            traco();
                            printf("\n\n VOCÊ ESTÁ ALTERANDO O NUMERO DE ANIMAIS;");
                            printf("\n\n DIGITE O NUMERO DE ANIMAIS:\n\n");
                            scanf("%d",&quartos[i].animais);
                            fprintf(pont_arq,"\n\n %d",quartos[i].animais);
                            system("cls");
                            agradecimento();
                               }break;

                       case 5:{
                            traco();
                            printf("\n\n VOCÊ ESTÁ ALTERANDO CHECK-IN;");
                            printf("\n\n DIGITE A DATA DE CHECK-IN: \n\n");
                            scanf("%s",&quartos[i].check_in);
                            fprintf(pont_arq,"\n\n %s",quartos[i].check_in);
                            system("cls");
                            agradecimento();
                               }break;

                       case 6:{
                            traco();
                            printf("\n\n VOCÊ ESTÁ ADICIONANDO O CHECK-OUT;");
                            printf("\n\n DIGITE A DATA DE CHECK-OUT: \n\n");
                            scanf("%s",&quartos[i].check_out);
                            fprintf(pont_arq,"\n\n %s",quartos[i].check_out);
                            printf("\n\n INFORME QUANTOS DIAS O CLIENTE PASSOU HOSPEDADO: \n\n");
                            scanf("%f",&dias);
                            quartos[i].valor=pagamento(diaria,dias);
                            fprintf(pont_arq,"\n\n %f",quartos[i].valor);
                            system("cls");
                            traco();
                            printf("\n\n O CLIENTE DEVERA PAGAR R$%.2f \n\n", quartos[i].valor);
                            system("pause");
                            system("cls");
                            agradecimento();
                               }break;

                       default:{
                           agradecimento();
                              }break;
                                }
                    }


                else {
                        agradecimento();
                     }
                   } break;

            case 3:{
                traco();
                printf("\n\n\t NO MOMENTO ESTAMOS COM %d QUARTOS EM MANUTENÇÃO !",manuten);
                traco();
                printf("\n\n\n DESEJA REALIZAR UMA ALTERAÇÃO?\n");
                opc();
                scanf("%d",&acao);
                system("cls");

                if (acao==1){
                    printf("\n\n\t\t VOCE ESTÁ REALIZADNO UMA ALTERAÇÃO!");
                    printf("\n\n\t VEJA A SITUAÇÃO DOS NOSSOS QUARTOS:\n");
                    for (i=0;i<10;i++){
                    printf("\n\t O QUARTO %d ESTÁ %s",i,quartos[i].situacao);
                      }
                    printf("\n\n\n INFORME O NUMERO DO QUARTO:\n\n ");
                    scanf("%d",&quartos[i].numero_quarto);
                    i=quartos[i].numero_quarto;
                    system("cls");
                    traco();
                    printf("\n\n\t VOCÊ ESTÁ ALTERANDO O ESTADO DO QUARTO \n");
                    printf("\n\n DIGITE 1 CASO DESEJE ALTERAR O STATUS PARA DISPONIVEL;");
                    printf("\n\n DIGITE 2 CASO DESEJE ALTERAR O STATUS PARA EM MANUTENÇÃO;");
                    printf("\n\n DIGITE QUALQUER OUTRO NUMERO CASO DESEJE SAIR. \n\n");
                    scanf("%d",&acao);
                    system("cls");

                    switch(acao){

                        case 1:{
                            strcpy(quartos[i].situacao,"DISPONIVEL");
                            disp=disp-1;
                            ocup=ocup+1;
                            traco();
                            printf("\n\n VOCÊ ALTEROU O STATUS DO QUARTO PARA DISPONIVEL!");
                            system("pause");
                            system("cls");
                               }break;

                        case 2:{
                            strcpy(quartos[i].situacao,"EM MANUTENÇÃO");
                            disp=disp-1;
                            manuten=manuten+1;
                            traco();
                            printf("\n\n VOCÊ ALTEROU O STATUS DO QUARTO PARA EM MANUTENÇÃO!");
                            system("pause");
                            system("cls");
                               }break;

                        default:{
                            agradecimento();
                                }break;
                    }
                }

                else {
                    agradecimento();
                     }
                   } break;

                     }

       }while(acao!=0);
    fclose(pont_arq);


    return 0;
}
