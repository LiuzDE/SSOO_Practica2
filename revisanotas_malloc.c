#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

#include "practica2.h"

int revisanotas(int fd) {
	int nbytes, nchanged, i;
	struct evaluacion alumno;
	struct evaluacion *p_array;

	p_array = malloc(217 * sizeof(struct evaluacion));

	while(1)
	{
		nbytes = (int) read(fd, &alumno, sizeof(alumno));
		if(nbytes == sizeof(alumno))
		{			
			if(alumno.notamedia >= 4.5 && alumno.notamedia <5)
			{
				alumno.notamedia = 5;
				nchanged++;
			}
			p_array[i] = alumno;
			i++;
		}
		else break;
	}
	if(write(fd, p_array, sizeof(p_array))!=-1) {
		printf("Escritura correcta\n");
	}

	printf("Número total de alumnos: %i\n", i);
	return nchanged;
}
