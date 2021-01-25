using System;
using System.Text;
using System.Collections.Generic;

namespace csEncryption
{
    class Program
    {
        static char[] encrypt(string userMessageToBeEncrypted)
        {
            char[] alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ".ToCharArray();
            char[] messageToBeEncrypted = userMessageToBeEncrypted.ToCharArray();
            byte[] asciiBytes = Encoding.ASCII.GetBytes(userMessageToBeEncrypted);
            List<char> charsAfterEncryption = new List<char>();  

            int len = alpha.Length;

            for (int i = 0; i < userMessageToBeEncrypted.Length; i++)
            {
                int asciiCode = (int)asciiBytes[i];
                while (asciiCode > len)
                {
                    if (asciiCode <= len)
                    {
                        charsAfterEncryption.Add(alpha[asciiCode]);
                        break;
                    }
                    asciiCode = asciiCode - len;
                }
            }
            char[] encryptedChars = charsAfterEncryption.ToArray();
            return encryptedChars;
        }
        static void Main(string[] args)
        {
            Console.WriteLine("SafeCrypt v1.0 algorithm by xHeinzDev\n\nPodaj słowo do zaszyfrowania:  ");
            string word = Console.ReadLine();
            char[] encrypted = encrypt(word);
            Console.WriteLine(encrypted);
        }
    }
}
