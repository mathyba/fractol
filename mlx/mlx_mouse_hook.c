/*
** mlx_mouse_hook.c for MiniLibx
**
** Made by Charlie Root
** Login <ol@epitech.net>
*/

#include "mlx_int.h"
#include "../includes/X.h"
//#include "mlx_int.h"

int		mlx_mouse_hook(t_win_list *win, int (*funct)(), void *param)
{
	win->hooks[ButtonPress].hook = funct;
	win->hooks[ButtonPress].param = param;
	win->hooks[ButtonPress].mask = ButtonPressMask;
}	
