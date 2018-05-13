#include "../ft_select.h"

int		command_carriage(t_interface *in, int mode)
{
	if (mode == DOWN)
	{
		in->carriage++;
		if (in->carriage == in->len)
			in->carriage = 0;
	}
	else if (mode == UP)
	{
		in->carriage--;
		if (in->carriage == -1)
			in->carriage = in->len - 1;
	}
	else if (mode == BACK)
	{
		if (in->carriage < in->lines)
			while (in->carriage < in->len)
				in->carriage += in->lines;
		in->carriage -= in->lines;
	}
	else if (mode == FORWARD)
		in->carriage += in->lines;
	if (in->carriage >= in->len)
		while (in->carriage >= in->lines)
			in->carriage -= in->lines;
	return (1);
}