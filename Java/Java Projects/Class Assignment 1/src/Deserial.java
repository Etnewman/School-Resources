import java.io.*;

public class Deserial {

	public static void main(String[] args) {

		try {
			ObjectInputStream in = new ObjectInputStream(new FileInputStream("outfileCA1.txt"));
			Game g1 = (Game)in.readObject();
			Game g2 = (Game)in.readObject();
			
			System.out.println(g1.name + ", " + g1.dateMade + ", " + g1.genre + ", " + g1.price);
			System.out.println(g2.name + ", " + g2.dateMade + ", " + g2.genre + ", " + g2.price);
			
			in.close();
		}catch(Exception g) {System.out.println(g);}

	}

}
