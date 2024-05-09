/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 21:39:33 by fandre-b          #+#    #+#             */
/*   Updated: 2024/04/27 21:39:33 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_countword(const char *str, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && c == str[i])
			i++;
		if (str[i] && str[i] != c)
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (count);
}

char	**ft_getsplitted(char **matrix, char *str, char c, int size)
{
	int		i;
	int		i_words;

	i_words = 0;
	while (*str && i_words < size)
	{
		i = ft_strchr_idx(str, c);
		if (i >= -1)
		{
			matrix[i_words] = ft_strnjoin(NULL, str, i);
			if (!matrix[i_words])
			{
				while (i_words-- >= 0)
					free(matrix[i_words]);
				free(matrix);
				return (NULL);
			}
			i_words++;
		}
		str = str + i + 1;
	}
	matrix[i_words] = NULL;
	return (matrix);
}

char	**ft_split(char *str, char c)
{
	char	**matrix;
	int		size;

	if (!str)
		return (NULL);
	size = ft_countword(str, c);
	matrix = (char **) malloc (sizeof(char *) * (size + 1));
	if (!matrix)
		return (NULL);
	matrix = ft_getsplitted(matrix, str, c, size);
	return (matrix);
}

void rejoin_quoted_args(char **arg_cmd)
{
	int idx[2];
	int i;
	static char *temp;

	while (*(++arg_cmd) != NULL)
	{
		idx[0] = ft_strpbrk_idx(*arg_cmd, "\"\'");
		if (idx[0] >= 0)
		{
			idx[1] = (*arg_cmd)[idx[0]];
			ft_strshift(&((*arg_cmd)[idx[0]]), 1);
			i = 0;
			while (arg_cmd[i] != NULL && ft_strchr_idx(temp, idx[1]) < 0)
			{
				temp = ft_strnjoin(temp, " ", 1);
				temp = ft_strnjoin(temp, arg_cmd[i], ft_strlen(arg_cmd[i]));
				free(arg_cmd[i++]);
			}
			if (ft_strchr_idx(temp, idx[1]))
				ft_strshift(&temp[ft_strchr_idx(temp, idx[1])], 1);
			*arg_cmd = temp;
			ft_ptrshift((void **)&arg_cmd[1], i - 1);
		}
	}
	return ;
}


// //count words (this is the max value possible)
// //have matrix 2 by n_words
// //interate over the string. at start of word get value
// //end of word get value
// while (str++)
// {
// 	if (str[i] == '\'' || str[i] == '\"')
// 	{
// 		ch = str[i++]; //skip ' or "
// 		word_matric[n][2] = int (ch);
// 		//
// 		while[str[i++] != ch] //find end ' or ""
// 			word_matrix[n][1] = i - 1; // skip ' or "
// 	}
// 	if (str[i] == ' ')
// 		if (word_matrix[n][0] < 0)
// 			word_matrix[n][0] ==
	
// 		if (spec_act == 1 && char_in_string("special char", str[i]))
// 			//preciso de um strcpy especial
// }
// //when find ' get last space possition
// //untill '' add \ to special chars
// //get end '
// //when findinding " get last space possition
// //just coppy as it is
// //get end "
// //close matrix with -1 values

// //use matrix to store the words
// //malloc acording to size of matrix
// //using indexes malloc and copy the words (strnjoin)
// //

// corre tudas as palavras.
// enquanto houver palavras procura padrao
// procura ' ou "
// guarda char a procurar, da shift
// enquanto nao voltar a econtrar da strnjoin de todas as palavras

// equanto palavras
// enquanto existir 

// while(++word + i)
// {
// 	index = charsrch
// 	if have ' or "
// 	{
// 		set ch
// 		shift by 1
// 		while (word + i)!=NULL and (no ch found)
// 		{
// 			temp = strnjoin(temp, word + i)
// 			free(word)
// 			word = word + i;
// 			word + i++ == NULL
// 		ch = srchchar
// 		if
// 			shift
//{"/usr/bin/awk", '/ur/, END, {print, $1}', NULL};
// 			1		 2		3	  4		 	  5


// void rejoin_quoted_args(char **arg_cmd)
// {
// 	int w;
// 	int i;
// 	int idx;
// 	char ch;
// 	char *temp;

// 	w = 0;
// 	i = 0;
// 	temp = NULL;
// 	idx = 0;
// 	while(arg_cmd[w + i] != NULL)
// 	{
// 		if (arg_cmd[w][idx] == '\'' || arg_cmd[w][idx] == '\"')
// 		{
// 			ch = arg_cmd[w][idx];
// 			ft_memshift(&arg_cmd[w][idx], 1);
// 			while(arg_cmd[w + i] != NULL && ft_strchr_index(arg_cmd[w + i], ch) < 0)
// 			{
// 				temp = strnjoin(temp, arg_cmd[w + i], ft_strlen(arg_cmd[w + i]));
// 				free(arg_cmd[w + i]);//free current saved word first
// 				arg_cmd[w + i++] = NULL; //set current to be empty no need tho
// 			}
// 			ft_memshift(&temp[ft_strchr_index(temp, ch)], 1);
// 			arg_cmd[w] = temp;
// 		}
// 		if (ft_strchr_index(arg_cmd[w], ch) < 0 && arg_cmd[w + i][++idx] == '\0')
// 		{//so transfere para o proximo se nao tiver encontrado 
// 			while(arg_cmd[++w + 1]);
// 			{
// 				w++;
// 				i = 0;
// 			}
// 		}
// 	}
// 	return ;
// }//gotta do 2 functions this aint working


// while words
// idx = 

// se ' ou "
// enquanto nao houver passa
// -guarda val
// -limpa
// enquanto i[0] nao houver val em temp 
// junta em temp
// free currente
// limpa temp
// enquanto i[0] + i[1]
// "'

// void junta(char **arg_cmd)
// {
// 	int idx;//
// 	int i;
// 	char *temp;
// 	char ch;

// 	idx = 0;
// 	while (*arg_cmd)
// 	{
// 		if ((*arg_cmd)[idx] == '\'' || (*arg_cmd)[idx] == '\"')
// 		{
// 			ch = (*arg_cmd)[idx];
// 			ft_memshift(&((*arg_cmd)[idx]), 1);
// 			temp = NULL;
// 			i = 0;
// 			while (arg_cmd[i] != NULL && strchr_idx(temp, ch) < 0)
// 			{
// 				temp = strnjoin(temp, arg_cmd[i], ft_strlen(arg_cmd[i]));
// 				free(arg_cmd[i++]);
// 			}
// 			if (ft_strchr_index(temp, ch))
// 				ft_memshift(&temp[ft_strchr_index(temp, ch)], 1);
// 			*arg_cmd = temp;
// 			ft_memshift(&arg_cmd[1], i);
// 		}
// 		if ((*arg_cmd)[idx++] == '\0')
// 		{
// 			arg_cmd++;
// 			idx = 0;
// 		}
// 	}
// 	return ;
// }

