package ru.perevoshchikov.springcourse.Convoy.services;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import ru.perevoshchikov.springcourse.Convoy.models.abstracts.CargoCarrier;
import ru.perevoshchikov.springcourse.Convoy.models.abstracts.Ship;
import ru.perevoshchikov.springcourse.Convoy.models.saved.*;

import ru.perevoshchikov.springcourse.Convoy.containers.Map;

import java.util.Iterator;

@Service
public class ConvoyService {
    private final Convoy convoy;

    @Autowired
    public ConvoyService(Convoy convoy) {
        this.convoy = convoy;
    }
    public Map<String, Ship> getShips() {
        return convoy.getShips();
    }

    public Ship getShip(String name) {
        return convoy.getShips().get(name);
    }

    public void addShip(String name, Ship ship) {
        convoy.getShips().add(name, ship);
    }

    public Ship removeShip(String name) {
        return convoy.getShips().remove(name);
    }

    public void loadCargo(double cargoWeight) {

    }

    public void distributeCargo() {

    }

    public void shareCargo(CargoCarrier from, CargoCarrier to, double sharedWeight) {
        from.setCargoWeight(from.getCargoWeight() - sharedWeight);
        if (from.getCargoWeight() < 0) from.setCargoWeight(0);

        to.setCargoWeight(to.getCargoWeight() + sharedWeight);
    }

    public WarShip modernTransport(TransportShip ship) {
        WarShip warShip = new WarShip(
                ship.getName(),
                ship.getCaptain(),
                ship.getDisplacement(),
                ship.getNumberOfCrewMembers()
        );

        Weapon weapon = new Weapon(25, 100, 20, 300);
        warShip.setWeapon(WeaponLocation.BOW, weapon);

        return warShip;
    }

    public long getDistance() {
        return (convoy.getDeparture().hashCode() + convoy.getDestination().hashCode()) % 100;
    }

    public void setDefaultShips() {
        addShip("T", new TransportShip());
        addShip("G", new GuardShip());
        addShip("W", new WarShip());

        Iterator<String> iterator = getShips().keys().iterator();

        while (iterator.hasNext()) {
            System.out.println("key: " + iterator.next());
        }
    }
}
