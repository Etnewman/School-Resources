class ClassModifyer implements Visitor
{
	ClassModifyer(){}
	
	public int visit(PrimaryClass obj)
	{
		System.out.println("\nModifying the Primary Class...\n");
		int tempID = obj.getID() % 5 ;
		System.out.println("The Primary ID has been hashed!\n");
		return tempID;
	}
}

