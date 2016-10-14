#include "directorios.h"

int main(int argc, char **argv){
	int fd = bmount(argv[1]);
	unsigned int nbloques = calcular_bloques();
	int ninodos = nbloques/4;
	int ninodo = atoi(argv[2]);
	int i = 0;
	int bytesleidos = 0;
	int tamanyobuffer = 1500;
	unsigned char buffer[tamanyobuffer];
	int a = 0;
	while((a = mi_read_f(ninodo, buffer, i, tamanyobuffer)) > 0){
		bytesleidos += a;
		write(1, buffer, a);
		i+=tamanyobuffer;
	}
	char string[128];
	sprintf(string, "Tamaño del inodo: %d\n", bytesleidos);
	write(2, string, strlen(string));
	bumount();
	
	
 }
