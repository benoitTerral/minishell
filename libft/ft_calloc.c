/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraujo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:40:49 by laraujo           #+#    #+#             */
/*   Updated: 2021/11/09 10:09:45 by laraujo          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	int		i;

	i = 0;
	ptr = 0;
	ptr = malloc((size * count));
	if (ptr == 0)
		return (0);
	ft_bzero(ptr, (count * size));
	return (ptr);
}
/*
#include <stdio.h>          
#include <stdlib.h>
#include <assert.h>

#define INT_NUMBER 10

int main() {
    
    int i;
    int * pointer = (int *) ft_calloc( INT_NUMBER, sizeof(int) );

    // Un petit test sur le bon fonctionnement de calloc 
    assert( pointer != NULL );

	for (i=0; i<INT_NUMBER; i++ ) {
        printf( "%d ", pointer[i] );
    }
    printf( "\n" );

    // Le dernier élément du tableau ne sera pas affecté par la 
    // boucle mais n'oubliez pas que calloc initialise de toute 
    // façon à 0 chaque octet. 
    for ( i=0; i<INT_NUMBER-1; i++ ) {
        pointer[i] = i;
    }

    // On affiche le contenu du tableau d'entier 
    // Ce qui donne : 0 1 2 3 4 5 6 7 8 0 
    for (i=0; i<INT_NUMBER; i++ ) {
        printf( "%d ", pointer[i] );
    }
    printf( "\n" );

    // On libère le bloc de mémoire alloué dynamiquement
    free( pointer );

    return 0;
}*/
