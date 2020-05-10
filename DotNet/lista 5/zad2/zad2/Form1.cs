using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace zad2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            listBox_auta.Items.Add("Audi");
            listBox_auta.Items.Add("Mercedes");
            listBox_auta.Items.Add("Daewoo");
            listBox_auta.Items.Add("Fiat");
            listBox_auta.Items.Add("BMW");
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void progressBar1_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            this.progressBar_10sec.Value = 0;
            this.timer_10sec.Start();
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            this.progressBar_10sec.Increment(1);

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void listBox_auta_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (listBox_auta.SelectedItem.ToString() == "Audi")
            {
                listView_auta.Visible = true;
                listView_auta.Items.Clear();
                listView_auta.Items.Add("A3");
                listView_auta.Items.Add("RSQ8");
                listView_auta.Items.Add("A4");
                listView_auta.Items.Add("A5");
                listView_auta.Items.Add("RS3");
                listView_auta.Items.Add("R8");
            }
            if (listBox_auta.SelectedItem.ToString() == "Mercedes")
            {
                listView_auta.Visible = true;
                listView_auta.Items.Clear();
                listView_auta.Items.Add("G63 AMG");
                listView_auta.Items.Add("AMG GTR");
                listView_auta.Items.Add("S650");
                listView_auta.Items.Add("A45 AMG");
                listView_auta.Items.Add("C63 AMG");
                listView_auta.Items.Add("E200");
            }
            if (listBox_auta.SelectedItem.ToString() == "Fiat")
            {
                listView_auta.Visible = true;
                listView_auta.Items.Clear();
                listView_auta.Items.Add("500 ABARTH");
                listView_auta.Items.Add("124 ABARTH");
                listView_auta.Items.Add("PUNTO EVO");
                listView_auta.Items.Add("Seicento");
                listView_auta.Items.Add("Panda");
                listView_auta.Items.Add("Multipla");
            }
            if (listBox_auta.SelectedItem.ToString() == "BMW")
            {
                listView_auta.Visible = true;
                listView_auta.Items.Clear();
                listView_auta.Items.Add("E36");
                listView_auta.Items.Add("M5");
                listView_auta.Items.Add("M3");
                listView_auta.Items.Add("I8");
                listView_auta.Items.Add("X5");
                listView_auta.Items.Add("E90");
            }
            if (listBox_auta.SelectedItem.ToString() == "Daewoo")
            {
                listView_auta.Visible = true;
                listView_auta.Items.Clear();
                listView_auta.Items.Add("Nubira");
                listView_auta.Items.Add("Lanos");
                listView_auta.Items.Add("Mariz");
                listView_auta.Items.Add("Espero");
                listView_auta.Items.Add("Tico");
                listView_auta.Items.Add("Leganza");
            }
        }

        private void listView_auta_SelectedIndexChanged(object sender, EventArgs e)
        {
            
        }
    }
}
