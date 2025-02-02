/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsennane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 13:33:58 by hsennane          #+#    #+#             */
/*   Updated: 2025/02/02 00:34:21 by hsennane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t   ft_len(const char *str)
{
        int             i;
        size_t  len;

        i = 0;
        len = 0;
        while (str[i] != '\0')
        {
                len++;
                i++;
        }
        return (len);
}

static void     ft_put_str(const char *str)
{
        int     i;

        i = 0;
        while (str[i] != '\0')
        {
                write (1, &str[i], 1);
                i++;
        }
        return ;
}

int     ft_print_str(const char *str)
{
        if (str == NULL)
                return (write(1, "(null)", 6));
        ft_put_str(str);
        return (ft_len(str));
}
