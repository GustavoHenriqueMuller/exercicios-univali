package org.rohling.rest.controller;

import lombok.RequiredArgsConstructor;
import org.rohling.domain.entity.User_;
import org.rohling.exception.InvalidPasswordException;
import org.rohling.rest.dto.CredentialDTO;
import org.rohling.rest.dto.TokenDTO;
import org.rohling.security.jwt.JwtService;
import org.rohling.service.implementation.UserServiceImplementation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.security.core.userdetails.User;
import org.springframework.security.core.userdetails.UserDetails;
import org.springframework.security.core.userdetails.UsernameNotFoundException;
import org.springframework.security.crypto.password.PasswordEncoder;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.server.ResponseStatusException;

import javax.validation.Valid;

@RestController
@RequestMapping("/api/users")
public class UserController {

    @Autowired
    private UserServiceImplementation userService;

    @Autowired
    private PasswordEncoder passwordEncoder;

    @Autowired
    private JwtService jwtService;

    @PostMapping
    @ResponseStatus(HttpStatus.CREATED)
    public User_ save(@RequestBody @Valid User_ user) {
        String password = passwordEncoder.encode(user.getPassword());
        user.setPassword(password);
        return userService.save(user);
    }

    @PostMapping("/auth")
    public TokenDTO authenticate(@RequestBody CredentialDTO credential) {
        try {
            User_ user = User_.builder().login(credential.getLogin()).password(credential.getPassword()).build();
            UserDetails authenticatedUser = userService.authenticate(user);
            String token = jwtService.generateToken(user);
            return new TokenDTO(user.getLogin(), token);
        } catch (UsernameNotFoundException | InvalidPasswordException e) {
            throw new ResponseStatusException(HttpStatus.UNAUTHORIZED, e.getMessage());
        }
    }
}
