/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 20:08:07 by lginer-m          #+#    #+#             */
/*   Updated: 2024/09/30 21:28:54 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

ft_check_map(int fd)
{
	int bytes_map;
	char	*map;
	
	bytes_map = read(fd, buffer, BUFFER_SIZE);
	if(fd < 0 || bytes_map <= 0)
		return (NULL);
	else{
		bytes_map[i++]
		map[bytes_map] = '\0';
	
			//llamar a la funcion get.. dos veces, una para reservar la memoria en funcion de las líneas que hay, y otra para los caracteres de cada linea
}