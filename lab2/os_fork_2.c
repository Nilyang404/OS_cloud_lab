/*******************************************************************
*Copyright(c) 2020 Ocean University of China. All rights reserved. *
*This file is created by: 									 	   *
*............................................................	   *
*............................................................	   *
*............................................................	   *
*............................................................	   *
*..............!M1...M*............+.....*`..................	   *
*......`]]]]]]]YM]]]]MY]]]]EMN~....M]...1M+.KF]]]]]]]ME......	   *
*.........!W*]]YM]]]]MY]]*MK.......M]..*]...K].......M!......	   *
*.........!M...!M....M!...M!.......M].!]....K].......M!......	   *
*.........!M...!M....M!...M!.......M]...F*..KK]]]]]]]M!......	   *
*...........KK..........KE.........M]**YNM;.K].......M!......	   *
*...........KW]]]]]]]]]]WK.........M]..1;...K].......M!......	   *
*...........KW]]]]]]]]]]WK.........M].......K].......M]......	   *
*...........*~..........1;.........F;........................	   *
*............................15020041003......................	   *
*............................................................ 	   *                                                                          

********************************************************************/

# include<stdio.h>   
# include<sys/types.h>   
# include<unistd.h>
# include<stdlib.h>
# include<sys/wait.h>
int main()
{   
	int id;
    
	

	
	if ((id = fork()) < 0) { 
		printf("Son process fails to create\n");
		//非法结果
		return -1;
	}
    //如果是子进程 ,创建子子进程
	else if (id == 0) {
		if((id = fork())<0){
			printf("c fail create!\n");
			return -1;
		}
		else if (id ==0){
			printf("c ID:%d\n",getpid());
			return 0;
		}
		else{
			printf("I am a son! ID:%d\n",getpid());
			return 0 ;	
		}	
	}
	else if (id>0){
		printf("I am father! ID:%d\n",getpid());
		return 0;
	}
	
	return 0;

}


