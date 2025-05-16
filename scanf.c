
#include <stdarg.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

/*ft_scanf
- handle s, d and c.
- dont handle options *, m and '
- dont handle max field width
- dont handle types mdifior vars
- dont handle conversions beginning with %n$

Allowed:isspace, isdigit, va_start, va_arg, va_copy, va_end, 
fgetc, ungetc, ferror, feof, stdi
*/

int	skip_input_space()
{
	int	i;

	while (1)
	{
		i = fgetc(stdin);
		if (i == EOF)
			return (-1);
		if (!isspace(i))
		{
			ungetc(i, stdin);
			return (0);
		}
	}
}

int	scan_char(char *c, int *result)
{
	int	i;

	i = fgetc(stdin);
	if (i == EOF)
		return (-1);
	*c = (char)i;
	(*result)++;
	return (0);
}

int	scan_int(int *n, int *result)
{
	int	first;
	int	i;
	int sign;

	first = 0;
	sign = 1;
	i = fgetc(stdin);
	if (i == EOF)
		return (-1);
	if ((char)i == '+')
	{
		i = fgetc(stdin);
		if (i == EOF)
			return (-1);
	}
	else if ((char)i == '-')
	{
		sign = -1;
		i = fgetc(stdin);
		if (i == EOF)
			return (-1);
	}
	while (isdigit(i))
	{
		if (first == 0)
		{
			first = 1;
			*n = i - '0';
		}
		else
		{
			*n *= 10;
			*n += i - '0';
		}
		i = fgetc(stdin);
		if (i == EOF)
			return (-1);
	}
	if (i != EOF)
		ungetc(i, stdin);
	if (first == 0)
		return 0;
	*n *= sign;
	(*result)++;
	return (0);
}

int	scan_string(char *c, int *result)
{
	int	i;
	int index;
	
	index = 0;
	while(1)
	{
		i = fgetc(stdin);
		if (i == EOF)
			return (-1);
		if (isspace(i))
		{
			ungetc(i, stdin);
			break;
		}
		c[index] = (char)i;
		index++;

	}
	c[index] = '\0';
	(*result)++;
	return (0);
}

int receive_input(const char *format, va_list ap, int *result)
{
	switch (*format)
	{
		case 'c':
			return (scan_char(va_arg(ap, char *), result));
		case 'd':
			skip_input_space();
			return (scan_int(va_arg(ap, int *), result));
		case 's':
			skip_input_space();
			return (scan_string(va_arg(ap, char *), result));
		default:
			return (-1);
	}
	return (0);
}

int ft_scanf(const char *format, ...)
{
	int	i = 0;
	int	result = 0;
	va_list	ap;
	
	va_start(ap,format);
	while (format[i] != '\0')
	{
		if (isspace(format[i])) {
			skip_input_space();
			i++;
			continue;
		}
		if (format[i] == '%')
		{
			i++;
			if (receive_input(&(format[i]), ap, &result) == -1)
				break;
		}
		i++;
	}
	va_end(ap);
	return (result);
}

int main(void)
{
	char	a;
	char	b;
	char	c;
	char	x;
	char	y;
	char	z;
	int		a1;
	int		b1;
	int		c1;
	int		x1;
	int		y1;
	int		z1;
	char	*a2;
	char	*b2;
	char	*c2;
	char	*x2;
	char	*y2;
	char	*z2;

	int		result;
	int		result1;

	// a2 = malloc(sizeof(char) * 10);
	// b2 = malloc(sizeof(char) * 10);
	// c2 = malloc(sizeof(char) * 10);
	// x2 = malloc(sizeof(char) * 10);
	// y2 = malloc(sizeof(char) * 10);
	// z2 = malloc(sizeof(char) * 10);

	// result1 = ft_scanf("%c %c %c", &x, &y, &z);
	// printf("New: %c %c %c %d\n", x, y, z, result1);
	// result = scanf("%c %c %c", &a, &b, &c);
	// printf("Ori: %c %c %c %d\n", a, b, c, result);

	// result = scanf("%s %s %s", a2, b2, c2);
	// printf("Ori: %s %s %s %d\n", a2, b2, c2, result);
	// result1 = ft_scanf("%s %s %s", x2, y2, z2);
	// printf("New: %s %s %s %d\n", x2, y2, z2, result1);
	// result = scanf("%d%d%d", &a1, &b1, &c1);
	// printf("Ori: %d %d %d %d\n", a1, b1, c1, result);
	// result1 = ft_scanf("%d%d%d", &x1, &y1, &z1);
	// printf("New: %d %d %d %d\n", x1, y1, z1, result1);
	return (0);
}
