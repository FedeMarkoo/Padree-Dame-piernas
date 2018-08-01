using System.Runtime.InteropServices;
using System.Text;

namespace Music_Player_Reciver
{
    class Music
    {
        //To import the dll winmn.dll which allows to play mp3 files
        [DllImport("winmm.dll")]
        private static extern long mciSendString(string lpstrCommand, StringBuilder lpstrReturnString,
            int uReturnLength, int hwndCallback);
        //To open a file to our application
        public void Open(string file)
        {
            string command = "open \"" + file + "\" type MPEGVideo alias MyMusic";
            mciSendString(command, null, 0, 0);
        }

        public void comando(string com)
        {
            mciSendString(com, null, 0, 0);
        }

        //To play the file
        public void Play()
        {
            if (!Reproduciendo())
            {
                string command = "play MyMusic";
                StringBuilder returnData = new StringBuilder();
                mciSendString(command, null, 0, 0);
            }
            else
            {
                string command = "stop MyMusic";
                mciSendString(command, null, 0, 0);
            }
        }

        //To pause the file
        public void Pause()
        {
                string command = "stop MyMusic";
                mciSendString(command, null, 0, 0);
        }

        public void Volumen(int vol)
        {
            mciSendString("setaudio MyMusic volume to " + vol, null, 0, 0);
        }

        public bool Reproduciendo()
        {
            StringBuilder returnData = new StringBuilder();
            mciSendString("status MyMusic mode", returnData, 128, 0);
            return returnData.ToString() == "playing";
        }

        public string Position()
        {
            StringBuilder returnData = new StringBuilder();
            mciSendString("status MyMusic position", returnData, 128, 0);
            System.Int32.TryParse(returnData.ToString(), out int i);
            int min = i / (60 * 1000);
            int seg = (i / 1000 - (min * 60));
            if (seg < 10)
                return min + ":0" + seg;
            else
                return min + ":" + seg;
        }

        public string Duration()
        {
            StringBuilder returnData = new StringBuilder();
            mciSendString("status MyMusic length", returnData, 128, 0);
            System.Int32.TryParse(returnData.ToString(), out int i);
            int min = i / (60 * 1000);
            int seg = (i / 1000 - (min * 60));
            if (seg < 10)
                return min + ":0" + seg;
            else
                return min + ":" + seg;
        }

        //To stop the file
        public void Stop()
        {
            string command = "stop MyMusic";
            mciSendString(command, null, 0, 0);
            command = "close MyMusic";
            mciSendString(command, null, 0, 0);
        }
    }
}

