#include <stdio.h>
#include <stdlib.h>

int	cancelar_reserva(int num)
{
	char    *db_acentos = "database/acentos.txt";
	char	*db_acentos1 = "database/acentos1.txt";
	FILE	*f_acentos, *f_acentos1;
	int	ch, i, j;
	
	i = 1;
	f_acentos1 = fopen(db_acentos1, "w+");
	f_acentos = fopen(db_acentos, "r+");
	if (f_acentos == NULL || f_acentos1 == NULL)
	{
		printf("FILE ERRO (RESERVAR): erro ao abrir o arquivo %s\n", db_acentos);
		exit(1);
	}
	while ((ch = fgetc(f_acentos)) != EOF)
	{
		if (i == num)
			fputc(68, f_acentos1);
		else
			fputc(ch, f_acentos1);
		i++;
	}
	fclose(f_acentos);
        fclose(f_acentos1);
	//------------------------------------------------------------------------------------------------------------------
	//                                              NOVA ABERTURA DE FICHEIRO
	//------------------------------------------------------------------------------------------------------------------
	f_acentos1 = fopen(db_acentos1, "r+");
        f_acentos = fopen(db_acentos, "w+");
        if (f_acentos == NULL || f_acentos1 == NULL)
        {
		printf("FILE ERRO (RESERVAR): erro ao abrir o arquivo %s\n", db_acentos);
		exit(1);
        }
	while ((ch = fgetc(f_acentos1)) != EOF)
        {
		fputc(ch, f_acentos);
        }
	printf("\nReserva %d cancelada :-)!\n", num);
	fclose(f_acentos);
	fclose(f_acentos1);
	printf("Deseja continuar na app? sim = 1, nao = 0.\n");
	scanf("%d", &j);
	if (j)
		return (1);
	return (0);
}
