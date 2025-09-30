//
// Created by GAD24 on 29/09/2025.
//

#include "Sauvegarde.h"
#include "../Mediatheque/Mediatheque.h"

#include "../Ressource/Livre/Livre.h"
#include "../Ressource/Livre/Revue/Revue.h"
#include "../Ressource/CD/CD.h"
#include "../Ressource/VHS/VHS.h"
#include "../Ressource/VHS/DVD/DVD.h"
#include "../Ressource/Numerique/Numerique.h"

#include <fstream>
#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <filesystem>

#ifndef PROJECT_DATA_DIR
#define PROJECT_DATA_DIR "."
#endif

namespace {
    namespace fs = std::filesystem;

    fs::path resolveToDataDir(const std::string &userPath, const std::string &defaultName = "save.txt", bool createDirs = true) {
        fs::path p = userPath.empty() ? fs::path(defaultName) : fs::path(userPath);

        if (!p.is_absolute()) {
            p = fs::path(PROJECT_DATA_DIR) / p;
        }
        if (createDirs && !p.parent_path().empty()) {
            std::error_code ec;
            fs::create_directories(p.parent_path(), ec);
        }
        return p;
    }
}

static std::string escapeField(const std::string &s) {
    std::string out;
    out.reserve(s.size());
    for (char c: s) {
        if (c == '\\' || c == ';' || c == '|' || c == '=') {
            out.push_back('\\');
            out.push_back(c);
        } else if (c == '\n' || c == '\r') {
            out.push_back('\\');
            out.push_back('n');
        } else out.push_back(c);
    }
    return out;
}

static std::string unescapeField(const std::string &s) {
    std::string out;
    out.reserve(s.size());
    bool esc = false;
    for (char c: s) {
        if (esc) {
            out.push_back(c == 'n' ? '\n' : c);
            esc = false;
        } else if (c == '\\') esc = true;
        else out.push_back(c);
    }
    return out;
}

static std::vector<std::string> splitEscaped(const std::string &line) {
    std::vector<std::string> cols;
    std::string cur;
    bool esc = false;
    for (char c: line) {
        if (esc) {
            cur.push_back('\\');
            cur.push_back(c);
            esc = false;
        } else if (c == '\\') esc = true;
        else if (c == ';') {
            cols.push_back(unescapeField(cur));
            cur.clear();
        } else cur.push_back(c);
    }
    cols.push_back(unescapeField(cur));
    return cols;
}

static std::string encodeArticles(const std::map<int, std::string> &arts) {
    std::string s;
    bool first = true;
    for (auto &[k, v]: arts) {
        if (!first) s.push_back('|');
        first = false;
        s += std::to_string(k);
        s.push_back('=');
        s += escapeField(v);
    }
    return s;
}

static std::map<int, std::string> decodeArticles(const std::string &s) {
    std::map<int, std::string> arts;
    std::string tok;
    bool esc = false;
    std::vector<std::string> tokens;
    for (char c: s) {
        if (esc) {
            tok.push_back('\\');
            tok.push_back(c);
            esc = false;
        } else if (c == '\\') esc = true;
        else if (c == '|') {
            tokens.push_back(unescapeField(tok));
            tok.clear();
        } else tok.push_back(c);
    }
    tokens.push_back(unescapeField(tok));
    for (auto &t: tokens) {
        auto pos = t.find('=');
        if (pos == std::string::npos) continue;
        int k = std::stoi(t.substr(0, pos));
        std::string v = t.substr(pos + 1);
        arts[k] = v;
    }
    return arts;
}

namespace sauvegarde {

