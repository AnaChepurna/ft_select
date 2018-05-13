#include "../ft_select.h"

int		get_maxlen(t_list *lst)
{
	int max;
	int	len;

	max = 0;
	while (lst)
	{
		len = ft_strlen((char *)lst->content);
		if (len > max)
			max = len;
		lst = lst->next; 
	}
	return (max);
}

int		is_choosen(t_interface *in, int i)
{
	int 	j;

	j = 0;
	while (j < in->ch_num && in->choosen)
	{
		if ((in->choosen)[j] == i)
			return (1);
		j++;
	}
	return(0);
}