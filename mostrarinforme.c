#include "directorios.h"


typedef struct registro{
	
	int fecha;
	int pid;
	int nescritura;
	int nregistro;
	
} Registro;

typedef struct registro_info{
	
	int pid;
	int nescrituras;
	Registro first;
	Registro last;
	Registro menor;
	Registro mayor;
	
} RegInfo;

int main(int argc, char **argv){
	if(argc != 3){ // ./mostrarinforme disco directorio_informe
		printf("Faltan argumentos\n");
		return -1;
	}
	bmount(argv[1]);
	empty(0);
	empty(1);
	STAT stat;
	mi_stat(argv[2], &stat);
	int nregistros = stat.bytesSize/sizeof(RegInfo);
	RegInfo arrayreginfo[nregistros];
	mi_read(argv[2], &arrayreginfo, 0, sizeof(arrayreginfo));
	printf("\n");
	int i;
	for(i = 0; i < nregistros; i++){
		printf("Registro del proceso %d\n", arrayreginfo[i].pid);
		printf("Número de escrituras: %d\n", arrayreginfo[i].nescrituras);
		printf("Primera escritura:\n");
		printf("	Fecha: %d\n", arrayreginfo[i].first.fecha);
		printf("	Número de escritura: %d\n", arrayreginfo[i].first.nescritura);
		printf("	Posición: %d\n", arrayreginfo[i].first.nregistro);
		printf("Última escritura:\n");
		printf("	Fecha: %d\n", arrayreginfo[i].last.fecha);
		printf("	Número de escritura: %d\n", arrayreginfo[i].last.nescritura);
		printf("	Posición: %d\n", arrayreginfo[i].last.nregistro);
		printf("Menor posición:\n");
		printf("	Posición: %d\n", arrayreginfo[i].menor.nregistro);
		printf("	Número de escritura: %d\n", arrayreginfo[i].menor.nescritura);
		printf("	Fecha: %d\n", arrayreginfo[i].menor.fecha);
		printf("Mayor posición:\n");
		printf("	Posición: %d\n", arrayreginfo[i].mayor.nregistro);
		printf("	Número de escritura: %d\n", arrayreginfo[i].mayor.nescritura);
		printf("	Fecha: %d\n", arrayreginfo[i].mayor.fecha);
		printf("\n\n");
	}
	
	
	bumount();
}
