#include <stdio.h>
#include <stdlib.h> // Para usar atoi()

// Estructura del nodo para la lista enlazada
typedef struct Node
{
	int			data;
	struct Node	*next;
}				Node;

Node			*top = NULL; // Puntero al tope del stack

// Función para verificar si un número ya está en el stack
int	isDuplicate(int value)
{
	Node	*current;

	current = top;
	while (current != NULL)
	{
		if (current->data == value)
		{
			return (1);
		}
		current = current->next;
	}
	return (0);
}

// Función para agregar un elemento al stack
void	pushAtFirst(int value)
{
	Node	*newNode;

	if (isDuplicate(value))
	{
		printf("El número %d ya está en el stack. No se permiten duplicados.\n",
			value);
		return ;
	}
	newNode = (Node *)malloc(sizeof(Node));
	if (newNode == NULL)
	{
		printf("Error: No se pudo asignar memoria para el nuevo elemento.\n");
		return ;
	}
	newNode->data = value;
	newNode->next = top;
	top = newNode;
}

int	main(int argc, char *argv[])
{
	int		i;
	int		num;
	Node	*current;

	if (argc > 1)
	{
		i = argc - 1;
		while (i > 0)
		{
			num = atoi(argv[i]);
			pushAtFirst(num);
			i--;
		}
	}
	current = top;
	while (current != NULL)
	{
		printf("%d\n", current->data); // Imprimir elementos del stack
		current = current->next;
	}
	printf("_  _\na  b");
	printf("\n");
	return (0);
}
