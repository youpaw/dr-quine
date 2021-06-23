#include <stdio.h>
#define FT(s) int main(){FILE *f=fopen("Grace_kid.c","w");if(f){fprintf(f,"%sFT(%s)",s,#s);fclose(f);}else{return(1);}}
/*
	This program will print its own source when run.
*/
FT("#include <stdio.h>\n#define FT(s) int main(){FILE *f=fopen(\"Grace_kid.c\",\"w\");if(f){fprintf(f,\"%sFT(%s)\",s,#s);fclose(f);}else{return(1);}}\n/*\n\tThis program will print its own source when run.\n*/\n")