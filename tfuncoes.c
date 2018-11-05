#include <stdio.h>
#include <stdlib.h>
#include <trabalho.h>
#include <string.h>

Pilha *  CriarPilha()
{
    Pilha * p;
    p = (Pilha*)malloc(sizeof(Pilha));
    p->tamanho = 0;
    return p;
}

void InserirPilha(Pilha *pi, int p, int arq)
{

  pi->numPilha[pi->qtd] = p;
  pi->arq = arq;
  pi->tamanho++;
}

int RemoverPilha(Pilha *pi)
{
  int topo = pi->numPilha[pi->numPilha-1];

  pi->tamanho--;

  return topo;
}

int opcoes()
{
    printf("-------------------MENU-----------------------\n");
    printf("Mostrar Registros (1)\n");
    printf("Mostrar Índice Primário (2)\n");
    printf("Encerrar programa (3)\n");
    int opcao;
    scanf("Opcao: %d",&opcao);
    return opcao;

}

void OpcaoEscolhida(int opcao, Aponta * lista1, Aponta * lista2)
{
  int numArq;

  switch(opcao)
  {
    case 1:
    PrintarLista(lista1,1);
    PrintarLista(lista2,2);
    break;
    case 2:
    printf("Escolha o arquivo\n");
    printf("Lista1 (1)\n");
    printf("Lista2 (2)\n");
    scanf("%d", %numArq);
    if(numArq == 1)
    {
       PrintarChavesPrimarias(lista1,1);
       else
       PrintarChavesPrimarias(lista2,2);
       break;
    }
    case 3:
    exit(1);
    break;
  }

Aponta * AlocCriaAPonta()
{
    Aponta * p = (Aponta*)malloc(sizeof(Aponta));
    p->inicio = NULL;
    p->fim = NULL;
    p->tamanho = 0;
    return p;

}

Elemento * AlocaElemento(int OP, char * curso, int matricula, char * chavePrimaria,int posicao, char turma)
{
    Elemento * p = (Elemento*)malloc(sizeof(Elemento));
    p->OP = OP;
    strcpy(p->curso,curso);
    p->matricula = matricula;
    p->chaveP = chavePrimaria;
    p->posicao = posicao;
    p->turma = turma;
    p->ant = NULL;
    p->prox = NULL;
    return p;
}

void InserirOrdenado(Aponta *lista, int matricula, char *nome, char *curso, char turma, int OP, int numArq, int posicao, char * chave_primaria)
{
  Elemento * atual = lista->inicio;
  Elemento * novo = AlocaElemento(matricula, nome, curso, turma, op, num_arq, posicao, chave_primaria);

  while(atual != NULL && (strcmp(atual->chave_primaria, chave_primaria) < 0))
  {
    atual = atual->prox;
  }


  if(lista->inicio == NULL && lista->fim == NULL)
  {
    lista->inicio = lista->fim = novo;
  }
  else if(atual == NULL)
  {

    novo->ant = lista->fim;
    novo->prox = NULL;
    lista->fim->prox = novo;
    lista->fim = novo;
  }
  else if(atual->ant == NULL)
  {
    novo->ant = NULL;
    novo->prox = atual;
    lista->inicio->ant = novo;
    lista->inicio = novo;
  }
  else
  {
    novo->ant = atual->ant;
    novo->prox = atual;
    novo->ant->prox = novo->prox->ant = novo;
  }
  lista->tamanho++;
}

void MostraLista(Aponta *lista,int arq)
{
    lista * aux = lista->inicio;
    if(arq == 1)
    {
        printf("Registros da Lista 1");
    }
    else
    {
        printf("Registros da Lista 2");
    }
  while(aux != NULL)
  {
      printf("%d %s\t%d  %s\t\t%c|%d\n",aux->matricula,aux->nome,aux->OP,aux->curso,aux->turma,i);
  }
}

void liberarElemento(Elemento **p)
{
    if(n != NULL && *p != NULL)
    {
        free(*p);
        *p = NULL;
    }
}

int vazia(Aponta * lista)
{
  if(lista == NULL)
  {
    return 0; /* lista vazia */
  }
  else
  {
    return 1;
  }
}














}








