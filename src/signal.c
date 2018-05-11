#include "../ft_select.h"

void	signal_window_handler(int signo)
{
	if (signo == SIGWINCH)
	{
		manage_interface();
		signal(SIGWINCH, signal_window_handler);
	}
}