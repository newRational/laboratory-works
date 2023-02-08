package ru.perevoshchikov.springcourse.Convoy.utils.mappers;

import org.springframework.stereotype.Component;
import ru.perevoshchikov.springcourse.Convoy.models.saved.WarShip;
import ru.perevoshchikov.springcourse.Convoy.models.saved.WeaponLocation;

@Component
public class WarShipMapper implements Mapper<WarShip, WarShip> {

    @Override
    public void map(WarShip dest, WarShip source) {
        dest.setName(source.getName());
        dest.setCaptain(source.getCaptain());
        dest.setNumberOfCrewMembers(source.getNumberOfCrewMembers());
        dest.setCargoWeight(source.getCargoWeight());

        for (WeaponLocation location : source.getWeapons().keys())
            dest.setWeapon(location, source.getWeapon(location));
    }
}