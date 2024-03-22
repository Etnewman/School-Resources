class Fruit implements ItemElement 
{ 
	private int pricePerKg; 
	private int weight; 
	private String name; 
	String ID;

	public Fruit(int priceKg, int wt, String nm, String ID) 
	{ 
		this.pricePerKg=priceKg; 
		this.weight=wt; 
		this.name = nm;
		this.ID= ID;
	} 

	public int getPricePerKg() 
	{ 
		return pricePerKg; 
	} 

	public int getWeight() 
	{ 
		return weight; 
	} 

	public String getName() 
	{ 
		return this.name; 
	} 
	
	public String getID() 
	{ 
		return this.ID; 
	} 

	@Override
	public int accept(VisitorInterface visitor) 
	{ 
		visitor.visit(this);
		return 0;  
	} 

} 
