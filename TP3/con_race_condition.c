#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define NUMBER_OF_THREADS 2
#define CANTIDAD_INICIAL_HAMBURGUESAS 8
int cantidad_restante_hamburguesas = CANTIDAD_INICIAL_HAMBURGUESAS;

int turno = 0;

void *comer_hamburguesa(void *tid)
{
    intptr_t id = (intptr_t) tid;
    while (1 == 1)
    {
        while (turno != id);

        if (cantidad_restante_hamburguesas > 0)
        {
            printf("Hola! soy el hilo(comensal) %ld , me voy a comer una hamburguesa ! ya que todavia queda/n %d \n", id, cantidad_restante_hamburguesas);
            cantidad_restante_hamburguesas--;
        }
        else
        {
            printf("SE TERMINARON LAS HAMBURGUESAS :( \n");
            turno = (turno + 1) % NUMBER_OF_THREADS;
            pthread_exit(NULL);
        }

        turno = (turno + 1) % NUMBER_OF_THREADS;
    }
}

int main(int argc, char *argv[])
{
    pthread_t threads[NUMBER_OF_THREADS];
    int status, i, ret;
    for (i = 0; i < NUMBER_OF_THREADS; i++)
    {
        printf("Hola!, soy el hilo principal. Estoy creando el hilo %d \n", i);
        status = pthread_create(&threads[i], NULL, comer_hamburguesa, (void *)(intptr_t)i);
        if (status != 0)
        {
            printf("Algo salio mal, al crear el hilo recibi el codigo de error %d \n", status);
            exit(-1);
        }
    }

    for (i = 0; i < NUMBER_OF_THREADS; i++)
    {
        void *retval;
        ret = pthread_join(threads[i], &retval);
    }
    pthread_exit(NULL);
}