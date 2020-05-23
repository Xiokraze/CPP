using Android.App;
using Android.OS;
using Android.Widget;

namespace DnDMobile.Droid
{
    [Activity(Label = "SplashActivity", Theme = "@style/SplashTheme", MainLauncher = true, NoHistory = true)]
    public class SplashActivity : Activity
    {
        protected override void OnCreate(Bundle savedInstanceState)
        {
            base.OnCreate(savedInstanceState);
            StartActivity(typeof(MainActivity));
            Finish();
        }
    }
}