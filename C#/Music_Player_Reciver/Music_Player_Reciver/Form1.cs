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

namespace Music_Player_Reciver
{
    public partial class Form1 : Form
    {
        private const string Path = "\\\\FEDE-DESK\\Drive (D)\\Accion.txt";
        //private const string Path = "C:\\Testeo\\Accion.txt";
        private Music Cancion = new Music();
        internal Music Song { get => Cancion; set => Cancion = value; }

        public Form1()
        {
            InitializeComponent();
            LeerStado();
        }

        public async void LeerStado()
        {
            while (true)
            {
                try
                {
                    if (File.Exists(Path))
                    {
                        string[] comandos = File.ReadAllLines(Path);
                        File.Delete(Path);
                        if (comandos.Length > 0)
                        {
                            bool i = false;
                            foreach (string line in comandos)
                            {
                                Cancion.comando(line);
                                Text = line;
                            }
                        }
                    }
                }
                catch (System.IO.IOException e) { e.ToString(); }
                await Task.Delay(200);
            }
        }
    }
}
