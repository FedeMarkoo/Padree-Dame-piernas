using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Discografias
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void webBrowser1_DocumentCompleted(object sender, WebBrowserDocumentCompletedEventArgs e)
        {
            asdAsync();
        }

        public async Task asdAsync()
        {
            await Task.Delay(20000);
            MessageBox.Show(webBrowser1.DocumentText);
            webBrowser1.Navigate("https://www.google.com.ar/search?q=los+piojos+albums");
        }
    }
}
