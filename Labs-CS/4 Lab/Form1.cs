using System;
using System.Windows.Forms;

namespace Lab_4___Csh__
{
    public partial class Form1 : Form
    {
        private Mp3Player _mp3Player;

        public Form1()
        {
            InitializeComponent();
        }

        private void btnOpen_Click(object sender, EventArgs e)
        {
            using (OpenFileDialog dlgOpen = new OpenFileDialog())
            {
                dlgOpen.Filter = "Mp3 File|*.mp3";
                dlgOpen.InitialDirectory = Environment.GetFolderPath(Environment.SpecialFolder.MyMusic);

                if(dlgOpen.ShowDialog() == System.Windows.Forms.DialogResult.OK)
                {
                    _mp3Player = new Mp3Player(dlgOpen.FileName);
                    textBox1.Text = dlgOpen.FileName;
                }
            }
        }

        private void btnPlay_Click(object sender, EventArgs e)
        {
            if(_mp3Player != null)
            {
                _mp3Player.Play();
            }
        }

        private void btnStop_Click(object sender, EventArgs e)
        {
            if (_mp3Player != null)
            {
                _mp3Player.Pause();
            }
        }

        private void trackBar1_Scroll(object sender, EventArgs e)
        {
            if (_mp3Player != null)
            {
                _mp3Player.SetVolume(trackBar1.Value);
            }
        }

        private void btnCloseMedia_Click(object sender, EventArgs e)
        {
            if (_mp3Player != null)
                _mp3Player.Stop();
            textBox1.Text = null;
        }
    }
}
