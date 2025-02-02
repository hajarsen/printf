/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsennane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 13:58:50 by hsennane          #+#    #+#             */
/*   Updated: 2025/02/02 01:22:47 by hsennane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int     ft_print_str(const char *str);
int     ft_print_int(int n);
int     ft_print_unsigned(unsigned int n);
int     ft_print_hexa(unsigned int n, int x);
int     ft_print_pointer(void *adress);
int     ft_print_char(char c);
int     ft_printf(const char *format, ...);
#endif
