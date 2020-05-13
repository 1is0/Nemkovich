using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace Lab_4___Csh__
{
    class Mp3Player : IDisposable
    {
        public Mp3Player(string fileName)
        {
            const string form = @"open ""{0}"" type mpegvideo alias MediaFile";
            string Command = String.Format(form, fileName);
            mciSendString(Command, null, 0, IntPtr.Zero);
        }
        public void Play()
        {
            string Command = "play MediaFile";
            mciSendString(Command, null, 0, IntPtr.Zero);
        }
        public void Pause()
        {
            string Command = "pause MediaFile";
            mciSendString(Command, null, 0, IntPtr.Zero);
        }
        public void Stop()
        {
            string Command = "close MediaFile";
            mciSendString(Command, null, 0, IntPtr.Zero);
        }
        public void SetVolume(int volume)
        {
            string command = "setaudio MediaFile volume to " + (volume * 100).ToString();
            mciSendString(command, null, 0, IntPtr.Zero);
        }
        [DllImport("winmm.dll")]
        private static extern long mciSendString(string strCommand, StringBuilder strReturn, int iReturnLength, IntPtr hwndCallback);
        public void Dispose()
        {
            string Command = "close MediaFile";
            mciSendString(Command, null, 0, IntPtr.Zero);
        }
    }
}
