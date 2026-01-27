#include <iostream>
#include <string>

// Base class for anything that can fight.
class Actor { 
    public:
        Actor(int life, int mana);
        virtual ~Actor() = default;

        virtual void autoAttack() const;
        void castSpell() const;
        virtual void die() const;

        int getLife() const;
        void setLife(int newLife);
        int getMana() const;
        void setMana(int newMana);

    private:
        int life;
        int mana;
};

Actor::Actor(int life, int mana)
    : life(life), mana(mana) {}

void Actor::autoAttack() const {
    std::cout << "AA" << std::endl;
}

void Actor::castSpell() const {
    std::cout << "Casting Spell" << std::endl;
}

void Actor::die() const {
    std::cout << "Im dead" << std::endl;
}

int Actor::getLife() const {
    return life;
}

void Actor::setMana(int newMana){
    mana = newMana;
}

int Actor::getMana() const {
    return mana;
}

void Actor::setLife(int newLife){
    life = newLife;
}

class Enemy: public Actor {
    public:
        Enemy(int life, int mana, std::string description)
            : Actor(life, mana), description(description) {}

        void callEnemies() const; // Non-virtual: base version always used via Enemy*.
        virtual void dropLoot() const;
        
        void setDescription(const std::string &newDescription);
        std::string getDescription() const;

    private:
        std::string description;
};

void Enemy::callEnemies() const {
    std::cout << "Calling more enemies!" << std::endl;
}

void Enemy::dropLoot() const {
    std::cout << "Dropping basic loot!" << std::endl;
}

void Enemy::setDescription(const std::string &newDescription){
    description = newDescription;
}

std::string Enemy::getDescription() const {
    return description;
}

class Character: public Actor {
    public:
        enum class Classes {
            MAGE,
            WARRIOR,
            HEALER
        };

        Character(int life, int mana, Classes classType)
            : Actor(life, mana), classType(classType) {}

        void escapeFight() const;

        Classes getClassType() const;

    private:
        Classes classType;
};

void Character::escapeFight() const {
    std::cout << "Escaping Fight!" << std::endl;
}

Character::Classes Character::getClassType() const {
    return classType;
}

class Goblin: public Enemy {
    public:
        enum class GoblinColors {
            RED,
            BLUE,
            GREEN
        };

        Goblin(int life, int mana, const std::string &description, GoblinColors goblinColor)
            : Enemy(life, mana, description), goblinColor(goblinColor) {}

        void goblinBuff();
        void dropLoot() const override;

        GoblinColors getGoblinColor() const;

    private:
        GoblinColors goblinColor;
};

void Goblin::goblinBuff(){
    std::cout << "Buffing Goblin!" << std::endl;
}

void Goblin::dropLoot() const {
    std::cout << "Dropping Goblin loot!" << std::endl;
}

Goblin::GoblinColors Goblin::getGoblinColor() const {
    return goblinColor;
}

class RedGoblin: public Goblin {
    public:
        RedGoblin(int life, int mana, const std::string &description)
            : Goblin(life, mana, description, GoblinColors::RED) {}

        void dropLoot() const override;
};

void RedGoblin::dropLoot() const {
    std::cout << "Dropping loot!" << std::endl;
}

class Mage: public Character {
    public:
        Mage(int life, int mana)
            : Character(life, mana, Classes::MAGE) {}

        void buffPlayers() const;
};

void Mage::buffPlayers() const{
    std::cout << "Buffing players!" << std::endl;
}

void runPolymorphism(){
    Actor actorTest(10, 10);
    std::cout << actorTest.getLife() << std::endl;

    Enemy* enemy = new RedGoblin(20, 5, "Red goblin grunt"); // Base pointer to derived object.
    enemy->callEnemies(); // Non-virtual: Enemy::callEnemies is used.
    enemy->dropLoot();    // Virtual: RedGoblin::dropLoot is used.
    enemy->die();         // Virtual in Actor: most-derived override would be used.
    delete enemy;          // Safe because Actor has a virtual destructor.
}
