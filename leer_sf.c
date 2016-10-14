#include "directorios.h"
#include <sys/stat.h>

int mostrarSuperbloque(Superbloque sb);
int mostrarMapaBits(unsigned int tamanyoMB, unsigned int posMB);
int mostrarInodo(unsigned int ninodo);

int main(int argc, char **argv){
	int fd = bmount(argv[1]);
	int nbloques = calcular_bloques();
	int ninodos = nbloques/4; // ninodos/8 bloques que ocupan los inodos (array de inodos)
	printf("Número de bloques del fichero: %u\n\n", nbloques);
	Superbloque sb;
	leerSuperbloque(&sb);
	mostrarSuperbloque(sb);
	printf("\nTamaño mapa de bits: %d\n", tamMB(nbloques));
	printf("Tamaño array de inodos: %d\n", tamAI(ninodos));
	printf("Sizeof superbloque: %lu\n", sizeof(Superbloque));
	printf("Sizeof inodo: %lu\n\n", sizeof(Inodo));
	//mostrarMapaBits(tamMB(nbloques), sb.primerMapa);
	//printf("Bloques ocupados, segun superbloque: %d", (sb.totbloques-sb.bloqueslibres));
	
	printf("\nPrimer Inodo Libre: %d\n\n",sb.primerInodoLibre);
	unsigned int ninodo = 0;
	printf("Inodos ocupados -> \n\n");
	
	while(ninodo < sb.totinodos){ // Mostramos inodos
		mostrarInodo(ninodo);
		ninodo++;
	}
		
	bumount();
	return 0;
}

int mostrarSuperbloque(Superbloque sb){

	printf("SB.primerMapa: %u\n", sb.primerMapa);
	printf("SB.ultimoMapa: %u\n", sb.ultimoMapa);
	printf("SB.primerInodos: %u\n", sb.primerInodos);
	printf("SB.ultimoInodos: %u\n", sb.ultimoInodos);
	printf("SB.primerDatos: %u\n", sb.primerDatos);
	printf("SB.ultimoDatos: %u\n", sb.ultimoDatos);
	printf("SB.inodoRaiz: %u\n", sb.inodoRaiz);
	printf("SB.primerInodoLibre: %u\n", sb.primerInodoLibre);
	printf("SB.bloqueslibres: %u\n", sb.bloqueslibres);
	printf("SB.inodoslibres: %u\n", sb.inodoslibres);
	printf("SB.totbloques: %u\n", sb.totbloques);
	printf("SB.totinodos: %u\n", sb.totinodos);

}

int mostrarMapaBits(unsigned int tamanyoMB, unsigned int posMB){
	int a = tamanyoMB*BLOCKSIZE*8;
	printf("Bits del mapa de bits: %d\n", a);
	int i;
	int cnt = 0;
	for(i=0;i<a;i++){
		if(leer_bit(i) == 1){
			printf("[%d]", i);
		}
		
		if(leer_bit(i)==1)cnt++;
		//printf("%d", leer_bit(i));
		
	}
	printf("Bloques ocupados del mapa: %d\n",cnt);
	return 0;
}

int mostrarInodo(unsigned int ninodo){
	
	Inodo inodo = leer_inodo(ninodo);
	if(inodo.tipo != 'l'){
		struct tm *ts;
		char atime[80];
		char mtime[80];
		char ctime[80];
		ts = localtime(&inodo.atime);
		strftime(atime, sizeof(atime), "%a %Y-%m-%d %H:%M:%S", ts);
		ts = localtime(&inodo.mtime);
		strftime(mtime, sizeof(mtime), "%a %Y-%m-%d %H:%M:%S", ts);
		ts = localtime(&inodo.ctime);
		strftime(ctime, sizeof(ctime), "%a %Y-%m-%d %H:%M:%S", ts);
		printf("Inodo nº %d: \n", ninodo);	
		printf("tipo: %c\n",inodo.tipo);
		printf("Permisos: %c\n",inodo.permisos);
		printf("Nº enlaces: %d\n",inodo.nentradas);
		printf("Tamaño en bytes logicos: %d\n", inodo.bytesSize);
		printf("inodo.bloquesocupados: %u\n", inodo.bloquesOcupados);
		printf("puntero directo 0: %u\n",inodo.punterosDirectos[0]);
		printf("puntero indirecto 0: %u\n",inodo.punterosIndirectos[0]);
		printf("puntero indirecto 1: %u\n",inodo.punterosIndirectos[1]);
		printf("puntero indirecto 2: %u\n",inodo.punterosIndirectos[2]);
		printf("ATIME: %s MTIME: %s CTIME: %s\n\n",atime,mtime,ctime);
	}
}

