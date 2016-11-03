#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/uio.h>
#include<unistd.h>
#include<string.h>

#include "practica2.h"

int main()
{
	int fd, nbytes;
	struct evaluacion alumno;

	fd = open("datos.bin",O_RDONLY); 

	while(1)
	{
		nbytes = (int) read(fd, &alumno, sizeof(alumno));
		if(nbytes == sizeof(alumno))
		{
			if(alumno.notamedia >= 4.5 && alumno.notamedia <5)
			{
				alumno.notamedia = 5;
			}
		
			printf("%s %s %s\n", alumno.apellido1, alumno.apellido2, alumno.nombre);
		}
		else break;
	}
	close(fd);
	return 0;
}
