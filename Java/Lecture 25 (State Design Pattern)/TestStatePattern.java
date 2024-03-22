
public class TestStatePattern {

	public static void main(String[] args) {
		Robot robot = new Robot();
		robot.on();
		robot.walk();
		robot.walk();
		robot.off();
		robot.off();
		
		
		robot.on();
		robot.walk();
		robot.run();
		robot.on();
		robot.walk();
		

	}

}
