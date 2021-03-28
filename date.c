// need file libdos.c to be compile in directory
//bcc -x -i -L -Md hello.c -o HELLO.COM
#define varn 0x0080
int day;
int mont;
void sstr(i,s);
void sputc(cc);
void sputs(cc);
int getdate();
int main(){
	char s[80];
	sstr(getdate(),s);
	sputs(s);
	sputs("/");
	sstr(mont,s);
	sputs(s);
	sputs("/");
	sstr(day,s);
	sputs(s);
	sputs("\r\n");
		asm	"db 0xb4,0,0xcd,0x21";
		
	return 0;
}

void sputc(cc)
char cc;
{
	int *c;
	c = (int * ) varn;
	*(c + 0) = cc;

	asm	"db 0xbb,0x80,0x0,0x2e,0x8a,0x17,0xb4,0x02,0xcd,0x21";
}
void sstr(i,s)
int i;
char *s;
{
	int n=0;
	int i10=10;
	int start=10000;
	int state=0;
	int sss=0;
	int remain=0;
	int boo=0;
	char *cursor;
	char cc;
	sss=i;
	cursor=s;
	
	for (n=0;n<5;n++){
		if(n>3)boo=1;
		state=sss/start;
		remain=sss-(state*start);
		sss=remain;
		cc=(char) state+'0';
		if(cc!='0')boo=1;
		if(boo==1)cursor[0]=cc;
		start=start/i10;
		if(boo==1)cursor++;
	}
	cursor[0]=0;
}

void sputs(cc)
char *cc;
{
		int i=0;
while(cc[i]!=0){
		sputc(cc[i]);
		i++;
}
}


int getdate()
{
	int *c;
	char years;	
	char years2;
	char monts;
	char days;
	c = (int * ) varn;
	*(c + 0)=0;
	*(c + 1)=0;
	*(c + 2)=0;
	*(c + 3)=0;
	asm	"db 0xB4,0x2A,0xCD,0x21,0xBB,0x80,0x00,0x2E,0x88,0x2F,0x43,0x43,0x2E,0x88,0x0F,0x43,0x43,0x2E,0x88,0x37,0x43,0x43,0x2E,0x88,0x17";
	years=*(c + 0);
	years2=*(c + 1);
	monts=*(c + 2);
	days=*(c + 3);
	mont=(int) monts;
	day=(int) days;
	return (int) years2+years*256;
}
