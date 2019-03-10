/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuckens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 14:48:06 by emuckens          #+#    #+#             */
/*   Updated: 2018/06/26 12:15:48 by emuckens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft.h"
# include "mlx.h"
# include <pthread.h>

# define ENV					t_environment
# define WIN_TITLE				"FRACTOL"
# define WIN_W					1100
# define WIN_H					800
# define NB_THREADS				8
# define MENU_START 			800
# define MENU_END				1100
# define COL_BCKGRND			0x1F1147
# define COL_SELECT				0xA0DB8E
# define SCALE					1.5

/*
 ** USER INPUT KEY CODES
*/
# define KEY_ESC				53
# define KEY_LF					123
# define KEY_RT					124
# define KEY_UP					126
# define KEY_DW					125
# define KEY_ADD				69
# define KEY_SUB				78
# define KEY_ZMIN				24
# define KEY_ZMOUT				27
# define KEY_RED				15
# define KEY_GREEN				5
# define KEY_BLUE				11
# define KEY_RED_ADD			17
# define KEY_GREEN_ADD			4
# define KEY_BLUE_ADD			45
# define KEY_COLOR_INV			8
# define KEY_COLOR_ROTATEUP 	116
# define KEY_COLOR_ROTATEDW 	121
# define KEY_PAUSE				35
# define KEY_RESET				50
# define KEY_DIR				34
# define KEY_THEME0				18
# define KEY_THEME1				19
# define KEY_MULTI				46

/*
** MENU TEXT
*/
# define R1						"R"
# define R2						"ED"
# define G1						"G"
# define G2						"REEN"
# define B1						"B"
# define B2						"LUE"
# define M1						"MOVE: "
# define M2						"<- | -> |"
# define C1						"FULL COLOR THEME"
# define C2						"STRIPPY THEME"
# define C3						"INSIDE OUT"
# define I1						"MAX ITERATIONS +/-"
# define Z1						"ZOOM: "
# define Z2						"CLICK OR SCROLL"
# define RS						"RESET"
# define F1						"MANDELBROT"
# define F2						"JULIA"
# define F3						"BARNSLEY'S FERN"
# define F4						"BURNING SHIP"
# define F5						"TRICORN"
# define F6						"SPIRAL"
# define F7						"GEO NERD"
# define P1						"P"
# define P2						"ause"

typedef struct	s_graphics
{
	void			*win;
	void			*mlx;
	void			*img;
	void			*coordimg;
	int				size;
	int				bpp;
	int				endian;
	char			*ptr;
	char			*coordptr;
}				t_graphics;

typedef struct	s_userinput
{
	t_4fvect		focus;
	t_4fvect		center;
	int				movex;
	int				movey;
	int				fractal;
	int				pause;
	int				iteration;
	int				color_inv;
	int				dir;
	int				theme;
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
	char			str[6][10];
}				t_userinput;

typedef	struct	s_environment
{
	pthread_t		thr[NB_THREADS];
	t_graphics		mlxvar;
	t_userinput		input;
	char			pad[4];
	t_4fvect		cmplx;
	t_4fvect		c;
	t_4fvect		constc;
	t_4fvect		offset;
	int				color;
	int				clr[7];
	float			zoom;
	float			zoominv;
	int				index;
	int				iteration;
	int				ppmove;
}				t_environment;

enum			e_color_schemes
{
	BLOCK, STRIPPY
};

enum			e_fractals
{
	MAN, JUL, BAR, BUR, TRI, SPI, GEO
};

enum			e_input_strings
{
	X, Y, ITE, R, G, B
};

/*
** Output
*/
void			ft_display(ENV *e);
void			ft_display_menu(ENV *e);
int				ft_getcolor(ENV *e, int iter);
void			ft_update_display_strings(ENV *e);

/*
** User interaction
*/
int				ft_dealkey(int key, void *param);
int				ft_dealbutton(int button, int x, int y, void *param);
int				ft_motionhook(int x, int y, void *param);
void			ft_reset(ENV *e);

/*
** Env
*/
int				ft_getenv(ENV *e);

/*
** Window
*/
int				ft_initwin(ENV *e);
int				ft_close_window(ENV *e);

/*
** Image
*/
int				ft_getimg(ENV *e);
void			ft_fill_bckgrnd(ENV *e, int end_row, int option);
void			ft_put_to_img(ENV *e, size_t row, size_t col, int color);
void			ft_putcoord_to_img(ENV *e, size_t row, size_t col, int color);

/*
** Fractals
*/
int				ft_select_fractal(ENV *e, int y, char *arg);
void			ft_fractalize(ENV *e);
int				ft_mandelbrot(ENV *arg, int row, int col);
int				ft_tricorn(ENV *arg, int row, int col);
int				ft_julia(ENV *arg, int row, int col);
int				ft_geonerd(ENV *arg, int row, int col);
int				ft_spiral(ENV *arg, int row, int col);
int				ft_barnsley(ENV *arg, int row, int col);
int				ft_burningship(ENV *arg, int row, int col);

/*
** Utils
*/
void			ft_itoa_cust(int n, char (*str)[10]);

#endif
