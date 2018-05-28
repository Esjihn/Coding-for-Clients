using System;


namespace CSSumNumArray
{
    class Program
    {
        static void Main(string[] args)
        {
            var sum = 0;
            while (true)
            {
                Console.Write("Enter a number (type 'ok' to exit)");
                var input = Console.ReadLine();

                if (input.ToString() == "ok" || input.ToString() == "OK")
                    break;
                // input.ToLower can also be used here for just "ok"
                sum += Convert.ToInt32(input);
            }
            Console.WriteLine("Sum of all numbers is: " + sum);
        }
    }
}
