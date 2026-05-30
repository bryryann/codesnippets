#include <bits/stdc++.h>

int main() {
    int p1,p2,p3,p4;
    bool acesso = true;

    std::cin >> p1;
    std::cin >> p2;
    std::cin >> p3;
    std::cin >> p4;

    if (p4 >= p3 && p3 >= p2 && p2 >= p1) {
        int soma = p1 + p2 + p3;
        if (p4 != soma) {
            acesso = false;
        }
    } else {
        acesso = false;
    }

    if (acesso) {
        std::cout << "LIBERADO\n";
    } else {
        std::cout << "NEGADO\n";
    }

    return 0;
}
