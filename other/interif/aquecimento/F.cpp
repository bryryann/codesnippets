#include <bits/stdc++.h>

struct Equipe {
    std::string nome;
    int pontos;
    int vitorias;
    int saldo;
};

enum Resultado {
    Vitoria,
    Derrota,
    Empate,
};

void adiciona_equipe(std::map<std::string, Equipe>& tabela, std::string& nome) {
    Equipe nova_equipe;

    nova_equipe.nome = nome;
    nova_equipe.pontos = 0;
    nova_equipe.saldo = 0;
    nova_equipe.vitorias = 0;

    tabela.insert({nome, nova_equipe});
}

void atualizar_equipe(Equipe& equipe, Resultado resultado, int saldo_gols) {
    switch (resultado) {
    case Resultado::Vitoria:
        equipe.pontos += 3;
        equipe.vitorias++;
        equipe.saldo += saldo_gols;
        break;

    case Resultado::Derrota:
        equipe.saldo -= saldo_gols;
        break;

    case Resultado::Empate:
        equipe.pontos++;
        break;
    }
}

bool comparar_equipes(Equipe *a, Equipe *b) {
    if (a->pontos > b->pontos) {
        return true;
    }
    if (a->pontos < b->pontos) {
        return false;
    }

    if (a->vitorias > b->vitorias) {
        return true;
    }
    if (a->vitorias < b->vitorias) {
        return false;
    }

    if (a->saldo > b->saldo) {
        return true;
    }
    if (a->saldo < b->saldo) {
        return false;
    }

    return a->nome < b->nome;
}

int main() {
    int qnt_equipes, qnt_jogos;
    std::map<std::string, Equipe> tabela;
    std::vector<Equipe*> classificacao;

    std::cin >> qnt_equipes;
    std::cin >> qnt_jogos;

    for (int i = 0; i < qnt_jogos; i++) {
        std::string nome_equipe1, nome_equipe2;
        int gols_equipe1, gols_equipe2;
        char x;

        std::cin >> nome_equipe1 >> gols_equipe1 >> x >> gols_equipe2 >> nome_equipe2;

        if (!tabela.count(nome_equipe1)) {
            adiciona_equipe(tabela, nome_equipe1);
            classificacao.push_back(&tabela[nome_equipe1]);
        }

        if (!tabela.count(nome_equipe2)) {
            adiciona_equipe(tabela, nome_equipe2);
            classificacao.push_back(&tabela[nome_equipe2]);
        }

        if (gols_equipe1 > gols_equipe2) {
            atualizar_equipe(tabela[nome_equipe1], Resultado::Vitoria, gols_equipe1 - gols_equipe2);
            atualizar_equipe(tabela[nome_equipe2], Resultado::Derrota, gols_equipe1 - gols_equipe2);
        }
        else if (gols_equipe1 < gols_equipe2) {
            atualizar_equipe(tabela[nome_equipe2], Resultado::Vitoria, gols_equipe2 - gols_equipe1);
            atualizar_equipe(tabela[nome_equipe1], Resultado::Derrota, gols_equipe2 - gols_equipe1);
        }
        else {
            atualizar_equipe(tabela[nome_equipe2], Resultado::Empate, 0);
            atualizar_equipe(tabela[nome_equipe1], Resultado::Empate, 0);
        }
    }

    std::sort(classificacao.begin(), classificacao.end(), comparar_equipes);

    for (Equipe *equipe : classificacao) {
        std::cout << equipe->nome << " " << equipe->pontos << " " << equipe->vitorias << " " << equipe->saldo << std::endl;
    }

    return 0;
}
