/*

1 Fight Club
Implementieren Sie eine Vererbungsstruktur, die als Basis f¨ur ein textbasiertes Beat-em’-
up-Spiel dient. Charaktere sollen rundenweise gegeneinander antreten k¨onnen. Weiters soll
es m¨oglich sein, den Charakteren verschiedene F¨ahigkeiten zuzuordnen, die dann im Kampf
genutzt werden k¨onnen.
Folgende Punkte m¨ussen dabei beachtet werden:
• Nutzen Sie Vererbung und teilen Sie den Code auf.
• Verwenden Sie sinnvolle Klassen. Beachten Sie dabei die richtige Verwendung von Zugriffsmodifikatoren, Gettern/Settern, den verschiedenen Konstruktoren und Destruktoren sowie der sinnvollen Strukturierung von Funktionen und Daten. Bilden Sie Ihre
Klassen in einem entsprechenden Diagramm ab.
• Uberpr¨ufen Sie alle Parameter¨ubergaben an Funktionen und Benutzereingaben auf ¨
Fehler und verhindern Sie so, dass Ihr Programm bei ung¨ultigen Eingaben nicht mehr
richtig funktioniert, Eingaben sollen so lange wiederholt werden, bis sie korrekt sind
und der Spielfluss erst dann fortgesetzt werden.
• Testen Sie Ihren Code ausgiebig und ber¨ucksichtigen Sie Randbedingungen.
Stufe 1
Zu Beginn soll es m¨oglich sein, aus zumindest zwei vorgefertigten Charakteren zu w¨ahlen oder
einen eigenen Charakter zu erstellen, jeder Charakter soll dabei zwei F¨ahigkeiten besitzen.
Die F¨ahigkeiten sollen bei der Charaktererstellung gew¨ahlt werden k¨onnen, implementieren
Sie also mehr als zwei F¨ahigkeiten.
Wurden zwei Charaktere gew¨ahlt, sollen diese danach rundenweise unter Verwendung ihrer
F¨ahigkeiten gegeneinander k¨ampfen. Der Kampf soll so lange andauern, bis einer der Charaktere besiegt wurde.
Gestalten Sie die Regeln f¨ur den Kampf selbst.
Nach einem Kampf soll es m¨oglich sein, wieder neue Charaktere zu w¨ahlen oder zu erstellen
und diese gegeneinander antreten zu lassen.
Weiters soll es eine M¨oglichkeit geben, sich die Anzahl der Siege und Niederlagen aller
Charaktere anzusehen.
Stufe 2
Erm¨oglichen Sie es Personen, gegen den Computer oder gegeneinander anzutreten und auch
Teams zu bilden, die als Klassen implementiert werden. Teams sollen aus mehreren Charakteren bestehen und dann in Team-K¨ampfen gegeneinander antreten k¨onnen. Gestalten Sie
auch hier die Regeln selbstst¨andig.
Stufe 3
Erweitern Sie Ihr Spiel um zumindest zwei Entscheidungsb¨aume als Klassen implementiert,
die den Charakteren bei der Erstellung zugeordnet werden k¨onnen. Diese B¨aume sollen das
Verhalten der Charaktere im Kampf ver¨andern und sich deutlich voneinander unterscheiden.
Bewertung
Aspekt Bewertung
Vererbung/Klassen 20%
Diagramm 10%
Fehlerpr¨ufung 10%
Stufe 1 30%
Stufe 2 15%
Stufe 3 15%
*/

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <limits>
#include <algorithm>

using namespace std;

// Vorwärtsdeklarationen
class Character;
class AIBehavior;

// ----------------------------- Hilfsfunktionen -----------------------------

