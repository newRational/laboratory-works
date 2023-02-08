package ru.perevoshchikov.springcourse.Convoy.models.saved;

import ru.perevoshchikov.springcourse.Convoy.models.abstracts.Commander;
import ru.perevoshchikov.springcourse.Convoy.models.abstracts.Rank;

public class Captain extends Commander {
    private CaptainRank rank;

    public Captain(String fullName, int periodOfService, CaptainRank rank) {
        super(fullName, periodOfService);
    }

    @Override
    public CaptainRank getRank() {
        return rank;
    }

    @Override
    public void setRank(Rank rank) {
        assert rank instanceof CaptainRank;
        this.rank = (CaptainRank) rank;
    }
}
