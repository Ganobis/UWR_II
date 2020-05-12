using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace zad2
{
    /// <summary>
    /// Logika interakcji dla klasy MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
            listBox_auta.Items.Add("Audi");
            listBox_auta.Items.Add("Mercedes");
            listBox_auta.Items.Add("Daewoo");
            listBox_auta.Items.Add("Fiat");
            listBox_auta.Items.Add("BMW");
        }

        private void listBox_auta_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            if (listBox_auta.SelectedItem.ToString() == "Audi")
            {
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
                listView_auta.Items.Clear();
                listView_auta.Items.Add("500 ABARD");
                listView_auta.Items.Add("124 ABARTH");
                listView_auta.Items.Add("PUNTO EVO");
                listView_auta.Items.Add("Seicento");
                listView_auta.Items.Add("Panda");
                listView_auta.Items.Add("Multipla");
            }
            if (listBox_auta.SelectedItem.ToString() == "BMW")
            {
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
                listView_auta.Items.Clear();
                listView_auta.Items.Add("Nubira");
                listView_auta.Items.Add("Lanos");
                listView_auta.Items.Add("Mariz");
                listView_auta.Items.Add("Espero");
                listView_auta.Items.Add("Tico");
                listView_auta.Items.Add("Leganza");
            }
        }
    }
}
