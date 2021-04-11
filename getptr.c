// need file libdos.c to be compile in directory
//bcc -x -i -L -Md hello.c -o HELLO.COM
#define varn 0x0080
#define stdout 0 
#define lpt 2 
#define com1 3 
int ii;
void writes(file,s);
void screens(n);
void sstr(i,s);
int getptr();

int main(){
	char c[80];
	int rets=getptr();
	sstr(rets & 0x7fff,c);
	screens(0);
	writes(stdout,c,6);
		asm	"db 0xb4,0,0xcd,0x21";
		
	return 0;
}

void writes(file,s,size)
int file;
char *s;
int size;
{
	int *c;
	c = (int * ) varn;
	*(c + 0) = file;
	*(c + 1) = s;
	*(c + 2) = size;

	asm	"db 0x1E,0x56,0x8C,0xC8,0x8E,0xD8,0xBE,0x80,0x00,0x2E,0x8B,0x1C,0x46,0x46,0x2E,0x8B,0x14,0x46,0x46,0x2E,0x8B,0x0C,0xB4,0x40,0xCD,0x21,0x5E,0x1F";
}



void screens(n)
int n;
{
	int *c;
	c = (int * ) varn;
	*(c + 0) = n;


	asm	"db 0x1E,0x56,0x8C,0xC8,0x8E,0xD8,0xBE,0x80,0x00,0x2E,0x8A,0x04,0xB4,0x00,0xCD,0x10,0x5E,0x1F";
}



int getptr()
{
	int *c;
	c = (int * ) varn;

	asm	"db 0x8C,0xC8,0x2E,0xA3,0x80,0x0";
	return *(c + 0);
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
