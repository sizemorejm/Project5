#include "ninja.hpp"


Ninja::Ninja(JsonEntityBuilder &builder, JsonItemBuilder & inventory, uint32_t uid) : 
        Entity(builder, inventory, uid)
{
    std::cout << Name() << " the ninja has entered the battle" << std::endl;
}

void Ninja::Slice(Entity* target)
{
    Attack(target, GetAgility() * 2.0, "Slice");
   
}


void Ninja::Shuriken(Entity* target)
{
    Attack(target, GetAgility() * 2.0, "Shuriken");
    Attack(target, GetAgility() * 2.0, "Shuriken");
    Attack(target, GetAgility() * 2.0, "Shuriken");
}

void Ninja::Kamikaze(Entity * target)
{
     _hp = 0;
    Attack(target, 50, "Kamikaze");
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
    Attack(target, 4.0, "Dagger Attack");
}


void Ninja::UseAction(Entity * target, const std::string& spellName, const std::string & args)
{
    if(spellName == "pick_pocket")
    {
        uint32_t itemUID = std::stoul(args);
        PickPocket(target, itemUID);
        return;
    }

    if(spellName == "weapon_attack")
    {
        WeaponAttack(target);
        return;
    }
    if(spellName == "backstab")
    {
        Backstab(target);
        return;
    }
    if(spellName == "blindside")
    {
        Blindside(target);
        return;
    }

    
    errorFindingAbility(spellName);

}