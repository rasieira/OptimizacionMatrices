//NOMBRE:Ramón Sieira Martínez
//Ejercicio-Optimizacion
//Grupo del X(16:30-18:00)-J(18:00-19:30)
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
void formaestatica()
{
  clock_t start,end;
  double time;
  start=clock();
  //int matriz[10000000][100];
  int i=0;
  int j=0;
  /*for(i=0;i<100;i++)
    {
      for(j=0;j<10000000;j++)
	{
	  matriz[i][j]=0;
        }
	}*/
  end=clock();
  time=((double)(end-start))/CLOCKS_PER_SEC;
  printf("No se tiene tanta memoria: Error de Segmentacion");
}
void doblepunteromalloc()
{
  clock_t start,end;
  double time;
  start=clock();
  int **matriz=(int **)malloc(10000000*sizeof(int *));
  for(int i=0;i<10000000;i++)
    {
      matriz[i]=(int *)malloc(100*sizeof(int));
    }
  for(int i=0;i<10000000;i++)
    {
      for(int j=0;j<100;j++)
	{
	  matriz[i][j]=0;
	}
    }
  end=clock();
  for(int i=0;i<10000000;i++)
    free(matriz[i]);
    
  free(matriz);
  time=((double)(end-start))/CLOCKS_PER_SEC;
  printf("El doble puntero malloc tarda %f milisegundos",time*1000);
  
}

void doblepunterocalloc()
{
  clock_t start,end;
  double time;
  start=clock();
  int **matriz=(int **)calloc(10000000,sizeof(int *));
  for(int i=0;i<10000000;i++)
    {
      matriz[i]=(int *)calloc(100,sizeof(int));
    }
  end=clock();
  for(int i=0;i<10000000;i++)
    free(matriz[i]);
    
  free(matriz);
  time=((double)(end-start))/CLOCKS_PER_SEC;
  printf("El doble puntero calloc tarda %f milisegundos",time*1000);
  
}
void doblepunterocallocinverso()
{
  clock_t start,end;
  double time;
  start=clock();
  int **matriz=(int **)calloc(100,sizeof(int *));
  for(int i=0;i<100;i++)
    {
      matriz[i]=(int *)calloc(10000000,sizeof(int));
    }
  end=clock();
  for(int i=0;i<100;i++)
    free(matriz[i]);
    
  free(matriz);
  time=((double)(end-start))/CLOCKS_PER_SEC;
  printf("El doble puntero calloc tarda %f milisegundos",time*1000);
  
}
void doblepunteromallocinverso()
{
  clock_t start,end;
  double time;
  start=clock();
  int **matriz=(int **)malloc(100*sizeof(int *));
  for(int i=0;i<100;i++)
    {
      matriz[i]=(int *)malloc(10000000*sizeof(int));
    }
  for(int i=0;i<100;i++)
    {
      for(int j=0;j<10000000;j++)
	{
	  matriz[i][j]=0;
	}
    }
  end=clock();
  for(int i=0;i<100;i++)
    free(matriz[i]);
    
  free(matriz);
  time=((double)(end-start))/CLOCKS_PER_SEC;
  printf("El doble puntero malloc tarda %f milisegundos",time*1000);
  
}
int main()
{
  printf("Forma Estatica: ");
  formaestatica();
  printf("\n");
  printf("Forma Doble Puntero Calloc: ");
  doblepunterocalloc();
  printf("\n");
  printf("Forma Doble Puntero Malloc: ");
  doblepunteromalloc();
  printf("\n");
  printf("Forma Doble Puntero Calloc Inverso: ");
  doblepunterocallocinverso();
  printf("\n");
  printf("Forma Doble Puntero Malloc Inverso: ");
  doblepunteromallocinverso();
  printf("\n");
}
//En primer lugar he intentado hacer un metodo esttico pero me daba error de segmentacion por lo que lo he descartado ya que consume mucha memoria
//En segundo lugar he buscado la forma de hacer punteros en internet y he encotrado dos funciones de C que son calloc y malloc
//Calloc reserva memoria e inicializa cada posicion de la matriz a cero y malloc unicamente hace la reserva de la memoria
//He hecho de dos formas cada metodo, uno inverso al otro y he llegado a l a conclusion que en todas las formas lo mejor es utilizar calloc pero sobre todo en la forma inversa a la normal.
//Tambien he comprobado los tiempos y he observado por tanto los cambios de cada algoritmo,tambien he probado dentro de las opciones del compilador a cambiar el nivel de optimizacion a 3 lo que hace que se modifiquen los tiempos aunque no de manera significativa aunque si en el doble puntero malloc inverso
