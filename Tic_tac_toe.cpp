/*
                 <------------------------Tic Tac Toe-------------------------------->
 

            
How to input position : write 1 2  (1st row and 2nd column)

           (1 1)| (1 2)  |(1 3)
           ---- +--------+----
           (2 1)| (2 2)  |(2 3)
            --- + ---------+---
           (3 1)| (3 2)  |(3 3)
*/

#include <bits\stdc++.h>

using namespace std;

   	    char a[5][5]={
		
		            {' ',  '|',  ' ',  '|',  ' '},                    
		            {'-',  '+',  '-',  '+',  '-'},
		            {' ',  '|',  ' ',  '|',  ' '},                 //2-D char array GAME Board
		            {'-',  '+',  '-',  '+',  '-'},
		            {' ',  '|',  ' ',  '|',  ' '}
		
  				          };
     		int k=9;	             // Here k is the number of turns

int convert(int a1)                //Here user defined positon of X-O is converted to array defined position
{
		if(a1==1)                             // (user defined pos)   ---->    (Actual pos)
		{
   	          return 0;                          //  (1 1)| (1 2)  |(1 3)            (0 0)| (0 2)  |(0 4)               If you compare coodinates :
		}                               //       ---- +--------+----             ---- +--------+----
		                               //        (2 1)| (2 2)  |(2 3)   ====>    (2 0)| (2,2)  |(2 4)                  1->0         2->2     3->4
		else if(a1==3)                //          --- + -------+ ----             ----+--------+----
		{                            //          (3 1)| (3 2)  |(3 3)            (4 0)| (4 2)  |(4 4)
			return 4;               
		}  
		else if(a1>=4 || a1<=0)         
		{                                    // when input is wrong function will return value greater than 4 
			return 5;
		}                                
		                                 
		return a1;	
}

  					
  		
  	/*prints empty game board*/				
void print_empty_board()
{
		cout << "\n";
			
		for(int i=0; i<5; i++)
	   	{         
			cout << " ";
	   		
	   	     	for(int j=0; j<5; j++)
	   	      	{
	   	      	    cout<<a[i][j] << " ";
			 	}
			 	
			cout << endl;             // endl may create problem
		}

}
		/*print game board after inserting requred X or O*/

void print(int n, int m, bool p)
{
	
		if(p==1 && a[n][m]==' ' && n<5 && m<5)                        // put x or o on requred positon  
		{
			a[n][m]='X';               // p=1 ->X     p=0->O
		}
	
		else if(p==0 && a[n][m]==' ' && n<5 && m<5)
		{
			a[n][m]='O';
		}
		else if(n>4 || m>4)                //  When wrong coordinates are used 
		{
			cout << "\n Input out of Bound";
			k++;
		}
	    
	    else                                  // When something other than number is written
	    {
	    	cout << "\n Wrong Input";
	    	k++;                                     // number of turns increased by one 
	    	
	  	}
			cout << endl <<endl;
	
	
	   for(int i=0; i<5; i++)
	   {          
	        cout << " ";                            //prints board after putting value
	            
	   	        for(int j=0; j<5; j++)
	   	        {
	   	      	cout<< a[i][j] << " ";
			    }
			    
			cout << endl;             
	   }
	
}

		/*This function checks do any one won the game and who won it X or O. It doesn't check match tie or not*/
int check()
{
			if((a[0][0]=='X' && a[0][2]=='X' && a[0][4]=='X') || (a[2][0]=='X' && a[2][2]=='X' && a[2][4]=='X') || (a[4][0]=='X' && a[4][2]=='X' && a[4][4]=='X'))
			{
				return 1;   // That means X Won  // for 1st, 2nd and 3rd row(horizontal)
			}
			
			if((a[0][0]=='X' && a[2][0]=='X' && a[4][0]=='X') || (a[0][2]=='X' && a[2][2]=='X' && a[4][2]=='X') || (a[0][4]=='X' && a[2][4]=='X' && a[4][4]=='X'))
			{
				return 1;   //for 1st, 2nd and 3rd column(vertical)
			}
			
		    if((a[0][0]=='X' && a[2][2]=='X' && a[4][4]=='X') || (a[4][0]=='X' && a[2][2]=='X' && a[0][4]=='X'))
			{
				return 1;   //for diagnal values
			}
			
			if((a[0][0]=='O' && a[0][2]=='O' && a[0][4]=='O') || (a[2][0]=='O' && a[2][2]=='O' && a[2][4]=='O') || (a[4][0]=='O' && a[4][2]=='O' && a[4][4]=='O'))
			{
				return 0;  //o wins    //for 1st, 2nd and 3rd row(horizontal)  
			}
			
			if((a[0][0]=='O' && a[2][0]=='O' && a[4][0]=='O') || (a[0][2]=='O' && a[2][2]=='O' && a[4][2]=='O') || (a[0][4]=='O' && a[2][4]=='O' && a[4][4]=='O'))
			{
				return 0;  //for 1st, 2nd and 3rd column(vertical)
			}
			
		    if((a[0][0]=='X' && a[2][2]=='X' && a[4][4]=='X') || (a[4][0]=='X' && a[2][2]=='X' && a[0][4]=='X'))
			{
				return 0;   //for diagnal values
		    }
		    
			// following line says that no one has won the game presently
	     return 8;  //Here you can put any integer besides 1 and 0 
			
}


int main()
{
		print_empty_board();
	                                // using boolean ck we will switch between X and O after each turn of player
		bool ck=1;                   //boolean  1->X   0->O 
	
		int n1 ,m1;                //positon 
		
	    
    for(int rr=1; rr<=30; rr++)      // maximum turns k =9
    {                                     // This    
	    	
	  		if(ck==1)
	  		{
		  
	  			cout << "\n\n Enter the position of X : ";
		 	}
		  
			else
		    {   	
				cout <<"\n\n Enter the position of O : ";
			}
			
	     	cin >>n1>> m1;                                // n1 and m1 stores input of user
	  	
	  	             n1=convert(n1);            //user pos --> actual pos
		             m1=convert(m1);
		             
         	  	int we=k;  // 
       
	     	print(n1,m1,ck);        //take in pos, put in array and print it
		    
	  	                       // when ck=1 => it's X input      ck=0 => it's O input
	  	                       
	    	ck=!ck;            //bool value is reversed inside loop so that user can input X and O alternately
	  	
	  	
	    	if(rr>=5)     // Atleast 5 turns(of both palyers "+") are required to win the game            
	  	    {
	  		    if(check()==1)
	  	  		{   
	  		   			cout << "\n X is the Winner";
	  					break;  //foe loop break after winner is announced
				}
			
				if(check()==0)
				{
					    cout << "\n O is the Winner";
						break;
				}
		    }
		         
		                if(we<k)        // "we' variable helps to switch back to X(or O) when wrong input is given in turn of X (or O respectively) in game.   
		               {
		         	   we++;
					
		         	   ck=!ck;
			       }
	    
		   	  if(rr==k)    
	  	          {
	  	          	cout << "\n The Match Ties!";       
	  	          	break;
			  }   
	  	
	}
	
	
 	return 0;     //Main class ended
}