char * criarindicep(FILE * file,char * filename)
{
    long pos;
    char ch;
    int i = 0,j = 0,n_registros;
    char * vchavep;//vetor que vai armazenar a chave primária (MATRICULA/NOME)
    char * vreg;//vetor que vai armazenar o registro todo
    FILE * ind;//ponteiro para possibilitar escrita no arquivo de índices primários
    //Declarações e verificações de ponteiros para arquivos
    ind = fopen(filename,"wb");
    if(file == NULL)
    {
      printf("Falha!!");
      exit(1);
    }
    if(ind == NULL)
    {
      printf("Falha!!");
      exit(1);
    }
    //alocaçao de memório para os vetores
    vchavep = (char *) malloc(sizeof(char)*30);//aloca chave primaria
    vreg = (char *)malloc (100*sizeof(char));//aloca registro
    //Calcular tamanho de um registro
    ch = fgetc(file);
    vreg[0] = ch;
    while( (ch = fgetc(file)) != '\n')
    {
      i++;
      vreg[i] = ch;
    }
    printf("PrimeiroChar %c\n", vreg[61]);
    printf("Tamanho %ld", strlen(vreg));
    printf("Tamanho+1 %ld",strlen(vreg)+1);
    //voltar para inicio do arquivo após calcular tamanho do registro
    rewind(file);
     //verificar numero de registros no arquivo lista
    n_registros = countregisters(file); //função para contar registros
    printf("\nNumber of Registers:%d\n",n_registros);//teste;

    //Construção do índice primário
    while(j < n_registros)//leitura até o fim do arquivo lista
    {
      fseek(file,(strlen(vreg)+1)*j,SEEK_SET);
      pos = ftell(file);
      printf("Registro%d:%ld\n",j,pos);
      fread(vchavep,sizeof(char),30,file);//leitura da chave primária
      fwrite(vchavep,sizeof(char),30,ind);//chave primária gravada
      fputc('|',ind);//separador entre chave primária e referencia
      fprintf(ind,"%ld",pos);//referencia gravada
      fputc('\n',ind);//pular pra próxima linha
      j++;

    }
    //desalocação e fechamento
    free(vreg);
    free(vchavep);
    fclose(file);
    fclose(ind);
}
//funcao para contar número de registros do arquivo
int countregisters(FILE * p)
{
    char ch;
    int n_registros = 0;
     while(!feof(p))
     {
       ch = fgetc(p);
       if(ch == '\n')
       {
         n_registros++;
       }
     }
     return n_registros;
     free(p);
}

typedef struct lista{
    char vchavep[32];
    char curso;
    int op;
    int matric;




}

int menu()
{
  int opção;
  printf("\n------------------------------------\n");
  printf("Incluir Registro                     (1)");
  printf("Excluir egistro                     (1)");
  printf("Atualizar registro                     (1)");
  printf("Mostrar todos os registros                     (1)");




}

void ordenarindiceP(char chaveP[][30], int inicio, int fim)
{





}
/*
void criarindicesec(void)
{




}
//protótipo criação índice primário
/*
void criarinds(void)
{
  FILE * lista2;
  char ch;
  int i = 0;
  lista2 = fopen("lista2.txt","rb");
  char * vreg;

  vreg = (char *)malloc (100*sizeof(char));//aloca registro

  ch = fgetc(lista2);
  vreg[0] = ch;
  printf("Primeiro char:%c\n",ch);
  while( (ch = fgetc(lista2)) != '\n')
  {

    i++;
    vreg[i] = ch;
  }
  printf("Primeiro char:%c\n",vreg[61]);
}
