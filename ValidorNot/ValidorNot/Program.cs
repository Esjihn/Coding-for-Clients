using System;


namespace ValidorNot
{
    class Program
    {
        static void Main(string[] args)
        {
            

            Console.Write("Please enter a number between 1 and 10: ");
            var number = Convert.ToInt32(Console.ReadLine());

            if (number >= 1 && number <= 10)
            {
                Console.WriteLine("Valid");
            }
            else
                Console.WriteLine("Not Valid");
        
        }
    }
}
