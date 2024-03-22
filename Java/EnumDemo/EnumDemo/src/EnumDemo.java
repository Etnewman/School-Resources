// Java program to demonstrate how values can 
// be assigned to enums. 
enum TrafficSignal 
{ 
	// This will call enum constructor with one 
	// String argument 
	RED("STOP"), GREEN("GO"), ORANGE("SLOW DOWN"); 

	// declaring private variable for getting values 
	private String action; 

	// getter method 
	public String getAction() 
	{ 
		return this.action; 
	} 

	// enum constructor - cannot be public or protected 
	private TrafficSignal(String action) 
	{ 
		this.action = action; 
	} 
} 

// Driver code 
public class EnumDemo 
{ 
	public static void main(String args[]) 
	{ 
		// let's print name of each enum and there action 
		// - Enum values() examples 
		TrafficSignal[] signals = TrafficSignal.values(); 

		for (TrafficSignal signal : signals) 
		{ 
			// use getter method to get the value 
			System.out.println("name : " + signal.name() + 
						" action: " + signal.getAction() ); 
		} 
	} 
} 
