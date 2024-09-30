/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 19:17:21 by lginer-m          #+#    #+#             */
/*   Updated: 2024/04/03 13:49:51 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 
#include <stdio.h> 

// La función ft_isalnum verifica si el carácter pasado es alfanumérico
int	ft_isalnum(int c)
{
    // La función devuelve 1 (verdadero) si el carácter es una letra minúscula (entre 'a' y 'z'),
    // una letra mayúscula (entre 'A' y 'Z'), o un dígito (entre '0' y '9').
    // De lo contrario, devuelve 0 (falso).
    return ((c >= 'a' && c <= 'z')
        || (c >= 'A' && c <= 'Z')
        || (c >= '0' && c <= '9'));
}
