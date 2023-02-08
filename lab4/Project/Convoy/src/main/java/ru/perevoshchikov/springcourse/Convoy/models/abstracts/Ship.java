package ru.perevoshchikov.springcourse.Convoy.models.abstracts;

import ru.perevoshchikov.springcourse.Convoy.models.saved.Captain;

abstract public class Ship {
    protected String name;
    protected Captain captain;
    protected double displacement;
    protected int numberOfCrewMembers;
    protected int defaultSpeed;
    protected Ship() {}
    protected Ship(String name, Captain captain, double displacement, int numberOfCrewMembers, int defaultSpeed) {
        this.name = name;
        this.captain = captain;
        this.displacement = displacement;
        this.numberOfCrewMembers = numberOfCrewMembers;
        this.defaultSpeed = defaultSpeed;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public Captain getCaptain() {
        return captain;
    }

    public void setCaptain(Captain captain) {
        this.captain = captain;
    }

    public double getDisplacement() {
        return displacement;
    }

    public void setDisplacement(double displacement) {
        this.displacement = displacement;
    }

    public int getNumberOfCrewMembers() {
        return numberOfCrewMembers;
    }

    public void setNumberOfCrewMembers(int numberOfCrewMembers) {
        this.numberOfCrewMembers = numberOfCrewMembers;
    }

    public int getDefaultSpeed() {
        return defaultSpeed;
    };

    public void setDefaultSpeed(int defaultSpeed) {
        this.defaultSpeed = defaultSpeed;
    }

    abstract public int getMaxSpeed();
}
