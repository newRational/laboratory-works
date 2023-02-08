package ru.perevoshchikov.springcourse.Convoy.models.saved;

import ru.perevoshchikov.springcourse.Convoy.models.abstracts.Commander;
import ru.perevoshchikov.springcourse.Convoy.models.abstracts.Rank;

public class Admiral extends Commander {
    private AdmiralRank rank;

    public Admiral(String fullName, int periodOfService, AdmiralRank rank) {
        super(fullName, periodOfService);
    }

    @Override
    public AdmiralRank getRank() {
        return rank;
    }

    @Override
    public void setRank(Rank rank) {
        assert rank instanceof AdmiralRank;
        this.rank = (AdmiralRank) rank;
    }
}
