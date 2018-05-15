/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achepurn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 14:55:58 by achepurn          #+#    #+#             */
/*   Updated: 2018/05/15 14:56:03 by achepurn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_select.h"

void		search_carriage(char *search, t_interface *in)
{
	char	**args;
	int		i;
	int		len;

	args = ft_lsttoarr(in->args);
	i = -1;
	len = ft_strlen(search);
	while (++i < in->len)
	{
		if (ft_strnequ(search, args[i], len))
		{
			in->carriage = i;
			ft_arrfree(&args);
			return ;
		}
	}
	manage_search(NO, NULL, NULL);
	ft_arrfree(&args);
}

void		manage_search(int mode, char *key, t_interface *in)
{
	static char *search = NULL;
	char		*buf;

	if (mode == NO)
	{
		if (search)
			free(search);
		search = NULL;
	}
	else if (mode == YES)
	{
		if (!search)
			search = ft_strdup("");
		buf = search;
		search = ft_strjoin(buf, key);
		free(buf);
		search_carriage(search, in);
	}
}
