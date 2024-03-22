class Book implements ItemElement 
{ 
	private int price; 
	private String isbnNumber;
	String ID;

	public Book(int cost, String isbn, String ID) 
	{ 
		this.price=cost; 
		this.isbnNumber=isbn; 
		this.ID= ID;
	} 

	public int getPrice() 
	{ 
		return price; 
	} 

	public String getIsbnNumber() 
	{ 
		return isbnNumber; 
	} 

	public String getID() 
	{ 
		return ID; 
	} 
	
	@Override
	public int accept(VisitorInterface visitor) 
	{ 
		visitor.visit(this); 
		return 0;
	} 

} 