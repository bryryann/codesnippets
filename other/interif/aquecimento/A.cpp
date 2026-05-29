#include <bits/stdc++.h>

int main() {
    std::string nome_monstro;
    int cont{0};

    std::getline(std::cin, nome_monstro);

    for (char c : nome_monstro) {
        switch (std::tolower(c)) {
            case 'a':
                cont++;
                break;
            case 'e':
                cont++;
                break;
            case 'i':
                cont++;
                break;
            case 'o':
                cont++;
                break;
            case 'u':
                cont++;
                break;
            default:
                break;
        }
    }

    std::cout << "frasco " << cont % 3 << std::endl;

    return 0;
}
