#include <iostream>

using namespace std;

int main()
{
    char letter;
    cout << "Digite uma letra .\n";
    cin >> letter;
        if (letter == 'a'||letter =='e'||letter =='i'||letter =='o'||letter =='u'){
            cout << "Essa letra e uma vogal .\n";

        } else {
            cout << "Essa letra e uma consoante .\n";

        }
    return 0;
}
