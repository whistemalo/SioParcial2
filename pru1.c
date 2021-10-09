#include <stdio.h>

int numeros_amigos(int x, int y)
{

int main (int argc, char *argv[])
{
int numero;
int i;
int b=0;
do{
printf("Introduce un numero: ");
scanf("%d", &numero);
} while (numero<=0);

for(i=1; i<=numero/2; i++){
	if(numero % i == 0){
		b=b+i;
		printf("%d\t",i);
	}
}
printf("%d\t\n", numero);
printf("La suma es: %d\t\n", b);

return 0;
}

