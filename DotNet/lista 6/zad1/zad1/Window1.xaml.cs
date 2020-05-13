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
using System.Windows.Shapes;

namespace zad1
{
    /// <summary>
    /// Logika interakcji dla klasy Window1.xaml
    /// </summary>
    public partial class Window1 : Window
    {
        public Window1()
        {
            InitializeComponent();
        }

        public void uzupelnij(String adres, String uczelnia, String cykl, bool dzienne, bool uzupelniajace)
        {
            Uczelnia.Text = uczelnia;
            Adres.Text = adres;
            Okres.Text = cykl;
            if (dzienne & uzupelniajace)
                Czek.Text = "dzienne oraz uzupełniajace";
            else if (dzienne)
                Czek.Text = "dzienne";
            else if (uzupelniajace)
                Czek.Text = "uzupelniajace";
            else
                Czek.Text = "";
        }


        private void Close(object sender, RoutedEventArgs e)
        {
            this.Close();
        }
    }
}
