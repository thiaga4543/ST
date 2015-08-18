
#include <stdio.h>
#include <string.h>


int main(void){
	FILE *fp;

	char returnData[64], returnV[200];
	char *token;
	char *s = ":";
	char *ret;
	char dest[20];
	

	fp = popen("/sbin/ifconfig eth0", "r");

	memset(dest, '\0', sizeof(dest));
	printf("\n");
	while (fgets(returnData, 64, fp) != NULL)
	{
		printf("%s", returnData);
		
		// get the first token 
		   token = strtok(returnData, s);
		   
		   // walk through other tokens 
		   while( token != NULL ) 
		   {

   			ret = strstr(token, "Bcast");
   			
   			 if (ret != NULL){
   			 	strncpy(dest,token,10);
   			 	//printf("->%s\n", dest);
   			 	break;
   			 }
		      token = strtok(NULL, s);
		   }
	}
	printf("\nThe IP address of this machine is: %s\n\n", dest);

	pclose(fp);
	return 0;
}

