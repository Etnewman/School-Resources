
public class RoboticOn implements RoboticState{

	private final Robot robot;
	
	public RoboticOn(Robot robot){
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
		
		robot.setState(robot.getRoboticWalking());
		System.out.println("Now Walking...");
		
	}
	
	
	@Override
	public void bendKnees()
	{
		
		System.out.println("Have not implemented it yet");
	}
	
		
	
	@Override
	public void jump()
	{
		
		System.out.println("Have not implemented it yet");
	}
	
		
	@Override
	public void sit()
	{
		System.out.println("Have not implemented it yet");
		
	}
	
	
	@Override
	public void sideRoll()
	{
		System.out.println("Have not implemented it yet");
		
	}
	
	
	@Override
	public void frontRoll()
	{
		System.out.println("Have not implemented it yet");
		
	}
	
	
	@Override
	public void run()
	{
		robot.setState(robot.getRoboticRunning());
		System.out.println("Now Running ...");
	}
	
	
		
	@Override
	public void off()
	{
		robot.setState(robot.getRoboticOff());
		System.out.println("Switched off ...");
	}
	
	
	
	
	
	
	/*@Override
	public void walk() {
		System.out.println("Walking...");
	}

	@Override
	public void cook() {
		System.out.println("Cooking...");
		robot.setState(robot.getRoboticCook());
	}

	@Override
	public void off() {
		robot.setState(robot.getRoboticOff());
		System.out.println("Robot is switched off");
		
	}*/

}