    bool save(const std::string &path, const Mediatheque &m) {
        fs::path p = resolveToDataDir(path, "save.txt", true);
        std::ofstream out(p, std::ios::binary);
        if (!out) {
            std::cerr << "Erreur: impossible d'ouvrir " << p.string() << " en écriture.\n";
            return false;
        }

        out << "#TYPE;id;titre;auteur;annee;...;statut\n";

        auto snap = m.snapshot(); // vector<pair<int,const Ressource*>>

        for (const auto &[id, r]: snap) {
            int s = static_cast<int>(r->getStatut());

            if (auto rev = dynamic_cast<const Revue *>(r)) {
                out << "REVUE" << ';' << id << ';'
                    << escapeField(r->getTitre()) << ';'
                    << escapeField(r->getAuteur()) << ';'
                    << r->getAnneeCreation() << ';'
                    << rev->getNbPages() << ';'
                    << escapeField(rev->getCollection()) << ';'
                    << escapeField(rev->getResume()) << ';'
                    << escapeField(rev->getEditeur()) << ';'
                    << rev->getNbArticles() << ';'
                    << encodeArticles(rev->getArticles()) << ';'
                    << s << '\n';
            } else if (auto l = dynamic_cast<const Livre *>(r)) {
                out << "LIVRE" << ';' << id << ';'
                    << escapeField(r->getTitre()) << ';'
                    << escapeField(r->getAuteur()) << ';'
                    << r->getAnneeCreation() << ';'
                    << l->getNbPages() << ';'
                    << escapeField(l->getCollection()) << ';'
                    << escapeField(l->getResume()) << ';'
                    << s << '\n';
            } else if (auto dvd = dynamic_cast<const DVD *>(r)) {
                out << "DVD" << ';' << id << ';'
                    << escapeField(r->getTitre()) << ';'
                    << escapeField(r->getAuteur()) << ';'
                    << r->getAnneeCreation() << ';'
                    << escapeField(dvd->getDuree()) << ';'
                    << escapeField(dvd->getMaisonProd()) << ';'
                    << dvd->getNbPistes() << ';'
                    << s << '\n';
            } else if (auto vhs = dynamic_cast<const VHS *>(r)) {
                out << "VHS" << ';' << id << ';'
                    << escapeField(r->getTitre()) << ';'
                    << escapeField(r->getAuteur()) << ';'
                    << r->getAnneeCreation() << ';'
                    << escapeField(vhs->getDuree()) << ';'
                    << escapeField(vhs->getMaisonProd()) << ';'
                    << s << '\n';
            } else if (auto cd = dynamic_cast<const CD *>(r)) {
                out << "CD" << ';' << id << ';'
                    << escapeField(r->getTitre()) << ';'
                    << escapeField(r->getAuteur()) << ';'
                    << r->getAnneeCreation() << ';'
                    << escapeField(cd->getDuree()) << ';'
                    << cd->getNbPistes() << ';'
                    << escapeField(cd->getMaisonProd()) << ';'
                    << s << '\n';
            } else if (auto num = dynamic_cast<const Numerique *>(r)) {
                out << "NUM" << ';' << id << ';'
                    << escapeField(r->getTitre()) << ';'
                    << escapeField(r->getAuteur()) << ';'
                    << r->getAnneeCreation() << ';'
                    << escapeField(num->getType()) << ';'
                    << num->getTaille() << ';'
                    << escapeField(num->getUrl()) << ';'
                    << s << '\n';
            }
        }

        std::cout << "Sauvegarde terminee : " << p.string() << "\n";
        return true;
    }

