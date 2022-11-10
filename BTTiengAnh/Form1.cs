using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace BTTiengAnh
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            
        }

        private void đTBài1ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            string fileCH = "E:\\LTTQ\\Cauhoi\\Cauhoi1.txt";
            string fileDA = "E:\\LTTQ\\Cauhoi\\Cauhoi1DapAn.txt";
            FillWord fw = new FillWord(fileCH, fileDA);
            fw.ShowDialog();
        }

        private void đTBài2ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            string fileCH = "E:\\LTTQ\\Cauhoi\\Cauhoi2.txt";
            string fileDA = "E:\\LTTQ\\Cauhoi\\Cauhoi2DapAn.txt";
            FillWord fw = new FillWord(fileCH, fileDA);
            fw.ShowDialog();
        }
    }
}
