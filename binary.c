// need file libdos.c to be compile in directory
//bcc -x -i -L -Md hello.c -o HELLO.COM
#define varn 0x0080
void sstr(i,s);
void sputc(cc);
void sputs(cc);
int bits(value,n);
void tobin(value,txt);
int main(){
	int k=0;
	int kk=0;
	unsigned int n=0;
	char s[80];
		for (k=0;k<16;k++){
			n=bset(n,k);
			sstr(k,s);
			sputs(s);
			sputs("	-	$");
			tobin(k,s);
			sputs(s);
			sputs("\r\n\0$");
			n=breset(n,k);
		}

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
unsigned int i;
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

void tobin(value,txt)
unsigned int value;
char *txt;
{
	int n;
	int i;
	for(n=0;n<17;n++)txt[n]='0';
	for(n=0;n<16;n++){
		i=bits(value,n);
		if(i!=0)txt[15-n]='1';
	}
	txt[16]=0;
	txt[17]='$';
}
int bits(value,n)
unsigned int value;
int n;
{
	static unsigned int bitv[]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,0x8000,0,0};
	unsigned int nn;
	unsigned nnn;
	unsigned nnnn;
	nnnn=value;
	nn=value & 0x7fff;
	nn=nn & bitv[n];
	if(nn!=0)nn=1;
	if (n==15 && value>0x7fff){
		nn=1;
	}
	if (n==15 && value<0x8000){
		nn=0;
	}
	return nn;
}

int bset(value,n)
int value;
int n;
{
	static unsigned int bitv[]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,0x8000,0,0};
	int nn;
	nn=value;
	nn=nn | bitv[n];
	return nn;
}

int breset(value,n)
int value;
int n;
{
	static unsigned int bitv[]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,0x8000,0,0};
	int nn;
	int n1;
	nn=value;
	n1=~bitv[n];
	nn=nn & n1;
	return nn;
}



