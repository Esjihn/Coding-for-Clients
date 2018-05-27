using System;


namespace SpeedCamera
{
    public enum Speeding
    {
        Ok,
        LicenseSuspended
    }
    class Program
    {
        static void Main(string[] args)
        {
            var demerit = 0;
            Console.WriteLine("Welcome to PD Speeding Assessment");
            Console.Write("What was speed limit in area of reading: ");
            var speedlimit = Convert.ToInt32(Console.ReadLine());
            Console.Write("Suspect(s) speed in mph?");
            var suspectspeed = Convert.ToInt32(Console.ReadLine());

            for (int i = speedlimit; i < suspectspeed; i++)
            {
                if (i % 5 == 0)
                    demerit++;
            }

            var result = (demerit > 12) ? Speeding.LicenseSuspended :
                Speeding.Ok;
            Console.WriteLine(" " + result);
            Console.WriteLine("Suspect Demerit Points: " + demerit);
        }
    }
}
