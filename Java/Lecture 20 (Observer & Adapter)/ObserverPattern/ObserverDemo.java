
 
import java.util.ArrayList;
 
public class ObserverDemo {
 
    public static void main(String[] args) {
        Subject subject = new CommentaryObject(new ArrayList<Observer>(), "TweetBook");
        Observer observer = new Friend(subject, "Ethan Newman");
        observer.subscribe();
 
        System.out.println();
 
        Observer observer2 = new SMSUsers(subject, "Jessica Aikens");
        observer2.subscribe();
 
        Commentary cObject = ((Commentary)subject);
        cObject.setDesc("Welcome to live Soccer match");
        cObject.setDesc("Current score 0-0");
 
        System.out.println();
 
        observer2.unSubscribe();
 
        System.out.println();
 
        cObject.setDesc("It's a goal!!");
        cObject.setDesc("Current score 1-0");
 
        System.out.println();
 
        Observer observer3 = new SMSUsers(subject, "Machaela Ramirez");
        observer3.subscribe();
 
        System.out.println();
 
        cObject.setDesc("It's another goal!!");
        cObject.setDesc("Half-time score 2-0");
 
    }
 
}