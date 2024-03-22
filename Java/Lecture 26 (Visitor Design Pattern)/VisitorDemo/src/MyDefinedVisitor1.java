


public class MyDefinedVisitor1 implements VisitorInterface 
{ 

	@Override
	public void visit(Book book) 
	{ 
		// new functionality  
		System.out.println("New added behavior for Book ( ID:" + book.getID()+ " )");
		 
	} 

	@Override
	public void visit(Fruit fruit) 
	{ 
		// new functionality
		System.out.println("New added behavior for Fruit (ID:"+ fruit.getID()+ " )");

	} 

} 
