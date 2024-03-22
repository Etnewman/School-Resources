import java.util.ArrayList;

public class LambdaLargestName
{
	public static void main(String[] args)
	{
		// Some sample names
		ArrayList<String> names = new ArrayList<>();
		names.add("Paco");
		names.add("Enrique");
		names.add("Bob");

		// Get the largest name as defined by length using a lambda function
		String s = names.stream()
		     .reduce("", (n1, n2) ->
		             {
		               if (n1.length() > n2.length())
		                     return n1;
		               else
		                     return n2;
		             }
		            );
		System.out.println("longest Name: " + s);

	}
}