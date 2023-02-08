package ru.perevoshchikov.springcourse.Convoy;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.AutoConfigureAfter;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import ru.perevoshchikov.springcourse.Convoy.services.ConvoyService;

@SpringBootApplication
public class ConvoyApplication {
	public static void main(String[] args) {
		SpringApplication.run(ConvoyApplication.class, args);
	}
}
