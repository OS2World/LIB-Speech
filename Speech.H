
#define SYS _syscall

void SYS string2phone(char *s,char *p,int *n); 	/* String to phoneme string*/
void SYS string2wave(char *s,char *w,int *m); 	/*String to raw wave file (no wave header) */
void SYS say_string(char *s);				/*Speek string*/
void SYS setsamprate(int s);				/*Set sample rate (8,11,22 ect.*/
void SYS setbits(int b);					/* 16 / 8 bits*/
void SYS say_phones(char *phone, int len);		/*Speek phonemes string*/
void SYS audio_init(int i);				/*Init device, 0=default, -1=don't change current*/
int SYS audio_term(void SYS);				/*terminate audio, returns 0 when all instances are stopped*/
void SYS audio_play(int n, short *data);		/*Play raw wave*/
void SYS set_mute(int n);				/*Mute on/off*/

