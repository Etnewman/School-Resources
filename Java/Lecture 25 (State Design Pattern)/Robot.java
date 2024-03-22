
public class Robot implements RoboticState{

	private RoboticState roboticOn;
	private RoboticState roboticWalking;
	private RoboticState roboticRunning;
	private RoboticState roboticOff;
	//private RoboticState roboticStandby;
	
	private RoboticState state;
	
	public Robot(){
		this.roboticOn = new RoboticOn(this);
		this.roboticWalking = new RoboticWalking(this);
		this.roboticRunning = new RoboticRunning(this);
		this.roboticOff = new RoboticOff(this);
	
		
		this.state = roboticOff;
	}
	
	public void setRoboticState(RoboticState state){
		this.state = state;
	}
	
	
	@Override
	public void on()
	{
		state.on();
		
	}
	
	
	@Override
	public void walk()
	{
		state.walk();
		
	}
	
	
	@Override
	public void bendKnees()
	{
		state.bendKnees();
		
	}
	
		
	
	@Override
	public void jump()
	{
		state.jump();
		
	}
	
		
	@Override
	public void sit()
	{
		state.sit();
		
	}
	
	
	@Override
	public void sideRoll()
	{
		state.sideRoll();
		
	}
	
	
	@Override
	public void frontRoll()
	{
		state.frontRoll();
		
	}
	
	@Override
	public void run()
	{
		state.run();
		
	}
	
		
	@Override
	public void off()
	{
		state.off();
		
	}


	public RoboticState getRoboticOn() {
		return roboticOn;
	}

/*	public void setRoboticOn(RoboticState roboticOn) {
		this.roboticOn = roboticOn;
	}
*/
	public RoboticState getRoboticWalking() {
		return roboticWalking;
	}
	
	
	public RoboticState getRoboticRunning() {
		return roboticRunning;
	}

/*	public void setRoboticCook(RoboticState roboticCook) {
		this.roboticCook = roboticCook;
	}*/

	public RoboticState getRoboticOff() {
		return roboticOff;
	}

	/*public void setRoboticOff(RoboticState roboticOff) {
		this.roboticOff = roboticOff;
	}*/

	public RoboticState getState() {
		return state;
	}

	public void setState(RoboticState state) {
		this.state = state;
	}

	/*public RoboticState getRoboticStandby() {
		return roboticStandby;
	}

	public void setRoboticStandby(RoboticState roboticStandby) {
		this.roboticStandby = roboticStandby;
	}
*/	
}
