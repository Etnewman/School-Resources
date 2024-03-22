
public class RoboticOff implements RoboticState{

	private final Robot robot;
	
	public RoboticOff(Robot robot){
		this.robot = robot;
	}
	
	@Override
	public void on()
	{
		robot.setState(robot.getRoboticOn());
		System.out.println("Now turned on...");
		
	}
	
	@Override
	public void walk()
	{		
		System.out.println("Can't walk while switched off");
		
	}
	
	
	@Override
	public void bendKnees()
	{
		
		System.out.println("Can't bend knees while switched off");
	}
	
		
	
	@Override
	public void jump()
	{
		
		System.out.println("Can't jump while switched off");
	}
	
		
	@Override
	public void sit()
	{
		System.out.println("Can't sit while switched off");
		
	}
	
	
	@Override
	public void sideRoll()
	{
		System.out.println("Can't sideroll while switched off");
		
	}
	
	
	@Override
	public void frontRoll()
	{
		System.out.println("Can't frontroll while switched off");
		
	}
	
	
	@Override
	public void run()
	{
		System.out.println("Can't run while switched off");
	}
	
	
		
	@Override
	public void off()
	{
		System.out.println("Already Switched off ...");
	}
	
}
