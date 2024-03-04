#include <iostream>
#define SIZEOFINTINBITS sizeof(unsigned int)*8

using namespace std;

int main() {
    char answer;
    do {
        int input;
        int count = 0;
        int mask = 0b111;
        cout << "Enter a number: ";
        cin >> input;
        if (!cin) {
            cout << "Invalid input" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        char format[SIZEOFINTINBITS];
        sprintf(format, "%%0%lub\n", SIZEOFINTINBITS); //lu можна замінити на d, але це може призвести до несподіваного результату
        /*cout << format*/; // ця строка виводить форматування, тобто %032b
        printf(format, input);

       /*for (int i = SIZEOFINTINBITS - 1; i >= 0; --i)
            cout << ((input & (1 << i)) ? '1' : '0');
        cout << endl;*/

        for (int i = 0; i < SIZEOFINTINBITS - 2;) { // -2 бо 3 біти
           // cout << "i:" << i << " " << input << " & " << (mask << i) << " = " << (input & (mask << i)) << endl;
            if ((input & (mask << i)) == (mask << i)) {
                count++;
                i += 3;
            } else {
                i++;
            }
        }
        cout << "Count: " << count << endl;
        cout << "press 'n' to exit or any other key to continue: ";
        cin >> answer;
    } while (answer != 'n');
    return 0;
}