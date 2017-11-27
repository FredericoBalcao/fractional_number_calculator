/*
 *  ESTGP/IPPortalegre
 *  Engenharia Informática
 *  Introdução à Programação 2013/2014 - Trabalho 1
 *
 *  Aluno: 15307 - Frederico Balcão
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h> /*para uso da função rand()*/

/*Variaveis que serão usadas em todo o programa*/
int vNum=0, vDen=1;  /* Variaveis para o visor (inicilaizados a 0/1)*/
int mNum, mDen;  /* Variaveis para a memoria */
char opcao, escolha;  /* Operação a ler do teclado */
int num, den;    /* Fraccionario a ler do teclado para calculadora */
int num1, num2, den1, den2; /*numeros fracionarios para a função de treino e teste*/
int oper1, oper2, oper3, resultado, resultado1, resultado2, resultado3, resultado4, resultado5, aux, aux1, divisor; /*todas as variaveis para os calculos*/
int i, certas = 0, erradas = 0, opcaoteste, num_perguntas=0, perc_certas=0, perc_erradas=0, tentativas, num_max_erradas, aux2;

int MDC(int num, int den){ /*criei esta função para calcular o maximo divisor comum para somas e subtrações */
    if (num==0)
        num=1;
    if (den==0)
        den=1;

        while(num != den)
            if(num > den)
                    num = num - den;
            else
                    den = den - num;
 return num;
}

void comandos() { /*função que mostra os comandos possiveis*/
    printf("\n");
    printf(" ________________________________________________ \n");
    printf("|                     COMANDOS                   |\n");
    printf("|------------------------------------------------|\n");
    printf("|       OPERACAO                      TECLA      |\n");
    printf("|                                                |\n");
    printf("|   ->  SOMA                            +        |\n");
    printf("|   ->  SUBTRACCAO                      -        |\n");
    printf("|   ->  DIVISAO                         /        |\n");
    printf("|   ->  MULTIPLICACAO                   *        |\n");
    printf("|   ->  SIMETRICO                       s        |\n");
    printf("|   ->  INVERSO                         i        |\n");
    printf("|   ->  GUARDAR NA MEMORIA              m        |\n");
    printf("|   ->  CHAMAR MEMORIA                  r        |\n");
    printf("|   ->  LIMPAR MEMORIA                  rr       |\n");
    printf("|   ->  ADICIONAR A MEMORIA             a        |\n");
    printf("|   ->  TROCAR VALOR COM O DA MEMORIA   x        |\n");
    printf("|   ->  LIMPAR O VISOR                  c        |\n");
    printf("|   ->  SAIR CALCULADORA                q        |\n");
    printf("|________________________________________________|\n");
    printf("\n");
    printf("\nIndique primeiro a operacao e em seguida os numeros fracionarios\n\n");
}

void soma(){ /*função para somar*/
            if((vDen != 0) && (den != 0) && (vDen != den)){ /*caso os denominadores serem diferentes*/
                oper1 = vDen * den;
                oper2 = ((oper1/vDen) * vNum);
                oper3 = ((oper1/den) * num);
                resultado1 = (oper2 + oper3);

  divisor = MDC(resultado1, oper1);

  if (divisor != 1){ /*opção avançada (3)*/
            resultado1 = resultado1 / divisor;
            oper1 = oper1 / divisor;

            if(resultado1 == oper1){
                    resultado1 = 1;
                printf("\nVisor: %d\n\n", resultado1);
            }else{
            /*opção avançada (2)*/
            if(resultado1 > 0 && oper1 < 0)
                printf("\nVisor: -(%d/%d)\n\n", resultado1, oper1*(-1));
            if(resultado1 < 0 && oper1 > 0)
                printf("\nVisor: -(%d/%d)\n\n", resultado1*(-1), oper1);
            if(resultado1 < 0 && oper1 < 0)
                printf("\nVisor: %d/%d\n\n", resultado1, oper1);
            if(resultado1 > 0 && oper1 > 0)
                printf("\nVisor: %d/%d\n\n", resultado1, oper1);
            }
  }else{
            if(resultado1 == oper1){
                    resultado1 = 1;
                printf("\nVisor: %d\n\n", resultado1);
            }else{
            /*opção avançada (2)*/
            if(resultado1 > 0 && oper1 < 0)
                printf("\nVisor: -(%d/%d)\n\n", resultado1, oper1*(-1));
            if(resultado1 < 0 && oper1 > 0)
                printf("\nVisor: -(%d/%d)\n\n", resultado1*(-1), oper1);
            if(resultado1 < 0 && oper1 < 0)
                printf("\nVisor: %d/%d\n\n", resultado1, oper1);
            if(resultado1 > 0 && oper1 > 0)
                printf("\nVisor: %d/%d\n\n", resultado1, oper1);
            }
  }
            vNum = resultado1;
            vDen = oper1;

}else if((vDen != 0) && (den != 0) && (vDen == den)){ /*caso os denominadores serem iguais*/
            resultado2 = (vNum + num);

divisor = MDC(resultado2, vDen);

    if (divisor != 1){ /*opção avançada (3)*/
            resultado2 = resultado2 / divisor;
            vDen = vDen / divisor;

            if(resultado2 == vDen){  /*caso o resultado do num e den sejam iguais, fica só um numero, por exemplo 1/1 no visor só aparece 1*/
                resultado2 = 1;
                printf("\nVisor: %d\n\n", resultado2);
            }else{
             /*opção avançada (2)*/
            if(resultado2 > 0 && vDen < 0)
                 printf("\nVisor: -(%d/%d)\n\n", resultado2, vDen*(-1));
            if(resultado2 < 0 && vDen > 0)
                 printf("\nVisor: -(%d/%d)\n\n", resultado2*(-1), vDen);
            if(resultado2 < 0 && vDen < 0)
                 printf("\nVisor: %d/%d\n\n", resultado2, vDen);
            if(resultado2 > 0 && vDen > 0)
                 printf("\nVisor: %d/%d\n\n", resultado2, vDen);
            }
    }else{ /*Se nao houver fracao irredutivel*/
            if(resultado2 == vDen){
                printf("\nVisor: %d\n\n", resultado2);
            }else{
             /*opção avançada (2)*/
            if(resultado2 > 0 && vDen < 0)
                 printf("\nVisor: -(%d/%d)\n\n", resultado2, vDen*(-1));
            if(resultado2 < 0 && vDen > 0)
                 printf("\nVisor: -(%d/%d)\n\n", resultado2*(-1), vDen);
            if(resultado2 < 0 && vDen < 0)
                 printf("\nVisor: %d/%d\n\n", resultado2, vDen);
            if(resultado2 > 0 && vDen > 0)
                 printf("\nVisor: %d/%d\n\n", resultado2, vDen);
    }
            vNum = resultado2;
            vDen = vDen;

    }
}else if(vDen == 0 || den == 0){ /*opção avançada (1)*/
            printf("\nVisor: Erro (Nao e possivel efectuar operacoes com denominadores a zero!)\n\n");
            printf("\nVisor: %d\n\n", vNum);
    }
}

