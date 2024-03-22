public class SocketAdapter implements BritishSocketTarget
{
	AmericanPinType americanPin;
	private AmericanSocketAdapteeImpl americanSocket;

	@Override
	public void provideElectricity(BritishPinType britishPin)
	{
		transferCurrent(britishPin, americanPin);
		americanSocket = new AmericanSocketAdapteeImpl();
		americanSocket.provideElectricity(americanPin);
	}

	private void transferCurrent(BritishPinType britishPin, AmericanPinType americanPin)
	{
		// the adapter provides circuit the allows the electricity to flow from
		// a British pin to American pin.
	}

}