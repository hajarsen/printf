/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsennane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:23:38 by hsennane          #+#    #+#             */
/*   Updated: 2025/02/02 00:21:33 by hsennane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t   ft_len(unsigned int n)
{
        size_t  len;

        len = 0;
        if (n == 0)
                len++;
        while (n != 0)
        {
                len ++;
                n /= 16;
        }
        return (len);
}

static void     ft_put_hexa(unsigned int n, int x)
{
        char    *base_lower;
        char    *base_upper;

        base_lower = "0123456789abcdef";
        base_upper = "0123456789ABCDEF";
        if (n >= 16)
                ft_put_hexa(n / 16, x);
        if (x == 0)
                write (1, &base_lower[n % 16], 1);
        else
                write (1, &base_upper[n % 16], 1);
        return ;
}

int     ft_print_hexa(unsigned int n, int x)
{
        int     len;

        len = ft_len(n);
        ft_put_hexa(n, x);
        return (len);
}