void subtrair(){ /*função para subtrair*/
            if((vDen != 0) && (den != 0) && (vDen != den)){ /*caso os denominadores serem diferentes*/
                oper1 = vDen * den;
                resultado1 = (den * vNum)-(vDen * num);

        divisor = MDC(resultado1, oper1);


    if (divisor != 1){  /*opção avançada (3)*/
            resultado1 = resultado1 / divisor;
            oper1 = oper1 / divisor;

            if(resultado1 > 0 && oper1 < 0)
                printf("\nVisor: -(%d/%d)\n\n", resultado1, oper1*(-1));
                if(resultado1 < 0 && oper1 > 0)
                printf("\nVisor: -(%d/%d)\n\n", resultado1*(-1), oper1);
                if(resultado1 < 0 && oper1 < 0)
                printf("\nVisor: %d/%d\n\n", resultado1, oper1);
                if(resultado1 > 0 && oper1 > 0)
                printf("\nVisor: %d/%d\n\n", resultado1, oper1);
                if (resultado1 == oper1)
                    resultado1 = 1;
                printf("\nVisor: %d\n\n", resultado1);

    }else{
            if(resultado1 > 0 && oper1 < 0)
                printf("\nVisor: -(%d/%d)\n\n", resultado1, oper1*(-1));
                if(resultado1 < 0 && oper1 > 0)
                printf("\nVisor: -(%d/%d)\n\n", resultado1*(-1), oper1);
                if(resultado1 < 0 && oper1 < 0)
                printf("\nVisor: %d/%d\n\n", resultado1, oper1);
                if(resultado1 > 0 && oper1 > 0)
                printf("\nVisor: %d/%d\n\n", resultado1, oper1);
                if (resultado1 == oper1)
                    resultado1 = 1;
                printf("\nVisor: %d\n\n", resultado1);
    }
            vNum = resultado1;
            vDen = oper1;

}else if((vDen != 0) && (den != 0) && (vDen == den)){ /*caso os denominadores serem iguais*/
                resultado2 = (vNum - num);


divisor = MDC(resultado2, vDen);

    if (divisor != 1){ /*opção avançada (3)*/
            resultado2 = resultado2 / divisor;
            vDen = vDen / divisor;

            if(resultado2 == vDen){
                    resultado2 = 1;
                printf("\nVisor: %d\n\n", resultado2);
            }else{
            /*opção avançada (2)*/
            if(resultado2 > 0 && vDen < 0)
                 printf("\nVisor: -(%d/%d)\n\n", resultado2, vDen*(-1));
            if(resultado2 < 0 && vDen > 0)
                 printf("\nVisor: -(%d/%d)\n\n", resultado2*(-1), vDen);
            if(resultado2 < 0 && vDen < 0)
                 printf("\nVisor: %d/%d\n\n", resultado2, vDen);
            if(resultado2 > 0 && vDen > 0)
                 printf("\nVisor: %d/%d\n\n", resultado2, vDen);
            }
    }else{
            if(resultado2 == vDen){
                    resultado2 = 1;
                printf("\nVisor: %d\n\n", resultado2);
            }else{
            /*opção avançada (2)*/
            if(resultado2 > 0 && vDen < 0)
                 printf("\nVisor: -(%d/%d)\n\n", resultado2, vDen*(-1));
            if(resultado2 < 0 && vDen > 0)
                 printf("\nVisor: -(%d/%d)\n\n", resultado2*(-1), vDen);
            if(resultado2 < 0 && vDen < 0)
                 printf("\nVisor: %d/%d\n\n", resultado2, vDen);
            if(resultado2 > 0 && vDen > 0)
                 printf("\nVisor: %d/%d\n\n", resultado2, vDen);
            }
    }
            vNum = resultado2;
            vDen = vDen;

}else if(vDen == 0 || den == 0){ /*op.avançada (1)*/
            printf("\nVisor: Resultado Invalido - Erro (Nao e possivel efectuar operacoes com denominadores a zero!)\n\n");
            printf("\nVisor: %d\n\n", vNum);
    }
}

void multiplicar(){ /*função para multiplicar*/
    if(vDen == 0 || den == 0){
                    printf("\nVisor: Resultado Invalido - Erro (Nao e possivel efectuar operacoes com denominadores a zero!)\n\n");
                    /*as variaveis do visor voltam a ter os valores iniciais*/
                    vNum = 0;
                    vDen = 1;
                    printf("\nVisor: %d\n\n", vNum);
    }else if(vNum == 0 || num == 0){
                /*as variaveis do visor voltam a ter os valores iniciais*/
                vNum = 0;
                vDen = 1;
                printf("\nVisor: %d\n\n", vNum);
    }else{
            resultado1= vNum * num;
            resultado2= vDen * den;


divisor = MDC(resultado1, resultado2);

  if (divisor != 1){ /*opção avançada (3)*/
            resultado1 = resultado1 / divisor;
            resultado2 = resultado2 / divisor;

            if(resultado1 == resultado2){
                    resultado1 = 1;
                printf("\nVisor: %d\n\n", resultado1);
            }else{
            /*opção avançada (2)*/
            if(resultado1 > 0 && resultado2 < 0)
                printf("\nVisor: -(%d/%d)\n\n", resultado1, resultado2*(-1));
            if(resultado1 < 0 && resultado2 > 0)
                printf("\nVisor: -(%d/%d)\n\n", resultado1*(-1), resultado2);
            if(resultado1 < 0 && resultado2 < 0)
                printf("\nVisor: %d/%d\n\n", resultado1, resultado2);
            if(resultado1 > 0 && resultado2 > 0)
                printf("\nVisor: %d/%d\n\n", resultado1, resultado2);
            }
  }else{
            if(resultado1 == resultado2){
                    resultado1 = 1;
                printf("\nVisor: %d\n\n", resultado1);
            }else{
            /*opção avançada (2)*/
            if(resultado1 > 0 && resultado2 < 0)
                printf("\nVisor: -(%d/%d)\n\n", resultado1, resultado2*(-1));
            if(resultado1 < 0 && resultado2 > 0)
                printf("\nVisor: -(%d/%d)\n\n", resultado1*(-1), resultado2);
            if(resultado1 < 0 && resultado2 < 0)
                printf("\nVisor: %d/%d\n\n", resultado1, resultado2);
            if(resultado1 > 0 && resultado2 > 0)
                printf("\nVisor: %d/%d\n\n", resultado1, resultado2);
            }
  }
            vNum = resultado1;
            vDen = resultado2;
}
}

void dividir(){ /*função para dividir*/
    if(vDen == 0 || den == 0){
             printf("\nVisor: Resultado Invalido - Erro (Nao e possivel efectuar operacoes com denominadores a zero!)\n\n");
                    /*as variaveis do visor voltam a ter os valores iniciais*/
                    vNum = 0;
                    vDen = 1;
                    printf("\nVisor: %d\n\n", vNum);
    }else if(vNum == 0 || num == 0){
                 /*as variaveis do visor voltam a ter os valores iniciais*/
                vNum = 0;
                vDen = 1;
                printf("\nVisor: %d\n\n", vNum);
    }else{
                aux= vNum * den;
                aux1= vDen * num;


divisor = MDC(aux, aux1);

  if (divisor != 1){ /*opção avançada (3)*/
            aux = aux / divisor;
            aux1 = aux1 / divisor;

            if(aux == aux1){
                    aux = 1;
                printf("\nVisor: %d\n\n", aux);
            }else{
           /*opção avançada (2)*/
            if(aux > 0 && aux1 < 0)
                printf("\nVisor: -(%d/%d)\n\n", aux, aux1*(-1));
            if(aux < 0 && aux1 > 0)
                printf("\nVisor: %d/%d\n\n", aux*(-1), aux1);
            if(aux < 0 && aux1 < 0)
                printf("\nVisor: %d/%d\n\n", aux, aux1);
            if(aux > 0 && aux1 > 0)
                printf("\nVisor: %d/%d\n\n", aux, aux1);
            }
  }else{
            if(aux == aux1){
                    aux = 1;
                printf("\nVisor: %d\n\n", aux);
            }else{
            /*opção avançada (2)*/
            if(aux > 0 && aux1 < 0)
                printf("\nVisor: -(%d/%d)\n\n", aux, aux1*(-1));
            if(aux < 0 && aux1 > 0)
                printf("\nVisor: %d/%d\n\n", aux*(-1), aux1);
            if(aux < 0 && aux1 < 0)
                printf("\nVisor: %d/%d\n\n", aux, aux1);
            if(aux > 0 && aux1 > 0)
                printf("\nVisor: %d/%d\n\n", aux, aux1);
            }
  }
            vNum = aux;
            vDen = aux1;
    }
}

void limpar(){ /*função para limpar o numero do visor*/
            vNum = 0;
            vDen = 1;
            system("cls");
            comandos();
            printf("\nVisor: %d\n\n", vNum);
}

void inverso(){ /*função para inverter o numero*/
            aux = vNum;
            aux1 = vDen;
            den = aux;
            num = aux1;
            printf("\nVisor: %d/%d\n\n", num, den);
            vNum = num;
            vDen = den;
}

void simetrico(){ /*função para o simetrico do numero*/
            //opção avançada (2)
            if(vNum > 0 && vDen < 0){
                printf("\nVisor: %d/%d = -(%d/%d)\n\n", num*(-1), den*(-1), num, den*(-1)); //op.avançada (2)
            }else if(vNum < 0 && vDen > 0){
                printf("\nVisor: %d/%d = -(%d/%d)\n\n", num*(-1), den*(-1), num*(-1), den); //op.avançada (2)
            }else if(vNum < 0 && vDen < 0){
                printf("\nVisor: %d/%d\n\n", num*(-1), den*(-1));
            }else if(vNum > 0 && vDen > 0){
                printf("\nVisor: %d/%d = %d/%d\n\n", num*(-1), den*(-1), num, den); //op.avançada (2)
            }
            vNum = num;
            vDen = den;
}

