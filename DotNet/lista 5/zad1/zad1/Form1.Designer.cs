namespace zad1
{
    partial class Form1
    {
        /// <summary>
        /// Wymagana zmienna projektanta.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Wyczyść wszystkie używane zasoby.
        /// </summary>
        /// <param name="disposing">prawda, jeżeli zarządzane zasoby powinny zostać zlikwidowane; Fałsz w przeciwnym wypadku.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Kod generowany przez Projektanta formularzy systemu Windows

        /// <summary>
        /// Metoda wymagana do obsługi projektanta — nie należy modyfikować
        /// jej zawartości w edytorze kodu.
        /// </summary>
        private void InitializeComponent()
        {
            this.group_Uczlnia = new System.Windows.Forms.GroupBox();
            this.label_Adres = new System.Windows.Forms.Label();
            this.label_Nazwa = new System.Windows.Forms.Label();
            this.textBox_Adres = new System.Windows.Forms.TextBox();
            this.textBox_Nazwa = new System.Windows.Forms.TextBox();
            this.group_Rodzaj = new System.Windows.Forms.GroupBox();
            this.label_Cykl = new System.Windows.Forms.Label();
            this.checkBox_Uzupelniajace = new System.Windows.Forms.CheckBox();
            this.checkBox_Dzienne = new System.Windows.Forms.CheckBox();
            this.comboBox_CyklNauki = new System.Windows.Forms.ComboBox();
            this.button_Akceptuj = new System.Windows.Forms.Button();
            this.button_Anuluj = new System.Windows.Forms.Button();
            this.group_Uczlnia.SuspendLayout();
            this.group_Rodzaj.SuspendLayout();
            this.SuspendLayout();
            // 
            // group_Uczlnia
            // 
            this.group_Uczlnia.Controls.Add(this.label_Adres);
            this.group_Uczlnia.Controls.Add(this.label_Nazwa);
            this.group_Uczlnia.Controls.Add(this.textBox_Adres);
            this.group_Uczlnia.Controls.Add(this.textBox_Nazwa);
            this.group_Uczlnia.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.25F);
            this.group_Uczlnia.Location = new System.Drawing.Point(12, 12);
            this.group_Uczlnia.Name = "group_Uczlnia";
            this.group_Uczlnia.Size = new System.Drawing.Size(776, 147);
            this.group_Uczlnia.TabIndex = 0;
            this.group_Uczlnia.TabStop = false;
            this.group_Uczlnia.Text = "Uczelnia";
            this.group_Uczlnia.Enter += new System.EventHandler(this.groupBox1_Enter);
            // 
            // label_Adres
            // 
            this.label_Adres.AutoSize = true;
            this.label_Adres.Location = new System.Drawing.Point(33, 99);
            this.label_Adres.Name = "label_Adres";
            this.label_Adres.Size = new System.Drawing.Size(49, 17);
            this.label_Adres.TabIndex = 4;
            this.label_Adres.Text = "Adres:";
            // 
            // label_Nazwa
            // 
            this.label_Nazwa.AutoSize = true;
            this.label_Nazwa.Location = new System.Drawing.Point(33, 43);
            this.label_Nazwa.Name = "label_Nazwa";
            this.label_Nazwa.Size = new System.Drawing.Size(54, 17);
            this.label_Nazwa.TabIndex = 3;
            this.label_Nazwa.Text = "Nazwa:";
            this.label_Nazwa.Click += new System.EventHandler(this.label1_Click);
            // 
            // textBox_Adres
            // 
            this.textBox_Adres.Location = new System.Drawing.Point(115, 96);
            this.textBox_Adres.Name = "textBox_Adres";
            this.textBox_Adres.Size = new System.Drawing.Size(635, 23);
            this.textBox_Adres.TabIndex = 1;
            // 
            // textBox_Nazwa
            // 
            this.textBox_Nazwa.Location = new System.Drawing.Point(115, 40);
            this.textBox_Nazwa.Name = "textBox_Nazwa";
            this.textBox_Nazwa.Size = new System.Drawing.Size(635, 23);
            this.textBox_Nazwa.TabIndex = 0;
            // 
            // group_Rodzaj
            // 
            this.group_Rodzaj.Controls.Add(this.label_Cykl);
            this.group_Rodzaj.Controls.Add(this.checkBox_Uzupelniajace);
            this.group_Rodzaj.Controls.Add(this.checkBox_Dzienne);
            this.group_Rodzaj.Controls.Add(this.comboBox_CyklNauki);
            this.group_Rodzaj.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.25F);
            this.group_Rodzaj.Location = new System.Drawing.Point(12, 165);
            this.group_Rodzaj.Name = "group_Rodzaj";
            this.group_Rodzaj.Size = new System.Drawing.Size(776, 133);
            this.group_Rodzaj.TabIndex = 1;
            this.group_Rodzaj.TabStop = false;
            this.group_Rodzaj.Text = "Rodzaj Studiów";
            this.group_Rodzaj.Enter += new System.EventHandler(this.Rodzaj_Studiow_Enter);
            // 
            // label_Cykl
            // 
            this.label_Cykl.AutoSize = true;
            this.label_Cykl.Location = new System.Drawing.Point(33, 58);
            this.label_Cykl.Name = "label_Cykl";
            this.label_Cykl.Size = new System.Drawing.Size(76, 17);
            this.label_Cykl.TabIndex = 5;
            this.label_Cykl.Text = "Cykl nauki:";
            // 
            // checkBox_Uzupelniajace
            // 
            this.checkBox_Uzupelniajace.AutoSize = true;
            this.checkBox_Uzupelniajace.Location = new System.Drawing.Point(260, 106);
            this.checkBox_Uzupelniajace.Name = "checkBox_Uzupelniajace";
            this.checkBox_Uzupelniajace.Size = new System.Drawing.Size(114, 21);
            this.checkBox_Uzupelniajace.TabIndex = 2;
            this.checkBox_Uzupelniajace.Text = "uzupełniające";
            this.checkBox_Uzupelniajace.UseVisualStyleBackColor = true;
            // 
            // checkBox_Dzienne
            // 
            this.checkBox_Dzienne.AutoSize = true;
            this.checkBox_Dzienne.Location = new System.Drawing.Point(115, 106);
            this.checkBox_Dzienne.Name = "checkBox_Dzienne";
            this.checkBox_Dzienne.Size = new System.Drawing.Size(77, 21);
            this.checkBox_Dzienne.TabIndex = 1;
            this.checkBox_Dzienne.Text = "dzienne";
            this.checkBox_Dzienne.UseVisualStyleBackColor = true;
            // 
            // comboBox_CyklNauki
            // 
            this.comboBox_CyklNauki.FormattingEnabled = true;
            this.comboBox_CyklNauki.Items.AddRange(new object[] {
            "3-letni",
            "3,5-letni",
            "5-letni"});
            this.comboBox_CyklNauki.Location = new System.Drawing.Point(115, 55);
            this.comboBox_CyklNauki.Name = "comboBox_CyklNauki";
            this.comboBox_CyklNauki.Size = new System.Drawing.Size(635, 25);
            this.comboBox_CyklNauki.TabIndex = 0;
            this.comboBox_CyklNauki.SelectedIndexChanged += new System.EventHandler(this.comboBox_CyklNauki_SelectedIndexChanged);
            // 
            // button_Akceptuj
            // 
            this.button_Akceptuj.Location = new System.Drawing.Point(12, 317);
            this.button_Akceptuj.Name = "button_Akceptuj";
            this.button_Akceptuj.Size = new System.Drawing.Size(75, 23);
            this.button_Akceptuj.TabIndex = 2;
            this.button_Akceptuj.Text = "Akceptuj";
            this.button_Akceptuj.UseVisualStyleBackColor = true;
            // 
            // button_Anuluj
            // 
            this.button_Anuluj.Location = new System.Drawing.Point(687, 317);
            this.button_Anuluj.Name = "button_Anuluj";
            this.button_Anuluj.Size = new System.Drawing.Size(75, 23);
            this.button_Anuluj.TabIndex = 3;
            this.button_Anuluj.Text = "Anuluj";
            this.button_Anuluj.UseVisualStyleBackColor = true;
            this.button_Anuluj.Click += new System.EventHandler(this.button_Anuluj_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 362);
            this.Controls.Add(this.button_Anuluj);
            this.Controls.Add(this.button_Akceptuj);
            this.Controls.Add(this.group_Rodzaj);
            this.Controls.Add(this.group_Uczlnia);
            this.Name = "Form1";
            this.Text = "Wybór uczelni";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.group_Uczlnia.ResumeLayout(false);
            this.group_Uczlnia.PerformLayout();
            this.group_Rodzaj.ResumeLayout(false);
            this.group_Rodzaj.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox group_Uczlnia;
        private System.Windows.Forms.GroupBox group_Rodzaj;
        private System.Windows.Forms.Label label_Nazwa;
        private System.Windows.Forms.TextBox textBox_Adres;
        private System.Windows.Forms.TextBox textBox_Nazwa;
        private System.Windows.Forms.CheckBox checkBox_Uzupelniajace;
        private System.Windows.Forms.CheckBox checkBox_Dzienne;
        private System.Windows.Forms.ComboBox comboBox_CyklNauki;
        private System.Windows.Forms.Button button_Akceptuj;
        private System.Windows.Forms.Button button_Anuluj;
        private System.Windows.Forms.Label label_Adres;
        private System.Windows.Forms.Label label_Cykl;
    }
}

