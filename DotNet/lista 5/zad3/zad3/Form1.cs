using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace zad3
{
    public partial class Form1 : Form
    {
        Timer t = new Timer();
        Bitmap bitmap;
        Graphics g;
        public Form1()
        {
            InitializeComponent();
        }

        private void t_Thic(object sender, EventArgs e)
        {
            g = Graphics.FromImage(bitmap);

            int s = DateTime.Now.Second;
            int m = DateTime.Now.Minute;
            int h = DateTime.Now.Hour;

            Point handCoord = new Point();

            g.Clear(Color.Blue);

            g.DrawEllipse(new Pen(Color.Yellow, 1f), 0, 0, 300, 300);

            handCoord = zegar_stopnie_min(s);
            g.DrawLine(new Pen(Color.Red, 1f), new Point(150, 150), handCoord);

            handCoord = zegar_stopnie_min(m);
            g.DrawLine(new Pen(Color.Yellow, 2f), new Point(150, 150), handCoord);

            handCoord = zegar_stopnie_hr(h%12, m);
            g.DrawLine(new Pen(Color.Yellow, 3f), new Point(150, 150), handCoord);

            pictureBox1.Image = bitmap;

            g.Dispose();
        }

        private Point zegar_stopnie_min(int val)
        {
            int ret1, ret2;
            val *= 6;
            
            if(val >= 0 && val <= 180)
            {
                ret1 = 150 + (int)(100 * Math.Sin(Math.PI * val / 180));
                ret2 = 150 - (int)(100 * Math.Cos(Math.PI * val / 180));
            }
            else
            {
                ret1 = 150 - (int)(100 * -Math.Sin(Math.PI * val / 180));
                ret2 = 150 - (int)(100 * Math.Cos(Math.PI * val / 180));
            }

            return new Point(ret1, ret2);
        }

        private Point zegar_stopnie_hr(int hval, int mval)
        {
            int ret1, ret2;


            int val = (int)((hval * 30) + (mval * 0.5));

            if (val >= 0 && val <= 180)
            {
                ret1 = 150 + (int)(80 * Math.Sin(Math.PI * val / 180));
                ret2 = 150 - (int)(80 * Math.Cos(Math.PI * val / 180));
            }
            else
            {
                ret1 = 150 - (int)(80 * -Math.Sin(Math.PI * val / 180));
                ret2 = 150 - (int)(80 * Math.Cos(Math.PI * val / 180));
            }

            return new Point(ret1, ret2);
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            bitmap = new Bitmap(301, 301);
            this.BackColor = Color.Blue;

            t.Interval = 1000;
            t.Tick += new EventHandler(this.t_Thic);
            t.Start();
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {

        }
    }
}
