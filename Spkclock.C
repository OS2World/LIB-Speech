
#include "speech.h"
#include <dos.h>
#include <string.h>
#include <stdlib.h>
#define INCL_WINSHELLDATA       /* Window Shell functions       */
#include <os2.h>

int interval=15;
int ampm=1;
int voice=0;


void getini(void)
{
 char ip[80];
 ampm = PrfQueryProfileInt(HINI_USERPROFILE,"PM_National","iTime",0);
 ampm &= 1;
}

void saytime(struct time *tp)
{
 char str[100];
 char *ap=" |A M| ";
 char ts[5];
 int tmp;
 strcpy(str,"~M(0) The time is ");
 str[3]='0'+voice;
 tmp=tp->ti_hour;
 if (ampm==0)
 {
   if (tmp >=12) {ap[2]='P'; tmp-=12;}
   if (tmp == 0) tmp=12;
   ap[4]='M';
 }
 else
 {
   ap[2]=' ';
   ap[4]=' ';
 }
 itoa(tmp,ts,10);
 strcat(str,ts);
 strcat(str," hours ");
 if(tp->ti_min != 0)
 {
   strcat(str,"and ");
   itoa(tp->ti_min,ts,10);
   strcat(str,ts);
   strcat(str," minutes ");
 }
 strcat(str,ap);
 audio_init(2);
 say_string(str);
 sleep(60);
 audio_term();
}


void main(int envc,char *env[])
{
  struct time timep;
  int i;
  if (envc>1) i=atoi(env[1]);
  if (i>9) interval=i; else voice=i;
  if (envc>2) i=atoi(env[2]);
  if (i>9) interval=i; else voice=i;
  if (interval>=60) interval=15;
  getini();
  sleep(60);
  gettime(&timep);
  for(;;)
  {
    sleep(60-timep.ti_sec);
    gettime(&timep);
    if((timep.ti_min % interval)==0) saytime(&timep);
  }
}

