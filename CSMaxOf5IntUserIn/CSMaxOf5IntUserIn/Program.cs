using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSMaxOf5IntUserIn
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Enter integers seperated by comma: ");
            var input = Console.ReadLine();

            var numbers = input.Split(',');

            // Always assume first number is the max.
            var max = Convert.ToInt32(numbers[0]);

            foreach (var str in numbers)
            {
                var number = Convert.ToInt32(str);
                if (number > max)
                    max = number;
            }
            Console.WriteLine("Max is " + max);

        }
    }
}
