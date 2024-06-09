/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abamksa <abamksa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 09:22:50 by abamksa           #+#    #+#             */
/*   Updated: 2024/06/06 09:27:38 by abamksa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				content;
	int				index;
	struct s_stack	*next;

}					t_stack;

void				sort_algo(t_stack **a, t_stack **b, int len, int range);
int					find_max(t_stack *stack);
int					find_min(t_stack *stack);
int					find_next(t_stack *stack, int size);
int					find_max_index(t_stack *stack, int max);
int					find_min_index(t_stack *stack, int min);
void				error_message(void);
int					check_sort(t_stack *stack);
void				sort_min(t_stack **a, t_stack **b);
void				sort_stack(t_stack **a);
t_stack				*ft_lstnew(int content);
int					ft_lstsize(t_stack *lst);
t_stack				*ft_lastlst(t_stack *lst);
void				ft_lstclear(t_stack *lst);
int					count_arguments(char **av);
size_t				ft_strlen(const char *str);
t_stack				*ft_beflastlst(t_stack *lst);
void				ft_swap(int *arr1, int *arr2);
void				check_args(char **av, int size);
char				**ft_split(char const *s, char c);
void				set_index(t_stack *stack, int arr[]);
char				*ft_strjoin(char const *s1, char const *s2);
void				stack_array(t_stack *a, int arr[], int len);
void				ft_lstadd_back(t_stack **lst, t_stack *node);
int					ft_atoi(char **av, const char *nptr, int *arr);
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
