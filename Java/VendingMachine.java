

public class VendingMachine {
 
    final static int ENOUGH_BALANCE = 1;
	final static int LESS_BALANCE = 2;
	final static int DISPENSE_ITEM = 3;
	final static int TRANSACTION_CANCEL = 4;
	final static int OUT_OF_ORDER = 5;
 
	int state = READY;
	int balance = 0;
	  
	public VendingMachine() {
		System.out.println("Vending Machine is ready");
		
		}
	}
  
	public void insertCoin() {
		
		if (state == ENOUGH_BALANCE) {
			System.out.println("You have deposited enough coin");
		} else if (state == LESS_BALANCE) {
			System.out.println("Please insert another coin");
			balance + = coin_value;
            if (balance => 1.5)
              state = ENOUGH_BALANCE;			
		} else if (state == DISPENSE_ITEM) {
			System.out.println("You don't need to insert any coin until your previous selected item is dispensed");
		} else if (state == TRANSACTION_CANCEL) {
        	System.out.println("Your transaction was cancelled. Please wait...");
		} else if (state == OUT_OF_ORDER) {
        	System.out.println("This machine is out of order. Can't insert any coin...");
	}

	public void selectItem() {
		if (state == ENOUGH_BALANCE) {
			System.out.println("Your item has been selected");
			state = DISPENSE_ITEM; 
			dispenseItem();
		} else if (state == LESS_BALANCE) {
			System.out.println("You don't have enough balance to select an item");
		} else if (state == DISPENSE_ITEM) {
			System.out.println("You don't need to insert any coin");
		} else if (state == TRANSACTION_CANCEL) {
        	System.out.println("Your transaction was cancelled. Please wait...");
		} else if (state == OUT_OF_ORDER) {
        	System.out.println("This machine is out of order. Can't insert any coin...");
	}
 
	public void dispenseItem() {
		if (state == SOLD) {
			System.out.println("Turning twice doesn't get you another gumball!");
		} else if (state == NO_QUARTER) {
			System.out.println("You turned but there's no quarter");
		} else if (state == SOLD_OUT) {
			System.out.println("You turned, but there are no gumballs");
		} else if (state == HAS_QUARTER) {
			System.out.println("You turned...");
			state = SOLD;
			dispense();
		}
	}
 
	private void dispense() {
		if (state == SOLD) {
			System.out.println("A gumball comes rolling out the slot");
			count = count - 1;
			if (count == 0) {
				System.out.println("Oops, out of gumballs!");
				state = SOLD_OUT;
			} else {
				state = NO_QUARTER;
			}
		} else if (state == NO_QUARTER) {
			System.out.println("You need to pay first");
		} else if (state == SOLD_OUT) {
			System.out.println("No gumball dispensed");
		} else if (state == HAS_QUARTER) {
			System.out.println("No gumball dispensed");
		}
	}
 
	public void refill(int numGumBalls) {
		this.count = numGumBalls;
		state = NO_QUARTER;
	}

	public String toString() {
		
	}
}


