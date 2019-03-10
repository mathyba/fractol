/*
** mlx_motion_hook.c for MiniLibx by Charlie Root
** Login <ol@epitech.net>
**
** Made by Mathyba 
*/


#include "mlx_int.h"

int		mlx_mouse_hook(t_win_list *win, int (*funct)(), void *param)
{
	win->hooks[MotionNotify].hook = funct;
	win->hooks[MotionNotify].param = param;
	win->hooks[MotionNotify].mask = PointerMotionMask;
}	
