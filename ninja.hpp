#ifndef NINJA_HPP
#define NINJA_HPP


#include "JsonEntityBuilder.hpp"
#include "entity.hpp"

class Ninja : public Entity
{
private:
    void Slice(Entity * target);
    void Shuriken(Entity * target);
    void Kamikaze(Entity * target);

public:

    Ninja(JsonEntityBuilder &builder, JsonItemBuilder & inventory, uint32_t uid);

    virtual void OutputStatus() const override;
    virtual void WeaponAttack(Entity * target) override;

    virtual void UseAction(Entity * target, const std::string& spellName, const std::string & args) override;
};


#endif