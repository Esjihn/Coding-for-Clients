using System;


namespace NumbersDivBy3
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Numbers divided by 3 with no remainder 0-100");
            var count = 0;
            for (int i = 0; i <= 100; i++)
            {
                if (i % 3 == 0)
                    //Console.WriteLine(i);
                    count++;
            }
            Console.WriteLine("There are {0} numbers divisible by 3 between 1 " +
                "and 100.", count);
        }
    }
}