void memoria(){ /*função para guardar na memória o número do visor.*/
                mNum = vNum;
                mDen = vDen;
                printf("\nNumero guardado na memoria!!\n\n");

}

void memoria_call(){ /*Coloca (recall) no visor o número guardado na memória*/
            if(mNum != 0 && mDen != 0){
                    mNum = vNum;
                    mDen = vDen;
                printf("\nVisor: %d/%d\n\n", mNum, mDen);
            }else{
                printf("\nMemoria vazia! Digite tecla m para guardar o numero na memoria\n\n");
            }
}

void memoria_limpar(){ /*Chamado duas vezes coloca a memória a zero (apaga a memória)*/
            mNum = 0;
            mDen = 0;
            printf("Chamou duas vezes a memoria! Memoria Apagada!!\n\n");
}

void memoria_add(){ /*Adiciona (add) à memória o número do visor*/
            mNum = vNum;
            mDen = vDen;
            printf("Numero adicionado na memoria!\n\n");
}

void memoria_troca(){ /*Troca (exchange) o número do visor com o da memória*/
            if(mNum != 0 && mDen != 0){
                    mNum = vNum;
                    mDen = vDen;
                printf("\nNumero do visor trocado com o da memoria = %d/%d\n\n", mNum, mDen);
            }else{
                printf("\nNao existe qualquer numero guardado na memoria\n\n");
}
}

/*funções para o treino*/

void somartreino(){
    /*dois numeros fraccionarios gerados aleatoriamente de 0 até 10*/
    num1 = (rand() % 10);
    den1 = (rand() % 10);
    num2 = (rand() % 10);
    den2 = (rand() % 10);

               printf("\n(%d/%d + %d/%d) \n", num1, den1, num2, den2);

            if((den1 != 0) && (den2 != 0) && (den1 != den2)){ /*caso os denominadores serem diferentes*/
                oper1 = den1 * den2;
                oper2 = ((oper1/den1) * num1);
                oper3 = ((oper1/den2) * num2);
                resultado1 = (oper2 + oper3);

/*opção avançada (3)*/
divisor = MDC(resultado1, oper1);

    if (divisor != 1){
            resultado2 = resultado1 / divisor;
            oper2 = oper1 / divisor;
 }
    printf("\nResposta: ");
    scanf("%d/%d", &num, &den);

    /*Condição para verificar se a resposta do utilizador está correcta e se corresponde aos resultados obtidos*/

    /*opcao avançada*/
    if(num == resultado1 && den == oper1){
        printf("\n");
        printf("CERTO!! Mas tem que indicar em fraccao irredutivel!!\n");
        printf("Coloque o resultado como fraccao irredutivel!!Tente mais uma vez\n");
        printf("\nResposta: ");
        scanf("%d/%d", &num, &den);
        if(num == resultado2 && den == oper2){
            printf("\n");
            printf("CERTO!!\n");
            }else{
            printf("\n");
            printf("ERRADO!! Tem mais 2 tentativas\n");
            printf("\nResposta: ");
            scanf("%d/%d", &num, &den);
            if(num == resultado1 && den == oper1){
                printf("\n");
                printf("CERTO!! Mas tem que indicar em fraccao irredutivel!!\n");
                printf("Coloque o resultado como fraccao irredutivel!!Tente mais uma vez\n");
                printf("\nResposta: ");
                scanf("%d/%d", &num, &den);
                if(num == resultado2 && den == oper2){
                    printf("\n");
                    printf("CERTO!!\n");
                }else{
                    printf("\n");
                    printf("ERRADO!! Tem mais 1 tentativas\n");
                    printf("\nResposta: ");
                    scanf("%d/%d", &num, &den);
                    if(num == resultado1 && den == oper1){
                            printf("\n");
                            printf("CERTO!! Mas tem que indicar em fraccao irredutivel!!\n");
                            printf("Coloque o resultado como fraccao irredutivel!!Tente mais uma vez\n");
                            printf("\nResposta: ");
                            scanf("%d/%d", &num, &den);
                            if(num == resultado2 && den == oper2){
                                printf("\n");
                                printf("CERTO!!\n");
                            }else{
                                 printf("\n");
                                printf("ERRADO!!\n");
                            }
                }
                }
            }
            }
            }else if(num == resultado2 && den == oper2){
            printf("\n");
            printf("CERTO!!\n");
            }else{
                printf("\n");
                printf("ERRADO!! Tem mais 2 tentativas\n");
                printf("\nResposta: ");
                scanf("%d/%d", &num, &den);
                if(num == resultado1 && den == oper1){
                printf("\n");
                printf("CERTO!! Mas tem que indicar em fraccao irredutivel!!\n");
                printf("Coloque o resultado como fraccao irredutivel!!Tente mais uma vez\n");
                printf("\nResposta: ");
                scanf("%d/%d", &num, &den);
                if(num == resultado2 && den == oper2){
                    printf("\n");
                    printf("CERTO!!\n");
                    }else{
                    printf("\n");
                    printf("ERRADO!!\n");
                    }
            }else{
            printf("\n");
            printf("ERRADO!! Tem mais 1 tentativa\n");
            printf("\nResposta: ");
            scanf("%d/%d", &num, &den);
            if(num == resultado1 && den == oper1){
                printf("\n");
                printf("CERTO!! Mas tem que indicar em fraccao irredutivel!!\n");
                printf("Coloque o resultado como fraccao irredutivel!!Tente mais uma vez\n");
                printf("\nResposta: ");
                scanf("%d/%d", &num, &den);
                if(num == resultado2 && den == oper2){
                    printf("\n");
                    printf("CERTO!!\n");
                    }else{
                        printf("\n");
                        printf("ERRADO!!\n");
                    }
    }else{
            /*Após 3 tentativas, o programa dá uma ajuda ao utilizador*/
            printf("\n");
            printf("ERRADO!!\n");
            printf("Ajuda: Deve efectuar o MMC (minimo multiplo comum)!!\n\n");
            printf("\nResposta: ");
            scanf("%d/%d", &num, &den);
            if(num == resultado1 && den == oper1){
                printf("\n");
                printf("CERTO!! Mas tem que indicar em fraccao irredutivel!!\n");
                printf("Coloque o resultado como fraccao irredutivel!!Tente mais uma vez\n");
                printf("\nResposta: ");
                scanf("%d/%d", &num, &den);
                if(num == resultado2 && den == oper2){
                    printf("\n");
                    printf("CERTO!!\n");
                    }
                    else{
                        printf("\n");
                        printf("ERRADO!!\n");
                    }
    }else{
            printf("\n");
            printf("ERRADO!!\n");
    }
    }
    }
    }
}else if((den1 != 0) && (den2 != 0) && (den1 == den2)){
            resultado3 = (num1 + num2);


               printf("\n(%d/%d + %d/%d) \n", num1, den1, num2, den2);

/*opção avançada (3)*/
divisor = MDC(resultado3, den1);

    if (divisor != 1){
            resultado4 = resultado3 / divisor;
            resultado5 = den1 / divisor;
 }
    printf("\nResposta: ");
    scanf("%d/%d", &num, &den);

    /*opcao avançada*/
    if(num == resultado3 && den == den1){
        printf("\n");
        printf("CERTO!! Mas tem que indicar em fraccao irredutivel!!\n");
        printf("Coloque o resultado como fraccao irredutivel!!Tente mais uma vez\n");
        printf("\nResposta: ");
        scanf("%d/%d", &num, &den);
        if(num == resultado4 && den == resultado5){
            printf("\n");
            printf("CERTO!!\n");
            }
    }else{
            printf("\n");
            printf("ERRADO!! Tem mais 2 tentativas\n");
            printf("\nResposta: ");
            scanf("%d/%d", &num, &den);
            if(num == resultado3 && den == den1){
                printf("\n");
                printf("CERTO!! Mas tem que indicar em fraccao irredutivel!!\n");
                printf("Coloque o resultado como fraccao irredutivel!!Tente mais uma vez\n");
                printf("\nResposta: ");
                scanf("%d/%d", &num, &den);
            if(num == resultado4 && den == resultado5){
                    printf("\n");
                    printf("CERTO!!\n");
                    }
    }else{
            printf("\n");
            printf("ERRADO!! Tem mais 1 tentativa\n");
            printf("\nResposta: ");
            scanf("%d/%d", &num, &den);
            if(num == resultado3 && den == den1){
                printf("\n");
                printf("CERTO!! Mas tem que indicar em fraccao irredutivel!!\n");
                printf("Coloque o resultado como fraccao irredutivel!!Tente mais uma vez\n");
                printf("\nResposta: ");
                scanf("%d/%d", &num, &den);
            if(num == resultado4 && den == resultado5){
                    printf("\n");
                    printf("CERTO!!\n");
                    }
    }else{
            /*Após 3 tentativas, o programa dá uma ajuda ao utilizador*/
            printf("\n");
            printf("ERRADO!!\n");
            printf("Ajuda: Deve efectuar o MMC (minimo multiplo comum)!!\n\n");
            printf("\nResposta: ");
            scanf("%d/%d", &num, &den);
            if(num == resultado3 && den == den1){
                printf("\n");
                printf("CERTO!! Mas tem que indicar em fraccao irredutivel!!\n");
                printf("Coloque o resultado como fraccao irredutivel!!Tente mais uma vez\n");
                printf("\nResposta: ");
                scanf("%d/%d", &num, &den);
            if(num == resultado4 && den == resultado5){
                    printf("\n");
                    printf("CERTO!!\n");
                    }
    }else{
            printf("\n");
            printf("ERRADO!!\n");

}
    }
    }
    }
}else if(den1 == 0 || den2 == 0){ /*opção avançada (1)*/
            den1 = 0;
            den2 = 0;

            printf("\nResposta: ");
            scanf("%d/%d", &num, &den);

            if(num == den1 && den == den2){
                printf("\n");
                printf("CERTO!!");
            }else{
                printf("\n");
                printf("ERRADO!! Tem mais 2 tentativas\n");
                printf("\nResposta: ");
                scanf("%d/%d", &num, &den);
                if(num == den1 && den == den2){
                printf("\n");
                printf("CERTO!!");
            }else{
                printf("\n");
                printf("ERRADO!! Tem mais 1 tentativa\n");
                printf("\nResposta: ");
                scanf("%d/%d", &num, &den);
                if(num == den1 && den == den2){
                printf("\n");
                printf("CERTO!!");
            }else{
                /*Após 3 tentativas, o programa dá uma ajuda ao utilizador*/
                printf("\n");
                printf("ERRADO!!\n");
                printf("Ajuda: Verifique os denominadores!! Nao pode efectuar qualquer operacao \ncom os denominadores a zeros!!\n\n");
                printf("\nResposta: ");
                scanf("%d/%d", &num, &den);
                if(num == den1 && den == den2){
                printf("\n");
                printf("CERTO!!");
            }else{
                printf("\n");
                printf("ERRADO!!\n");
    }

}
}
}
}
}

