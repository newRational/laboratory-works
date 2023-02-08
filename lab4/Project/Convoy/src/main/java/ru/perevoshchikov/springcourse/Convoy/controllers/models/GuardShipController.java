package ru.perevoshchikov.springcourse.Convoy.controllers.models;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.data.util.Pair;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.*;
import ru.perevoshchikov.springcourse.Convoy.models.saved.GuardShip;
import ru.perevoshchikov.springcourse.Convoy.services.GuardShipService;

@Controller
@RequestMapping("/ships/guard-ship")
public class GuardShipController {
    private final GuardShipService guardShipService;

    @Autowired
    public GuardShipController(GuardShipService guardShipService) {
        this.guardShipService = guardShipService;
    }

    @GetMapping
    public String index(Model model) {
        model.addAttribute("guard-ships", guardShipService.findAll());
        return "ships/guard-ships/index";
    }

    @GetMapping("/{name}")
    public String show(@PathVariable("name") String name, Model model) {
        GuardShip guardShip = guardShipService.findByName(name);
        model.addAttribute("guard-ship", guardShip);
        return "ships/guard-ships/show";
    }

    @GetMapping("/new")
    public String newGuardShip(@ModelAttribute("guard-ship") GuardShip guardShip) {
        return "ships/guard-ships/new";
    }

    @PostMapping("/{name}")
    public String save(@PathVariable("name") String name, @ModelAttribute("guard-ship") GuardShip guardShip) {
        guardShipService.save(name, guardShip);
        return "ships/guard-ships/index";
    }

    @GetMapping("/{name}/edit")
    public String edit(@PathVariable("name") String name, Model model) {
        model.addAttribute("guard-ship", guardShipService.findByName(name));
        return "ships/guard-ships/edit";
    }

    @PatchMapping("/{name}")
    public String update(@PathVariable("name") String name, @ModelAttribute("guard-ship") GuardShip guardShip) {
        guardShipService.update(name, guardShip);
        return "redirect:/ships/guard-ships";
    }

    @DeleteMapping("/{name}")
    public String delete(@PathVariable("name") String name) {
        guardShipService.delete(name);
        return "redirect:/ships/guard-ships";
    }

    @GetMapping("/{name}/shoot")
    public String shoot(@PathVariable("name") String name,
                        @RequestParam("weapon-location") String weaponLocation,
                        Model model) {

        boolean enoughShellsToShoot = guardShipService.shoot(name, weaponLocation);
        model.addAttribute("enoughShellsToShoot", enoughShellsToShoot);

        return "redirect:/ships/guard-ship/" + name;
    }

}
