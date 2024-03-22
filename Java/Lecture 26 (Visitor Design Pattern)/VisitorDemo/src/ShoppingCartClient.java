class ShoppingCartClient 
{ 

	public static void main(String[] args) 
	{ 
		ItemElement[] items = new ItemElement[]{new Book(20, "1234", "B00001"),new Book(100, "5678", "B00002"), 
				new Fruit(10, 2, "Banana", "F00001"), new Fruit(5, 5, "Apple" , "F00002")}; 

				
		VisitorInterface newvisitor = new MyDefinedVisitor1();
		for(ItemElement item : items) 
		{ 
			
			item.accept(newvisitor);
		} 
		
	}

} 
