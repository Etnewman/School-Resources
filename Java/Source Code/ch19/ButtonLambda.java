// The example uses Java 8's lambda function to implement
// the action listener
import javax.swing.JButton;
import javax.swing.JFrame;
import java.awt.Color;
import java.awt.Container;
import java.awt.FlowLayout;
//import java.awt.event.ActionEvent;
//import java.awt.event.ActionListener;

public class ButtonLambda extends JFrame //implements ActionListener not needed
{
    public ButtonLambda( )
    {
        setSize(250, 100);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setTitle("Action Listener");
        Container contentPane = getContentPane( );
        contentPane.setLayout(new FlowLayout( ));

        JButton goButton = new JButton("Click Me");
        //goButton.addActionListener(this);   // Modified as shown below
        // Add function directly in the action listener
        goButton.addActionListener(e -> System.out.println("You clicked me!"));
        contentPane.add(goButton);
    }

/* Method no longer needed
    public void actionPerformed(ActionEvent e)
    {
       System.out.println("You clicked me");
    }
*/

    public static void main(String[] args)
    {
        ButtonLambda buttonGui = new ButtonLambda( );
        buttonGui.setVisible(true);
    }
}

