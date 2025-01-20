/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 21:00:03 by mpapin            #+#    #+#             */
/*   Updated: 2025/01/19 21:00:03 by mpapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    cmd(char *argv)
{
    char **cmd;
    int i = 0;

    cmd = ft_split(argv, ' ');
    while (cmd[i] != NULL)
    {
        printf("%s", cmd[i]);
        i++;
    }
    return;
}

int main(int argc, char **argv)
{
    if (argc != 5)
        return(1);
    cmd(argv[2]);
}