// need file libdos.c to be compile in directory
//bcc -x -i -L -Md hello.c -o HELLO.COM
#define varn 0x0080
void setdate(y,m,d);

int main(){
	setdate(2021,11,22);
	
		asm	"db 0xb4,0,0xcd,0x21";
		
	return 0;
}

void setdate(y,m,d)
int y;
int m;
int d;
{
	int *c;
	c = (int * ) varn;
	*(c + 0) = y;
	*(c + 1) = m;
	*(c + 2) = d;

	asm	"db 0xBB,0x80,0x00,0x2E,0x8B,0x0F,0x43,0x43,0x2E,0x8A,0x37,0x43,0x43,0x2E,0x8A,0x17,0xB4,0x2B,0xCD,0x21";
}
