package ru.perevoshchikov.springcourse.Convoy.services;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import ru.perevoshchikov.springcourse.Convoy.models.saved.*;
import ru.perevoshchikov.springcourse.Convoy.utils.mappers.WarShipMapper;

import ru.perevoshchikov.springcourse.Convoy.containers.*;

@Service
public class WarShipService {
    private final ConvoyService convoyService;
    private final WarShipMapper warShipMapper;

    @Autowired
    public WarShipService(ConvoyService convoyService, WarShipMapper warShipMapper) {
        this.convoyService = convoyService;
        this.warShipMapper = warShipMapper;
    }

    public List<Pair<String, WarShip>> findAll() {
        List<Pair<String, WarShip>> warShips = new List<>();

        convoyService.getShips().keys().stream()
                .filter(key -> convoyService.getShips().get(key).getClass().equals(WarShip.class))
                .forEach(key -> warShips.add(new Pair<>(key, (WarShip) convoyService.getShips().get(key))));

        for (Pair<String, WarShip> pair : warShips)
            System.out.println("PAIR: K - " + pair.getFirst() + "; V - " + pair.getSecond());

        return warShips;
    }

    public WarShip findByName(String name) {
        return (WarShip) convoyService.getShip(name);
    }

    public void save(String name, WarShip warShip) {
        convoyService.addShip(name, warShip);
    }

    public void update(String name, WarShip updatedShip) {
        WarShip shipToBeUpdated = findByName(name);
        warShipMapper.map(shipToBeUpdated, updatedShip);
    }

    public void delete(String name) {
        convoyService.removeShip(name);
    }

    public boolean shoot(String name, String weaponLocationAsString) {
        WarShip warShip = findByName(name);
        WeaponLocation weaponLocation = WeaponLocation.valueOf(weaponLocationAsString.toUpperCase());
        Weapon weapon = warShip.getWeapon(weaponLocation);

        return warShip.shoot(weapon);
    }

    public boolean loadCargo(String name, double cargoWeight) {
        WarShip warShip = findByName(name);
        warShip.setCargoWeight(cargoWeight);

        return cargoWeight > 0;
    }
}
