#include <stdio.h>
#include "speech.h"

void main (void)
{
char in[100];
char out[256];
int n;
while (audio_term() !=0) ;
audio_init(-1);
for(;;)
 {
   gets(in);
   n=255;
   say_string(in);
   string2phone(in,out,&n);
   puts(out);
   say_phones(out,n);
 }
audio_term();
}