int readIntInRange(int minVal, int maxVal) {
    int value;
    while (true) {
        cout << "> ";
        if (!(cin >> value)) {
            cout << "Fehler: Bitte eine ganze Zahl eingeben.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        if (value < minVal || value > maxVal) {
            cout << "Fehler: Bitte eine Zahl zwischen " << minVal << " und " << maxVal << " eingeben.\n";
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return value;
    }
}

string readNonEmptyLine(const string& prompt) {
    while (true) {
        cout << prompt;
        string line;
        getline(cin, line);
        if (!line.empty())
            return line;
        cout << "Eingabe darf nicht leer sein.\n";
    }
}

// -------------------------------- Fähigkeiten --------------------------------

class Ability {
protected:
    string name;
    string description;

public:
    Ability(const string& n, const string& d) : name(n), description(d) {}
    virtual ~Ability() = default;

    const string& getName() const { return name; }
    const string& getDescription() const { return description; }

    virtual void use(Character& user, Character& target) = 0;
};

class SimpleAttack : public Ability {
    int power;

public:
    SimpleAttack(const string& n, const string& d, int p)
        : Ability(n, d), power(p) {
    }

    void use(Character& user, Character& target) override;
};

class HeavyAttack : public Ability {
    int power;

public:
    HeavyAttack(const string& n, const string& d, int p)
        : Ability(n, d), power(p) {
    }

    void use(Character& user, Character& target) override;
};

class HealAbility : public Ability {
    int amount;

public:
    HealAbility(const string& n, const string& d, int a)
        : Ability(n, d), amount(a) {
    }

    void use(Character& user, Character& target) override;
};

// ---------------------------- AI-Verhalten (Bäume) ----------------------------

class AIBehavior {
protected:
    string name;

public:
    AIBehavior(const string& n) : name(n) {}
    virtual ~AIBehavior() = default;

    const string& getName() const { return name; }

    // Gibt den Index der zu verwendenden Fähigkeit zurück
    virtual int chooseAbilityIndex(const Character& self, const Character& enemy) = 0;
};

class AggressiveBehavior : public AIBehavior {
public:
    AggressiveBehavior() : AIBehavior("Aggressiv") {}

    int chooseAbilityIndex(const Character& self, const Character& enemy) override;
};

class DefensiveBehavior : public AIBehavior {
public:
    DefensiveBehavior() : AIBehavior("Defensiv") {}

    int chooseAbilityIndex(const Character& self, const Character& enemy) override;
};

// -------------------------------- Charaktere --------------------------------

class Character {
    string name;
    int maxHp;
    int hp;
    int attack;
    int defense;
    int wins = 0;
    int losses = 0;
    vector<shared_ptr<Ability>> abilities;
    shared_ptr<AIBehavior> behavior;

public:
    Character(const string& n, int maxHp, int atk, int def, shared_ptr<AIBehavior> beh)
        : name(n), maxHp(maxHp), hp(maxHp), attack(atk), defense(def), behavior(std::move(beh)) {
    }

    const string& getName() const { return name; }
    int getMaxHp() const { return maxHp; }
    int getHp() const { return hp; }
    int getAttack() const { return attack; }
    int getDefense() const { return defense; }

    void resetHp() { hp = maxHp; }

    bool isAlive() const { return hp > 0; }

    void receiveDamage(int amount) {
        hp -= amount;
        if (hp < 0) hp = 0;
    }

    void heal(int amount) {
        hp += amount;
        if (hp > maxHp) hp = maxHp;
    }

    void addAbility(const shared_ptr<Ability>& ability) {
        abilities.push_back(ability);
    }

    const vector<shared_ptr<Ability>>& getAbilities() const {
        return abilities;
    }

    void setBehavior(shared_ptr<AIBehavior> beh) { behavior = std::move(beh); }
    shared_ptr<AIBehavior> getBehavior() const { return behavior; }

    void addWin() { ++wins; }
    void addLoss() { ++losses; }
    int getWins() const { return wins; }
    int getLosses() const { return losses; }
};

// Jetzt können wir die Ability-Methoden definieren, da Character nun bekannt ist

void SimpleAttack::use(Character& user, Character& target) {
    int dmg = power + user.getAttack() - target.getDefense();
    if (dmg < 1) dmg = 1;
    target.receiveDamage(dmg);
    cout << user.getName() << " setzt " << name << " ein und verursacht " << dmg
        << " Schaden an " << target.getName() << "!\n";
}

void HeavyAttack::use(Character& user, Character& target) {
    int dmg = power + user.getAttack() - target.getDefense();
    if (dmg < 1) dmg = 1;
    cout << user.getName() << " lädt einen mächtigen Angriff auf...\n";
    target.receiveDamage(dmg);
    cout << user.getName() << " trifft mit " << name << " für " << dmg
        << " Schaden! (" << target.getName() << ")\n";
}

void HealAbility::use(Character& user, Character& target) {
    (void)target; // wird nicht benutzt
    int before = user.getHp();
    user.heal(amount);
    int healed = user.getHp() - before;
    cout << user.getName() << " benutzt " << name << " und heilt " << healed << " HP.\n";
}

// Jetzt können wir die AI-Entscheidungsbäume definieren

int AggressiveBehavior::chooseAbilityIndex(const Character& self, const Character& enemy) {
    const auto& abs = self.getAbilities();
    if (abs.empty()) return -1;

    int idxSimple = -1;
    int idxHeavy = -1;
    int idxHeal = -1;

    for (size_t i = 0; i < abs.size(); ++i) {
        if (dynamic_cast<SimpleAttack*>(abs[i].get())) idxSimple = (int)i;
        else if (dynamic_cast<HeavyAttack*>(abs[i].get())) idxHeavy = (int)i;
        else if (dynamic_cast<HealAbility*>(abs[i].get())) idxHeal = (int)i;
    }

    int hpPercent = self.getHp() * 100 / self.getMaxHp();

    // Entscheidungsbaum (stark vereinfacht):
    // 1. Wenn HP sehr niedrig und Heilung vorhanden -> heilen
    if (hpPercent < 30 && idxHeal != -1) return idxHeal;

    // 2. Wenn der Gegner fast tot ist und ein schneller Schlag existiert -> SimpleAttack
    if (enemy.getHp() < self.getAttack() * 2 && idxSimple != -1) return idxSimple;

    // 3. Sonst vorrangig HeavyAttack
    if (idxHeavy != -1) return idxHeavy;

    // 4. Fallback
    if (idxSimple != -1) return idxSimple;
    if (idxHeal != -1) return idxHeal;

    return 0;
}

int DefensiveBehavior::chooseAbilityIndex(const Character& self, const Character& enemy) {
    (void)enemy; // wird hier nicht genutzt
    const auto& abs = self.getAbilities();
    if (abs.empty()) return -1;

    int idxSimple = -1;
    int idxHeavy = -1;
    int idxHeal = -1;

    for (size_t i = 0; i < abs.size(); ++i) {
        if (dynamic_cast<SimpleAttack*>(abs[i].get())) idxSimple = (int)i;
        else if (dynamic_cast<HeavyAttack*>(abs[i].get())) idxHeavy = (int)i;
        else if (dynamic_cast<HealAbility*>(abs[i].get())) idxHeal = (int)i;
    }

    int hpPercent = self.getHp() * 100 / self.getMaxHp();

    // Entscheidungsbaum Defensiv:
    // 1. Wenn HP < 50% und Heal verfügbar -> Heal
    if (hpPercent < 50 && idxHeal != -1) return idxHeal;

    // 2. Sonst lieber den einfachen Angriff
    if (idxSimple != -1) return idxSimple;

    // 3. Fallback Heavy
    if (idxHeavy != -1) return idxHeavy;
    if (idxHeal != -1) return idxHeal;

    return 0;
}

// -------------------------------- Teams --------------------------------

class Team {
    string name;
    vector<shared_ptr<Character>> members;

public:
    Team(const string& n) : name(n) {}

    const string& getName() const { return name; }

    void addMember(const shared_ptr<Character>& c) {
        members.push_back(c);
    }

    const vector<shared_ptr<Character>>& getMembers() const { return members; }

    bool hasLivingMembers() const {
        for (const auto& m : members) {
            if (m->isAlive()) return true;
        }
        return false;
    }

    Character* getNextLivingMember() {
        for (auto& m : members) {
            if (m->isAlive()) return m.get();
        }
        return nullptr;
    }
};

// ------------------------------- Globale Daten ------------------------------

vector<shared_ptr<Ability>> g_abilityPool;
vector<shared_ptr<AIBehavior>> g_behaviorPool;
vector<shared_ptr<Character>> g_characters;

// -------------------------- Initialisierung --------------------------

void initAbilities() {
    g_abilityPool.push_back(
        make_shared<SimpleAttack>("Schneller Schlag",
            "Ein schneller, zuverlässiger Angriff.",
            8));
    g_abilityPool.push_back(
        make_shared<HeavyAttack>("Wuchtiger Schlag",
            "Ein langsamer, aber sehr starker Angriff.",
            14));
    g_abilityPool.push_back(
        make_shared<HealAbility>("Heilzauber",
            "Stellt eine mittlere Menge HP wieder her.",
            15));
}

void initBehaviors() {
    g_behaviorPool.push_back(make_shared<AggressiveBehavior>());
    g_behaviorPool.push_back(make_shared<DefensiveBehavior>());
}

void createPremadeCharacters() {
    // Fertiger Kämpfer 1
    auto c1 = make_shared<Character>("Brutus", 80, 15, 5, g_behaviorPool[0]); // aggressiv
    c1->addAbility(g_abilityPool[0]); // schneller Schlag
    c1->addAbility(g_abilityPool[1]); // wuchtiger Schlag
    g_characters.push_back(c1);

    // Fertiger Kämpfer 2
    auto c2 = make_shared<Character>("Healerina", 90, 10, 6, g_behaviorPool[1]); // defensiv
    c2->addAbility(g_abilityPool[0]); // schneller Schlag
    c2->addAbility(g_abilityPool[2]); // Heilung
    g_characters.push_back(c2);
}

// -------------------------- Charaktererstellung --------------------------

shared_ptr<AIBehavior> chooseBehavior() {
    cout << "\nWähle ein Verhalten (Entscheidungsbaum):\n";
    for (size_t i = 0; i < g_behaviorPool.size(); ++i) {
        cout << "  " << (i + 1) << ") " << g_behaviorPool[i]->getName() << "\n";
    }
    int choice = readIntInRange(1, (int)g_behaviorPool.size());
    return g_behaviorPool[choice - 1];
}

void chooseAbilitiesForCharacter(const shared_ptr<Character>& c) {
    cout << "\nVerfügbare Fähigkeiten:\n";
    for (size_t i = 0; i < g_abilityPool.size(); ++i) {
        cout << "  " << (i + 1) << ") " << g_abilityPool[i]->getName()
            << " - " << g_abilityPool[i]->getDescription() << "\n";
    }

    cout << "Wähle eine erste Fähigkeit (Zahl):\n";
    int first = readIntInRange(1, (int)g_abilityPool.size());

    int second;
    while (true) {
        cout << "Wähle eine zweite, unterschiedliche Fähigkeit (Zahl):\n";
        second = readIntInRange(1, (int)g_abilityPool.size());
        if (second != first) break;
        cout << "Die zweite Fähigkeit muss verschieden von der ersten sein!\n";
    }

    c->addAbility(g_abilityPool[first - 1]);
    c->addAbility(g_abilityPool[second - 1]);
}

shared_ptr<Character> createCharacter() {
    cout << "\n--- Neuen Charakter erstellen ---\n";
    string name = readNonEmptyLine("Name des Charakters: ");

    cout << "Wähle einen Archetypen:\n";
    cout << "  1) Ausgewogen (HP 100, ATK 12, DEF 8)\n";
    cout << "  2) Krieger (HP 90, ATK 16, DEF 5)\n";
    cout << "  3) Tank (HP 120, ATK 10, DEF 10)\n";
    int choice = readIntInRange(1, 3);

    int hp, atk, def;
    switch (choice) {
    case 1: hp = 100; atk = 12; def = 8; break;
    case 2: hp = 90;  atk = 16; def = 5; break;
    case 3: hp = 120; atk = 10; def = 10; break;
    default: hp = 100; atk = 12; def = 8; break;
    }

    auto behavior = chooseBehavior();
    auto c = make_shared<Character>(name, hp, atk, def, behavior);
    chooseAbilitiesForCharacter(c);
    g_characters.push_back(c);

    cout << "Charakter '" << name << "' wurde erstellt!\n";
    return c;
}

shared_ptr<Character> chooseCharacterFromList(const string& title) {
    cout << "\n--- " << title << " ---\n";

    if (g_characters.empty()) {
        cout << "Es sind noch keine Charaktere vorhanden. Es wird einer erstellt.\n";
        return createCharacter();
    }

    while (true) {
        cout << "Verfügbare Charaktere:\n";
        for (size_t i = 0; i < g_characters.size(); ++i) {
            cout << "  " << (i + 1) << ") "
                << g_characters[i]->getName()
                << " (Siege: " << g_characters[i]->getWins()
                << ", Niederlagen: " << g_characters[i]->getLosses() << ")\n";
        }
        cout << "  " << (g_characters.size() + 1) << ") Neuen Charakter erstellen\n";

        int choice = readIntInRange(1, (int)g_characters.size() + 1);
        if (choice == (int)g_characters.size() + 1) {
            return createCharacter();
        }
        else {
            return g_characters[choice - 1];
        }
    }
}

// -------------------------- Kampf-Logik 1v1 --------------------------

int chooseAbilityForHuman(const Character& c) {
    const auto& abs = c.getAbilities();
    while (true) {
        cout << "Fähigkeiten von " << c.getName() << ":\n";
        for (size_t i = 0; i < abs.size(); ++i) {
            cout << "  " << (i + 1) << ") " << abs[i]->getName()
                << " - " << abs[i]->getDescription() << "\n";
        }
        cout << "Wähle Fähigkeit: \n";
        int choice = readIntInRange(1, (int)abs.size());
        return choice - 1;
    }
}

void turn(Character& active, bool isHuman, Character& enemy) {
    cout << "\n--- " << active.getName() << " ist am Zug (HP: "
        << active.getHp() << "/" << active.getMaxHp() << ") ---\n";
    const auto& abs = active.getAbilities();
    if (abs.empty()) {
        cout << active.getName() << " hat keine Fähigkeiten!\n";
        return;
    }

    int idx = -1;
    if (isHuman) {
        idx = chooseAbilityForHuman(active);
    }
    else {
        auto beh = active.getBehavior();
        if (beh) {
            idx = beh->chooseAbilityIndex(active, enemy);
        }
        else {
            // Fallback: erste Fähigkeit
            idx = 0;
        }
    }

    if (idx < 0 || idx >= (int)abs.size()) {
        cout << "Fehler bei der Fähigkeitswahl, Standardangriff wird verwendet.\n";
        idx = 0;
    }

    abs[idx]->use(active, enemy);
    cout << enemy.getName() << " hat nun " << enemy.getHp() << " HP.\n";
}

void fightDuel(shared_ptr<Character> c1, bool c1Human,
    shared_ptr<Character> c2, bool c2Human) {
    cout << "\n=== Kampf: " << c1->getName() << " vs. " << c2->getName() << " ===\n";

    c1->resetHp();
    c2->resetHp();

    int round = 1;
    while (c1->isAlive() && c2->isAlive()) {
        cout << "\n========== Runde " << round << " ==========\n";
        // Spieler 1
        if (c1->isAlive()) {
            turn(*c1, c1Human, *c2);
        }
        if (!c2->isAlive()) break;

        // Spieler 2
        if (c2->isAlive()) {
            turn(*c2, c2Human, *c1);
        }
        round++;
    }

    cout << "\n=== Kampf beendet! ===\n";
    if (c1->isAlive() && !c2->isAlive()) {
        cout << c1->getName() << " gewinnt!\n";
        c1->addWin();
        c2->addLoss();
    }
    else if (!c1->isAlive() && c2->isAlive()) {
        cout << c2->getName() << " gewinnt!\n";
        c2->addWin();
        c1->addLoss();
    }
    else {
        cout << "Unentschieden (beide sind gefallen).\n";
        // optional: als Niederlage zählen
        c1->addLoss();
        c2->addLoss();
    }
}

// -------------------------- Team-Kampf (Stufe 2) --------------------------

Team createTeam(const string& label) {
    cout << "\n--- Team " << label << " erstellen ---\n";
    string name = readNonEmptyLine("Name des Teams: ");
    Team t(name);

    cout << "Wie viele Charaktere soll das Team haben? (1-3 empfohlen)\n";
    int count = readIntInRange(1, 3);
    for (int i = 0; i < count; ++i) {
        cout << "\nMitglied " << (i + 1) << " wählen:\n";
        auto c = chooseCharacterFromList("Team-Mitglied wählen");
        t.addMember(c);
    }
    return t;
}

void resetTeamHP(Team& t) {
    for (auto& m : t.getMembers()) {
        m->resetHp();
    }
}

void turnTeam(Character& active, bool teamIsHuman, Character& enemy) {
    turn(active, teamIsHuman, enemy);
}

void teamBattle(Team& t1, bool t1Human,
    Team& t2, bool t2Human) {
    cout << "\n=== Teamkampf: " << t1.getName()
        << " vs. " << t2.getName() << " ===\n";

    resetTeamHP(t1);
    resetTeamHP(t2);

    int round = 1;
    while (t1.hasLivingMembers() && t2.hasLivingMembers()) {
        cout << "\n========== Team-Runde " << round << " ==========\n";
        Character* a = t1.getNextLivingMember();
        Character* b = t2.getNextLivingMember();
        if (!a || !b) break;

        cout << "\nAktive Kämpfer:\n";
        cout << "  " << t1.getName() << ": " << a->getName()
            << " (" << a->getHp() << "/" << a->getMaxHp() << " HP)\n";
        cout << "  " << t2.getName() << ": " << b->getName()
            << " (" << b->getHp() << "/" << b->getMaxHp() << " HP)\n";

        // Kämpfer A
        if (a->isAlive()) {
            turnTeam(*a, t1Human, *b);
        }
        if (!b->isAlive()) {
            cout << b->getName() << " ist gefallen!\n";
            if (!t2.hasLivingMembers()) break;
        }

        // Kämpfer B
        b = t2.getNextLivingMember();
        a = t1.getNextLivingMember();
        if (!a || !b) break;

        if (b->isAlive()) {
            turnTeam(*b, t2Human, *a);
        }
        if (!a->isAlive()) {
            cout << a->getName() << " ist gefallen!\n";
            if (!t1.hasLivingMembers()) break;
        }
        round++;
    }

    cout << "\n=== Teamkampf beendet! ===\n";
    if (t1.hasLivingMembers() && !t2.hasLivingMembers()) {
        cout << "Team " << t1.getName() << " gewinnt!\n";
        for (auto& c : t1.getMembers()) c->addWin();
        for (auto& c : t2.getMembers()) c->addLoss();
    }
    else if (!t1.hasLivingMembers() && t2.hasLivingMembers()) {
        cout << "Team " << t2.getName() << " gewinnt!\n";
        for (auto& c : t2.getMembers()) c->addWin();
        for (auto& c : t1.getMembers()) c->addLoss();
    }
    else {
        cout << "Unentschieden.\n";
        for (auto& c : t1.getMembers()) c->addLoss();
        for (auto& c : t2.getMembers()) c->addLoss();
    }
}

// -------------------------- Statistik --------------------------

void showStatistics() {
    cout << "\n=== Statistik aller Charaktere ===\n";
    if (g_characters.empty()) {
        cout << "Keine Charaktere vorhanden.\n";
        return;
    }
    for (const auto& c : g_characters) {
        cout << "- " << c->getName()
            << " | Siege: " << c->getWins()
            << " | Niederlagen: " << c->getLosses() << "\n";
    }
}

// -------------------------- Hauptmenü --------------------------

void mainMenu() {
    while (true) {
        cout << "\n===== Fight Club Menü =====\n";
        cout << "1) Mensch vs Computer (1v1)\n";
        cout << "2) Mensch vs Mensch (1v1)\n";
        cout << "3) Teamkampf\n";
        cout << "4) Neuen Charakter erstellen\n";
        cout << "5) Statistik anzeigen\n";
        cout << "0) Beenden\n";

        int choice = readIntInRange(0, 5);
        if (choice == 0) {
            cout << "Programm wird beendet.\n";
            break;
        }

        switch (choice) {
        case 1: {
            auto human = chooseCharacterFromList("Charakter für Spieler 1 (Mensch)");
            auto ai = chooseCharacterFromList("Charakter für Computer");
            fightDuel(human, true, ai, false);
            break;
        }
        case 2: {
            auto p1 = chooseCharacterFromList("Charakter für Spieler 1");
            auto p2 = chooseCharacterFromList("Charakter für Spieler 2");
            fightDuel(p1, true, p2, true);
            break;
        }
        case 3: {
            cout << "\nTeamkampf-Modus:\n";
            cout << "1) Mensch vs Mensch\n";
            cout << "2) Mensch vs Computer\n";
            int mode = readIntInRange(1, 2);

            Team t1 = createTeam("A");
            Team t2 = createTeam("B");

            bool t1Human = true;
            bool t2Human = (mode == 1);

            teamBattle(t1, t1Human, t2, t2Human);
            break;
        }
        case 4: {
            createCharacter();
            break;
        }
        case 5: {
            showStatistics();
            break;
        }
        }
    }
}

// ------------------------------ main ------------------------------

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    initAbilities();
    initBehaviors();
    createPremadeCharacters();

    mainMenu();

    return 0;
}
