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

namespace WPFAnimation
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
            FirstTextBlock.Visibility = Visibility.Collapsed;
            SecondTextBlock.Visibility = Visibility.Collapsed;
            ThirdTextBlock.Visibility = Visibility.Collapsed;
            FourthTextBlock.Visibility = Visibility.Collapsed;
        }

        private void DisableButton_OnClick(object sender, RoutedEventArgs e)
        {
            this.FirstRadioButton.IsChecked = false;
            this.SecondRadioButton.IsChecked = false;
            this.ThirdRadioButton.IsChecked = false;


        }

        private void ThirdRadioButton_Checked(object sender, RoutedEventArgs e)
        {
            FirstTextBlock.Visibility = Visibility.Collapsed;
            SecondTextBlock.Visibility = Visibility.Collapsed;
            FourthTextBlock.Visibility = Visibility.Collapsed;
            ThirdTextBlock.Visibility = Visibility.Visible;
        }

        private void SecondRadioButton_Checked(object sender, RoutedEventArgs e)
        {
            FirstTextBlock.Visibility = Visibility.Collapsed;
            SecondTextBlock.Visibility = Visibility.Visible;
            ThirdTextBlock.Visibility = Visibility.Collapsed;
            FourthTextBlock.Visibility = Visibility.Collapsed;
        }

        private void FirstRadioButton_Checked(object sender, RoutedEventArgs e)
        {
            FirstTextBlock.Visibility = Visibility.Visible;
            SecondTextBlock.Visibility = Visibility.Collapsed;
            FourthTextBlock.Visibility = Visibility.Collapsed;
            ThirdTextBlock.Visibility = Visibility.Collapsed;
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            FirstTextBlock.Visibility = Visibility.Collapsed;
            SecondTextBlock.Visibility = Visibility.Collapsed;
            FourthTextBlock.Visibility = Visibility.Visible;
            ThirdTextBlock.Visibility = Visibility.Collapsed;
        }
    }
}
