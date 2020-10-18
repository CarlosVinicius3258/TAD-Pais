#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pais.h"
#include "colecao.h"

#define TRUE 1
#define FALSE 0

Colecao* mundo = NULL;
Pais* pais = NULL;

void fundarPais();
void listarPaises();
void buscarPais();
void destruirPais();
void destruirMundo();
void sair();

int main(void){
  int op = 0;

  do{
      printf("\n\t\t\t-----------------*---------------\n");
      printf("\t\t\t---------- Colecao Pais ---------");
      printf("\n\t\t\t-----------------*---------------\n");
      printf("\t\t\t1. Fundar Pais\n");
      printf("\t\t\t2. Listar Paises\n");
      printf("\t\t\t3. Buscar Pais\n");
      printf("\t\t\t4. Destruir Pais\n");
      printf("\t\t\t5. Destruir Mundo\n");
      printf("\t\t\t6. Sair\n");
      printf("\t\t\tOpção: ");  
      scanf("%d", &op);

      switch(op){
        case 1:
          fundarPais();
          break;
        case 2:
          listarPaises();
          break; 
        case 3:
          buscarPais();
        break;
        case 4: 
          destruirPais();
        break;
        case 5:
        destruirMundo();
          break;
        case 6:
          sair();
          break;

        default:
          system("clear");
          printf("\n\t\t\t-----------------*---------------\n");
          printf("\t\t\t------------ OPCAO INVALIDA -------\n");
          printf("\n\t\t\t-----------------*---------------\n");
          break;

      }
    }while(op!=6);
 



  return 0;
}


//----------------OPCOES---------------\\




//1.Funda um pais dentro do mundo
void fundarPais(){
  
  if(mundo==NULL){
    int tamanho = 0;

    printf("\n\t\t\tCRIE SEU MUNDO!!\n\t\t\tQUANTIDADE DE PAISES: ");
    scanf("%d", &tamanho);

    //Criar mundo
    mundo = colCriar(tamanho);
     //Adicionar pais ao mundo
  } 

     char nome[30];
     int idade;
     float idh;
     printf("\t\t\t --- Informacoes de pais ---\n");
     printf("\t\t\tNome do pais: ");
     scanf("%s", nome);

     printf("\t\t\tIdade do pais: ");
     scanf("%d", &idade);

     printf("\t\t\tIDH do pais: ");
     scanf("%f", &idh);

     //Fundar pais
     pais = criarPais(nome,idade,idh);

     if(pais!=NULL){
       if(colInserir(mundo, pais)){
         printf("\n\t\t\tParabéns!! Pais fundado.\n");
       
       }else{
       printf("\n\t\t\tErro! Tente novamente.\n");
     }

   }else{
     printf("\n\t\t\tErro! Tente novamente.\n");
   } 
   
}

//2. Lista as informações dos paises no mundo
void listarPaises(){
  if(mundo!=NULL){
    pais = colPegarPrimeiro(mundo);
    while(pais!=NULL){
      printf("\n\t\t\t -- PAIS -- \n");
      printf("\t\t\t NOME:  %s\n", pegarNome(pais));
      printf("\t\t\t IDADE:  %d\n", pegarIdade(pais));
      printf("\t\t\t IDH: %f \n\n", pegarIdh(pais));
      pais = colPegarProximo(mundo);
    }
  }else{
    printf("\n\t\t\tPRIMEIRO FUNDE ALGUNS PAISES PARA SABER QUAIS EXISTEM. \n");
  }
  
}


//3.Busca paises fundados no mundo

void buscarPais(){
  if (mundo!=NULL){
    char nome[30];
    int idade;
    float idh;

     printf("\t\t\t --- INFORMACOES DO PAIS ---\n");
     printf("\t\t\tNOME DO PAIS: ");
     scanf("%s", nome);

     printf("\t\t\tIDADE DO PAIS: ");
     scanf("%d", &idade);

     printf("\t\t\tIDH DO PAIS: ");
     scanf("%f", &idh);

     pais = criarPais(nome,idade,idh);

     if(pais!=NULL){
       if(colBuscar(mundo, pais, cmpPais) != NULL){
         printf("\n\t\t\t PAIS RECONHECIDO!!\n");
       }else{
         printf("\t\t\t PAIS NAO ENCONTRADO. TENTE NOVAMENTE\n");
       }
     }else{
       printf("\t\t\t ERRO NA INSERCAO DE DADOS.\n\t\t\t TENTE NOVAMENTE\n");
     }
  }else{
    printf("\t\t\t PRIMEIRO FUNDE UM PAIS PARA PROCURAR POR UM.\n\t\t\t TENTE NOVAMENTE.\n");
  }
}

//4. Destruir pais

void destruirPais(){
  if (mundo!=NULL){
    char nome[30];
    int idade;
    float idh;
     printf("\t\t\t --- MODO DESTRUICAO ATIVADA ---\n");
     printf("\t\t\t --- INFORMACOES DO PAIS ---\n");
     printf("\t\t\tNOME DO PAIS: ");
     scanf("%s", nome);

     printf("\t\t\tIDADE DO PAIS: ");
     scanf("%d", &idade);

     printf("\t\t\tIDH DO PAIS: ");
     scanf("%f", &idh);

     pais = criarPais(nome,idade,idh);

     if(pais!=NULL){
       if(colRemover(mundo, pais, cmpPais)!=NULL){
         printf("\t\t\t PAIS DESTRUIDO!!\n");
       }else{
         printf("\t\t\t PAIS NAO ENCONTRADO. TENTE NOVAMENTE\n");
       }
     }else{
       printf("\t\t\t ERRO NA INSERCAO DE DADOS.\n\t\t\t TENTE NOVAMENTE\n");
     }
  }else{
    printf("\t\t\t PRIMEIRO FUNDE UM PAIS PARA DESTRUI-LO.\n\t\t\t TENTE NOVAMENTE.\n");
  }
}

//5. Destruir Mundo
void destruirMundo(){
  system("clear");
          if(mundo!=NULL){
            int opcao = 0;
            printf("\n\t\t\t-----------------*---------------\n");
            printf("\t\t\t-----Bomba Atomica / COVID 19 ----\n");
            printf("\n\t\t\t-----------------*---------------\n");
            printf("\n\t\t\t1.Covid 19\n");
            printf("\t\t\t2.Bomba atomica\n");
            scanf("%d", &opcao);
          if(opcao==1){
            printf("\n\t\t\tVocê foi o ultimo sobrevivente, reconstrua-o e destrua-o novamente\n");
            colDestruir(mundo);
          }else if(opcao==2){
            printf("\n\t\t\tDestruicao sucedida!! Voce dizimou a humanidade com maestria. Seu imperio nasce.\n");
            colDestruir(mundo);
          }else{
            printf("Arregou?");
          }
          
          }else{
            printf("\n\t\t\tNAO HA PAISES PARA SEREM DESTRUIDOS!!\n");
          }
}

//6. Sair do programa

void sair(){
  system("clear");
  printf("\n\t\t\t-----------------*---------------\n");
  printf("\t\t\t------------- BYE BYE --------");
  printf("\n\t\t\t-----------------*---------------\n");
  system("exit");
}