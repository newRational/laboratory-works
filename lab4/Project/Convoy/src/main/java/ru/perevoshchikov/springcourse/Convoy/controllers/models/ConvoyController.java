package ru.perevoshchikov.springcourse.Convoy.controllers.models;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.*;
import ru.perevoshchikov.springcourse.Convoy.services.ConvoyService;
import ru.perevoshchikov.springcourse.Convoy.services.GuardShipService;
import ru.perevoshchikov.springcourse.Convoy.services.TransportShipService;
import ru.perevoshchikov.springcourse.Convoy.services.WarShipService;

@Controller
@RequestMapping("/convoy")
public class ConvoyController {
    private final ConvoyService convoyService;
    private final TransportShipService transportShipService;
    private final GuardShipService guardShipService;
    private final WarShipService warShipService;

    @Autowired
    public ConvoyController(ConvoyService convoyService,
                            TransportShipService transportShipService,
                            GuardShipService guardShipService,
                            WarShipService warShipService) {
        this.convoyService = convoyService;
        this.transportShipService = transportShipService;
        this.guardShipService = guardShipService;
        this.warShipService = warShipService;
    }

    @GetMapping
    public String index(Model model) {
        convoyService.setDefaultShips();
        model.addAttribute("transport-ships", transportShipService.findAll());
        model.addAttribute("guard-ships", guardShipService.findAll());
        model.addAttribute("warships", warShipService.findAll());
        return "convoy/index";
    }

    @DeleteMapping("/{name}")
    public String deleteShip(@PathVariable("name") String name) {
        convoyService.removeShip(name);
        return "redirect:/convoy";
    }
}
