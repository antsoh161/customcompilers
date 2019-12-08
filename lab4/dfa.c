
#include <stdio.h>
#include <stdlib.h>

int main(){
	int c;
	int state = 1; //Starting state

	while(1){
		c = getchar();
		if(c == '\n' || c == ' ' || c == '\t')
			continue; //Ignore line feed and whitespace

		else{
			switch(state){
				case 1:
					if(c == 'a'){
						state = 2;
					}
					else{
						state = 4;
						printf("Exit stage 4\n");
						return(EXIT_SUCCESS); //Return stage 4 end
					}
					break;
				case 2:
					if(c == 'a'){
						state = 3;
						printf("Exit stage 3\n");
						return(EXIT_SUCCESS);  //Return stage 3 end
					}
					else if (c == 'b'){
						state = 1;
					}
					else{
						state = 4;
						printf("Exit stage 4\n");
						return(EXIT_SUCCESS); //Return stage 4 end
					}
					break;

				/* Inte nödvändigt 
				case 3:
					printf("Exit stage 4\n");
					return(EXIT_SUCCESS);
				case 4:
					printf("Exit stage 4\n");
					return(EXIT_SUCCESS);
				*/
			}
		printf("Moved to stage %d\n",state);
		}
	}
	return(EXIT_SUCCESS);
}
