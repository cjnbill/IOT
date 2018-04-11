#include <xinu.h>


int main(int argc, const char *argv[])
{
	char str[10];
	char edge_ip[] = "192.168.0.1";
	
	/* Obtain an IP address */
	netstart();

	/* Start sending the temperature */
	kprintf("Start main function\r\n");
	unsigned int integer = 0;
	unsigned int decimal = 0;
	float temperature;
	while (1)
	{
		read(TMP36, (char*)&temperature, 4);

		integer = (unsigned int)temperature;
		decimal = (unsigned int)((temperature - integer)*10);
		sprintf(str, "%d.%d", integer, decimal);
		
		// kprintf("temperature = %s celcius\r\n", str);
		sendEdge(edge_ip, 8000, str, strlen(str));
		
		sleep(1);
	}
}
