import java.util.ArrayList;
import java.util.List;

public class MasterMindAIRandom implements MasterMindAI
{
   private MasterMind game;

   public MasterMindAIRandom(MasterMind game)  
   {
      this.game = game;
   }


   public Guess nextGuess(int guess_id)
   {
      return makeRandomGuess(guess_id);
   }

   private static Guess makeRandomGuess(int guess_id)
   {
      Guess random_guess = new Guess(guess_id);
	  Random r = Random.getRandomNumberGenerator();
      for (int i = 1; i <= 4; i++)
      {
         int random_int = r.randomInt(1, 7);
		 random_guess.addGuess(random_int);
         //add the random int to your guess list
		 
      }

      return random_guess;
   }
}