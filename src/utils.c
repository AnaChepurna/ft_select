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
	}
	return (len);
}