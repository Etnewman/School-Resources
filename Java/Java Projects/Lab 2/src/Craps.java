
public class Craps
{

   public static int playCraps(int num_rolls)
   {
	   int counter = 0;
	   int rollNum = 0;
	   
	   CrapsDice cd = new CrapsDice();
	   
    for (int i = 0; i < num_rolls; i++)
    {
    	rollNum = cd.roll();
    	
    	if(rollNum == 2 || rollNum == 3 || rollNum == 12)
    		counter++;
    }
    
    return counter;
	 
   }
   public static void main(String[] args)
   {
     int counter = 0;
	 counter = playCraps(752);
	 
	 double counterD = (double) counter;
	 double percent = 0;
	 
	 percent = counterD / 752;
	 percent = percent*100;
	 
	 System.out.println(percent + "%");

   }

}