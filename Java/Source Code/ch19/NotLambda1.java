// The Runnable interface implements a single method, run()
class OldStyleRunnable implements Runnable
{
	public void run()
	{
		System.out.println("Running in a class!");
	}
}

public class NotLambda1
{
	public static void main(String[] args)
	{
		OldStyleRunnable r0 = new OldStyleRunnable();
	 	r0.run();  // Not in a thread, so we can invoke directly
	 			   // rather than calling start() as in Section 19.1
	}
}