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

namespace zad1
{
    /// <summary>
    /// Logika interakcji dla klasy MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private String adres = "Uniwersytet Wrocławski";
        private String uczelnia = "pl. Uniwersytecki 1, 50-137 Wrocław";
        private String cykl = "3-letnie licencjackie";
        private bool dzinne = false;
        private bool uzupelniajace = false;

        public MainWindow()
        {
            InitializeComponent();
        }

        private void ComboBox_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {

        }

        private void OpenWindow(object sender, RoutedEventArgs e)
        {
            uczelnia = TextNazwa.Text;
            adres = TextAdres.Text;
            cykl = Combo1.Text;
            Window1 window1 = new Window1();
            window1.uzupelnij(adres, uczelnia, cykl, dzinne, uzupelniajace);
            window1.Show();
        }

        private void CloseWindow(object sender, RoutedEventArgs e)
        {
            this.Close();
        }

        private void CheckBox_Checked(object sender, RoutedEventArgs e)
        {
            dzinne = true;
        }

        private void CheckBox_Unchecked(object sender, RoutedEventArgs e)
        {
            dzinne = false;
        }

        private void CheckBox_Unchecked_1(object sender, RoutedEventArgs e)
        {
            uzupelniajace = false;
        }

        private void CheckBox_Checked_1(object sender, RoutedEventArgs e)
        {
            uzupelniajace = true;
        }
    }
}
