using System;

namespace MaximumofTwoNumbers
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Enter 2 numbers. Their maximum will be displayed");
            var input1 = Console.ReadLine();
            var input2 = Console.ReadLine();
            var number1 = Convert.ToInt32(input1);
            var number2 = Convert.ToInt32(input2);

            //if (number1 > number2)
                //Console.WriteLine("Number 1 was the max: {0}", number1);
            //else if
                //(number1 == number2)
                //Console.WriteLine("No Max found.");
                //else
                // Console.WriteLine("Number 2 was the max: {0}", number2);
            var max = (number1 > number2) ? number1 : number2;
            Console.WriteLine("Max is " + max);
        }
    }
}
