package ru.perevoshchikov.springcourse.Convoy.models.saved;

import org.springframework.stereotype.Component;
import ru.perevoshchikov.springcourse.Convoy.models.abstracts.Ship;

import ru.perevoshchikov.springcourse.Convoy.containers.Map;

@Component
public class Convoy {
    private final Map<String, Ship> ships;
    private Admiral admiral;
    private String departure;
    private String destination;

    public Convoy() {
        ships = new Map<>();
    }

    public Convoy(Admiral admiral, String departure, String destination) {
        this.admiral = admiral;
        this.departure = departure;
        this.destination = destination;
        ships = new Map<>();
    }
    public Map<String, Ship> getShips() {
        return ships;
    }

    public Admiral getAdmiral() {
        return admiral;
    }
    public void setAdmiral(Admiral admiral) {
        this.admiral = admiral;
    }
    public String getDeparture() {
        return departure;
    }
    public void setDeparture(String departure) {
        this.departure = departure;
    }
    public String getDestination() {
        return destination;
    }
    public void setDestination(String destination) {
        this.destination = destination;
    }
}