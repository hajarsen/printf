/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsennane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:39:15 by hsennane          #+#    #+#             */
/*   Updated: 2025/02/02 00:31:35 by hsennane         ###   ########.fr       */
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
                len++;
                n /= 10;
        }
        return (len);
}

static void     ft_put_nbr(unsigned int n)
{
        char    *base;

        base = "0123456789";
        if (n >= 10)
                ft_put_nbr(n / 10);
        write (1, &base[n % 10], 1);
        return ;
}

int     ft_print_unsigned(unsigned int n)
{
        int     len;

        len = ft_len(n);
        ft_put_nbr(n);
        return (len);
}
