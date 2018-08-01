using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace Music_Player_Remote
{
    public partial class Form1 : Form
    {
        //private const string Dir = "C:\\Testeo\\Accion.txt";
        private const string Dir = "\\\\FEDE-DESK\\Drive (D)\\Accion.txt";

        public Form1()
        {
            InitializeComponent();
        }

        private void Anterior(object sender, EventArgs e)
        {
            //File.AppendAllText("C:\\Testeo\\Accion.txt", ((System.Windows.Forms.ButtonBase)sender).Text + "\r\n");
        }

        private void Open(object sender, EventArgs e)
        {
            string file = File.ReadAllLines("Lista.dat")[new Random().Next(5000)];
            string command = "open \"" + file + "\" type MPEGVideo alias MyMusic\r\n";
            try
            {
                File.AppendAllText(Dir, command);
            }
            catch (IOException) { }
            catch (UnauthorizedAccessException) { }
        }


        private async void Siguiente(object sender, EventArgs e)
        {
            await Task.Delay(50);
            Close(null,null);
            await Task.Delay(50);
            Open(null, null);
            await Task.Delay(50);
            Play(null, null);
        }

        private void Play(object sender, EventArgs e)
        {
            string command = "play MyMusic\r\n";
            try
            {
                File.AppendAllText(Dir, command);
            }
            catch (IOException) { }
            catch (UnauthorizedAccessException) { }
        }

        private void Pause(object sender, EventArgs e)
        {
            string command = "stop MyMusic\r\n";
            try
            {
                File.AppendAllText(Dir, command);
            }
            catch (IOException) { }
            catch (UnauthorizedAccessException) { }
        }

        private void Close(object sender, EventArgs e)
        {
            string command = "close MyMusic\r\n";
            try
            {
                File.AppendAllText(Dir, command);
            }
            catch (IOException) { }
            catch (UnauthorizedAccessException) { }
        }
    }
}
