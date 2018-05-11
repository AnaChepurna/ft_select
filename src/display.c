#include "../ft_select.h"

void	display_interface(t_interface in)
{
	char	**args;
	int		i;
	int		x;
	int		y;

	args = ft_lsttoarr(in.args);
	y = 0;
	i = 0;
	while (i < in.len && y < in.lines)
	{
		x = 0;
		while (i < in.len && x < in.columnes)
		{
			i = y + x * in.lines;
			displa
			x++;
		}
		y++;
	}
	ft_arrfree(&args);
}