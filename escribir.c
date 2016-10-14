#include "directorios.h"
#include <stdio.h>


int main(int argc, char **argv){
	int fd = bmount(argv[1]);
	unsigned int nbloques = calcular_bloques();
	int ninodos = nbloques/4;
	
	// Reservamos inodo ->
	int ninodo = reservar_inodo('f', 6);
	//printf("\nNumero de inodo: %d\n", ninodo);
	
	
	// Escribimos texto ->
	//unsigned char buffer[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Donec interdum pretium mollis. Nunc et sollicitudin sapien, a rhoncus velit. Sed dui neque, sagittis vel suscipit sit amet, ornare eu lorem. Suspendisse vitae nulla eget risus luctus vestibulum. Quisque viverra vehicula odio, in dapibus felis elementum vel. Suspendisse bibendum leo non porttitor interdum. Nullam lacinia faucibus urna nec lacinia. Etiam sem sem, condimentum a nisl vitae, tristique commodo arcu. Suspendisse pellentesque justo eget velit pellentesque, at feugiat augue placerat. Aenean dictum porttitor sagittis. Sed mollis hendrerit convallis. Mauris rutrum lacinia enim. Sed euismod accumsan iaculis. Nullam adipiscing odio quis est accumsan, vel placerat turpis lobortis. Morbi vel metus tincidunt, tincidunt magna ac, porta metus. In in lacinia sem, nec ullamcorper lectus. Duis feugiat risus nisl, rhoncus tempus dolor sodales vitae. Aenean molestie elit vitae nulla vulputate, ac dictum dolor mattis. Sed tincidunt, odio ut posuere varius, sem erat faucibus est, ut faucibus est tellus eu mauris. Suspendisse laoreet, ipsum vitae consequat dapibus, nibh nunc accumsan magna, vel congue diam ante et est. Duis laoreet, felis in imperdiet malesuada, dui quam lobortis metus, non cursus nulla erat in libero. Integer condimentum interdum tristique. Nunc ut magna id tortor faucibus tempor. Donec egestas nisi eget convallis viverra. Proin tincidunt mi ac nibh euismod, non faucibus magna pulvinar. Duis eget feugiat orci. In eu libero semper, pretium augue ut, vehicula lectus. Phasellus porta urna et felis congue aliquam. Fusce justo velit, posuere ut massa at, laoreet elementum neque. Integer mauris ipsum, sagittis non ante non, accumsan mollis urna. Integer egestas odio et orci consectetur consequat. Aenean hendrerit leo urna, id sagittis tortor porta eu. Pellentesque non felis tellus. Ut eros massa, cursus ac hendrerit vitae, aliquet eu lacus. Fusce enim velit, dictum fermentum blandit sit amet, mattis volutpat.";
	
	unsigned char buffer[] = "Esto es una prueba";
 	mi_write_f(ninodo, buffer, 30720000, strlen(buffer));
	
	// Escribimos texto ->
	mi_write_f(ninodo, buffer, 5120, strlen(buffer));
	
	// Escribimos texto ->
	mi_write_f(ninodo, buffer, 256000, strlen(buffer));
	
	// Escribimos texto ->
	mi_write_f(ninodo, buffer, 71680000, strlen(buffer));
	
	
	char string[40];
	/*
	// Leemos texto ->
	unsigned char bufleido[BLOCKSIZE];
	memset(bufleido, 0, BLOCKSIZE);
	int a = mi_read_f(ninodo, bufleido, 30720000, strlen(buffer));
	
	// Escribimos el texto y los bytes leidos por pantalla ->
	write(1, bufleido, strlen(bufleido));
	memset(string, 0, strlen(string));
	sprintf(string, "Bytes leidos: %d\n", a);
	write(2, string, strlen(string));
	
	// Leemos texto ->
	bufleido[sizeof(buffer)];
	memset(bufleido, 0, sizeof(bufleido));
	a = mi_read_f(ninodo, bufleido, 5120, strlen(buffer));
	
	// Escribimos el texto y los bytes leidos por pantalla ->
	write(1, bufleido, strlen(bufleido));
	memset(string, 0, strlen(string));
	sprintf(string, "Bytes leidos: %d\n", a);
	write(2, string, strlen(string));
	
	// Leemos texto ->
	bufleido[sizeof(buffer)];
	memset(bufleido, 0, sizeof(bufleido));
	a = mi_read_f(ninodo, bufleido, 256000, strlen(buffer));
	
	// Escribimos el texto y los bytes leidos por pantalla ->
	write(1, bufleido, strlen(bufleido));
	memset(string, 0, strlen(string));
	sprintf(string, "Bytes leidos: %d\n", a);
	write(2, string, strlen(string));
	
	// Leemos texto ->
	bufleido[sizeof(buffer)];
	memset(bufleido, 0, sizeof(bufleido));
	a = mi_read_f(ninodo, bufleido, 71680000, strlen(buffer));
	
	// Escribimos el texto y los bytes leidos por pantalla ->
	write(1, bufleido, strlen(bufleido));
	memset(string, 0, strlen(string));
	sprintf(string, "Bytes leidos: %d\n", a);
	write(2, string, strlen(string));
	
	*/
	
	// Escribimos el número de inodo ->
	memset(string, 0, strlen(string));
	sprintf(string, "Numero de inodo: %d\n", ninodo);
	write(2, string, strlen(string));
	
	
	// Desmontamos ->
	bumount();
	
	
	return 0;
	
	
	
	
	
 }

