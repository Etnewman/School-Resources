public class DispenseItem implements State {

	VMachine obj;
	
	public DispenseItem(VMachine obj)
	{
		this.obj=obj;
	}
	
	public void insertDollar()
	{
		System.out.println("Please wait! Dispensing item...");
	}
	
	public void ejectDollar()
	{
		System.out.println("You've already bought the item, you cannot eject now!");
	}
	
	public void inputItem()
	{
		System.out.println("Item already selected. Dispensing...");
	}
	
	public void dispense()
	{
		obj.releaseItem();
		
		if (obj.getItems() > 0)
			obj.setState(obj.getLessBalance());
		else
		{
			System.out.println("Oops! Out of items!");
			obj.setState(obj.getOutOfOrder());
		}
	}
	
	public void cancel()
	{
		System.out.println("Cancelling Transaction...");
		obj.setState(obj.getTransactionCancel());
	}
	
	public void refill() {}
	
	public String toString()
	{
		return "Now dispensing item.";
	}
}

			