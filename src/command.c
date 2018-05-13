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

int		manage_choice(t_interface *in)
{
	int		*buf;
	int		i;
	int		j;

	buf = in->choosen;
	i = 0;
	j = -1;
	if (is_choosen(in, in->carriage))
	{
		in->choosen = (int *)malloc(sizeof(int) * --(in->ch_num));
		while (++j <= in->ch_num)
			if (buf[j] != in->carriage)
				(in->choosen)[i++] = buf[j];
	}
	else
	{
		in->choosen = (int *)malloc(sizeof(int) * ++(in->ch_num));
		while (++j < in->ch_num - 1)
			(in->choosen)[j] = buf[j];
		(in->choosen)[j] = in->carriage;
	}
	free(buf);
	return (1);
}

char	*get_ret(t_interface *in)
{
	char	*ret;
	char	*buf;
	char	**args;
	int		i;

	args = ft_lsttoarr(in->args);
	ret = ft_strdup("");
	i = -1;
	while (++i < in->ch_num)
	{
		buf = ret;
		ret = ft_strjoin(buf, args[(in->choosen)[i]]);
		free(buf);
		if (i < in->ch_num - 1)
		{
			buf = ret;
			ret = ft_strjoin(buf, " ");
			free(buf);
		}
	}
	ft_arrfree(&args);
	return (ret);
}

int		make_return(t_interface *in)
{
	char	*ret;

	ret = get_ret(in);
	manage_term(RE_SET);
	ft_putstr_fd(ret, 1);
	free(ret);
	exit(0);
	return (0);
}