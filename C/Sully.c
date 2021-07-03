#include <stdio.h>
#include <stdlib.h>
#define N_LINES 53
#define SRC_LINE 8
#define CNT_LINE 24
char	g_src_code[N_LINES][80] = {
		{"#include <stdio.h>"},
		{"#include <stdlib.h>"},
		{"#define N_LINES 53"},
		{"#define SRC_LINE 8"},
		{"#define CNT_LINE 23"},
		{"char	g_src_code[N_LINES][80] = {"},
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
		{"	char filename[20];"},
		{"	char binname[20];"},
		{"	char cmdname[60];"},
		{"	sprintf(filename, \"Sully_%d.c\", i);"},
		{"	sprintf(binname, \"Sully_%d\", i);"},
		{"	FILE *f = fopen(filename);"},
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
		{"	sprintf(cmdname, \"clang -o %s %s;./%s\", binname, filename, binname);"},
		{"	if (i >= 0)"},
		{"		return (system(cmdname));"},
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
	char filename[20];
	char binname[20];
	char cmdname[60];
	sprintf(filename, "Sully_%d.c", i);
	sprintf(binname, "Sully_%d", i);
	FILE *f = fopen(filename, "w");
	if (!f)
		return (1);
	for (int l=0; l<SRC_LINE; l++)
		fprintf(f, "%s\n", g_src_code[l]);
	for (int l=0; l<N_LINES; l++)
	{
		fprintf(f, "	{\"");
		fprint_esc(g_src_code[l]);
		fprintf(f, "\"},\n");
	}
	for (int l=SRC_LINE; l<N_LINES; l++)
	{
		if (l == SRC_LINE)
			fprintf(f, "	int i = "i";\n");
		else
			fprintf(f, "%s\n", g_src_code[l]);
	}
	sprintf(cmdname, "clang -o %s %s;./%s", binname, filename, binname);
	if (i >= 0)
		return (system(cmdname));
	return (0);
}
