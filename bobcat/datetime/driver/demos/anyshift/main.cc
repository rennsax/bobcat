#include "main.ih"

int main(int argc, char **argv)
{
    if (argc == 1)
        cout << "\n"
            "   optionally specify:\n"
            "   zone shift (hrs[.5]);  dst (minutes);  req. hours (opt)\n\n";

    getLocal();
    getDesired(argc, argv);

    showLocalTime();            // show the time info based on current zone
    showDesiredTime();          // show the time if requested
    changeHours();              // change the hours setting
}
