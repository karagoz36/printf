/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 13:33:06 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/07/18 14:20:20 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//#include <limits.h>

static int	ft_ptr(unsigned long n, char *base, int base_n, int s)
{
	int	i;

	i = 0;
	if (s == 1)
	{
		if (!n)
		{
			ft_putstr("(nil)");
			return (5);
		}
		else
			ft_putstr("0x");
		i = 2;
	}
	if (n / base_n > 0)
		i += ft_ptr(n / base_n, base, base_n, 0);
	ft_putchar(base[n % base_n]);
	i++;
	return (i);
}

static int	ft_p_base(long int n, char *base, int base_n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		i++;
	}
	if (n / base_n > 0)
		i += ft_p_base(n / base_n, base, base_n);
	ft_putchar(base[n % base_n]);
	i++;
	return (i);
}

static int	ft_flag(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'p')
		return (ft_ptr(va_arg(args, unsigned long), "0123456789abcdef", 16, 1));
	else if (c == 'd' || c == 'i')
		return (ft_p_base(va_arg(args, int), "0123456789", 10));
	else if (c == 'u')
		return (ft_p_base(va_arg(args, unsigned int), "0123456789", 10));
	else if (c == 'x')
		return (ft_p_base(va_arg(args, unsigned int), "0123456789abcdef", 16));
	else if (c == 'X')
		return (ft_p_base(va_arg(args, unsigned int), "0123456789ABCDEF", 16));
	else if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		pc_ctr;
	va_list	args;

	pc_ctr = 0;
	i = 0;
	if (!str)
		return (-1);
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && (str[i + 1]))
		{
			pc_ctr += ft_flag(str[i + 1], args);
			i++;
		}
		else
		{
			write(1, &str[i], 1);
			pc_ctr++;
		}
		i++;
	}
	va_end(args);
	return (pc_ctr);
}

//int	main(void)
//{
// 	int		n;
// 	char	c;

// 	c = 'a';

// 	printf("MOI:\n");
// 	n = ft_printf("%p %XLivre1%c %c\n", &c, -33, c, c);
// 	printf("\nPCN:%d\n", n);
// 	ft_printf("\n%p\n", NULL);

// 	printf("\nMAC:\n");
// 	n = printf("%p %XLivre1%c %c\n", &c, -33, c, c);
// 	printf("\nPCN:%d\n", n);
// 	printf("\n%p\n", NULL);

// 	printf("//////\n");
// 	printf("printf:%d\n", printf("string:%s\n", "string"));
// 	ft_printf("printf:%d\n", ft_printf("string:%s\n", "string"));
// 	printf("//////\n");

// 	//printf(" %p %p\n", LONG_MIN, LONG_MAX);
// 	// printf(" %p %p\n\n", ULONG_MAX, -ULONG_MAX);
// 	//ft_printf(" %p %p\n", LONG_MIN, LONG_MAX);
// 	// ft_printf(" %p %p\n\n", ULONG_MAX, -ULONG_MAX);

// 	//printf("%d\n", "blabla");
// 	//ft_printf("%d\n", "blabla");
//	printf("%d\n", printf(0));
//	printf("%d\n", ft_printf(0));

//	return (0);
//}
