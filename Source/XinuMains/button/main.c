#include <xinu.h>


int main(int argc, const char *argv[])
{
	char edge_ip[] = "192.168.1.102";
	
	/* Obtain an IP address */
	netstart();

	/* Start sending the temperature */
	kprintf("Start main function\r\n");
        char prev = '0';
        char prev2 = '0';
	while (1)
	{
                char buf[1];
                char buf2[1];
       
                char sendmsg[1];
		read(BUTTON, buf, 1);
		if(buf[0]=='1')
                {
		        if(prev=='0')
		        {
		        sendmsg[0]='1';
		        kprintf("sending %s\n", sendmsg);
			sendEdge(edge_ip, 8000, sendmsg, 1);
		        }
                prev = '1';
                }
                else
                {
                prev = '0';
                }
                sleep(0.01);
		
		read(BUTTON2, buf2, 1);
		if(buf2[0]=='1')
                {
		        if(prev2=='0')
		        {
                        sendmsg[0]='2';
		        kprintf("sending %s\n", sendmsg);
			sendEdge(edge_ip, 8000, sendmsg, 1);
			}
                prev2 = '1';
                }
		else
                {
                prev2 = '0';
                }
                sleep(0.01);
		
	}
}
