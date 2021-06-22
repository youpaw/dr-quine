#include <stdio.h>
#define N_LINES 40
#define SRC_LINE 9
/*
	Program source code
*/
char	g_src_code[N_LINES][51] = {
	{"#include <stdio.h>"},
	{"#define N_LINES 41"},
	{"#define SRC_LINE 9"},
	{"/*"},
	{"	Program source code"},
	{"*/"},
	{"char	g_src_code[N_LINES][51] = {"},
	{"};"},
	{""},
	{"static void	print_esc(char *s)"},
	{"{"},
	{"	while (*s)"},
	{"	{"},
	{"		if (*s == '\\\\')"},
	{"			printf(\"\\\\\\\\\");"},
	{"		else if (*s == '\"')"},
	{"			printf(\"\\\\\\\"\");"},
	{"		else"},
	{"			printf(\"%c\", *s);"},
	{"		s++;"},
	{"	}"},
	{"}"},
	{""},
	{"int	main(void)"},
	{"{"},
	{"	/*"},
	{"		This program will print its own source when run."},
	{"	*/"},
	{"	for (int i=0; i<SRC_LINE; i++)"},
	{"		printf(\"%s\\n\", g_src_code[i]);"},
	{"	for (int i=0; i<N_LINES; i++)"},
	{"	{"},
	{"		printf(\"	{\\\"\");"},
	{"		print_esc(g_src_code[i]);"},
	{"		printf(\"\\\"},\\n\");"},
	{"	}"},
	{"	for (int i=SRC_LINE; i<N_LINES; i++)"},
	{"		printf(\"%s\\n\", g_src_code[i]);"},
	{"}"},
};

static void	print_esc(char *s)
{
	while (*s)
	{
		if (*s == '\\')
			printf("\\\\");
		else if (*s == '"')
			printf("\\\"");
		else
			printf("%c", *s);
		s++;
	}
}

int	main(void)
{
	/*
		This program will print its own source when run.
	*/
	for (int i=0; i<SRC_LINE; i++)
		printf("%s\n", g_src_code[i]);
	for (int i=0; i<N_LINES; i++)
	{
		printf("	{\"");
		print_esc(g_src_code[i]);
		printf("\"},\n");
	}
	for (int i=SRC_LINE; i<N_LINES; i++)
		printf("%s\n", g_src_code[i]);
}
