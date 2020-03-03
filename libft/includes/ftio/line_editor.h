/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_editor.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 07:12:23 by abaurens          #+#    #+#             */
/*   Updated: 2019/12/03 04:14:55 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_EDITOR_H
# define LINE_EDITOR_H

# include <term.h>
# include <termios.h>
# include <inttypes.h>
# include <sys/ioctl.h>

# define MAX_CMD	4096

typedef char	t_cmdline[MAX_CMD + 1];

typedef struct	s_escape_dispatch
{
	char		c;
	char		(*func)(const int fd, t_cmdline buf, uint32_t *i);
}				t_escape_dispatch;

typedef struct termios	t_term;
typedef struct winsize	t_winsize;

char			*ft_readline_(const int fd, const char *prompt);

int				init_term(t_term *term);
char			line_editor_reader(const int fd, char **ret);
char			esc_sequence(const int fd, t_cmdline buf, uint32_t *i);

char			esc_up_arrow(const int fd, t_cmdline buf, uint32_t *i);
char			esc_down_arrow(const int fd, t_cmdline buf, uint32_t *i);
char			esc_left_arrow(const int fd, t_cmdline buf, uint32_t *i);
char			esc_right_arrow(const int fd, t_cmdline buf, uint32_t *i);
char			esc_end_key(const int fd, t_cmdline buf, uint32_t *i);
char			esc_begin_key(const int fd, t_cmdline buf, uint32_t *i);

#endif
