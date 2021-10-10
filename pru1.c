#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

int nParo;

void* routine(void *arg) {

		
		int numero = *(int*) arg;
		
		int i=0;
		int multiplos1=0;
		int multiplos2=0;

		for(i=1; i<=numero/2; i++){
			if(numero % i == 0){
				multiplos1=multiplos1+i;
			}
		}

		for(i=1; i<=multiplos1/2; i++){
			if(numero % i == 0){
				multiplos2=multiplos2+i;
			}
		}

		// if (numero==220)
		// {
		// 	printf("\n Llego al %d \n Multiplos 1: %d \n multiplos 2: %d \n ", numero,multiplos1, multiplos2);
			
		// }
		// if (numero==284)
		// {
		// 	printf("\n Llego al %d \n Multiplos 1: %d \n multiplos 2: %d \n ", numero,multiplos1, multiplos2);
			
		// }
		

		if (numero==220 || numero==284)
		{
			multiplos1=0;
			multiplos2=0;
			printf("\n Los divisiores propios de %d son: ", numero);
			for(i=1; i<=numero/2; i++){
				if(numero % i == 0){

					multiplos1=multiplos1+i;
					printf("%d, ",i);
				}
			}

			printf(" que suman: %d \n", multiplos1);
			printf("Los divisiores propios de %d son: ", multiplos1);

			for(i=1; i<=multiplos1/2; i++){
				if(numero % i == 0){
					multiplos2=multiplos2+i;
					printf("%d, ",i);
				}
			}
			printf(" que suman: %d \n", multiplos2);
		}
		
    
	}


int main(int argc, char* argv[]) {
    pthread_t th1,th2;

    int i,h,temp;
    printf("Introduce un numero: ");
	// scanf("%d", &nParo);
	nParo=498;
	printf("numero ingresado: %d", nParo);
	

	for (h = 0; h < nParo;)
	{
		
		if (pthread_create(&th1, NULL, &routine, &h) != 0) {
			perror("Failed to create thread");
			return 1;
		}
		temp=h+1;
		if (pthread_create(&th2, NULL, &routine, &(temp)) != 0) {
			perror("Failed to create thread");
			return 1;
		}

		if (pthread_join(th1, NULL) != 0) {
			return 2;
		}

		if (pthread_join(th2, NULL) != 0) {
			return 2;
		}

		h=h+2;
		
	}

    return 0;
}



