#include <stdio.h>
#include <stdlib.h>

int	limpar_tudo()
{
	char    *db_acentos = "database/acentos.txt";
	char	*db_acentos1 = "database/acentos2.txt";
	FILE	*f_acentos, *f_acentos1;
	int	ch, j;
	
	f_acentos1 = fopen(db_acentos1, "r+");
	f_acentos = fopen(db_acentos, "w+");
	if (f_acentos == NULL || f_acentos1 == NULL)
	{
		printf("FILE ERRO (Limpeza): erro ao abrir o arquivo %s\n", db_acentos);
		exit(1);
	}
	while ((ch = fgetc(f_acentos1)) != EOF)
	{
		fputc(ch, f_acentos);
	}
	printf("\nLimpeza concluída :-)!\n");
	fclose(f_acentos);
	fclose(f_acentos1);
	printf("Deseja sair? sim = 1, nao = 0.\n");
	scanf("%d", &j);
	if (j)
		return (1);
	return (0);
}