void subtrairtreino(){
    num1 = (rand() % 10);
    den1 = (rand() % 10);
    num2 = (rand() % 10);
    den2 = (rand() % 10);


               printf("\n(%d/%d - %d/%d) \n", num1, den1, num2, den2);

            if((den1 != 0) && (den2 != 0) && (den1 != den2)){
                oper1 = den1 * den2;
                resultado1 = (den2 * num1)-(den2 * num2);

/*opção avançada (3)*/
divisor = MDC(resultado1, oper1);

    if (divisor != 1){
            resultado2 = resultado1 / divisor;
            oper2 = oper1 / divisor;
 }

    printf("\nResposta: ");
    scanf("%d/%d", &num, &den);

    /*opcao avançada*/
    if(num == resultado1 && den == oper1){
        printf("\n");
        printf("CERTO!! Mas tem que indicar em fraccao irredutivel!!\n");
        printf("Coloque o resultado como fraccao irredutivel!!Tente mais uma vez\n");
        printf("\nResposta: ");
        scanf("%d/%d", &num, &den);
        if(num == resultado2 && den == oper2){
            printf("\n");
            printf("CERTO!!\n");
            }else{
            printf("\n");
            printf("ERRADO!! Tem mais 2 tentativas\n");
            printf("\nResposta: ");
            scanf("%d/%d", &num, &den);
            if(num == resultado1 && den == oper1){
                printf("\n");
                printf("CERTO!! Mas tem que indicar em fraccao irredutivel!!\n");
                printf("Coloque o resultado como fraccao irredutivel!!Tente mais uma vez\n");
                printf("\nResposta: ");
                scanf("%d/%d", &num, &den);
                if(num == resultado2 && den == oper2){
                    printf("\n");
                    printf("CERTO!!\n");
                }else{
                    printf("\n");
                    printf("ERRADO!! Tem mais 1 tentativas\n");
                    printf("\nResposta: ");
                    scanf("%d/%d", &num, &den);
                    if(num == resultado1 && den == oper1){
                            printf("\n");
                            printf("CERTO!! Mas tem que indicar em fraccao irredutivel!!\n");
                            printf("Coloque o resultado como fraccao irredutivel!!Tente mais uma vez\n");
                            printf("\nResposta: ");
                            scanf("%d/%d", &num, &den);
                            if(num == resultado2 && den == oper2){
                                printf("\n");
                                printf("CERTO!!\n");
                            }else{
                                 printf("\n");
                                printf("ERRADO!!\n");
                            }
                }
                }
            }
            }
            }else if(num == resultado2 && den == oper2){
            printf("\n");
            printf("CERTO!!\n");
            }else{
                printf("\n");
                printf("ERRADO!! Tem mais 2 tentativas\n");
                printf("\nResposta: ");
                scanf("%d/%d", &num, &den);
                if(num == resultado1 && den == oper1){
                printf("\n");
                printf("CERTO!! Mas tem que indicar em fraccao irredutivel!!\n");
                printf("Coloque o resultado como fraccao irredutivel!!Tente mais uma vez\n");
                printf("\nResposta: ");
                scanf("%d/%d", &num, &den);
                if(num == resultado2 && den == oper2){
                    printf("\n");
                    printf("CERTO!!\n");
                    }else{
                    printf("\n");
                    printf("ERRADO!!\n");
                    }
            }else{
            printf("\n");
            printf("ERRADO!! Tem mais 1 tentativa\n");
            printf("\nResposta: ");
            scanf("%d/%d", &num, &den);
            if(num == resultado1 && den == oper1){
                printf("\n");
                printf("CERTO!! Mas tem que indicar em fraccao irredutivel!!\n");
                printf("Coloque o resultado como fraccao irredutivel!!Tente mais uma vez\n");
                printf("\nResposta: ");
                scanf("%d/%d", &num, &den);
                if(num == resultado2 && den == oper2){
                    printf("\n");
                    printf("CERTO!!\n");
                    }else{
                        printf("\n");
                        printf("ERRADO!!\n");
                    }
    }else{
            /*Após 3 tentativas, o programa dá uma ajuda ao utilizador*/
            printf("\n");
            printf("ERRADO!!\n");
            printf("Ajuda: Deve efectuar o MMC (minimo multiplo comum)!!\n\n");
            printf("\nResposta: ");
            scanf("%d/%d", &num, &den);
            if(num == resultado1 && den == oper1){
                printf("\n");
                printf("CERTO!! Mas tem que indicar em fraccao irredutivel!!\n");
                printf("Coloque o resultado como fraccao irredutivel!!Tente mais uma vez\n");
                printf("\nResposta: ");
                scanf("%d/%d", &num, &den);
                if(num == resultado2 && den == oper2){
                    printf("\n");
                    printf("CERTO!!\n");
                    }else{
                        printf("\n");
                        printf("ERRADO!!\n");
                    }
    }else{
            printf("\n");
            printf("ERRADO!!\n");
    }
    }
    }
    }
}else if((den1 != 0) && (den2 != 0) && (den1 == den2)){
            resultado3 = (num1 + num2);

               printf("\n(%d/%d - %d/%d) \n", num1, den1, num2, den2);

/*opção avançada (3)*/
divisor = MDC(resultado3, den1);

    if (divisor != 1){
            resultado4 = resultado3 / divisor;
            resultado5 = den1 / divisor;
 }
    printf("\nResposta: ");
    scanf("%d/%d", &num, &den);

    /*opcao avançada*/
    if(num == resultado3 && den == den1){
        printf("\n");
        printf("CERTO!! Mas tem que indicar em fraccao irredutivel!!\n");
        printf("Coloque o resultado como fraccao irredutivel!!Tente mais uma vez\n");
        printf("\nResposta: ");
        scanf("%d/%d", &num, &den);
        if(num == resultado4 && den == resultado5){
            printf("\n");
            printf("CERTO!!\n");
            }
    }else{
            printf("\n");
            printf("ERRADO!! Tem mais 2 tentativas\n");
            printf("\nResposta: ");
            scanf("%d/%d", &num, &den);
            if(num == resultado3 && den == den1){
                printf("\n");
                printf("CERTO!! Mas tem que indicar em fraccao irredutivel!!\n");
                printf("Coloque o resultado como fraccao irredutivel!!Tente mais uma vez\n");
                printf("\nResposta: ");
                scanf("%d/%d", &num, &den);
            if(num == resultado4 && den == resultado5){
                    printf("\n");
                    printf("CERTO!!\n");
                    }
    }else{
            printf("\n");
            printf("ERRADO!! Tem mais 1 tentativa\n");
            printf("\nResposta: ");
            scanf("%d/%d", &num, &den);
            if(num == resultado3 && den == den1){
                printf("\n");
                printf("CERTO!! Mas tem que indicar em fraccao irredutivel!!\n");
                printf("Coloque o resultado como fraccao irredutivel!!Tente mais uma vez\n");
                printf("\nResposta: ");
                scanf("%d/%d", &num, &den);
            if(num == resultado4 && den == resultado5){
                    printf("\n");
                    printf("CERTO!!\n");
                    }
    }else{
            /*Após 3 tentativas, o programa dá uma ajuda ao utilizador*/
            printf("\n");
            printf("ERRADO!!\n");
            printf("Ajuda: Deve efectuar o MMC (minimo multiplo comum)!!\n\n");
            printf("\nResposta: ");
            scanf("%d/%d", &num, &den);
            if(num == resultado3 && den == den1){
                printf("\n");
                printf("CERTO!! Mas tem que indicar em fraccao irredutivel!!\n");
                printf("Coloque o resultado como fraccao irredutivel!!Tente mais uma vez\n");
                printf("\nResposta: ");
                scanf("%d/%d", &num, &den);
            if(num == resultado4 && den == resultado5){
                    printf("\n");
                    printf("CERTO!!\n");
                    }
    }else{
            printf("\n");
            printf("ERRADO!!\n");

}
    }
    }
    }
}else if(den1 == 0 || den2 == 0){ /*opção avançada (1)*/
            den1 = 0;
            den2 = 0;

            printf("\nResposta: ");
            scanf("%d/%d", &num, &den);

            if(num == den1 && den == den2){
                printf("\n");
                printf("CERTO!!");
            }else{
                printf("\n");
                printf("ERRADO!! Tem mais 2 tentativas\n");
                printf("\nResposta: ");
                scanf("%d/%d", &num, &den);
                if(num == den1 && den == den2){
                printf("\n");
                printf("CERTO!!");
            }else{
                printf("\n");
                printf("ERRADO!! Tem mais 1 tentativa\n");
                printf("\nResposta: ");
                scanf("%d/%d", &num, &den);
                if(num == den1 && den == den2){
                printf("\n");
                printf("CERTO!!");
            }else{
                /*Após 3 tentativas, o programa dá uma ajuda ao utilizador*/
                printf("\n");
                printf("ERRADO!!\n");
                printf("Ajuda: Verifique os denominadores!! Nao pode efectuar qualquer operacao \ncom os denominadores a zeros!!\n\n");
                printf("\nResposta: ");
                scanf("%d/%d", &num, &den);
                if(num == den1 && den == den2){
                printf("\n");
                printf("CERTO!!");
            }else{
                printf("\n");
                printf("ERRADO!!\n");
    }

}
}
}
}
}

