package ru.perevoshchikov.springcourse.Convoy.models.saved;

public class Weapon {
    private final int caliber;
    private final long firingRange;
    private int countOfShells;
    private double weight;

    public Weapon(int caliber, long firingRange, int countOfShells, double weight) {
        this.caliber = caliber;
        this.firingRange = firingRange;
        this.countOfShells = countOfShells;
        this.weight = weight;
    }

    public int getCaliber() {
        return caliber;
    }

    public long getFiringRange() {
        return firingRange;
    }

    public int getCountOfShells() {
        return countOfShells;
    }

    public double getWeight() {
        return weight;
    }

    public void setWeight(double weight) {
        this.weight = weight;
    }

    public boolean shoot() {
        System.out.println("SHOOT");

        if (countOfShells == 0)
            return false;

        --countOfShells;
        return true;
    }
}
