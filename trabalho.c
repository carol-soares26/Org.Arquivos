#include <stdio.h>
#include <stdlib.h>
#include <trabalho.h>


int main()
{
  //Declarcão,abertura e verificação de ponteiros para listas
  FILE * lista1;
  FILE * lista2;
  lista1 = fopen("lista1.txt","rb");hah
  if(lista1 == NULL)
  {
    printf("Falha!!");
    exit(1);
  }

  lista2 = fopen("lista2.txt","rb");
  if(lista2 == NULL)
  {
    printf("Falha!!");
    exit(1);
  }

  char filename[20];//string para nomear indices primários

  //nomeaçao dos arquivos txt e criacão dos índices primarios
  sprintf(filename,"indicelista1.txt");
  criarindicep(lista1,filename);
  sprintf(filename,"indicelista2.txt");
  criarindicep(lista2,filename);

  //teste para índice secundário
  printf("///////TESTE/////\n");
  criarinds();






  fclose(lista1);
  fclose(lista2);
  return 0;

}
