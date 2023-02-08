package ru.perevoshchikov.springcourse.Convoy.controllers.models;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.*;
import ru.perevoshchikov.springcourse.Convoy.models.saved.TransportShip;
import ru.perevoshchikov.springcourse.Convoy.services.TransportShipService;

@Controller
@RequestMapping("/ships/transport-ships")
public class TransportShipController {
    private final TransportShipService transportShipService;

    @Autowired
    public TransportShipController(TransportShipService transportShipService) {
        this.transportShipService = transportShipService;
    }

    @GetMapping
    public String index(Model model) {
        model.addAttribute("transport-ships", transportShipService.findAll());
        return "ships/transport-ships/index";
    }

    @GetMapping("/{name}")
    public String show(@PathVariable("name") String name, Model model) {
        TransportShip transportShip = transportShipService.findByName(name);
        model.addAttribute("transport-ship", transportShip);
        return "ships/transport-ships/show";
    }

    @GetMapping("/new")
    public String newTransportShip(@ModelAttribute("transport-ship") TransportShip transportShip) {
        return "ships/transport-ships/new";
    }

    @PostMapping("/{name}")
    public String save(@PathVariable("name") String name,
                       @ModelAttribute("transport-ship") TransportShip transportShip) {
        transportShipService.save(name, transportShip);
        return "ships/transport-ships/index";
    }

    @GetMapping("/{name}/edit")
    public String edit(@PathVariable("name") String name, Model model) {
        model.addAttribute("transport-ship", transportShipService.findByName(name));
        return "ships/transport-ships/edit";
    }

    @PatchMapping("/{name}")
    public String update(@PathVariable("name") String name,
                         @ModelAttribute("transport-ship") TransportShip transportShip) {
        transportShipService.update(name, transportShip);
        return "redirect:/ships/transport-ships";
    }

    @DeleteMapping("/{name}")
    public String delete(@PathVariable("name") String name) {
        transportShipService.delete(name);
        return "redirect:/ships/transport-ships";
    }

    @GetMapping("/{name}/cargo")
    public String loadCargo(@PathVariable("name") String name,
                            @RequestParam("weight") double weight,
                            Model model) {

        boolean isLoaded = transportShipService.loadCargo(name, weight);
        model.addAttribute("isLoaded", isLoaded);

        return "redirect:/ships/transport-ships/" + name;
    }
}
