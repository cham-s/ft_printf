#incude "ft_printf.h"

void	debug_fmt(t_formater *fmt)
{
	if (fmt->flag)
	{
		printf("[DEBUG flag] The flag is: ");
		if (fmt->flag & F_MINUS)
			printf("- ");
		if (fmt->flag & F_PLUS)
			printf("+ ");
		if (fmt->flag & F_BLANK)
			printf("blank ");
		if (fmt->flag & F_ZERO)
			printf("0 ");
		if (fmt->flag & F_SHARP)
			printf("# ");
		printf("\n");
	}
	if (fmt->width)
		printf("[DEBUG width] The width is: %d\n", fmt->width);
	if (fmt->length)
		printf("[DEBUG length] The precision length is: %d\n", fmt->length);
	if (fmt->modifier)
	{
		printf("[DEBUG modifier] The modifier is: ");
		if (fmt->modifier == F_SH)
			printf("h ");
		if (fmt->modifier == F_SL)
			printf("l ");
		if (fmt->modifier == F_DL)
			printf("ll ");
		if (fmt->modifier == F_DH)
			printf("hh ");
		if (fmt->modifier == F_Z)
			printf("z ");
		printf("\n");
	}
	if (fmt->type)
	{
		printf("[DEBUG type] The type is: ");
		if (fmt->type == T_S)
			printf("s");
		else if (fmt->type == T_GS)
			printf("S");
		else if (fmt->type == T_GS)
			printf("S");
		else if (fmt->type == T_D)
			printf("d");
		else if (fmt->type == T_GD)
			printf("GD");
		else if (fmt->type == T_I)
			printf("i");
		else if (fmt->type == T_O)
			printf("o");
		else if (fmt->type == T_GO)
			printf("O");
		else if (fmt->type == T_U)
			printf("u");
		else if (fmt->type == T_GU)
			printf("U");
		else if (fmt->type == T_X)
			printf("x");
		else if (fmt->type == T_GX)
			printf("X");
		else if (fmt->type == T_C)
			printf("c");
		else if (fmt->type == T_GC)
			printf("C");
		else if (fmt->type == T_EE)
			printf("eE");
		else if (fmt->type == T_FF)
			printf("fF");
		else if (fmt->type == T_GG)
			printf("gG");
		else if (fmt->type == T_AA)
			printf("aA");
		else if (fmt->type == T_N)
			printf("n");
		else if (fmt->type == T_P)
			printf("p");
		printf("\n");
	}
}
