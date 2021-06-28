#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_node {
	int				id;
	int				val;
	int				f;
	int				k;
	struct s_node	*next;
}				t_node;

typedef struct s_temp {
	int				t1;
	int				t2;
	int				t3;
	int				t4;
	int				t5;
	int				t6;
	int				t7;
	int				t8;
	int				t9;
}				t_temp;

typedef struct s_border {
	int				last;
	int				diff;
	int				l_b;
	int				lm_b;
	int				m_b;
	int				mr_b;
	int				r_b;
}				t_border;

typedef struct s_structs {
	int				cnt;
	int				flg_b;
	int				all;
	int				flg_c;
	int				o;
	t_temp			t;
	t_border		x;
	t_node			*a;
	t_node			*b;
	t_node			*tmp1;
	t_node			*tmp2;
}				t_structs;

t_node	*create_node(int set_id, int set_val, int set_b);
void	add_befor_node(t_node **uzel, int set_id, int set_val, int set_b);
void	add_after_node(t_node **uzel, int set_id, int set_val, int set_b);

void	pars_argv(t_structs *s, int argc, char **argv);
void	sort_val_by_pas(t_structs *s, t_node *list, int size);
void	sort_id_by_val(t_structs *s, t_node *list, int size);
void	parsing_input(t_structs *s, t_node **s1, t_node **s2, char *line);

void	swap(t_structs *s, t_node **list);
void	rotate(t_structs *s, t_node **list);
void	rev_rotate(t_structs *s, t_node **list);
void	push(t_structs *s, t_node **list2, t_node **list);

void	swap_double(t_structs *s, t_node **list1, t_node **list2);
void	rotate_double(t_structs *s, t_node **list1, t_node **list2);
void	rev_rotate_double(t_structs *s, t_node **list1, t_node **list2);

void	sort_two(t_structs *s, t_node **s1);
void	sort_three(t_structs *s, t_node **s1);
void	sort_four(t_structs *s, t_node **s1, t_node **s2);
void	sort_five(t_structs *s, t_node **s1, t_node **s2);
void	sort_five_out_s2(t_structs *s, t_node **s1, t_node **s2, size_t cnt);
void	sort_three_four_five(t_structs *s, t_node **s1, t_node **s2);
void	sort_three_four_five_1(t_structs *s, t_node **s1, t_node **s2);
int		sort_three_four_five_2(t_structs *s, t_node **s1, t_node **s2);
void	sort_three_four_five_3(t_structs *s, t_node **s1, t_node **s2);
void	sort_up_to_five(t_structs *s, t_node **s1, t_node **s2);

void	sort_basic(t_structs *s, t_node **s1, t_node **s2, int right);
void	sort_basic_1(t_structs *s, t_node **s1, t_node **s2);
void	sort_basic_2(t_structs *s, t_node **s1, t_node **s2);
void	sort_basic_rev(t_structs *s, t_node **s1, t_node **s2, int right);
void	sort_basic_rev_1(t_structs *s, t_node **s1, t_node **s2);
void	sort_basic_rev_2(t_structs *s, t_node **s1, t_node **s2);
void	defining_border_1(t_structs *s, int e_id);
void	defining_border_2(t_structs	*s, int e_id);

int		counter_befor_flags(t_structs *s, t_node **s1);
int		search_flags(t_structs *s, t_node **s1);
int		orderliness(t_structs *s, t_node **s1, int cnt_s1);
void	zero_k_pos(t_node *list);

void	output_result(t_structs *s);

#endif