typedef struct Pilha
{
    int tamanho;
    int arq;
    int numPilha[25];
} Pilha;

typedef struct Elemento
{
  char chave_primaria[30];
    int OP;
    char curso[3];
    char nome[43];
    int matricula;
    char turma;
    int numArq;
    int posicao;
    struct Elemento * prox;
    struct Elemento * ant;
  } Elemento;

  typedef struct Aponta
  {
      Elemento * inicio;
      Elemento * fim;
      int tamanho;
  }Aponta;
//FUNCOES DO PROGRAMA//
int opcoes()
void InserirPilha(Pilha *, int , int)
int RemoverPilha(Pilha *);
void OpcaoEscolhida(int , Aponta * , Aponta * );
Elemento * AlocaElemento(int , char * , int , char * ,int , char );
void InserirOrdenado(Aponta *lista, int matricula, char *nome, char *curso, char turma, int OP, int numArq, int posicao, char * chave_primaria);
void MostraLista(Aponta *,int );
int vazia(Aponta * lista)
void liberarElemento(Elemento **p)
Aponta * AlocCriaAPonta();
Pilha * criarPilha();
char * criarindicep(FILE*,char*);
int countregisters(FILE*);
void criarinds(void);
void criarindicesec(void);
