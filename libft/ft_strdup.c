/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraujo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:19:13 by laraujo           #+#    #+#             */
/*   Updated: 2021/11/09 10:07:06 by laraujo          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*copy;
	int		i;

	copy = 0;
	i = -1;
	copy = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (copy == 0)
		return (0);
	while (s1[++i])
		copy[i] = s1[i];
	copy[i] = '\0';
	return (copy);
}
/*
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() 
{
    const char * original = "The original string.";

    // On duplique la chaîne de caractères initiale.
    char * copy = ft_strdup( original );
    
    // On passe chaque lettre en majuscule.
    char * ptr = copy;
    while( *ptr != '\0' ) {
        *ptr = toupper( *ptr );
        ptr++;
    }
    // On affiche la chaîne original
    printf( "%s\n", original);
    // On affiche la chaîne finale copier
    printf( "%s\n", copy );

    // Sans oublier de libérer l'espace mémoire au final.
    free( copy );

    return 0;
}*/
