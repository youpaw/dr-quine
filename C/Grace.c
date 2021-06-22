#include <stdio.h>
#define FT(c1, c2, c3, c4, c5) int main() {printf(c1"\n");printf(c2"\n");printf(c3"\n");printf(c4"\n");printf(c5"\n");printf("FT("#c1", "#c2", "#c3", "#c4", "#c5")");}
/*
	This program will print its own source when run.
*/
FT("#include <stdio.h>", "#define FT(c1, c2, c3, c4, c5) int main() {printf(c1\"\\n\");printf(c2\"\\n\");printf(c3\"\\n\");printf(c4\"\\n\");printf(c5\"\\n\");printf(\"FT(\"#c1\", \"#c2\", \"#c3\", \"#c4\", \"#c5\")\");}", "/*", "	This program will print its own source when run.", "*/")