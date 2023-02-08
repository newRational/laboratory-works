package ru.perevoshchikov.springcourse.Convoy.utils.validators;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.autoconfigure.AutoConfigureAfter;
import org.springframework.stereotype.Component;
import org.springframework.validation.Errors;
import org.springframework.validation.Validator;
import ru.perevoshchikov.springcourse.Convoy.models.saved.TransportShip;
import ru.perevoshchikov.springcourse.Convoy.models.saved.WarShip;
import ru.perevoshchikov.springcourse.Convoy.services.WarShipService;

@Component
public class WarShipValidator implements Validator {

    private final WarShipService warShipService;

    @Autowired
    public WarShipValidator(WarShipService warShipService) {
        this.warShipService = warShipService;
    }

    @Override
    public boolean supports(Class<?> instanceClass) {
        return TransportShip.class.equals(instanceClass);
    }

    @Override
    public void validate(Object target, Errors errors) {
        WarShip warShip = (WarShip) target;
    }
}
