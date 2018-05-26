using System;

namespace Conditionals
{
    class Program
    {
        static void Main(string[] args)
        {
            var season = Season.Autumn;

            switch(season)
            {
                case Season.Autumn:
                case Season.Summer:
                    Console.WriteLine("It's perfect to go to beach.");
                    break;

                default:
                    Console.WriteLine("I don't understand that season!");
                    break;
            }
        }
    }
}
