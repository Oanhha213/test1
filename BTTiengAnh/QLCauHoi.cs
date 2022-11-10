using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BTTiengAnh
{
    internal class QLCauHoi
    {
        string cauhoi;
        List<string> dapan;
        string traloi;

        public QLCauHoi(string cauhoi, List<string> dapan, string traloi)
        {
            this.cauhoi = cauhoi;
            this.dapan = dapan;
            this.traloi = traloi;
        }

        public string Cauhoi { get => cauhoi; set => cauhoi = value; }
        public List<string> Dapan { get => dapan; set => dapan = value; }
        public string Traloi { get => traloi; set => traloi = value; }
    }
}
