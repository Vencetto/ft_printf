/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 15:17:25 by vzomber           #+#    #+#             */
/*   Updated: 2018/02/02 15:17:28 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		f_unction(char *str_final, char **line, t_list **node, int fd)
{
	t_list		*element;
	size_t		i;
	int			jv[2];
	char		*g;
	char		*p;

	i = 0;
	while (str_final[i] != '\n' && str_final[i] != '\0')
		i++;
	*line = ft_strnew((size_t)i);
	jv[0] = i;
	while (--jv[0] > -1)
		(*line)[jv[0]] = str_final[jv[0]];
	g = ft_strnew(ft_strlen(str_final) - i);
	jv[1] = -1;
	while ((++jv[1] + i) < ft_strlen(str_final))
		g[jv[1]] = str_final[jv[1] + i + 1];
	free(str_final);
	element = *node;
	while (element->content_size != (size_t)fd)
		element = element->next;
	p = element->content;
	element->content = g;
	free(p);
	return (1);
}

t_list	*make_new(int fd, t_list **node)
{
	t_list	*new_el;

	new_el = (t_list *)malloc(sizeof(t_list));
	new_el->content = ft_strnew(0);
	new_el->content_size = (size_t)fd;
	new_el->next = *node;
	return (new_el);
}

int		fd_searcher(int fd, char **tmp_buff, t_list **node)
{
	char	*str;
	t_list	*list_iter;

	if (!(*node))
		return ((*node = make_new(fd, node)) ? 0 : 1);
	list_iter = *node;
	while (list_iter && list_iter->content_size != (size_t)fd)
		list_iter = list_iter->next;
	if (!list_iter)
		return ((*node = make_new(fd, node)) ? 0 : 1);
	if (list_iter->content == NULL || ft_strlen(list_iter->content) == 0)
		return (0);
	else
	{
		str = *tmp_buff;
		*tmp_buff = ft_strjoin(list_iter->content, *tmp_buff);
		ft_bzero(list_iter->content, ft_strlen(list_iter->content));
		free(str);
	}
	return (1);
}

int		ft_crutch(char **str, char *buff, int *ch)
{
	char	*str_tmp;

	*ch += 1;
	str_tmp = *str;
	*str = ft_strjoin(*str, buff);
	free(str_tmp);
	ft_bzero(buff, ft_strlen(buff));
	if (ft_strchr(*str, '\n'))
		return (1);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	char			*buff;
	static t_list	*node = NULL;
	int				ch;
	char			*str_final;

	CHECKER((buff = ft_strnew(BUFF_SIZE)));
	if (read(fd, buff, 0) < 0 || fd < 0 || !line || (ch = 0) || BUFF_SIZE < 0)
		return (-1);
	CHECKER((str_final = ft_strnew(1)));
	ch += fd_searcher(fd, &str_final, &node);
	while (read(fd, buff, BUFF_SIZE))
	{
		if (ft_crutch(&str_final, buff, &ch))
			break ;
	}
	free(buff);
	if (!ch)
	{
		free(str_final);
		return (0);
	}
	return (f_unction(str_final, line, &node, fd));
}
