public class Friend implements Observer
{
	private final Subject subject;
	private String desc;
	private String userInfo;
	
	public Friend(Subject subject,String userInfo){
		if(subject==null){
			throw new IllegalArgumentException("No friend found.");
		}
		this.subject = subject;
		this.userInfo = userInfo;
	}
	
	public void update(String desc) {
		this.desc = desc;
		display();
	}
	
	
	private void display(){
		System.out.println("["+userInfo+"]: "+desc);
	}
	
	public void subscribe() {
		System.out.println("Sending friend request to " + userInfo + " ...");
		this.subject.subscribeObserver(this);
		System.out.println("Friend added!");
	}


	public void unSubscribe() {
		System.out.println("Unfriending " + userInfo +" ...");
		this.subject.unSubscribeObserver(this);
		System.out.println("Unfriended...");
	}
}
