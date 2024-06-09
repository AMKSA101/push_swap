/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abamksa <abamksa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:06:21 by abamksa           #+#    #+#             */
/*   Updated: 2024/06/09 11:06:57 by abamksa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 3

typedef struct s_stack
{
	int				content;
	int				index;
	struct s_stack	*next;

}					t_stack;

char				*get_next_line(int fd);
void				ft_check_space(char **av);
int					check_sort(t_stack *stack);
size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *src);
char				*ft_strchr(const char *str, int c);
char				**ft_split(char const *s, char c);
int					ft_strcmp(const char *s1, const char *s2);
void				error_message(void);
size_t				ft_strlen(const char *str);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_joinstr(char *buffer, const char *content);
void				ft_swap(int *arr1, int *arr2);
void				stack_array(t_stack *a, int arr[], int len);
void				stack_init(t_stack **a, char **av, int size);
void				sort_stack(t_stack **a);
int					ft_atoi(char **av, const char *nptr, int *arr);
t_stack				*ft_beflastlst(t_stack *lst);
int					count_arguments(char **av);
void				set_index(t_stack *stack, int arr[]);
void				check_args(char **av, int size);
void				ft_lstclear(t_stack *lst);
void				ft_lstadd_back(t_stack **lst, t_stack *node);
t_stack				*ft_lastlst(t_stack *lst);
t_stack				*ft_lstnew(int content);
int					ft_lstsize(t_stack *lst);
void				sa(t_stack **stack_a, int flag);
void				sb(t_stack **stack_b, int flag);
void				ss(t_stack **stack_a, t_stack **s_tack_b, int flag);
void				pa(t_stack **stack_a, t_stack **stack_b, int flag);
void				pb(t_stack **stack_a, t_stack **stack_b, int flag);
void				ra(t_stack **stack, int flag);
void				rb(t_stack **stack, int flag);
void				rr(t_stack **stack_a, t_stack **stack_b, int flag);
void				rra(t_stack **stack, int flag);
void				rrb(t_stack **stack, int flag);
void				rrr(t_stack **stack_a, t_stack **stack_b, int flag);

#endif
