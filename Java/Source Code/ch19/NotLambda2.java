public class NotLambda2
{
	public static void main(String[] args)
	{
     // Anonymous class that overrides
     // the run() method
     Runnable r = new Runnable()
     {
       public void run(){
         System.out.println("I'm in an anonymous class2!");
       }
     };
     r.run();
	}
}