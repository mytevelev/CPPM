#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

int main() {
<<<<<<< HEAD
    // Óñòàíîâêà êîäèðîâêè êîíñîëè íà UTF-8
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    // Çàïðîñ èìåíè ïîëüçîâàòåëÿ
    string name;
    cout << "Ââåäèòå èìÿ: ";
    getline(cin, name);

    // Ïðèâåòñòâèå ïîëüçîâàòåëÿ
    cout << "Çäðàâñòâóéòå, " << name << "!" << endl;
=======
    // Ð£ÑÑ‚Ð°Ð½Ð¾Ð²ÐºÐ° ÐºÐ¾Ð´Ð¸Ñ€Ð¾Ð²ÐºÐ¸ ÐºÐ¾Ð½ÑÐ¾Ð»Ð¸ Ð½Ð° UTF-8
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    // Ð—Ð°Ð¿Ñ€Ð¾Ñ Ð¸Ð¼ÐµÐ½Ð¸ Ð¿Ð¾Ð»ÑŒÐ·Ð¾Ð²Ð°Ñ‚ÐµÐ»Ñ
    string name;
    cout << "Ð’Ð²ÐµÐ´Ð¸Ñ‚Ðµ Ð¸Ð¼Ñ: ";
    getline(cin, name);

    // ÐŸÑ€Ð¸Ð²ÐµÑ‚ÑÑ‚Ð²Ð¸Ðµ Ð¿Ð¾Ð»ÑŒÐ·Ð¾Ð²Ð°Ñ‚ÐµÐ»Ñ
    cout << "Ð—Ð´Ñ€Ð°Ð²ÑÑ‚Ð²ÑƒÐ¹Ñ‚Ðµ, " << name << "!" << endl;
>>>>>>> 3195b580a1c0b895cc74c05c2b45532fe70f1f50

    return 0;
}
