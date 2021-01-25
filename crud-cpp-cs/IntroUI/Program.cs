using System;
using IntroLibrary;

namespace IntroUI
{
    class Program
    {
        static void Main(string[] args)
        {
            PersonModel p = new PersonModel
            {
                FirstName = "Tim",
                LastName = "Corey"
            };

            System.Console.WriteLine($"{ p.FirstName  } { p.LastName } is my name");

            Console.WriteLine("Hello World!");
            Console.WriteLine("This is a test");
            System.Console.WriteLine("The end");
        }
    }
}
