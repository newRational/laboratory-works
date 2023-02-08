package ru.perevoshchikov.springcourse.Convoy.models.abstracts;

abstract public class Commander {
    protected String fullName;
    protected int periodOfService;
    protected Commander(String fullName, int periodOfService) {
        this.fullName = fullName;
        this.periodOfService = periodOfService;
    }

    public String getFullName() {
        return fullName;
    }

    public int getPeriodOfService() {
        return periodOfService;
    }

    public void setPeriodOfService(int periodOfService) {
        this.periodOfService = periodOfService;
    }

    abstract public Rank getRank();
    abstract public void setRank(Rank rank);
}