#include <stdio.h>
#include <stdlib.h>
#define N_LINES 47
#define SRC_LINE 8
#define CNT_LINE 24
char	g_src_code[N_LINES][66] = {
		{"#include <stdio.h>"},
		{"#include <stdlib.h>"},
		{"#define N_LINES 47"},
		{"#define SRC_LINE 8"},
		{"#define CNT_LINE 23"},
		{"char	g_src_code[N_LINES][66] = {"},
		{"};"},
		{""},
		{"static void	fprint_esc(FILE *f, char *s)"},
		{"{"},
		{"	while (*s)"},
		{"	{"},
		{"		if (*s == '\\\\')"},
		{"			fprintf(f, \"\\\\\\\\\");"},
		{"		else if (*s == '\"')"},
		{"			fprintf(f, \"\\\\\\\"\");"},
		{"		else"},
		{"			fprintf(f, \"%c\", *s);"},
		{"		s++;"},
		{"	}"},
		{"}"},
		{""},
		{"int	main(int argc, char **argv, char **env)"},
		{"{"},
		{"	int i = 5;"},
		{"	FILE *f = fopen(\"Sully_\"i\".c\", \"w\");"},
		{"	if (!f)"},
		{"		return(1);"},
		{"	for (int l=0; l<SRC_LINE; l++)"},
		{"		fprintf(f, \"%s\\n\", g_src_code[l]);"},
		{"	for (int l=0; l<N_LINES; l++)"},
		{"	{"},
		{"		fprintf(\"	{\\\"\");"},
		{"		fprint_esc(g_src_code[l]);"},
		{"		fprintf(\"\\\"},\\n\");"},
		{"	}"},
		{"	for (int l=SRC_LINE; l<N_LINES; l++)"},
		{"	{"},
		{"		if (l == SRC_LINE)"},
		{"			fprintf(f, \"\tint i = \"i\";\\n\")"},
		{"		else"},
		{"			fprintf(f, \"%s\\n\", g_src_code[l]);"},
		{"	}"},
		{"	if (i >= 0)"},
		{"		return (system(\"gcc -o Sully_\"i\" Sully_\"i\".c;./Sully_\"i));"},
		{"	return (0);"},
		{"}"},
};

static void	fprint_esc(FILE *f, char *s)
{
	while (*s)
	{
		if (*s == '\\')
			fprintf(f, "\\\\");
		else if (*s == '"')
			fprintf(f, "\\\"");
		else
			fprintf(f, "%c", *s);
		s++;
	}
}

int	main(int argc, char **argv, char **env)
{
	int i = 5;
	FILE *f = fopen("Sully_"i".c", "w");
	if (!f)
		return (1);
	for (int l=0; l<SRC_LINE; l++)
		fprintf(f, "%s\n", g_src_code[l]);
	for (int l=0; l<N_LINES; l++)
	{
		fprintf("	{\"");
		fprint_esc(g_src_code[l]);
		fprintf("\"},\n");
	}
	for (int l=SRC_LINE; l<N_LINES; l++)
	{
		if (l == SRC_LINE)
			fprintf(f, "	int i = "i";\n");
		else
			fprintf(f, "%s\n", g_src_code[l]);
	}
	if (i >= 0)
		return (system("clang -o Sully_"i" Sully_"i".c;./Sully_"i));
	return (0);
}
