package ru.perevoshchikov.springcourse.Convoy.services;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import ru.perevoshchikov.springcourse.Convoy.models.saved.GuardShip;
import ru.perevoshchikov.springcourse.Convoy.models.saved.Weapon;
import ru.perevoshchikov.springcourse.Convoy.models.saved.WeaponLocation;
import ru.perevoshchikov.springcourse.Convoy.utils.mappers.GuardShipMapper;

import ru.perevoshchikov.springcourse.Convoy.containers.*;

@Service
public class GuardShipService {
    private final ConvoyService convoyService;
    private final GuardShipMapper guardShipMapper;

    @Autowired
    public GuardShipService(ConvoyService convoyService, GuardShipMapper guardShipMapper) {
        this.convoyService = convoyService;
        this.guardShipMapper = guardShipMapper;
    }

    public List<Pair<String, GuardShip>> findAll() {
        List<Pair<String, GuardShip>> guardShips = new List<>();

        convoyService.getShips().keys().stream()
                .filter(key -> convoyService.getShips().get(key).getClass().equals(GuardShip.class))
                .forEach(key -> guardShips.add(new Pair<>(key, (GuardShip) convoyService.getShips().get(key))));

        for (Pair<String, GuardShip> pair : guardShips)
            System.out.println("PAIR: K - " + pair.getFirst() + "; V - " + pair.getSecond());

        return guardShips;
    }

    public GuardShip findByName(String name) {
        return (GuardShip) convoyService.getShip(name);
    }

    public void save(String name, GuardShip guardShip) {
        convoyService.addShip(name, guardShip);
    }

    public void update(String name, GuardShip updatedShip) {
        GuardShip shipToBeUpdated = findByName(name);
        guardShipMapper.map(shipToBeUpdated, updatedShip);
    }

    public void delete(String name) {
        convoyService.removeShip(name);
    }

    public boolean shoot(String name, String weaponLocationAsString) {
        GuardShip guardShip = findByName(name);
        WeaponLocation weaponLocation = WeaponLocation.valueOf(weaponLocationAsString.toUpperCase());
        Weapon weapon = guardShip.getWeapon(weaponLocation);

        return guardShip.shoot(weapon);
    }
}
