#include <stdio.h>
#include <stdlib.h>
#include <trabalho.h>
#include <string.h>

void criarindicep(FILE * file,char * filename)
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
//protótipo criação índice primário
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
