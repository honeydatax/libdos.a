// need file libdos.c to be compile in directory
//bcc -x -i -L -Md hello.c -o HELLO.COM
#define varn 0x0080
#define stdout 0 
#define lpt 2 
#define com1 3 
int ii;
void writes(file,s);


int main(){
	char *cc="hello world \r\n";
	writes(stdout,cc,len(cc));
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

int len(s)
char *s;
{
	int n;
	int ss=0;
	for(n=0;n<32002;n++){
		if (s[n]==0){
			ss=n;
			n=32008;
		}
	}
	return ss;
}
