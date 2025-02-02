/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsennane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:41:43 by hsennane          #+#    #+#             */
/*   Updated: 2025/02/02 01:27:37 by hsennane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t   ft_len(unsigned long long n)
{
        size_t  len;

        len = 0;
        while (n != 0)
        {
                len++;
                n /= 16;
        }
        return (len);
}

static void     ft_put_pointer(unsigned long long n)
{
        char    *base;

        base = "0123456789abcdef";
        if (n >= 16)
                ft_put_pointer(n / 16);
        write (1, &base[n % 16], 1);
        return ;
}

int     ft_print_pointer(void *adress)
{
        int     len;

        if (adress == NULL)
                return (write (1, "(nil)", 5));
        write (1, "0x", 2);
        len = ft_len((unsigned long long) adress) + 2;
        ft_put_pointer((unsigned long long) adress);
        return (len);
}
