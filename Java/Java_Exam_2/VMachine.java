public class VMachine {
	
	State ready;
	State enoughBalance;
	State lessBalance;
	State dispenseItem;
	State transactionCancel;
	State outOfOrder;
	
	State state;
	int numItems = 0;
	
	public VMachine(int numItems)
	{
		enoughBalance = new EnoughBalance(this);
		lessBalance = new LessBalance(this);
		dispenseItem = new DispenseItem(this);
		transactionCancel = new TransactionCancel(this);
		outOfOrder = new OutOfOrder(this);
		ready = new Ready(this);
		
		state = ready;
		
		this.numItems = numItems;
		
		if (numItems > 0)
			state = lessBalance;
		else
			state = outOfOrder;
	}
	
	public void insertDollar()
	{
		state.insertDollar();
	}
	
	public void ejectDollar()
	{
		state.ejectDollar();
	}
	
	public void inputItem()
	{
		state.inputItem();
	}
	
	public void dispense()
	{
		state.dispense();
	}
	
	public void cancel()
	{
		state.cancel();
	}
	
	public void releaseItem()
	{
		System.out.println("An item comes out of the vending machine!");
		if (numItems != 0)
			numItems = numItems - 1;
	}
	
	public int getItems()
	{
		return numItems;
	}
	
	public void refill(int numItems)
	{
		this.numItems += numItems;
		System.out.println("The vending machine was just refilled! It now has: " + numItems + " items in stock.");
		state.refill();
	}
	
	void setState(State state) 
	{
		this.state = state;
	}
	
    public State getState() 
	{
        return state;
    }
	
	public State getReady()
	{
		return ready;
	}
	
	public State getEnoughBalance()
	{
		return enoughBalance;
	}
	
	public State getLessBalance()
	{
		return lessBalance;
	}
	
	public State getDispenseItem()
	{
		return dispenseItem;
	}
	
	public State getTransactionCancel()
	{
		return transactionCancel;
	}
	
	public State getOutOfOrder()
	{
		return outOfOrder;
	}
	
	public String toString()
	{
		StringBuffer result = new StringBuffer();
		result.append("\nBest-Vend, Corp.");
		result.append("\nInventory: " + numItems + " item(s)\n");
		result.append("Vending Machine state: " + state + "\n");
		return result.toString();
	}
}

		
	
	
	
	
	
	
	
	
	
	
	
	