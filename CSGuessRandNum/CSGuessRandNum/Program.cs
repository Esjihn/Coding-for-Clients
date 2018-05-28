using System;


namespace CSGuessRandNum
{
    class Program
    {
        static void Main(string[] args)
        {
            var number = new Random().Next(1, 10);
            //Console.WriteLine("Secret is " + number);
            for (var i = 0; i < 4; i++)
            {
                Console.WriteLine("Guess the secret number: ");
                var guess = Convert.ToInt32(Console.ReadLine());

                if (guess == number)
                {
                    Console.WriteLine("You won!");
                    return;
                }
            }
            Console.WriteLine("You Lost!");
        }
    }
}
