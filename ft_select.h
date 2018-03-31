#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "libft/libft.h"
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <signal.h>
# include <termios.h>
# include <dirent.h>
# include <sys/ioctl.h>
# include <termcap.h>
# include <sys/param.h>

/*
**terminal.c
*/
void	init_term(struct termios *old, struct termios *new);
void	set_term(struct termios new);
void	reset_term(struct termios old);


#endif