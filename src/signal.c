#include "../ft_select.h"

void	signal_window_handler(int signo)
{
	if (signo == SIGWINCH)
	{
		print_interface(t_interface interface);
		signal(SIGWINCH, signal_window_handler);
	}
}