void multiplicartreino(){
    num1 = (rand() % 10);
    den1 = (rand() % 10);
    num2 = (rand() % 10);
    den2 = (rand() % 10);


               printf("\n(%d/%d * %d/%d) \n", num1, den1, num2, den2);


            resultado1= num1 * num2;
            resultado2= den1 * den2;

/*opção avançada (3)*/
divisor = MDC(resultado1, resultado2);

    if (divisor != 1){
            resultado3 = resultado1 / divisor;
            resultado4 = resultado2 / divisor;
 }
    printf("\nResposta: ");
    scanf("%d/%d", &num, &den);

    if(den1 == 0 || den2 == 0){ /*opção avançada (1)*/
            den1 = 0;
            den2 = 0;

            printf("\nResposta: ");
            scanf("%d/%d", &num, &den);

            if(num == den1 && den == den2){
                printf("\n");
                printf("CERTO!!");
            }else{
                printf("\n");
                printf("ERRADO!! Tem mais 2 tentativas\n");
                printf("\nResposta: ");
                scanf("%d/%d", &num, &den);
                if(num == den1 && den == den2){
                printf("\n");
                printf("CERTO!!");
            }else{
                printf("\n");
                printf("ERRADO!! Tem mais 1 tentativa\n");
                printf("\nResposta: ");
                scanf("%d/%d", &num, &den);
                if(num == den1 && den == den2){
                printf("\n");
                printf("CERTO!!");
            }else{
                /*Após 3 tentativas, o programa dá uma ajuda ao utilizador*/
                printf("\n");
                printf("ERRADO!!\n");
                printf("Ajuda: Verifique os denominadores!! Nao pode efectuar qualquer operacao \ncom os denominadores a zeros!!\n\n");
                printf("\nResposta: ");
                scanf("%d/%d", &num, &den);
                if(num == den1 && den == den2){
                printf("\n");
                printf("CERTO!!");
            }else{
                printf("\n");
                printf("ERRADO!!\n");
    }
}
}
            }
}else if(num == resultado1 && den == resultado2){ /*opcao avançada*/
        printf("\n");
        printf("CERTO!! Mas tem que indicar em fraccao irredutivel!!\n");
        printf("Coloque o resultado como fraccao irredutivel!!Tente mais uma vez\n");
        printf("\nResposta: ");
        scanf("%d/%d", &num, &den);
        if(num == resultado3 && den == resultado4){
            printf("\n");
            printf("CERTO!!\n");
            }else{
            printf("\n");
            printf("ERRADO!! Tem mais 2 tentativas\n");
            printf("\nResposta: ");
            scanf("%d/%d", &num, &den);
            if(num == resultado1 && den == resultado2){
                printf("\n");
                printf("CERTO!! Mas tem que indicar em fraccao irredutivel!!\n");
                printf("Coloque o resultado como fraccao irredutivel!!Tente mais uma vez\n");
                printf("\nResposta: ");
                scanf("%d/%d", &num, &den);
                if(num == resultado3 && den == resultado4){
                printf("\n");
                printf("CERTO!!\n");
            }else{
                printf("\n");
                printf("ERRADO!! Tem mais 1 tentativa\n");
                printf("\nResposta: ");
                scanf("%d/%d", &num, &den);
                if(num == resultado1 && den == resultado2){
                printf("\n");
                printf("CERTO!! Mas tem que indicar em fraccao irredutivel!!\n");
                printf("Coloque o resultado como fraccao irredutivel!!Tente mais uma vez\n");
                printf("\nResposta: ");
                scanf("%d/%d", &num, &den);
                if(num == resultado3 && den == resultado4){
                printf("\n");
                printf("CERTO!!\n");
            }else{
                printf("\n");
            printf("ERRADO!!\n");
            printf("Ajuda: Multiplique numerador com numerador e denominador com denominador!!\n\n");
            printf("\nResposta: ");
            scanf("%d/%d", &num, &den);
            }if(num == resultado1 && den == resultado2){
                printf("\n");
                printf("CERTO!! Mas tem que indicar em fraccao irredutivel!!\n");
                printf("Coloque o resultado como fraccao irredutivel!!Tente mais uma vez\n");
                printf("\nResposta: ");
                scanf("%d/%d", &num, &den);
                if(num == resultado3 && den == resultado4){
                    printf("\n");
                    printf("CERTO!!\n");
                    }
    }else{
            printf("\n");
            printf("ERRADO!!\n");
}

            }
    }
            }

            }
    }else if(num == resultado3 && den == resultado4){
            printf("\n");
            printf("CERTO!!\n");
    }else{
            printf("\n");
            printf("ERRADO!! Tem mais 2 tentativas\n");
            printf("\nResposta: ");
            scanf("%d/%d", &num, &den);
            if(num == resultado1 && den == resultado2){
                printf("\n");
                printf("CERTO!! Mas tem que indicar em fraccao irredutivel!!\n");
                printf("Coloque o resultado como fraccao irredutivel!!Tente mais uma vez\n");
                printf("\nResposta: ");
                scanf("%d/%d", &num, &den);
                if(num == resultado3 && den == resultado4){
                    printf("\n");
                    printf("CERTO!!\n");
                    }
    }else{
            printf("\n");
            printf("ERRADO!! Tem mais 1 tentativa\n");
            printf("\nResposta: ");
            scanf("%d/%d", &num, &den);
            if(num == resultado1 && den == resultado2){
                printf("\n");
                printf("CERTO!! Mas tem que indicar em fraccao irredutivel!!\n");
                printf("Coloque o resultado como fraccao irredutivel!!Tente mais uma vez\n");
                printf("\nResposta: ");
                scanf("%d/%d", &num, &den);
                if(num == resultado3 && den == resultado4){
                    printf("\n");
                    printf("CERTO!!\n");
                    }
    }else{
            /*Após 3 tentativas, o programa dá uma ajuda ao utilizador*/
            printf("\n");
            printf("ERRADO!!\n");
            printf("Ajuda: Multiplique numerador com numerador e denominador com denominador!!\n\n");
            printf("\nResposta: ");
            scanf("%d/%d", &num, &den);
            }if(num == resultado1 && den == resultado2){
                printf("\n");
                printf("CERTO!! Mas tem que indicar em fraccao irredutivel!!\n");
                printf("Coloque o resultado como fraccao irredutivel!!Tente mais uma vez\n");
                printf("\nResposta: ");
                scanf("%d/%d", &num, &den);
                if(num == resultado3 && den == resultado4){
                    printf("\n");
                    printf("CERTO!!\n");
                    }
    }else{
            printf("\n");
            printf("ERRADO!!\n");
}
    }
    }

}


