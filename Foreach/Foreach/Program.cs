using System;


namespace Foreach
{
    class Program
    {
        static void Main(string[] args)
        {
            var numbers = new int[] { 1, 2, 3, 4 };

            foreach (var number in numbers)
                Console.WriteLine(number);

        }
    }
}
