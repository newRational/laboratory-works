package ru.perevoshchikov.springcourse.Convoy.utils.mappers;

import org.springframework.stereotype.Component;
import ru.perevoshchikov.springcourse.Convoy.models.saved.GuardShip;
import ru.perevoshchikov.springcourse.Convoy.models.saved.WeaponLocation;

@Component
public class GuardShipMapper implements Mapper<GuardShip, GuardShip> {

    @Override
    public void map(GuardShip dest, GuardShip source) {
        dest.setName(source.getName());
        dest.setCaptain(source.getCaptain());
        dest.setNumberOfCrewMembers(source.getNumberOfCrewMembers());

        for (WeaponLocation location : source.getWeapons().keys())
            dest.setWeapon(location, source.getWeapon(location));
    }
}