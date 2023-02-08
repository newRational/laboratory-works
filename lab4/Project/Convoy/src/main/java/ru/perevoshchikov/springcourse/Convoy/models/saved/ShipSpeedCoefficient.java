package ru.perevoshchikov.springcourse.Convoy.models.saved;

public enum ShipSpeedCoefficient {
    TRANSPORT(90), WARSHIP(70), GUARD(50);
    private final int coefficient;
    ShipSpeedCoefficient(int coefficient) {
        this.coefficient = coefficient;
    }

    public int getCoefficient() {
        return coefficient;
    }
}
