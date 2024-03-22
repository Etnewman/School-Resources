public class VisitorDriver
{
	public static void main(String args[])
	{
		ClassModifyer objMod = new ClassModifyer();
	
		PrimaryClass obj = new PrimaryClass(108);
	
		System.out.println(obj.accept(objMod) + "\n");
	}
}