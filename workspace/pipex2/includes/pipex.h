/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 11:18:01 by fandre-b          #+#    #+#             */
/*   Updated: 2024/04/26 11:18:01 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdlib.h>
# include <errno.h>
# include <sys/wait.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

typedef struct s_info
{
	int		fd[2];
	int		exe_fd[2];
	int		error;
	int		here_doc;
	char	***cmd;
	char	**envp;
	char	*limiter;
}				t_info;

int		main(int argc, char **argv, char **envp);
int		pipe_arg_cmd(t_info *info);
void	free_info(t_info *info);
////extract info
int		parcel_argv(int argc, char **argv, t_info *info);
void	rejoin_quoted_args(char **arg_cmd);
void	join_rm_quotes(char **arg_cmd, char ch, int idx);
char	*get_path(char *cmd, char **envp);
int		parcel_open_fd(int argc, char **argv, t_info *info);
int		input_gnl(t_info *info);
////run program ->TODO restructure passing args TO MANY ARGS
int		execute_command(t_info *info, char **cmd);
void	exe_cmd_child(t_info *info, int *fd_error, char **cmd);
int		exe_cmd_parent(t_info *info, int *fd_error);
int		close_all(void);
////big utils
int		get_next_line(int fd, char **new_str);
char	**ft_split(char *str, char c);
////libft utils
//split utils
char	*ft_clearbuffer(void *str, int size);
int		ft_countword(const char *str, char c);
//string utils
int		ft_strlen(char *s);
char	*ft_strstr(const char *big, const char *little);
char	*ft_strnjoin(char *old_str, char *str_add, int size);
int		ft_strchr_idx(char *str, char ch);
int		ft_strpbrk_idx(char *str, char *chrs);
void	*ft_strshift(void *ptr, int n_shift);
//pointer utils
void	**ft_ptrshift(void **ptr, int n_shift);
//debug utils TODO REMOVE
void	print_struct(char *str, t_info *info);
void	print_cmds(char *str, char **matrix);

#endif