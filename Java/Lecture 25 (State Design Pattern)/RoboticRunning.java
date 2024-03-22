
public class RoboticRunning implements RoboticState {

private final Robot robot;
	
	public RoboticRunning(Robot robot){
		this.robot = robot;
	}
	
	
	@Override
	public void on()
	{
		System.out.println("Already on...");
		
	}
	
	@Override
	public void walk()
	{
		
		System.out.println("Running...");
		robot.setState(robot.getRoboticWalking());
		System.out.println("Now Walking...");
		
	}
	
	
	@Override
	public void bendKnees()
	{
		
		System.out.println("Can't bend knees while Running...");
	}
	
		
	
	@Override
	public void jump()
	{
		
		System.out.println("Can't jump while Running...");
	}
	
		
	@Override
	public void sit()
	{
		System.out.println("Can't sit while Running...");
		
	}
	
	
	@Override
	public void sideRoll()
	{
		System.out.println("Can't sideroll while Running...");
		
	}
	
	
	@Override
	public void frontRoll()
	{
		System.out.println("Can't frontroll while Running...");
		
	}
	
	
	@Override
	public void run()
	{
		System.out.println("Already Running...");
	}
	
	
		
	@Override
	public void off()
	{
		robot.setState(robot.getRoboticOff());
		System.out.println("Switched off ...");
	}
}
