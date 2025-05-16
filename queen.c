#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(char *str)
{
	int	i;
	int	numb;

	i = -1;
	numb = 0;
	while (str[++i] == '+' || str[i] == '-' || str[i] == ' ');
	while (str[i] != '\0')
	{
		numb *= 10;
		numb += str[i] - '0';
		i++;
	}
	return (numb);
}

int	check(int *board, int queen)
{
	int	i;

	i = -1;
	while (++i < queen)
	{
		if (board[i] == board[queen])
			return (1);
		if (board[i] == board[queen] - (queen - i) || board[i] == board[queen] + (queen - i))
			return (1);
	}
	return (0);
}

void place_queen(int *board, int queen, int max, int *count)
{
	int	i;

	if (queen == max)
	{
		(*count)++;
		i = -1;
		while (++i < max)
			printf("%d ", board[i]);
		printf("\n");
		return ;
	}
	else
	{
		i = -1;
		while (++i < max)
		{
			board[queen] = i;
			if (check(board, queen) == 0)
				place_queen(board, queen + 1, max, count);
		}
	}
}

int	main(int ac, char **av)
{
	int	i;
	int	j;
	int	*board;
	int	count;

	if (ac == 2)
	{
		i = ft_atoi(av[1]);
		board = malloc(sizeof(int) * i);
		if (board == NULL)
			return (1);
		j = -1;
		while (board[++j] < i)
			board[j] = -1;
		count = 0;
		place_queen(board, 0, i, &count);
		printf("total: %d\n", count);
		free(board);
	}
	return (0);
}
