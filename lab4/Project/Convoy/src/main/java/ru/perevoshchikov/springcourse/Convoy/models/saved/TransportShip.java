package ru.perevoshchikov.springcourse.Convoy.models.saved;

import ru.perevoshchikov.springcourse.Convoy.models.abstracts.CargoCarrier;
import ru.perevoshchikov.springcourse.Convoy.models.abstracts.Ship;

public class TransportShip extends Ship implements CargoCarrier {
    private double cargoWeight;

    public TransportShip() {
        super();
    }

    public TransportShip(String model, Captain captain, double displacement, int numberOfCrewMembers) {
        super(model, captain, displacement, numberOfCrewMembers, ShipSpeedCoefficient.TRANSPORT.getCoefficient());
    }

    @Override
    public double getCargoWeight() {
        return cargoWeight;
    }

    @Override
    public void setCargoWeight(double cargoWeight) {
        this.cargoWeight = cargoWeight;
    }

    @Override
    public int getMaxSpeed() {
        return (int) (1 / (defaultSpeed + cargoWeight));
    }
}
