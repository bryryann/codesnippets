#include <bits/stdc++.h>

int main() {
    std::string campeao;
    float melhor_salto = -1.0f;
    int n, m;

    std::cin >> n;
    std::cin >> m;

    for (int i = 0; i < n; i++) {
        std::string nome;
        std::cin >> nome;

        float melhor_do_atleta = -1.0f;

        for (int k = 0; k < m; k++) {
            float v;
            std::cin >> v;


            char c;
            if (std::cin.peek() == ' ') {
                std::cin >> c;
                if (c == 'I')  continue;
            }

            if (v > melhor_do_atleta) {
                melhor_do_atleta = v;
            }
        }

        if (melhor_do_atleta > melhor_salto) {
            melhor_salto = melhor_do_atleta;
            campeao = nome;
        }
    }

    std::cout << campeao << std::endl;
    std::cout << std::fixed << std::setprecision(2) << melhor_salto << std::endl;

    return 0;
}
