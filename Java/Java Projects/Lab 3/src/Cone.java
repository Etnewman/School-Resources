
public class Cone {

	private int coneType;
	
	public Cone (int coneType)
	{
	this.coneType = coneType;
	}
	
	public double getConePrice()
	{
		if (coneType == 1)
			return 0.59;
		else if (coneType == 2)
			return 0.79;
		else
			return 0.00;
	}
	
	public String coneToStr()
	{
		if (coneType == 1)
			return "Sugar Cone";
		else if (coneType == 2)
			return "Waffle Cone";
		else
			return "Cup";
	}
	
}