void dividirtreino(){
    num1 = (rand() % 10);
    den1 = (rand() % 10);
    num2 = (rand() % 10);
    den2 = (rand() % 10);


               printf("\n(%d/%d / %d/%d) \n", num1, den1, num2, den2);

            aux= num1 * den2;
            aux1= den1 * num2;

/*opção avançada (3)*/
divisor = MDC(aux, aux1);

    if (divisor != 1){
            resultado1 = aux / divisor;
            resultado2 = aux1 / divisor;
 }

    printf("\nResposta: ");
    scanf("%d/%d", &num, &den);

    if(den1 == 0 || den2 == 0){ /*opção avançada (1)*/
            den1 = 0;
            den2 = 0;

            printf("\n%d/%d\n\n", den1, den2);

            printf("\nResposta: ");
            scanf("%d/%d", &num, &den);

            if(num == den1 && den == den2){
                printf("\n");
                printf("CERTO!!");
            }else{
                printf("\n");
                printf("ERRADO!! Tem mais 2 tentativas\n");
                printf("\nResposta: ");
                scanf("%d/%d", &num, &den);
                if(num == den1 && den == den2){
                printf("\n");
                printf("CERTO!!");
            }else{
                printf("\n");
                printf("ERRADO!! Tem mais 1 tentativa\n");
                printf("\nResposta: ");
                scanf("%d/%d", &num, &den);
                if(num == den1 && den == den2){
                printf("\n");
                printf("CERTO!!");
            }else{
                /*Após 3 tentativas, o programa dá uma ajuda ao utilizador*/
                printf("\n");
                printf("ERRADO!!\n");
                printf("Ajuda: Verifique os denominadores!! Nao pode efectuar qualquer operacao \ncom os denominadores a zeros!!\n\n");
                printf("\nResposta: ");
                scanf("%d/%d", &num, &den);
                if(num == den1 && den == den2){
                printf("\n");
                printf("CERTO!!");
            }else{
                printf("\n");
                printf("ERRADO!!\n");
    }

}
}
}
}if(num == aux && den == aux1){ /*opcao avançada*/
        printf("\n");
        printf("CERTO!! Mas tem que indicar em fraccao irredutivel!!\n");
        printf("Coloque o resultado como fraccao irredutivel!!Tente mais uma vez\n");
        printf("\nResposta: ");
        scanf("%d/%d", &num, &den);
        if(num == resultado1 && den == resultado2){
            printf("\n");
            printf("CERTO!!\n");
            }else{
            printf("\n");
            printf("ERRADO!! Tem mais 2 tentativas\n");
            printf("\nResposta: ");
            scanf("%d/%d", &num, &den);
            if(num == aux && den == aux1){
                printf("\n");
                printf("CERTO!! Mas tem que indicar em fraccao irredutivel!!\n");
                printf("Coloque o resultado como fraccao irredutivel!!Tente mais uma vez\n");
                printf("\nResposta: ");
                scanf("%d/%d", &num, &den);
                if(num == resultado1 && den == resultado2){
                printf("\n");
                printf("CERTO!!\n");
            }else{
                printf("\n");
                printf("ERRADO!! Tem mais 1 tentativa\n");
                printf("\nResposta: ");
                scanf("%d/%d", &num, &den);
                if(num == aux && den == aux1){
                printf("\n");
                printf("CERTO!! Mas tem que indicar em fraccao irredutivel!!\n");
                printf("Coloque o resultado como fraccao irredutivel!!Tente mais uma vez\n");
                printf("\nResposta: ");
                scanf("%d/%d", &num, &den);
                if(num == resultado1 && den == resultado2){
                printf("\n");
                printf("CERTO!!\n");
            }else{
                printf("\n");
            printf("ERRADO!!\n");
            printf("Ajuda: Multiplique numerador com numerador e denominador com denominador!!\n\n");
            printf("\nResposta: ");
            scanf("%d/%d", &num, &den);
            }if(num == aux && den == aux1){
                printf("\n");
                printf("CERTO!! Mas tem que indicar em fraccao irredutivel!!\n");
                printf("Coloque o resultado como fraccao irredutivel!!Tente mais uma vez\n");
                printf("\nResposta: ");
                scanf("%d/%d", &num, &den);
                if(num == resultado1 && den == resultado2){
                    printf("\n");
                    printf("CERTO!!\n");
                    }
    }else{
            printf("\n");
            printf("ERRADO!!\n");
}

            }
    }
            }

            }
    }else if(num == resultado1 && den == resultado2){
            printf("\n");
            printf("ERRADO!! Tem mais 2 tentativas\n");
            printf("\nResposta: ");
            scanf("%d/%d", &num, &den);
            if(num == aux && den == aux1){
                printf("\n");
                printf("CERTO!! Mas tem que indicar em fraccao irredutivel!!\n");
                printf("Coloque o resultado como fraccao irredutivel!!Tente mais uma vez\n");
                printf("\nResposta: ");
                scanf("%d/%d", &num, &den);
                if(num == resultado1 && den == resultado2){
                    printf("\n");
                    printf("CERTO!!\n");
                    }
    }else{
            printf("\n");
            printf("ERRADO!! Tem mais 1 tentativa\n");
            printf("\nResposta: ");
            scanf("%d/%d", &num, &den);
            if(num == aux && den == aux1){
                printf("\n");
                printf("CERTO!! Mas tem que indicar em fraccao irredutivel!!\n");
                printf("Coloque o resultado como fraccao irredutivel!!Tente mais uma vez\n");
                printf("\nResposta: ");
                scanf("%d/%d", &num, &den);
                if(num == resultado1 && den == resultado2){
                    printf("\n");
                    printf("CERTO!!\n");
                    }
    }else{
            /*Após 3 tentativas, o programa dá uma ajuda ao utilizador*/
            printf("\n");
            printf("ERRADO!!\n");
            printf("Ajuda: Multiplique numerador com numerador e denominador com denominador!!\n\n");
            printf("\nResposta: ");
            scanf("%d/%d", &num, &den);
            }if(num == aux && den == aux1){
                printf("\n");
                printf("CERTO!! Mas tem que indicar em fraccao irredutivel!!\n");
                printf("Coloque o resultado como fraccao irredutivel!!Tente mais uma vez\n");
                printf("\nResposta: ");
                scanf("%d/%d", &num, &den);
                if(num == resultado1 && den == resultado2){
                    printf("\n");
                    printf("CERTO!!\n");
                    }
    }else{
            printf("\n");
            printf("ERRADO!!\n");
}
    }
    }

}

