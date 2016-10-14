#include <sys/wait.h>
#include "directorios.h"

int acabados = 0;

void reaper(){
	while(wait3(NULL, WNOHANG, NULL) > 0){
		acabados++;
	}
}

typedef struct registro{
	
	int fecha;
	int pid;
	int nescritura;
	int nregistro;
	
} Registro;

int posMAX = 500000;
int MAXPROCESOS = 100;

int main(int argc, char **argv){
	if(argc != 2){
		printf("Faltan argumentos\n");
		return -1;
	}
	bmount(argv[1]);
	empty(0);
	empty(1);
	
	//Prepara enterrador
	signal(SIGCHLD, reaper);
	
	//Creamos directorio principal "/simul_aammddhhmmss/"
	char directorio1[30];
	memset(directorio1, 0, sizeof(directorio1));
	time_t hora;
	struct tm *tm;
	hora = time(NULL);
	tm = localtime(&hora);
	sprintf(directorio1,"/simul_%d%d%d%d%d%d/",tm->tm_year+1900,tm->tm_mon+1,tm->tm_mday,tm->tm_hour, tm->tm_min, tm->tm_sec);
	mi_creat(directorio1, '7');
	//Directorio principal creado
	int i;
	for(i = 0; i < MAXPROCESOS; i++){
		if(fork() == 0){
			srand(getpid());
			char rutadir[40];
			memset(rutadir, 0, sizeof(rutadir));
			sprintf(rutadir, "%sproceso_%d/", directorio1, getpid());
			if(mi_creat(rutadir, '7') < 0){
				printf("Error al crear fichero\n");
				return -1;
			}
			char rutafich[60];
			memset(rutafich, 0, sizeof(rutafich));
			sprintf(rutafich, "%sprueba.dat", rutadir);
			if(mi_creat(rutafich, '7') < 0){
				printf("Error al crear fichero\n");
				return -1;
			}
			int j;
			for(j = 0; j < 50; j++){
				Registro reg;
				reg.fecha = time(NULL);
				reg.pid = getpid();
				reg.nescritura = j+1;
				reg.nregistro = rand()%posMAX;
				if(mi_write(rutafich, &reg, reg.nregistro*sizeof(Registro), sizeof(Registro)) < 0){
					printf("Error al escribir\n");
					return -1;
				}
				usleep(50000);
			}
			exit(0);
		}
		usleep(200000); // Duerme 0,2 seg
	}
	
	while(acabados < MAXPROCESOS){
		pause();
	}
	printf("Simulación completada\n");
	printf("Directorio de simulación: %s\n", directorio1);
	
	bumount();
	
	return 0;
	
}





