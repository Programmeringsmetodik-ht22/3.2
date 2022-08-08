
/*******************************************************************************
* 3.2.c: Ber användaren kontinuerligt mata in ett textstycke, som sedan skrivs
*        till en fil tillsammans med antalet genomförda utskrifter. Programmet
*        avslutas när en blank rad matas in.
*******************************************************************************/
#include <stdio.h>

/*******************************************************************************
* print: Skriver ut ett textstycke samt radnummer via angiven utström.
*******************************************************************************/
static void print(const char* s, size_t* line, FILE* ostream)
{
   if (!ostream) ostream = stdout;
   fprintf(ostream, "Line %zu: %s\n", ++(*line), s);
   return;
}

/*******************************************************************************
* readline: Läser en rad med text från tangentbordet och lagrar i en sträng.
*******************************************************************************/
static void readline(char* s, const size_t size)
{
   fgets(s, (int)size, stdin);
   fprintf(stdout, "\n");
   for (char* i = s; *i; ++i)
      { if (*i == '\n') *i = '\0'; }
   return;
}

/*******************************************************************************
* main: Läser in text från tangentbordet och skriver till en fil döpt data.txt,
*       tillsammans med aktuellt radnummer. När en blank rad matas in 
*       avslutas programmet.
*******************************************************************************/
int main(void)
{
   char s[100] = { '\0' };
   FILE* ostream = fopen("data.txt", "w");
   size_t num_lines = 0;

   while (1)
   {
      printf("Enter text or a blank line to finish:\n");
      readline(s, sizeof(s));

      if (!s[0]) break;
      else print(s, &num_lines, ostream);
   }

   fclose(ostream);
   printf("Bye!\n");
   return 0;
}
