package ru.perevoshchikov.springcourse.Convoy.models.abstracts;

import ru.perevoshchikov.springcourse.Convoy.models.saved.Weapon;
import ru.perevoshchikov.springcourse.Convoy.models.saved.WeaponLocation;

import ru.perevoshchikov.springcourse.Convoy.containers.*;

public interface WeaponCarrier {
    Map<WeaponLocation, Weapon> getWeapons();
    Weapon getWeapon(WeaponLocation location);
    void setWeapon(WeaponLocation location, Weapon weapon);
    void removeWeapon(WeaponLocation location);
    default double getWeaponWeight(List<Weapon> weapons) {
        double sum = 0;

        for (Weapon w : weapons)
            sum += w.getWeight();

        return sum;
    }

    default boolean shoot(Weapon weapon) {
        System.out.println("SHOOT");
        return weapon.shoot();
    }
}