void calculadora(){ /*função para a calculadora de numeros fracionarios*/
        char flag_r = 0; /*criei esta flag_r para gerir o caso das funções memoria_limpar() e memoria_call()*/
        comandos();
        vNum = 0;
        vDen = 1;
        printf("Visor: %d\n\n", vNum); /*numero do visor inicializado a 0*/

        do{
                /*Pede a operação que o utilizador quer*/
                printf("Operacao: ");
                scanf(" %c", &opcao);

                switch(opcao){ /*usei comandos tanto para letras maiusculas como minusculas */
                case '+':
                        printf("Numerador/Denominador: ");
                        scanf("%d/%d", &num, &den);
                        soma(); flag_r = 0;
                        break;
                case '-':
                        printf("Numerador/Denominador: ");
                        scanf("%d/%d", &num, &den);
                        subtrair(); flag_r = 0;
                        break;
                case '*':
                        printf("Numerador/Denominador: ");
                        scanf("%d/%d", &num, &den);
                        multiplicar(); flag_r = 0;
                        break;
                case '/':
                        printf("Numerador/Denominador: ");
                        scanf("%d/%d", &num, &den);
                        dividir(); flag_r = 0;
                        break;
                case 'C': case 'c': limpar(); flag_r = 0; break;
                case 'I': case 'i': inverso(); flag_r = 0; break;
                case 'S': case 's': simetrico(); flag_r = 0; break;
                case 'M': case 'm': memoria(); flag_r = 0; break;
                case 'R': case 'r':
                        if( flag_r == 1) { memoria_limpar(); flag_r = 0; }
                                else { memoria_call(); flag_r = 1; }
                        break;
                case 'A': case 'a': memoria_add(); flag_r = 0; break;
                case 'X': case 'x': memoria_troca(); flag_r = 0; break;
                default:
                        printf("Opcao Invalida\n\n"); flag_r = 0;
                }
        }while(opcao != 'q' && opcao != 'Q'); /*para sair da calculadora é a tecla q */
}

void treino(){ /*função para mostrar todo o treino*/
    printf("\n");
    printf("TREINO COMPOSTO POR 20 PERGUNTAS\n");
    printf("---------------------------------------\n");

    for (i=1; i<20; i++){ /*ciclo para 20 perguntas*/

        printf("\nPergunta Nr.%i\n\n", i);

        srand(time(NULL));

        opcaoteste = 1 + rand() % 4;  /*gera um numero aleatorio para as questões serem sobre as várias operações de 1 a 4*/

        switch (opcaoteste) {   /*ciclo switch para escolher a operação a fazer de acordo com o numero aleatório*/
            case 1: somartreino();
                break;
            case 2: subtrairtreino();
                break;
            case 3: multiplicartreino();
                break;
            case 4: dividirtreino();
                break;
        }
    }
}

