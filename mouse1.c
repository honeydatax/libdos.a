// need file libdos.c to be compile in directory
//bcc -x -i -L -Md hello.c -o HELLO.COM
#define varn 0x0080
#define stdout 0 
#define lpt 2 
#define com1 3 
#define COM1 0
#define COM2 1
#define COM3 2
#define COM4 3
#define RIGTH	64
#define LEFT	79
#define UP		76
#define DOWN	67
#define CLICK	80

int ii;
void sputs(cc);
int comport(ports);

int main(){
	int x=0;
	int y=0;
	int clicks=0;
	int n=0;
	int nn=0;
	int b=0;
	char c[80];
	char *cc=" $";
	while(n!=27){
		nn=comport(COM1);
		nn=nn & 0xff;
		if(nn==UP){
			sputs("UP $");
		}

		if(nn==DOWN){
			sputs("DOWN	$");
		}
		if(nn==LEFT){
			sputs("LEFT	$");
		}
		if(nn==RIGTH){
			sputs("RIGTH $");
		}
		if(nn==CLICK){
			sputs("CLICK	$");
		}



	}
		
			return 0;
}


int comport(ports)
int ports;
{
	int *c;
	c = (int * ) varn;
	*(c + 0) = ports;

	asm	"db 0x1E,0x56,0x8C,0xC8,0x8E,0xD8,0xBE,0x80,0x00,0x2E,0x8B,0x14,0xB4,0x02,0xCD,0x14,0xBE,0x80,0x00,0x2E,0x89,0x04,0x5E,0x1F";
	return *(c + 0);


}


void sputs(cc)
char *cc;
{
	int *c;
	int i;
	c = (int * ) varn;
	*(c + 0) = cc;

	asm	"db 0xbb,0x80,0x0,0x2e,0x8b,0x17,0xb4,0x09,0xcd,0x21";
}
