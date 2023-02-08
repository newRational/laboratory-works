package ru.perevoshchikov.springcourse.Convoy.utils.mappers;

import org.springframework.stereotype.Component;
import ru.perevoshchikov.springcourse.Convoy.models.saved.TransportShip;

@Component
public class TransportShipMapper implements Mapper<TransportShip, TransportShip> {

    @Override
    public void map(TransportShip dest, TransportShip source) {
        dest.setName(source.getName());
        dest.setCaptain(source.getCaptain());
        dest.setNumberOfCrewMembers(source.getNumberOfCrewMembers());
        dest.setCargoWeight(source.getCargoWeight());
    }
}
