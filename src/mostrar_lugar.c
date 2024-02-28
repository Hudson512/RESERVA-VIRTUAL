#include <stdio.h>
#include <stdlib.h>

void	mostrar_lugar()
{
	char	*db_acentos = "database/acentos.txt";
	FILE	*f_acentos;
	int	ch, i;
	
	i = 1;
	f_acentos = fopen(db_acentos, "r");
	if (f_acentos == NULL)
	{
		printf("FILE ERRO: erro ao abrir o arquivo %s.\n", db_acentos);
		exit(1);
	}
	printf("/////////////////////////////////\n");
	printf("////      BILHETE VIRTUAL    ////\n");
	printf("/////////////////////////////////\n\n");
	while ((ch = fgetc(f_acentos)) != EOF)
	{
		if (i == 1)
                        printf("0%d-%d ", i, i+19);
		putchar(ch);
		if (i == 21 || i == 42 || i == 63)
			printf("%d-%d ", i+1, i+20);
		i++;
	}
	printf("/////////////////////////////////\n");
	fclose(f_acentos);
}
