#include "../ft_select.h"

int		command_carriage(t_interface *in, int mode)
{
	if (mode == DOWN)
		in->carriage++;
	else if (mode == UP)
		in->carriage++;
	else if (mode == BACK)
		in->carriage -= in->lines;
	else if (mode == FORWARD)
		in->carriage += in->lines;
	if (in->carriage >= in->len)
		in->carriage -= in->lines;
	if (in->carriage < 0)
		in->carriage = in->len - in->carriage;
	return (1);
}