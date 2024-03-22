
public class RoboticWalking implements RoboticState{

	private final Robot robot;
	
	public RoboticWalking(Robot robot){
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
		System.out.println("Already walking...");
		
	}
	
	
	@Override
	public void bendKnees()
	{
		
		System.out.println("Can't bend knees while Walking...");
	}
	
		
	
	@Override
	public void jump()
	{
		
		System.out.println("Can't jump while Walking...");
	}
	
		
	@Override
	public void sit()
	{
		System.out.println("Can't sit while Walking...");
		
	}
	
	
	@Override
	public void sideRoll()
	{
		System.out.println("Can't sideroll while Walking...");
		
	}
	
	
	@Override
	public void frontRoll()
	{
		System.out.println("Can't frontroll while Walking...");
		
	}
	
	
	@Override
	public void run()
	{
		System.out.println("Walking...");
		robot.setState(robot.getRoboticRunning());
		System.out.println("Now Running...");
	}
	
	
		
	@Override
	public void off()
	{
		robot.setState(robot.getRoboticOff());
		System.out.println("Switched off ...");
	}
}
