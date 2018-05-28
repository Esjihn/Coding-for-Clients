using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    public enum ImageOrientation
    {
        LandScape,
        Portrait
    }
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Program Determines Picture Orientation");

            Console.WriteLine("Enter Portrait Width");
            var width = Convert.ToInt32(Console.ReadLine());


            Console.WriteLine("Enter Portait Height");
            var height = Convert.ToInt32(Console.ReadLine());

            //string pr = "portrait";
            //string ld = "landscape";

            // var orientation = (width > height) ? ld : pr;
            //  Console.WriteLine("Picture orientation is " + orientation);

            // Using enum class instead of strings.
            var orientation = (width > height) ? ImageOrientation.LandScape :
               ImageOrientation.Portrait;
            Console.WriteLine("picture orientation is " + orientation);

        }
    }
}
