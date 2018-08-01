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

namespace SpamerFace
{
    public partial class Form1 : Form
    {
        string link;
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void webBrowser1_DocumentCompleted(object sender, WebBrowserDocumentCompletedEventArgs e)
        {

        }

        public void inicio()
        {
            navegador.Navigate(new Uri ("https://www.facebook.com/share.php?"+link));
        }

        void getTodo()
        {
            FileStream pf = new FileStream("HorariosSeteados", FileMode.Open);
            byte []aux=new byte[50];
            pf.Read(aux, 0,50);\

        }

    }
}
