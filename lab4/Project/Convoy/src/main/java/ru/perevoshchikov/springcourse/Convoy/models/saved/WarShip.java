package ru.perevoshchikov.springcourse.Convoy.models.saved;

import ru.perevoshchikov.springcourse.Convoy.models.abstracts.CargoCarrier;
import ru.perevoshchikov.springcourse.Convoy.models.abstracts.Ship;
import ru.perevoshchikov.springcourse.Convoy.models.abstracts.WeaponCarrier;

import ru.perevoshchikov.springcourse.Convoy.containers.*;

public class WarShip extends Ship implements CargoCarrier, WeaponCarrier {
    private double cargoWeight;
    private final Map<WeaponLocation, Weapon> weapons;

    public WarShip() {
        super();
        weapons = new Map<>();
    }

    public WarShip(String name, Captain captain, double displacement, int numberOfCrewMembers) {
        super(name, captain, displacement, numberOfCrewMembers, ShipSpeedCoefficient.WARSHIP.getCoefficient());
        weapons = new Map<>();
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

    @Override
    public double getCargoWeight() {
        return cargoWeight;
    }

    @Override
    public void setCargoWeight(double cargoWeight) {
        this.cargoWeight = cargoWeight;
    }

    private double sumExternalWeight() {
        return cargoWeight + getWeaponWeight(weapons.values());
    }

    @Override
    public int getMaxSpeed() {
        return (int) (1 / (defaultSpeed + 1.5 * sumExternalWeight()));
    }
}