    bool load(const std::string& path, Mediatheque& m) {
        std::error_code ec;
        fs::path p = resolveToDataDir(path, "save.txt", false);

        // 1) Fichier présent ?
        if (!fs::exists(p, ec) || !fs::is_regular_file(p, ec)) {
            std::cerr << "Aucun fichier de sauvegarde trouvé : "
                      << fs::absolute(p).string() << "\n"
                      << "Astuce : utilisez SAVE pour en créer un (ex: SAVE -> save.txt)\n";
            return false;
        }

        // 2) Fichier non vide ?
        auto sz = fs::file_size(p, ec);
        if (!ec && sz == 0) {
            std::cerr << "Le fichier est vide : " << fs::absolute(p).string()
                      << " — rien à charger.\n";
            return true; // on considère que ce n'est pas une erreur bloquante
        }

        // 3) Ouverture
        std::ifstream in(p, std::ios::binary);
        if (!in) {
            std::cerr << "Erreur: impossible d'ouvrir " << p.string() << " en lecture.\n";
            return false;
        }

        m.viderMediatheque();

        std::string line;
        int count = 0;
        while (std::getline(in, line)) {
            if (line.empty() || line[0] == '#') continue;
            auto c = splitEscaped(line);
            if (c.size() < 2) continue;

            const std::string type = c[0];

            try {
                if (type == "REVUE") {
                    if (c.size() < 12) continue;
                    int id = std::stoi(c[1]);
                    std::string t = c[2];
                    std::string a = c[3];
                    int an = std::stoi(c[4]);
                    int pages = std::stoi(c[5]);
                    std::string col = c[6];
                    std::string res = c[7];
                    std::string ed = c[8];
                    int nbA = std::stoi(c[9]);
                    auto arts = decodeArticles(c[10]);
                    int s = std::stoi(c[11]);

                    auto *obj = new Revue(t, a, an, pages, col, res, ed, arts, nbA);
                    obj->setStatut(static_cast<Ressource::statut>(s));
                    m.ajouterRessourceAvecId(id, obj);
                    ++count;
                } else if (type == "LIVRE") {
                    if (c.size() < 9) continue;
                    int id = std::stoi(c[1]);
                    std::string t = c[2];
                    std::string a = c[3];
                    int an = std::stoi(c[4]);
                    int pages = std::stoi(c[5]);
                    std::string col = c[6];
                    std::string res = c[7];
                    int s = std::stoi(c[8]);

                    auto *obj = new Livre(t, a, an, pages, col, res);
                    obj->setStatut(static_cast<Ressource::statut>(s));
                    m.ajouterRessourceAvecId(id, obj);
                    ++count;
                } else if (type == "DVD") {
                    if (c.size() < 9) continue;
                    int id = std::stoi(c[1]);
                    std::string t = c[2];
                    std::string a = c[3];
                    int an = std::stoi(c[4]);
                    std::string d = c[5];
                    std::string mp = c[6];
                    int pistes = std::stoi(c[7]);
                    int s = std::stoi(c[8]);

                    auto *obj = new DVD(t, a, an, d, mp, pistes);
                    obj->setStatut(static_cast<Ressource::statut>(s));
                    m.ajouterRessourceAvecId(id, obj);
                    ++count;
                } else if (type == "VHS") {
                    if (c.size() < 8) continue;
                    int id = std::stoi(c[1]);
                    std::string t = c[2];
                    std::string a = c[3];
                    int an = std::stoi(c[4]);
                    std::string d = c[5];
                    std::string mp = c[6];
                    int s = std::stoi(c[7]);

                    auto *obj = new VHS(t, a, an, d, mp);
                    obj->setStatut(static_cast<Ressource::statut>(s));
                    m.ajouterRessourceAvecId(id, obj);
                    ++count;
                } else if (type == "CD") {
                    if (c.size() < 9) continue;
                    int id = std::stoi(c[1]);
                    std::string t = c[2];
                    std::string a = c[3];
                    int an = std::stoi(c[4]);
                    std::string d = c[5];
                    int pistes = std::stoi(c[6]);
                    std::string mp = c[7];
                    int s = std::stoi(c[8]);

                    auto *obj = new CD(t, a, an, d, pistes, mp);
                    obj->setStatut(static_cast<Ressource::statut>(s));
                    m.ajouterRessourceAvecId(id, obj);
                    ++count;
                } else if (type == "NUM") {
                    if (c.size() < 9) continue;
                    int id = std::stoi(c[1]);
                    std::string t = c[2];
                    std::string a = c[3];
                    int an = std::stoi(c[4]);
                    std::string ty = c[5];
                    int taille = std::stoi(c[6]);
                    std::string url = c[7];
                    int s = std::stoi(c[8]);

                    auto *obj = new Numerique(t, a, an, ty, taille, url);
                    obj->setStatut(static_cast<Ressource::statut>(s));
                    m.ajouterRessourceAvecId(id, obj);
                    ++count;
                }
            } catch (const std::exception &e) {
                std::cerr << "Ligne invalide: " << e.what() << " → " << line << "\n";
            }
        }
        std::cout << "Chargement termine depuis : " << p.string() << "\n";
        return true;
    }

}