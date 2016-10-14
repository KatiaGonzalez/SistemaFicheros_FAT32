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
	if(argc != 3){ // ./verificacion disco directorio_simul
		printf("Faltan argumentos\n");
		return -1;
	}
	bmount(argv[1]);
	empty(0);
	empty(1);
	
	//Creamos informe.txt en directorio simulacion
	char dirinforme[50];
	sprintf(dirinforme, "%sinforme.txt", argv[2]);
	mi_creat(dirinforme, '7');
	
	RegInfo reginfo;
	Registro first;
	Registro last;
	Registro menor;
	Registro mayor;
	Entrada entrada;
	STAT estado;
	mi_stat(argv[2], &estado);
	int entradastotales = estado.bytesSize/sizeof(Entrada) - 1;
	int i = 0;
	int n;
	while(i < 100){
		mi_read(argv[2], &entrada, i*sizeof(Entrada), sizeof(Entrada));
		char proceso[20];
		memset(proceso, 0, sizeof(proceso));
		strcpy(proceso, entrada.nombre+strlen("proceso_"));
		int pid = atoi(proceso);
		char lectura[50];
		sprintf(lectura, "%s%s/prueba.dat", argv[2], entrada.nombre);
		Registro arrayreg[10000]; //Acumula registros de 10000 en 10000
		int j = 0;
		n = 0;
		int primero = 1;
		int over = 0;
		int m;
		Registro reg;
		while(mi_read(lectura, arrayreg, j*sizeof(arrayreg), sizeof(arrayreg)) > 0){
			m = 0;
			while(m < (sizeof(arrayreg)/(sizeof(Registro)))){
				reg = arrayreg[m];
				if(reg.pid == pid){
					if(primero == 1){
						first = reg;
						last = reg;
						menor = reg;
						mayor = reg;
						primero = 0;
					}else{
						if(reg.nescritura <= first.nescritura) first = reg;
						if(reg.nescritura >= last.nescritura) last = reg;
						if(reg.nregistro <= menor.nregistro) menor = reg;
						if(reg.nregistro >= mayor.nregistro) mayor = reg;
					}
					n++;
				}
				m++;
			}
			j++;
			memset(arrayreg, 0, sizeof(arrayreg));
		}
		if(n == 0){
			reginfo.pid = pid;
			reginfo.nescrituras = 0;
			printf("NO HAY REGISTROS\n");
		}else{
			reginfo.pid = pid;
			reginfo.first = first;
			reginfo.last = last;
			reginfo.menor = menor;
			reginfo.mayor = mayor;
			reginfo.nescrituras = n;
		}
		STAT st;
		mi_stat(dirinforme, &st);
		mi_write(dirinforme, &reginfo, st.bytesSize, sizeof(RegInfo));
		i++;
	}
	printf("Verificación completada\n");
	printf("\nRuta del informe: ");
	printf("%s\n", dirinforme);
	
	bumount();
}
