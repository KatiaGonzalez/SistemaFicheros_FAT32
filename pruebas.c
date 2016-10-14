#include "directorios.h"

int main(int argc, char **argv){
	bmount(argv[1]); //./pruebas disco_imagen 0/1
	
	
	empty(0);
	empty(1);
	mi_creat("/hola/", '7');
	printf("Creando 17 rutas: /hola/...\n");
	mi_creat("/hola/hola1", '7');
	mi_creat("/hola/hola2", '7');
	mi_creat("/hola/hola3", '7');
	mi_creat("/hola/hola4", '7');
	mi_creat("/hola/hola5", '7');
	mi_creat("/hola/hola6", '7');
	mi_creat("/hola/hola7", '7');
	mi_creat("/hola/hola8", '7');
	mi_creat("/hola/hola9", '7');
	mi_creat("/hola/hola10", '7');
	mi_creat("/hola/hola11", '7');
	mi_creat("/hola/hola12", '7');
	mi_creat("/hola/hola13", '7');
	mi_creat("/hola/hola14", '7');
	mi_creat("/hola/hola15", '7');
	mi_creat("/hola/hola16", '7');
	mi_creat("/hola/hola17", '7');
	
	printf("17 rutas creadas\n");
/*
	printf("\n");
	char buffer[512];
	memset(buffer, 0, sizeof(buffer));
	mi_dir("/", buffer);
	printf("%s\n", buffer);
	
	mi_link("/hola/hola", "/hola2");
	
	printf("\n");
	memset(buffer, 0, sizeof(buffer));
	mi_dir("/", buffer);
	printf("%s\n", buffer);
	
	mi_unlink("/hola/hola");
	
	printf("\n");
	memset(buffer, 0, sizeof(buffer));
	mi_dir("/", buffer);
	printf("%s\n", buffer);
	
	char buf0[] = "Esto es una prueba\n";
	mi_write("/hola2", buf0, 0, sizeof(buf0));
	
	char buf1[] = "Esto es la segunda prueba\n";
	mi_write("/hola2", buf1, strlen(buf0), sizeof(buf1));
printf("Comienza lectura\n");
/*
	char buffer0[BLOCKSIZE];
	int bl = mi_read("/hola2", buffer0, 0, sizeof(buffer0));
	write(1, buffer0, bl);
*/
/*
	int total = 0;
	int bl;
	char read0[1];
	int i = 0;
	while((bl = mi_read("/hola2", read0, i, 1)) > 0){
		write(1, read0, bl);
		i++;
		total += bl;
	}
	char string[128];
	sprintf(string, "Tamaño: %d\n", total);
	write(2, string, strlen(string));

*/
	bumount();
}
