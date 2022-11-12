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
    public partial class FillWord : Form
    {
        List<string> lstDA;
        List<TextBox> txtTL;
        public FillWord(string tepCH, string tepDA)
        {
            InitializeComponent();
            QLFile qlFile = new QLFile();
            rtbCauHoi.Text = qlFile.readCH(tepCH);
            lstDA = qlFile.readDA(tepDA);
            txtTL = new List<TextBox>() {textBox1,textBox2,textBox3,textBox4,textBox5,textBox6,textBox7,textBox8,textBox9,textBox10};
        }

        private void FillWord_Load(object sender, EventArgs e)
        {

        }

        private void btnDapAn_Click(object sender, EventArgs e)
        {
            for(int i=0;i<lstDA.Count;i++)
            {
                txtTL[i].Text = lstDA[i]; 
            }
        }

        private void btnOk_Click(object sender, EventArgs e)
        {
            int diem = 0;
            for(int i = 0; i < lstDA.Count; i++)
            {
                if (lstDA[i].Equals(txtTL[i].Text.Trim(),StringComparison.OrdinalIgnoreCase))
                {
                    diem++;
                    txtTL[i].BackColor = Color.GreenYellow;
                } else
                    txtTL[i].BackColor = Color.Orange;
            }
            MessageBox.Show("Số điểm có " + diem.ToString());
        }

        private void btnExit_Click(object sender, EventArgs e)
        {

        }
    }
}
