/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:25:49 by kiroussa          #+#    #+#             */
/*   Updated: 2023/11/01 20:11:00 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <ft/io.h>
# include <ft/list.h>
# include <ft/macros.h>
# include <ft/mem.h>
# include <ft/string/parse.h>
# include <ft/string.h>

# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# ifndef PF_FORMAT_SYMBOL
#  define PF_FORMAT_SYMBOL "%" 
# endif // PF_FORMAT_SYMBOL

# ifndef PF_FLAGS
#  define PF_FLAGS "-0 #+"
# endif // PF_FLAGS

# ifndef PF_SPECIFIERS
#  define PF_SPECIFIERS "cspdiuxX%"
# endif // PF_SPECIFIERS

# define PF_LEFT_JUSTIFY	1  // (1 << 0)
# define PF_ZERO_PAD		2  // (1 << 1)
# define PF_SPACE			4  // (1 << 2)
# define PF_HASH			8  // (1 << 3)
# define PF_PLUS			16 // (1 << 4)

typedef struct s_fmt_spec
{
	uint8_t	flags;
	int		width;
	int		precision;

	char	*length;
	char	specifier;

	char	*raw;
}	t_fmt_spec;

typedef struct s_type_formatter
{
	char	*specifier;
	char	*(*parse)(va_list args);
}	t_type_formatter;

int			ft_printf(const char *format, ...);
int			ft_dprintf(int fd, const char *format, ...);
int			ft_vprintf(const char *format, va_list args);
int			ft_vdprintf(int fd, const char *format, va_list args);
int			ft_asprintf(char **str_ptr, const char *format, ...);
int			ft_vasprintf(char **str_ptr, const char *format, va_list args);

TODO char	*ft_formatf(const char *format, ...);
TODO char	*ft_vformatf(const char *format, va_list args);

t_fmt_spec	*ft_parse_spec(const char *format, va_list args);
char		*ft_format_spec(t_fmt_spec *spec, va_list args);

#endif
