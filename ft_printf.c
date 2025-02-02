/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsennane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:10:18 by hsennane          #+#    #+#             */
/*   Updated: 2025/02/02 01:21:27 by hsennane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int      part_flags(const char *format, va_list args)
{
        int     len;

        len = 0;
        if (*format == 'c')
                len += ft_print_char(va_arg(args, int));
        else if (*format == 's')
                len += ft_print_str(va_arg(args, const char *));
        else if (*format == 'p')
                len += ft_print_pointer(va_arg(args, void *));
        else if (*format == 'x')
                len += ft_print_hexa(va_arg(args, unsigned int), 0);
        else if (*format == 'X')
                len += ft_print_hexa(va_arg(args, unsigned int), 1);
        else if (*format == 'd' || *format == 'i')
                len += ft_print_int(va_arg(args, int));
        else if (*format == 'u')
                len += ft_print_unsigned(va_arg(args, unsigned int));
        else if (*format == '%')
                len += ft_print_char(va_arg(args, int));
        return (len);
}

int     ft_printf(const char *format, ...)
{
        int             len;
        va_list args;

        len = 0;
        va_start(args, format);
        if (!format)
                return (len);
        while (*format != '\0')
        {
                if (*format == '%')
                {
                        format++;
                        if (*format == '\0')
                                break ;
                        len += part_flags(format, args);
                }
                else
                        ft_print_char(*format);
                format++;
        }
        va_end(args);
        return (len);
}
