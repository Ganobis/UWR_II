using System;
using System.Collections.Generic;
using System.IO;
using System.Xml.Serialization;

namespace zad4
{
    [System.CodeDom.Compiler.GeneratedCodeAttribute("xsd", "4.8.3928.0")]
    [System.SerializableAttribute()]
    [System.Diagnostics.DebuggerStepThroughAttribute()]
    [System.ComponentModel.DesignerCategoryAttribute("code")]
    [System.Xml.Serialization.XmlTypeAttribute(AnonymousType = true, Namespace = "MojeDane")]
    [System.Xml.Serialization.XmlRootAttribute(Namespace = "MojeDane", IsNullable = false)]
    public partial class ListaOsób
    {

        private ListaOsóbOsoba[] itemsField;

        /// <remarks/>
        [System.Xml.Serialization.XmlElementAttribute("Osoba")]
        public ListaOsóbOsoba[] Items
        {
            get
            {
                return this.itemsField;
            }
            set
            {
                this.itemsField = value;
            }
        }
    }

    /// <remarks/>
    [System.CodeDom.Compiler.GeneratedCodeAttribute("xsd", "4.8.3928.0")]
    [System.SerializableAttribute()]
    [System.Diagnostics.DebuggerStepThroughAttribute()]
    [System.ComponentModel.DesignerCategoryAttribute("code")]
    [System.Xml.Serialization.XmlTypeAttribute(AnonymousType = true, Namespace = "MojeDane")]
    public partial class ListaOsóbOsoba
    {

        private string imięField;

        private string nazwiskoField;

        private string dataUrField;

        private string adresStalyField;

        private string adresTymField;

        private ListaOsóbOsobaListaZajęć[] listaZajęćField;

        /// <remarks/>
        public string Imię
        {
            get
            {
                return this.imięField;
            }
            set
            {
                this.imięField = value;
            }
        }

        /// <remarks/>
        public string Nazwisko
        {
            get
            {
                return this.nazwiskoField;
            }
            set
            {
                this.nazwiskoField = value;
            }
        }

        /// <remarks/>
        public string DataUr
        {
            get
            {
                return this.dataUrField;
            }
            set
            {
                this.dataUrField = value;
            }
        }

        /// <remarks/>
        public string AdresStaly
        {
            get
            {
                return this.adresStalyField;
            }
            set
            {
                this.adresStalyField = value;
            }
        }

        /// <remarks/>
        public string AdresTym
        {
            get
            {
                return this.adresTymField;
            }
            set
            {
                this.adresTymField = value;
            }
        }

        /// <remarks/>
        [System.Xml.Serialization.XmlElementAttribute("ListaZajęć")]
        public ListaOsóbOsobaListaZajęć[] ListaZajęć
        {
            get
            {
                return this.listaZajęćField;
            }
            set
            {
                this.listaZajęćField = value;
            }
        }
    }

    /// <remarks/>
    [System.CodeDom.Compiler.GeneratedCodeAttribute("xsd", "4.8.3928.0")]
    [System.SerializableAttribute()]
    [System.Diagnostics.DebuggerStepThroughAttribute()]
    [System.ComponentModel.DesignerCategoryAttribute("code")]
    [System.Xml.Serialization.XmlTypeAttribute(AnonymousType = true, Namespace = "MojeDane")]
    public partial class ListaOsóbOsobaListaZajęć
    {

        private ListaOsóbOsobaListaZajęćZajęcie[] zajęcieField;

        private string nazwaField;

        /// <remarks/>
        [System.Xml.Serialization.XmlElementAttribute("Zajęcie")]
        public ListaOsóbOsobaListaZajęćZajęcie[] Zajęcie
        {
            get
            {
                return this.zajęcieField;
            }
            set
            {
                this.zajęcieField = value;
            }
        }

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public string nazwa
        {
            get
            {
                return this.nazwaField;
            }
            set
            {
                this.nazwaField = value;
            }
        }
    }

    /// <remarks/>
    [System.CodeDom.Compiler.GeneratedCodeAttribute("xsd", "4.8.3928.0")]
    [System.SerializableAttribute()]
    [System.Diagnostics.DebuggerStepThroughAttribute()]
    [System.ComponentModel.DesignerCategoryAttribute("code")]
    [System.Xml.Serialization.XmlTypeAttribute(AnonymousType = true, Namespace = "MojeDane")]
    public partial class ListaOsóbOsobaListaZajęćZajęcie
    {

        private string nazwaField;

        private string ocenaField;

        /// <remarks/>
        public string Nazwa
        {
            get
            {
                return this.nazwaField;
            }
            set
            {
                this.nazwaField = value;
            }
        }

        /// <remarks/>
        public string Ocena
        {
            get
            {
                return this.ocenaField;
            }
            set
            {
                this.ocenaField = value;
            }
        }
    }
    public class Student
    {
        public string Imie;
        public string Nazwisko;
        public string Data;
        public string Adres_Staly;
        public string Adres_Tymczasowy;
        public Zajecia Zajecia;
        public Student(string i, string n, string d, string staly, string tymcz, Zajecia z)
        {
            Imie = i;
            Nazwisko = n;
            Data = d;
            Adres_Staly = staly;
            Adres_Tymczasowy = tymcz;
            Zajecia = z;
        }
        public override string ToString()
        {
            string res = "Imie: " + Imie
                + "\nNazwiasko: " + Nazwisko
                + "\nData urodzenia: " + Data
                + "\nAdres staly: " + Adres_Staly
                + "\nAdres symczasowy: " + Adres_Tymczasowy
                + "\nPrzedmioty i ocena: \n\t";

            foreach (var elem in Zajecia.PrzedmiotOcena)
            {
                res += "" + elem.Key + " -- " + elem.Value + "\n\t";
            }

            return res;
        }
    }
    public class Zajecia
    {
        public Zajecia() { PrzedmiotOcena = new Dictionary<string, string>(); }
        public Dictionary<string, string> PrzedmiotOcena;
    }
    class Program
    {
        static void Main(string[] args)
        {
            XmlSerializer xmlSerializer = new XmlSerializer(typeof(Zajecia));
            FileStream fileStream = new FileStream("dane.xml", FileMode.Open);
            Zajecia deserialize = (Zajecia)xmlSerializer.Deserialize(fileStream);
            fileStream.Close();
        }
    }
}
