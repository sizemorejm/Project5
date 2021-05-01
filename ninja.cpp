#include "ninja.hpp"
//James

Ninja::Ninja(JsonEntityBuilder &builder, JsonItemBuilder & inventory, uint32_t uid) : 
        Entity(builder, inventory, uid)
{
    std::cout << Name() << " the ninja has entered the battle" << std::endl;
}


void Ninja::Shuriken(Entity* target)
{
    Attack(target, GetAgility() * 2.2, "Shuriken");
    Attack(target, GetAgility() * 2.2, "Shuriken");
    Attack(target, GetAgility() * 2.2, "Shuriken");
}

void Ninja::Kamikaze(Entity * target)
{
    
    Attack(target, 50, "Kamikaze");
    Attack(this, CurrentHP(), "Kamikaze Self Damage");
}

void Ninja::OutputStatus() const
{
    std::cout << Class() << ": " << this->Name()
                << "\n\tCurrent HP: " << this->CurrentHP()
                << "\n\tAgility: " << this->GetAgility()
                << std::endl;
                
    PrintInventory();
}


void Ninja::WeaponAttack(Entity * target)
{
    Attack(target, 4.0, "Slice");
}


void Ninja::UseAction(Entity * target, const std::string& spellName, const std::string & args)
{
    

    if(spellName == "weapon_attack")
    {
        WeaponAttack(target);
        return;
    }
    if(spellName == "Shuriken")
    {
        Shuriken(target);
        return;
    }
    if(spellName == "Kamikaze")
    {
        Kamikaze(target);
        return;
    }

    
    errorFindingAbility(spellName);

}