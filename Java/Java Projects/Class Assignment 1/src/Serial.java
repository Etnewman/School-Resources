import java.io.*;

public class Serial {

	public static void main(String[] args) {

		try {
		Game g1 = new Game("League of Legends", "October 27, 2009", "MOBA", 0.00);
		Game g2 = new Game("Horizon Zero Dawn", "February 28, 2017", "Sci-Fi, RPG", 59.99);
		
		FileOutputStream fout = new FileOutputStream("outfileCA1.txt");
		ObjectOutputStream out = new ObjectOutputStream(fout);
		out.writeObject(g1);
		out.writeObject(g2);
		out.flush();

		out.close();
		}catch(Exception g) {System.out.println(g);}
		
		try {
		ObjectInputStream inStream = new ObjectInputStream(new FileInputStream("outfileCA1"));
		
		
		
		
	}
}