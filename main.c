#include <stdio.h>
#include <stdlib.h>

void	mostrar_lugar();
int	reservar_lugar(int num);
int	cancelar_reserva(int num);
int	limpar_tudo();

void	cinema(void)
{
	int	cadeira, dec;

	mostrar_lugar();
	printf("1 - Fazer nova reserva\n");
	printf("2 - Cancelar reserva existente\n");
	printf("3 - Limpar todas reservas\n");
	printf("4 - Sair\n");
	scanf("%d", &dec);
	switch (dec)
	{
		case 1:
			printf("\nEscolha o lugar: ");
			scanf("%d", &cadeira);
			if (reservar_lugar(cadeira))
				cinema();
			else
				mostrar_lugar();
			break;
		case 2:
			printf("\nEscolha o lugar: ");
                        scanf("%d", &cadeira);
                        if (cancelar_reserva(cadeira))
                                cinema();
                        else
                                mostrar_lugar();
			break;
		case 3:
			printf("Desejas limpar tudo? sim = 1 e nao = 0\n");
			scanf("%d", &dec);
			if (dec == 1)
			{
				if (!limpar_tudo())
					cinema();
			}
			break;
		default:
			exit(1);
	}
}

int	main(void)
{
	cinema();
	return(0);
}

