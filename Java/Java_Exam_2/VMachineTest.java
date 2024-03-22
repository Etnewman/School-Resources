public class VMachineTest {

	public static void main(String[] args) {
		
		VMachine obj = new VMachine(1);
		
		//First Test
		System.out.println(obj);
		
		//First Stress Test 
		obj.insertDollar();
		obj.inputItem();
		obj.cancel();
		
		//Second Test
		System.out.println("\n" + obj + "\n");
		
		//Second Stress Test
		obj.insertDollar();
		obj.inputItem();
		obj.dispense();
		
		//Third Test
		System.out.println("\n" + obj + "\n");
		
		//Third Stress Test
		obj.insertDollar();
		obj.refill(10);
		
		//Fourth Test
		System.out.println("\n" + obj + "\n");
		
		//Final Stress Test
		obj.insertDollar();
		obj.ejectDollar();
		obj.inputItem();
		obj.dispense();
		
		
		//Final Test
		System.out.println("\n" + obj + "\n");
		
	}
}