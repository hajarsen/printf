/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsennane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 14:10:15 by hsennane          #+#    #+#             */
/*   Updated: 2025/02/02 00:28:30 by hsennane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t   ft_len(int n)
{
        size_t  len;

        len = 0;
        if (n <= 0)
                len++;
        while (n != 0)
        {
                len++;
                n /= 10;
        }
        return (len);
}

static void     ft_put_nbr(int n)
{
        char    *base;

        base = "0123456789";
        if (n == -2147483648)
        {
                write (1, "-2147483648", 11);
                return ;
        }
        if (n < 0)
        {
                write (1, "-", 1);
                n *= -1;
        }
        if (n >= 10)
                ft_put_nbr(n / 10);
        write (1, &base[n % 10], 1);
        return ;
}

int     ft_print_int(int n)
{
        int     len;

        len = ft_len(n);
        ft_put_nbr(n);
        return (len);
}
