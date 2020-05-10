namespace zad2
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
            this.components = new System.ComponentModel.Container();
            this.progressBar_10sec = new System.Windows.Forms.ProgressBar();
            this.label_10sec = new System.Windows.Forms.Label();
            this.button_10sec = new System.Windows.Forms.Button();
            this.listBox_auta = new System.Windows.Forms.ListBox();
            this.timer_10sec = new System.Windows.Forms.Timer(this.components);
            this.label_auta = new System.Windows.Forms.Label();
            this.listView_auta = new System.Windows.Forms.ListView();
            this.label_auta1 = new System.Windows.Forms.Label();
            this.label_auta2 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // progressBar_10sec
            // 
            this.progressBar_10sec.Location = new System.Drawing.Point(158, 60);
            this.progressBar_10sec.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.progressBar_10sec.Name = "progressBar_10sec";
            this.progressBar_10sec.Size = new System.Drawing.Size(482, 29);
            this.progressBar_10sec.Step = 1;
            this.progressBar_10sec.TabIndex = 0;
            this.progressBar_10sec.Click += new System.EventHandler(this.progressBar1_Click);
            // 
            // label_10sec
            // 
            this.label_10sec.AutoSize = true;
            this.label_10sec.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.label_10sec.Location = new System.Drawing.Point(35, 18);
            this.label_10sec.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label_10sec.Name = "label_10sec";
            this.label_10sec.Size = new System.Drawing.Size(245, 18);
            this.label_10sec.TabIndex = 2;
            this.label_10sec.Text = "Aby omierzyć 10 sekund kliknij start!";
            this.label_10sec.Click += new System.EventHandler(this.label2_Click);
            // 
            // button_10sec
            // 
            this.button_10sec.Location = new System.Drawing.Point(38, 60);
            this.button_10sec.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.button_10sec.Name = "button_10sec";
            this.button_10sec.Size = new System.Drawing.Size(65, 29);
            this.button_10sec.TabIndex = 3;
            this.button_10sec.Text = "START";
            this.button_10sec.UseVisualStyleBackColor = true;
            this.button_10sec.Click += new System.EventHandler(this.button1_Click);
            // 
            // listBox_auta
            // 
            this.listBox_auta.FormattingEnabled = true;
            this.listBox_auta.Location = new System.Drawing.Point(38, 154);
            this.listBox_auta.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.listBox_auta.Name = "listBox_auta";
            this.listBox_auta.Size = new System.Drawing.Size(295, 173);
            this.listBox_auta.TabIndex = 4;
            this.listBox_auta.SelectedIndexChanged += new System.EventHandler(this.listBox_auta_SelectedIndexChanged);
            // 
            // timer_10sec
            // 
            this.timer_10sec.Tick += new System.EventHandler(this.timer1_Tick);
            // 
            // label_auta
            // 
            this.label_auta.AutoSize = true;
            this.label_auta.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.label_auta.Location = new System.Drawing.Point(35, 100);
            this.label_auta.Name = "label_auta";
            this.label_auta.Size = new System.Drawing.Size(262, 16);
            this.label_auta.TabIndex = 5;
            this.label_auta.Text = "Przykłądowa lista z różnymi samochodami";
            this.label_auta.Click += new System.EventHandler(this.label1_Click);
            // 
            // listView_auta
            // 
            this.listView_auta.HideSelection = false;
            this.listView_auta.Location = new System.Drawing.Point(370, 154);
            this.listView_auta.Name = "listView_auta";
            this.listView_auta.Size = new System.Drawing.Size(338, 173);
            this.listView_auta.TabIndex = 6;
            this.listView_auta.UseCompatibleStateImageBehavior = false;
            this.listView_auta.SelectedIndexChanged += new System.EventHandler(this.listView_auta_SelectedIndexChanged);
            // 
            // label_auta1
            // 
            this.label_auta1.AutoSize = true;
            this.label_auta1.Location = new System.Drawing.Point(35, 128);
            this.label_auta1.Name = "label_auta1";
            this.label_auta1.Size = new System.Drawing.Size(37, 13);
            this.label_auta1.TabIndex = 7;
            this.label_auta1.Text = "Marka";
            // 
            // label_auta2
            // 
            this.label_auta2.AutoSize = true;
            this.label_auta2.Location = new System.Drawing.Point(367, 128);
            this.label_auta2.Name = "label_auta2";
            this.label_auta2.Size = new System.Drawing.Size(36, 13);
            this.label_auta2.TabIndex = 8;
            this.label_auta2.Text = "Model";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.label_auta2);
            this.Controls.Add(this.label_auta1);
            this.Controls.Add(this.listView_auta);
            this.Controls.Add(this.label_auta);
            this.Controls.Add(this.listBox_auta);
            this.Controls.Add(this.button_10sec);
            this.Controls.Add(this.label_10sec);
            this.Controls.Add(this.progressBar_10sec);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ProgressBar progressBar_10sec;
        private System.Windows.Forms.Label label_10sec;
        private System.Windows.Forms.Button button_10sec;
        private System.Windows.Forms.ListBox listBox_auta;
        private System.Windows.Forms.Timer timer_10sec;
        private System.Windows.Forms.Label label_auta;
        private System.Windows.Forms.ListView listView_auta;
        private System.Windows.Forms.Label label_auta1;
        private System.Windows.Forms.Label label_auta2;
    }
}

