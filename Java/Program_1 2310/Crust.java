public class Crust
{
	private char size;
	private String type;
	
	public Crust(char size, String type)
	{
		this.size = size;
		this.type = type;
	}
	
	public double getCost()
	{
		double totalCost = 0;
		
		if (size == 'S')
			totalCost = totalCost + CrustSize.S.getSize();
		else if (size == 'M')
			totalCost = totalCost + CrustSize.M.getSize();
		else if (size == 'L')
			totalCost = totalCost + CrustSize.L.getSize();
		
		if (type == "THIN")
			totalCost = totalCost + CrustType.THIN.getType();
		else if (type == "HAND")
			totalCost = totalCost + CrustType.HAND.getType();
		else if (type == "PAN")
			totalCost = totalCost + CrustType.PAN.getType();
		
		return totalCost;
	}
	
	public char getSize()
	{
		return size;
	}
	
		public String getCrust()
	{
		return type;
	}
	
	public String toString()
	{
		return new String("size: " + size + " crust: " + type + " \r\n");
	}
	
}

enum CrustSize
{
	S(5.99), M(7.99), L(9.99);
	
	private double size;
	
	public double getSize()
	{
		return this.size;
	}

	private CrustSize(double size)
	{
		this.size = size;
	}
	
}


enum CrustType
{
	THIN(0.00), HAND(0.50), PAN(1.00);
	
	private double type;
	
	public double getType()
	{
		return this.type;
	}
	
	private CrustType(double type)
	{
		this.type = type;
	}
}

	
	
	
	
	
	

