package ru.perevoshchikov.springcourse.Convoy.controllers.models;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.*;
import ru.perevoshchikov.springcourse.Convoy.models.saved.WarShip;
import ru.perevoshchikov.springcourse.Convoy.services.WarShipService;

@Controller
@RequestMapping("/ships/warship")
public class WarShipController {
    public final WarShipService warShipService;

    @Autowired
    public WarShipController(WarShipService warShipService) {
        this.warShipService = warShipService;
    }

    @GetMapping
    public String index(Model model) {
        model.addAttribute("warships", warShipService.findAll());
        return "ships/warship/index";
    }

    @GetMapping("/{name}")
    public String show(@PathVariable("name") String name, Model model) {
        WarShip warShip = warShipService.findByName(name);
        model.addAttribute("warship", warShip);
        return "ships/warship/show";
    }

    @GetMapping("/new")
    public String newWarShip(@ModelAttribute("warship") WarShip warShip) {
        return "ships/warship/new";
    }

    @PostMapping("/{name}")
    public String save(@PathVariable("name") String name,
                       @ModelAttribute("warship") WarShip warShip) {
        warShipService.save(name, warShip);
        return "ships/warship/index";
    }

    @GetMapping("/{name}/edit")
    public String edit(@PathVariable("name") String name, Model model) {
        model.addAttribute("warship", warShipService.findByName(name));
        return "ships/warship/edit";
    }

    @PatchMapping("/{name}")
    public String update(@PathVariable("name") String name,
                         @ModelAttribute("warship") WarShip warShip) {
        warShipService.update(name, warShip);
        return "redirect:/ships/warship";
    }

    @DeleteMapping("/{name}")
    public String delete(@PathVariable("name") String name) {
        warShipService.delete(name);
        return "redirect:/ships/warship";
    }

    @GetMapping("/{name}/shoot")
    public String shoot(@PathVariable("name") String name,
                        @RequestParam("weapon-location") String weaponLocation,
                        Model model) {

        boolean enoughShellsToShoot = warShipService.shoot(name, weaponLocation);
        model.addAttribute("enoughShellsToShoot", enoughShellsToShoot);

        return "redirect:/ships/warship/" + name;
    }

    @GetMapping("/{name}/cargo")
    public String loadCargo(@PathVariable("name") String name,
                       @RequestParam("weight") double weight,
                       Model model) {

        boolean isLoaded = warShipService.loadCargo(name, weight);
        model.addAttribute("isLoaded", isLoaded);

        return "redirect:/ships/warship/" + name;
    }
}
