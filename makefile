mi_mkfs.o: mi_mkfs.c
	gcc -c mi_mkfs.c
bloques.o: bloques.c
	gcc -c bloques.c
semaforo_mutex_posix.o: semaforo_mutex_posix.c
	gcc -c semaforo_mutex_posix.c
ficheros_basico.o: ficheros_basico.c
	gcc -c ficheros_basico.c
main: mi_mkfs.o
	gcc mi_mkfs.o bloques.o semaforo_mutex_posix.o ficheros_basico.o -pthread -o mi_mkfs

