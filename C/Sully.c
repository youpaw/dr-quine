#include <stdio.h>
#define N_LINES 43
#define SRC_LINE 7
#define CNT_LINE 23
char	g_src_code[N_LINES][51] = {
		{"#include <stdio.h>"},
		{"#define N_LINES 43"},
		{"#define SRC_LINE 7"},
		{"#define CNT_LINE 23"},
		{"char	g_src_code[N_LINES][51] = {"},
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
		{"int	main(void)"},
		{"{"},
		{""},
		{"	FILE *f = fopen(\"Sully_\"i\".c\", \"w\");"},
		{"	if (!f)"},
		{"		return(1);"},
		{"	for (int l=0; l<SRC_LINE; l++)"},
		{"		fprintf(f, \"%s\\n\", g_src_code[l]);"},
		{"	for (int l=0; l<N_LINES; l++)"},
		{"	{"},
		{"		fprintf(\"\t{\\\"\");"},
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

int	main(void)
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
			fprintf(f, "	int i = "i";\n")
		else
			fprintf(f, "%s\n", g_src_code[l]);
	}
}
