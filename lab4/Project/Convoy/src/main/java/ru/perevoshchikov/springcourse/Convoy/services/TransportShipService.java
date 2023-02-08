package ru.perevoshchikov.springcourse.Convoy.services;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import ru.perevoshchikov.springcourse.Convoy.models.saved.TransportShip;
import ru.perevoshchikov.springcourse.Convoy.utils.mappers.TransportShipMapper;

import ru.perevoshchikov.springcourse.Convoy.containers.*;

@Service
public class TransportShipService {
    private final ConvoyService convoyService;
    private final TransportShipMapper transportShipMapper;

    @Autowired
    public TransportShipService(ConvoyService convoyService, TransportShipMapper transportShipMapper) {
        this.convoyService = convoyService;
        this.transportShipMapper = transportShipMapper;
    }

    public List<Pair<String, TransportShip>> findAll() {
        List<Pair<String, TransportShip>> transportShips = new List<>();

        convoyService.getShips().keys().stream()
                .filter(key -> convoyService.getShips().get(key).getClass().equals(TransportShip.class))
                .forEach(key -> transportShips.add(new Pair<>(key, (TransportShip) convoyService.getShips().get(key))));

        for (Pair<String, TransportShip> pair : transportShips)
            System.out.println("PAIR: K - " + pair.getFirst() + "; V - " + pair.getSecond());

        return transportShips;
    }

    public TransportShip findByName(String name) {
        return (TransportShip) convoyService.getShip(name);
    }

    public void save(String name, TransportShip transportShip) {
        convoyService.addShip(name, transportShip);
    }

    public void update(String name, TransportShip updatedShip) {
        TransportShip shipToBeUpdated = findByName(name);
        transportShipMapper.map(shipToBeUpdated, updatedShip);
    }

    public void delete(String name) {
        convoyService.removeShip(name);
    }

    public boolean loadCargo(String name, double cargoWeight) {
        TransportShip transportShip = findByName(name);
        transportShip.setCargoWeight(cargoWeight);

        return cargoWeight > 0;
    }
}
