import java.util.ArrayList;

//note: normally a MerkleTree would also have a way to lookup and verify the authenicity of individual transactions, although for this program we just care about calculating the Merkle Root


public class MerkleTree {
	
    private ArrayList<String> tranList; //in reality, we would want to encrypt our transaction list, although it is not necessary for our simulation purposes
    private ArrayList<String> hashTranList;
	private String root;
	
	//DO THIS
	//Merkle Tree Constructor
    public MerkleTree(ArrayList<String> tranList) {
		//update your transaction list
		this.tranList = tranList;
		
		//instantiate your hashed transaction list
		
		this.hashTranList = new ArrayList<String>();

		
		//add SHA 256 hashes of your transaction list to our hashed transaction list
		
		for (String indvTran : tranList)
		{
			hashTranList.add(SHA256.getSHA(indvTran));
		}
		
    }
 
	//concatenate two strings and then calculate and return a SHA256 hash
    private String concatenateHash(String str1, String str2) {
		String result = str1.concat(str2);
		return SHA256.getSHA(result);
  
    }
	
	//return the transaction list
	public ArrayList<String> getTranList() {
		return tranList;
	}
	
	//returns the hashed transaction list
	public ArrayList<String> getHashTranList() {
		return hashTranList;
	}
	
	//Convenience method
	//call the recursive getMerkleRoot method passing in the hashed transaction list & return the first item in the ArrayList
    public String getMerkleRoot() {
		return getMerkleRoot(hashTranList).get(0);


    }
	
	//method to recursively calculate our Merkle Root
    private ArrayList<String> getMerkleRoot(ArrayList<String> hashTranList) {
		//grab the size of the hashed transaction list
        int sizeHash = hashTranList.size();
 
		//if we only have a single item in the list, it is our Merkle Root (exit condition for recursion)
		if (sizeHash == 1)
		{
			return hashTranList;
		}

		
		//create and instantiate a temporary ArrayList of Strings
		ArrayList<String> tempList = new ArrayList<String>();
 
 
		//concatenate and hash each subsequent pair of transactions (use concatenateHash method)
		for (int i = 0; i < sizeHash-1; i+=2)
		{
			tempList.add(concatenateHash(hashTranList.get(i), hashTranList.get(i+1)));
		}
		
 
		//if we do not have an even amount of transactions, concatenate the last transaction with itself & hash	
		if (sizeHash % 2 != 0)
		{
			tempList.add(concatenateHash(hashTranList.get(sizeHash-1), hashTranList.get(sizeHash-1)));
		}
        
		
		
		//recursively return this method, passing in our temporary ArrayList (each call reduces the size of our list, until only one item remains
        return getMerkleRoot(tempList);
		
		
		
    }
 
 
}