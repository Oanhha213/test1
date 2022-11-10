using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace BTTiengAnh
{
    internal class QLFile
    {
        public string readCH(string tentep)
        {
            string s = "";
            StreamReader sr = new StreamReader(tentep);
            s = sr.ReadToEnd();
            sr.Close();
            return s;
        }
        public List<string> readDA(string tentep)
        {
            List<string> list = new List<string>();
            string s = "";
            StreamReader sr = new StreamReader(tentep);
            while((s = sr.ReadLine()) != null)
            {
                list.Add(s);
            }
            sr.Close();
            return list;
        }
    }
}
