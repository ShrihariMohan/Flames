#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

void flamesPrinter(char f )
{
    switch(f)
    {
        case 'F' :  printf("\nYou Two are Friends ");
                    break ;
        case 'L' :  printf("\n Good luck , Love ");
                    break ; 
        case 'A' :  printf("\n Who Needs Affection ? You TWO !");
                    break ;
        case 'M' :  printf("\n Suicide is easy to do but Marriage.. ");
                    break ;  
        case 'E' :  printf("\n Enemy , Flames is Wrong ! ");
                    break ;
        case 'S' :  printf("\nSister , hope you two aren't Boys ");
                    break ;
    }
}

int lenghtFinder(char * s1, char * s2)
{
   int pair = 0 ;
   int totallen = strlen(s1) + strlen(s2) ;
   for ( int i = 0 ; i < strlen(s1) ; i ++ )
   {
       for ( int j = 0 ; j < strlen(s2) ; j ++)
       {
           if ( s1[i] == s2[j] ) 
           {
               s2[j] = '*' ;
               pair++ ;
               break;
           }
       }
   }
   
   return (totallen-2*pair) ;
}

char flamer(int num)
{
    char flame[] = "FLAMES" ;
    int star_count = 0, ind= 0 ;
    
    while( star_count != 5 )
    {
        int count = 0 ;
       // printf(flame) ;
        while (1)
        {
           // printf("%d %d \n", ind , count ) ;
            if ( flame[ind] == '*' ) 
            {
                ind ++ ;
                if  ( ind == 6 ) ind = 0 ;
                //printf("1 ");
                continue ;
            }
            else if ( count < num )
            {
                count ++ ; 
                ind ++ ;
                if ( count == num )
                {
                    //printf("%d ", ind );
                    flame[ind-1] = '*' ;
                    star_count ++ ;
                    //printf("%s \n",flame) ;
                    if  ( ind == 6 ) ind = 0 ;
                    
                    break;
                        
                }
                if  ( ind == 6 ) ind = 0 ;
            }     
        }
    }
    for ( int i = 0 ; i < 6 ; i ++ )
        if ( flame[i] != '*' ) return flame[i] ;
    //printf(flame) ;
    
}
int main(int argc, char **argv)
{
	char name_one[30] , name_two[30] ;
    int iterboy ;
    int ch ;
    printf("Flames Calculator \n(30 char len , without space)\n") ;
    printf("Enter 1 to Play\nEnter 2 to Exit");
    loop:
    printf("\nEnter Your Preference ");
    scanf("%d",&ch);
    if  ( ch == 2 ) return 0 ;
    printf ("First Name  : ") ;
    scanf("%s",name_one);
    printf("Second Name : ");
    scanf("%s",name_two) ;
    iterboy = lenghtFinder(strlwr(name_one),strlwr(name_two));
   if ( iterboy == 0 ) 
   {
    printf(" Either you are trying your Name || Your partner is Jumbled with your Name ! " ) ; 
    getch();
    goto loop ;
    return 0;
   }
    flamesPrinter(flamer(iterboy)) ;
    getch();
    goto loop;
	return 0;
}