void teste(){ /*função para mostrar todo o teste de conhecimentos*/
    printf("\n");
    printf("TESTE\n");
    printf("---------------------------------------\n");
    printf("\nQuantas perguntas deseja no teste: ");
    scanf("%d", &num_perguntas); /*numero de perguntas que o utilizador quer no teste*/
    printf("\nQuantas vezes pode errar uma pergunta: ");
    scanf("%d", &tentativas);
    printf("\nNumero maximo de respostas erradas: ");
    scanf("%d", &num_max_erradas);


    for (i=0; i<num_perguntas; i++){ /*ciclo até ao numero de perguntas pretendidas*/

        if(tentativas == 0){ /*se ultrapassar o numero de respostas erradas, o programa pára o ciclo de perguntas*/
            printf("\n");
            printf("ERRADO!!\n");
            sucesso_respostas();
            system("cls");
    return menu();
        }
        printf("---------------------------------------\n");
        printf("\nPergunta Nr.%i\n\n", i);

        srand(time(NULL));

        opcaoteste = 1 + rand() % 4; /*gera um numero aleatorio para as questões serem sobre as várias operações de 1 a 4*/

        switch (opcaoteste) {      /*ciclo switch para escolher a operação a fazer de acordo com o numero aleatório*/
            case 1: /*caso para somar*/
    num1 = rand() % 10;
    den1 = rand() % 10;
    num2 = rand() % 10;
    den2 = rand() % 10;


            printf("\n(%d/%d + %d/%d) \n", num1, den1, num2, den2);

            if((den1 != 0) && (den2 != 0) && (den1 != den2)){
                oper1 = den1 * den2;
                oper2 = ((oper1/den1) * num1);
                oper3 = ((oper1/den2) * num2);
                resultado1 = (oper2 + oper3);

/*opção avançada (3)*/
divisor = MDC(resultado1, oper1);

    if (divisor != 1){
            resultado2 = resultado1 / divisor;
            oper2 = oper1 / divisor;
 }

    printf("\nResposta: ");
    scanf("%d/%d", &num, &den);

    if((num == resultado1 && den == oper1) || (num == resultado2 && den == oper2)){
            printf("\n");
            printf("CERTO!!\n");
            certas++;
        }else{
            do{
            printf("\n");
            printf("ERRADO!!\n");
            num_max_erradas--;
            if (num_max_erradas == 0)
                erradas++;
                printf("\nResposta: ");
                scanf("%d/%d", &num, &den);
    }while(((num != resultado1) && (den != oper1) && (num != resultado2) && (den != oper2)) && (num_max_erradas!=0));
    tentativas--;
    if(tentativas == 0){ /*se ultrapassar o numero de respostas erradas, o programa pára o ciclo de perguntas*/
            printf("\n");
            printf("ERRADO!!\n");
            sucesso_respostas();
            system("cls");
    return menu();
        }
    }
}else if((den1 != 0) && (den2 != 0) && (den1 == den2)){
            resultado3 = (num1 + num2);

             printf("\n(%d/%d + %d/%d) \n", num1, den1, num2, den2);

/*opção avançada (3)*/
divisor = MDC(resultado3, den1);

    if (divisor != 1){
            resultado4 = resultado3 / divisor;
            resultado5 = den1 / divisor;
 }
    printf("\nResposta: ");
    scanf("%d/%d", &num, &den);

    if((num == resultado3 && den == den1) || (num == resultado4 && den == resultado5)){
            printf("\n");
            printf("CERTO!!\n");
            certas++;
        } else {
            do{
            printf("\n");
            printf("ERRADO!!\n");
            num_max_erradas--;
            if (num_max_erradas == 0)
                erradas++;
            printf("\nResposta: ");
            scanf("%d/%d", &num, &den);
        }while(((num != resultado3) && (den != den1) && (num != resultado4) && (den != resultado5)) && (num_max_erradas!=0));
        tentativas--;
         if(tentativas == 0){ /*se ultrapassar o numero de respostas erradas, o programa pára o ciclo de perguntas*/
            printf("\n");
            printf("ERRADO!!\n");
            sucesso_respostas();
            system("cls");
    return menu();
        }
        }
}else if(den1 == 0 || den2 == 0){ /*opção avançada (1)*/
            den1 = 0;
            den2 = 0;

            printf("\nResposta: ");
            scanf("%d/%d", &num, &den);

            if(num == den1 && den == den2){
                printf("\n");
            printf("CERTO!!\n");
            certas++;
        } else {
            do{
            printf("\n");
            printf("ERRADO!!\n");
            num_max_erradas--;
            if (num_max_erradas == 0)
                erradas++;
            printf("\nResposta: ");
            scanf("%d/%d", &num, &den);
}while(((num != den1) && (den != den2)) && (num_max_erradas != 0));
tentativas--;
 if(tentativas == 0){ /*se ultrapassar o numero de respostas erradas, o programa pára o ciclo de perguntas*/
            printf("\n");
            printf("ERRADO!!\n");
            sucesso_respostas();
            system("cls");
    return menu();
        }
}
}
                break;
            case 2: /*caso para subtrair*/
    num1 = rand() % 10;
    den1 = rand() % 10;
    num2 = rand() % 10;
    den2 = rand() % 10;

            printf("\n(%d/%d - %d/%d) \n", num1, den1, num2, den2);

            if((den1 != 0) && (den2 != 0) && (den1 != den2)){
                oper1 = den1 * den2;
                resultado1 = (den2 * num1)-(den2 * num2);

/*opção avançada (3)*/
divisor = MDC(resultado1, oper1);

    if (divisor != 1){
            resultado2 = resultado1 / divisor;
            oper2 = oper1 / divisor;
 }
    printf("\nResposta: ");
    scanf("%d/%d", &num, &den);

    if((num == resultado1 && den == oper1) || (num == resultado2 && den == oper2)){
            printf("\n");
            printf("CERTO!!\n");
            certas++;
        } else {
            do{
            printf("\n");
            printf("ERRADO!!\n");
            num_max_erradas--;
            if (num_max_erradas == 0)
                erradas++;
            printf("\nResposta: ");
            scanf("%d/%d", &num, &den);
        }while(((num != resultado1) && (den != oper1) && (num != resultado2) && (den != oper2)) && (num_max_erradas != 0));
        tentativas--;
         if(tentativas == 0){ /*se ultrapassar o numero de respostas erradas, o programa pára o ciclo de perguntas*/
            printf("\n");
            printf("ERRADO!!\n");
            sucesso_respostas();
            system("cls");
    return menu();
        }
        }
}else if((den1 != 0) && (den2 != 0) && (den1 == den2)){
            resultado3 = (num1 + num2);


               printf("\n(%d/%d - %d/%d) \n", num1, den1, num2, den2);

/*opção avançada (3)*/
divisor = MDC(resultado3, den1);

    if (divisor != 1){
            resultado4 = resultado3 / divisor;
            resultado5 = den1 / divisor;
 }

    printf("\nResposta: ");
    scanf("%d/%d", &num, &den);

    if((num == resultado3 && den == den1) || (num == resultado4 && den == resultado5)){
        printf("\n");
            printf("CERTO!!\n");
            certas++;
        } else {
            do{
            printf("\n");
            printf("ERRADO!!\n");
            num_max_erradas--;
            if (num_max_erradas == 0)
                erradas++;
            printf("\nResposta: ");
            scanf("%d/%d", &num, &den);
        }while(((num != resultado3) && (den != den1) && (num != resultado4) && (den != resultado5)) && (num_max_erradas != 0));
        tentativas--;
         if(tentativas == 0){ /*se ultrapassar o numero de respostas erradas, o programa pára o ciclo de perguntas*/
            printf("\n");
            printf("ERRADO!!\n");
            sucesso_respostas();
            system("cls");
    return menu();
        }
        }
}else if(den1 == 0 || den2 == 0){ /*opção avançada (1)*/
            den1 = 0;
            den2 = 0;

            printf("\nResposta: ");
            scanf("%d/%d", &num, &den);

            if(num == den1 && den == den2){
                printf("\n");
                printf("CERTO!!\n");
                certas++;
        } else {
            do{
                printf("\n");
                printf("ERRADO!!\n");
                num_max_erradas--;
            if (num_max_erradas == 0)
                erradas++;
                printf("\nResposta: ");
                scanf("%d/%d", &num, &den);
}while(((num != den1) && (den != den2)) && (num_max_erradas!=0));
        tentativas--;
         if(tentativas == 0){ /*se ultrapassar o numero de respostas erradas, o programa pára o ciclo de perguntas*/
            printf("\n");
            printf("ERRADO!!\n");
            sucesso_respostas();
            system("cls");
    return menu();
        }
        }
}
                break;
            case 3: /*caso para multiplicar*/
    num1 = rand() % 10;
    den1 = rand() % 10;
    num2 = rand() % 10;
    den2 = rand() % 10;

            printf("\n(%d/%d * %d/%d) \n", num1, den1, num2, den2);

            resultado1= num1 * num2;
            resultado2= den1 * den2;


/*opção avançada (3)*/
divisor = MDC(resultado1, resultado2);

    if (divisor != 1){
            resultado3 = resultado1 / divisor;
            resultado4 = resultado2 / divisor;
 }

    printf("\nResposta: ");
    scanf("%d/%d", &num, &den);

    if((num == resultado1 && den == resultado2) || (num == resultado3 && den == resultado4)){
            printf("\n");
            printf("CERTO!!\n");
            certas++;
        } else {
            do{
            printf("\n");
            printf("ERRADO!!\n");
           num_max_erradas--;
            if (num_max_erradas == 0)
                erradas++;
            printf("\nResposta: ");
            scanf("%d/%d", &num, &den);
        }while(((num != resultado1 && den != resultado2) && (num != resultado3 && den != resultado4)) && (num_max_erradas != 0));
         tentativas--;
          if(tentativas == 0){ /*se ultrapassar o numero de respostas erradas, o programa pára o ciclo de perguntas*/
            printf("\n");
            printf("ERRADO!!\n");
            sucesso_respostas();
            system("cls");
    return menu();
        }
        }
if(den1 == 0 || den2 == 0){ /*opção avançada (1)*/
            den1 = 0;
            den2 = 0;

            printf("\n%d/%d\n\n", den1, den2);
            printf("\nResposta: ");
            scanf("%d/%d", &num, &den);

            if(num == den1 && den == den2){
                printf("\n");
                printf("CERTO!!\n");
                certas++;
        } else {
            do{
                printf("\n");
                printf("ERRADO!!\n");
                num_max_erradas--;
            if (num_max_erradas == 0)
                erradas++;
                printf("\nResposta: ");
                scanf("%d/%d", &num, &den);
}while(((num != den1 && den != den2) && (tentativas!=0)) && (num_max_erradas != 0));
tentativas--;
 if(tentativas == 0){ /*se ultrapassar o numero de respostas erradas, o programa pára o ciclo de perguntas*/
            printf("\n");
            printf("ERRADO!!\n");
            sucesso_respostas();
            system("cls");
    return menu();
        }
}
}
                break;
            case 4: /*caso para dividir*/
    num1 = rand() % 10;
    den1 = rand() % 10;
    num2 = rand() % 10;
    den2 = rand() % 10;

            printf("\n(%d/%d + %d/%d) \n", num1, den1, num2, den2);

            aux= num1 * den2;
            aux1= den1 * num2;

/*opção avançada (3)*/
divisor = MDC(aux, aux1);

    if (divisor != 1){
            resultado1 = resultado1 / divisor;
            resultado2 = resultado2 / divisor;
 }
    printf("\nResposta: ");
    scanf("%d/%d", &num, &den);

    if((num == aux && den == aux1) || (num == resultado1 && den == resultado2)) {
            printf("\n");
            printf("CERTO!!\n");
            certas++;
        } else {
            do{
            printf("\n");
            printf("ERRADO!!\n");
            num_max_erradas--;
            if (num_max_erradas == 0)
                erradas++;
            printf("\nResposta: ");
            scanf("%d/%d", &num, &den);
            }while(((num != aux) && (den != aux1) && (num != resultado1) && (den != resultado2)) && (num_max_erradas != 0));
        tentativas--;
    if(tentativas == 0){ /*se ultrapassar o numero de respostas erradas, o programa pára o ciclo de perguntas*/
            printf("\n");
            printf("ERRADO!!\n");
            sucesso_respostas();
            system("cls");
    return menu();
        }
        }
if(den1 == 0 || den2 == 0){ /*opção avançada (1)*/
            den1 = 0;
            den2 = 0;

            printf("\n%d/%d\n\n", den1, den2);

            printf("\nResposta: ");
            scanf("%d/%d", &num, &den);

            if(num == den1 && den == den2){
                printf("\n");
                printf("CERTO!!\n");
                certas++;
        } else {
            do{
                printf("\n");
                printf("ERRADO!!\n");
                num_max_erradas--;
            if (num_max_erradas == 0)
                erradas++;
                printf("\nResposta: ");
                scanf("%d/%d", &num, &den);
}while((num != den1 && den != den2) && (num_max_erradas != 0));
        tentativas--;
    if(tentativas == 0){ /*se ultrapassar o numero de respostas erradas, o programa pára o ciclo de perguntas*/
            printf("\n");
            printf("ERRADO!!\n");
            sucesso_respostas();
            system("cls");
    return menu();
        }
        }
}
                break;

        }
    }

    sucesso_respostas();   /*mostra a função do sucesso das respostas*/

    certas = 0;
    erradas = 0;
}


void sucesso_respostas(){ /*função que calcula o sucesso das respostas em percentagem e numero absoluto*/
    perc_certas = (certas * 100) / num_perguntas;
    perc_erradas = 100 - perc_certas;

    printf("____________________________________\n");
    printf("Respostas certas: %d\n", certas);
    printf("Respostas erradas: %d\n", erradas);
    printf("Percentagem de respostas certas: %.1d%% \n", perc_certas);
    printf("Percentagem de respostas erradas: %.1d%% \n", perc_erradas);
    printf("____________________________________\n");
    system("pause");
}

void menu(){ /*função que mostra o menu principal do programa*/
printf("\n");
    printf(" __________________________________________ \n");
    printf("|                 COMANDOS                 |\n");
    printf("|------------------------------------------|\n");
    printf("|       OPERACAO                OPCAO      |\n");
    printf("|                                          |\n");
    printf("|   ->  CALCULADORA               1        |\n");
    printf("|   ->  TREINAR                   2        |\n");
    printf("|   ->  TESTE DE CONHECIMENTOS    3        |\n");
    printf("|   ->  SAIR DO PROGRAMA          4        |\n");
    printf("|__________________________________________|\n");
    printf("\n");
    printf("\nOpcao desejada: ");
}

int main()
{
  int opcao;

  do {
    system("cls");
    menu();
    scanf("%i", &opcao);
    switch (opcao) {
    case 1:
      system("cls");
      calculadora();
      break;
    case 2:
      system("cls");
      treino();
      break;
    case 3:
      system("cls");
      teste();
      break;
    }
  } while (opcao != 4);

  return 0;
}
