/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:14:30 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/07/18 14:20:15 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

//# include <stdio.h> //delete
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...)
	__attribute__((format(printf, 1, 2)));
int	ft_putchar(char c);
int	ft_putstr(char *str);

#endif
