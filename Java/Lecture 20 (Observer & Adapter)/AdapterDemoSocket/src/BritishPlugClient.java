public class BritishPlugClient
{

	BritishPinType britishPin;
	private SocketAdapter adapter;

	public static void main(String[] args)
	{
		BritishPlugClient plug = new BritishPlugClient();
		plug.connectToSocket();
	}

	private void connectToSocket()
	{
		adapter = new SocketAdapter();
		adapter.provideElectricity(britishPin);
	}
}
