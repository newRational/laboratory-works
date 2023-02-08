package ru.perevoshchikov.springcourse.Convoy.models.saved;

import ru.perevoshchikov.springcourse.Convoy.models.abstracts.Ship;
import ru.perevoshchikov.springcourse.Convoy.models.abstracts.WeaponCarrier;

import ru.perevoshchikov.springcourse.Convoy.containers.Map;

public class GuardShip extends Ship implements WeaponCarrier {
    private final Map<WeaponLocation, Weapon> weapons;

    public GuardShip() {
        super();
        weapons = new Map<>();
    }

    public GuardShip(String model, Captain captain, double displacement, int numberOfCrewMembers) {
        super(model, captain, displacement, numberOfCrewMembers, ShipSpeedCoefficient.GUARD.getCoefficient());
        weapons = new Map<>();
    }

    @Override
    public int getMaxSpeed() {
        return (int) (1 / defaultSpeed + 2 * getWeaponWeight(weapons.values()));
    }

    @Override
    public Map<WeaponLocation, Weapon> getWeapons() {
        return weapons;
    }

    @Override
    public Weapon getWeapon(WeaponLocation location) {
        return weapons.get(location);
    }

    @Override
    public void setWeapon(WeaponLocation location, Weapon weapon) {
        weapons.add(location, weapon);
    }

    @Override
    public void removeWeapon(WeaponLocation location) {
        weapons.remove(location);
    }
}
